#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512

int main() {
    WSADATA wsaData;
    int iResult;

    struct addrinfo* result = NULL, hints;

    SOCKET ListenSocket = INVALID_SOCKET;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    // SOCK_DGRAM(UDP - User Datagram Protocol) :
    // 데이터그램 방식의 소켓 유형입니다.
    // 비연결형 프로토콜로, 데이터를 전송할 때 연결을 설정하거나 해제할 필요가 없습니다.
    // 패킷의 손실이나 순서가 보장되지 않으며, 데이터 전송이 신속하고 경량화되어 있습니다.
    // 각 데이터그램은 독립적으로 처리되므로 데이터의 경계가 보존됩니다.
    // 예시 : DNS 쿼리, 스트리밍 서비스 등에 사용됩니다.
    hints.ai_socktype = SOCK_DGRAM;
    // IPPROTO_UDP : UDP 프로토콜 을 지정
    hints.ai_protocol = IPPROTO_UDP;
    hints.ai_flags = AI_PASSIVE;

    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("Error at socket(): %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    // 데이터 수신 및 에코
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    sockaddr_in clientAddr;
    int clientAddrSize = sizeof(clientAddr);
    int bytesReceived;

    while (true) {
        bytesReceived = recvfrom(ListenSocket, recvbuf, recvbuflen, 0, (sockaddr*)&clientAddr, &clientAddrSize);
        if (bytesReceived == SOCKET_ERROR) {
            printf("recvfrom failed: %d\n", WSAGetLastError());
            closesocket(ListenSocket);
            WSACleanup();
            return 1;
        }

        // 받은 메시지를 클라이언트에게 에코
        int bytesSent = sendto(ListenSocket, recvbuf, bytesReceived, 0, (sockaddr*)&clientAddr, clientAddrSize);
        if (bytesSent == SOCKET_ERROR) {
            printf("sendto failed: %d\n", WSAGetLastError());
            closesocket(ListenSocket);
            WSACleanup();
            return 1;
        }
    }

    closesocket(ListenSocket);
    WSACleanup();

    system("pause");

    return 0;
}