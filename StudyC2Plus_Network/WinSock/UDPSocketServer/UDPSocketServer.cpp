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
    // �����ͱ׷� ����� ���� �����Դϴ�.
    // �񿬰��� �������ݷ�, �����͸� ������ �� ������ �����ϰų� ������ �ʿ䰡 �����ϴ�.
    // ��Ŷ�� �ս��̳� ������ ������� ������, ������ ������ �ż��ϰ� �淮ȭ�Ǿ� �ֽ��ϴ�.
    // �� �����ͱ׷��� ���������� ó���ǹǷ� �������� ��谡 �����˴ϴ�.
    // ���� : DNS ����, ��Ʈ���� ���� � ���˴ϴ�.
    hints.ai_socktype = SOCK_DGRAM;
    // IPPROTO_UDP : UDP �������� �� ����
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

    // ������ ���� �� ����
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

        // ���� �޽����� Ŭ���̾�Ʈ���� ����
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