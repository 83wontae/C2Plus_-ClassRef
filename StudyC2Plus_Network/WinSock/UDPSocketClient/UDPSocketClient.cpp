#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512

int main() {
    WSADATA wsaData;
    int iResult;

    struct addrinfo* result = NULL, * ptr = NULL, hints;

    SOCKET ConnectSocket = INVALID_SOCKET;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        system("pause");
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = IPPROTO_UDP;

    iResult = getaddrinfo("127.0.0.1", DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed: %d\n", iResult);
        WSACleanup();
        system("pause");
        return 1;
    }

    // 소켓 생성
    ConnectSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ConnectSocket == INVALID_SOCKET) {
        printf("Error at socket(): %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        system("pause");
        return 1;
    }

    // 서버로 메시지 전송
    const char* message = "Hello, server!";
    int messageLength = strlen(message);
    iResult = sendto(ConnectSocket, message, messageLength, 0, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("sendto failed: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        system("pause");
        return 1;
    }

    // 서버로부터 응답 받기
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    sockaddr_in serverAddr;
    int serverAddrSize = sizeof(serverAddr);
    iResult = recvfrom(ConnectSocket, recvbuf, recvbuflen, 0, (sockaddr*)&serverAddr, &serverAddrSize);
    if (iResult == SOCKET_ERROR) {
        printf("recvfrom failed: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        system("pause");
        return 1;
    }

    // 서버로부터 받은 메시지 출력
    recvbuf[iResult] = '\0'; // NULL 종료 문자 추가
    printf("Server response: %s\n", recvbuf);

    closesocket(ConnectSocket);
    WSACleanup();
    system("pause");
    return 0;
}