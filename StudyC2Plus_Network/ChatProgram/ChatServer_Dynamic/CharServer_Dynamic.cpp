#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <map>

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 512 // ���� ���� ũ��
#define DEFAULT_PORT "27015" // ����� ��Ʈ ��ȣ ����

const int MAX_CLIENT = 10;

int clientCount = 0;
std::map<int, SOCKET> clients; // Ŭ���̾�Ʈ ������ �����ϴ� Map
std::mutex mtx;

void broadcastMessage(const char* message, int senderId) {
    // std::lock_guard : ������ ��� �� ���� ���, �Լ��� ������ ������ ��� �� �ڵ����� ���� ����
    std::lock_guard<std::mutex> lock(mtx); // RAII ��� �� ����
    int messageLength = strlen(message); // ���� �޽��� ���� ���

    // Ŭ���̾�Ʈ Map ��ȸ
    // C++17 �̻� ���� ���
    for (const auto& [clientId, clientSocket] : clients) {
        if (clientId != senderId) {
            send(clientSocket, message, messageLength, 0);
        }
    }

    /*
    // C++11/14 ���� ���
    for (const auto& client : clients) {
        int clientId = client.first;       // Key (Client ID)
        SOCKET clientSocket = client.second; // Value (Client Socket)
        
        if (clientId != senderId) {
            send(clientSocket, message, messageLength, 0);
        }
    }
    */
}

void clientHandler(int clientId)
{
    char buffer[DEFAULT_BUFLEN + 1];

    while (true) {
        int bytesReceived = recv(clients[clientId], buffer, DEFAULT_BUFLEN, 0);

        if (bytesReceived <= 0) {
            std::lock_guard<std::mutex> lock(mtx);

            // Ŭ���̾�Ʈ ���� �ݱ� �� Map���� ����
            if (clients.count(clientId)) {
                closesocket(clients[clientId]);
                clients.erase(clientId);
                std::cout << "Client disconnected: ID " << clientId << std::endl;
            }
            break;
        }

        buffer[bytesReceived] = '\0';
        broadcastMessage(buffer, clientId);
    }
}

void serverLoop(SOCKET ListenSocket)
{
    int clientIdCounter = 0;

    while (true)
    {
        // Accept a client socket
        SOCKET ClientSocket = accept(ListenSocket, NULL, NULL);
        if (ClientSocket == INVALID_SOCKET) {
            std::cerr << "accept failed with error: " << WSAGetLastError() << std::endl;
            continue;
        }

        // RAII�� �̿��� �� ����
        {
            std::lock_guard<std::mutex> lock(mtx); // RAII lock

            if (clients.size() < MAX_CLIENT) { // MAX_CLIENT�� �ʿ信 ���� ����ϰų� ������ ������ ������ �� ����
                int clientId = clientIdCounter++;
                clients[clientId] = ClientSocket;

                std::cout << "Client connected: ID " << clientId << std::endl;

                // �����忡�� Ŭ���̾�Ʈ �ڵ鷯 ����
                std::thread(clientHandler, clientId).detach();
            }
            else {
                // Ŭ���̾�Ʈ�� ���� á���� ���� �ݱ�
                closesocket(ClientSocket);
                std::cout << "Connection refused: server full" << std::endl;
            }
        }
        // `std::lock_guard`�� �Ҹ��ڷ� ���� ���⼭ �ڵ����� mtx.unlock() ȣ��
    }
}

int __cdecl main(void)
{
    WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo* result = NULL;
    struct addrinfo hints;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Create a SOCKET for the server to listen for client connections.
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Setup the TCP listening socket
    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    iResult = listen(ListenSocket, MAX_CLIENT);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Chat server started on port " << DEFAULT_PORT << std::endl;

    serverLoop(ListenSocket);

    // ���� ���� ����
    closesocket(ListenSocket);
    WSACleanup();

    return 0;
}