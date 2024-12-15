#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <map>

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 512 // 수신 버퍼 크기
#define DEFAULT_PORT "27015" // 사용할 포트 번호 선언

const int MAX_CLIENT = 10;

int clientCount = 0;
std::map<int, SOCKET> clients; // 클라이언트 소켓을 저장하는 Map
std::mutex mtx;

void broadcastMessage(const char* message, int senderId) {
    // std::lock_guard : 스코프 기반 락 관리 방식, 함수의 실행이 범위를 벗어날 때 자동으로 락을 해제
    std::lock_guard<std::mutex> lock(mtx); // RAII 기반 락 관리
    int messageLength = strlen(message); // 실제 메시지 길이 계산

    // 클라이언트 Map 순회
    // C++17 이상 버전 방식
    for (const auto& [clientId, clientSocket] : clients) {
        if (clientId != senderId) {
            send(clientSocket, message, messageLength, 0);
        }
    }

    /*
    // C++11/14 버전 방식
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

            // 클라이언트 소켓 닫기 및 Map에서 제거
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

        // RAII를 이용한 락 관리
        {
            std::lock_guard<std::mutex> lock(mtx); // RAII lock

            if (clients.size() < MAX_CLIENT) { // MAX_CLIENT를 필요에 따라 사용하거나 제한을 완전히 제거할 수 있음
                int clientId = clientIdCounter++;
                clients[clientId] = ClientSocket;

                std::cout << "Client connected: ID " << clientId << std::endl;

                // 스레드에서 클라이언트 핸들러 실행
                std::thread(clientHandler, clientId).detach();
            }
            else {
                // 클라이언트가 가득 찼으면 소켓 닫기
                closesocket(ClientSocket);
                std::cout << "Connection refused: server full" << std::endl;
            }
        }
        // `std::lock_guard`의 소멸자로 인해 여기서 자동으로 mtx.unlock() 호출
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

    // 리슨 소켓 정리
    closesocket(ListenSocket);
    WSACleanup();

    return 0;
}