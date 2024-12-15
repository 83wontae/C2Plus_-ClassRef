#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 512 // 수신 버퍼 크기
#define DEFAULT_PORT "27015" // 사용할 포트 번호 선언

const int MAX_CLIENT = 10;

int clientCount = 0;
std::vector<SOCKET> clients;// Dynamic하게 유동적인 배열로 변경
std::mutex mtx;

void broadcastMessage(const char* message, int senderIndex) {
    // std::lock_guard : 스코프 기반 락 관리 방식, 함수의 실행이 범위를 벗어날 때 자동으로 락을 해제
    std::lock_guard<std::mutex> lock(mtx); // RAII 기반 락 관리
    int messageLength = strlen(message); // 실제 메시지 길이 계산

    // 클라이언트 벡터를 순회
    int index = 0; // 현재 인덱스를 추적
    for (auto& clientSocket : clients) {
        if (index != senderIndex) {
            send(clientSocket, message, messageLength, 0);
        }
        ++index; // 다음 클라이언트로 인덱스 증가
    }
}

void clientHandler(int idx)
{
    char buffer[DEFAULT_BUFLEN + 1];

    while (true) {
        int bytesReceived = recv(clients[idx], buffer, DEFAULT_BUFLEN, 0);

        if (bytesReceived <= 0) {
            std::lock_guard<std::mutex> lock(mtx);

            // 클라이언트 인덱스가 유효한지 확인
            if (idx >= 0 && idx < clients.size() && clients[idx] != INVALID_SOCKET) {
                closesocket(clients[idx]);
                clients[idx] = INVALID_SOCKET;
                std::cout << "Client disconnected" << std::endl;
            }
            break;
        }

        buffer[bytesReceived] = '\0';
        broadcastMessage(buffer, idx);
    }
}

void serverLoop(SOCKET ListenSocket)
{
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
                clients.push_back(ClientSocket);
                int clientIndex = clients.size() - 1;

                std::cout << "Client connected" << std::endl;

                // 스레드에서 클라이언트 핸들러 실행
                std::thread(clientHandler, clientIndex).detach();
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