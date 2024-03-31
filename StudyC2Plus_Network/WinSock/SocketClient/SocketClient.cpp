// https://learn.microsoft.com/ko-kr/windows/win32/winsock/getting-started-with-winsock

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


#define DEFAULT_BUFLEN 512 // 수신 버퍼 크기
#define DEFAULT_PORT "27015" // 사용할 포트 번호 선언

int __cdecl main(int argc, char** argv)
{
    WSADATA wsaData;

    int iResult;

    // argv : 첫번째 값은 무조건 실행 파일의 경로, 두번째 부터는 추가한 명령 인수
    // argc : argv에 갯수
    printf("argv[0] : %s\n", argv[0]);
    printf("argv[1] : %s\n", argv[1]);

    // 접속할 주소 정보를 명령 인수로 추가했는지 여부 채크
    // Validate the parameters
    if (argc != 2) {
        printf("usage: %s server-name\n", argv[0]);
        system("pause");
        return 1;
    }

    // Initialize Winsock
    // WSAStartup : WS2_32.dll 사용을 시작
    // MAKEWORD(2, 2) : Winsock 버전 2.2를 요청
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        system("pause");
        return 1;
    }

    // ***** 클라이언트에 대한 소켓 만들기 ***** //
    struct addrinfo* result = NULL,
        * ptr = NULL,
        hints;

    ZeroMemory(&hints, sizeof(hints));
    // AF_UNSPEC : IPv4 또는 IPv6와 같은 특정한 주소 체계를 선택할 필요 없이 시스템이 사용 가능한 모든 주소 체계를 자동으로 선택
    hints.ai_family = AF_UNSPEC;
    // SOCK_STREAM : 스트림 소켓을 지정
    hints.ai_socktype = SOCK_STREAM; 
    // IPPROTO_TCP : TCP 프로토콜 을 지정
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    // getaddrinfo : IP, port를 이용하여 네트워크 주소 정보를 가져오는 데 사용
    // argv[1] : 명령 인수로 추가한 주소 정보
    // &hints : 가져올 주소에 대한 힌트 제공
    // &result : 가져온 주소 정보를 저장
    iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        system("pause");
        return 1;
    }

    // 클라이언트 연결 대기 socket
    SOCKET ConnectSocket = INVALID_SOCKET;

    // result에 반환되는 주소가 여러개가 될수 있다
    // 예를 들어, 로드 밸런싱이나 장애 조치를 위해 여러개의 IP를 사용할 수 있다.
    // Attempt to connect to an address until one succeeds
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

        // Create a SOCKET for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
            ptr->ai_protocol);

        if (ConnectSocket == INVALID_SOCKET) {
            printf("socket failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
            system("pause");
            return 1;
        }

        // Connect to server.
        iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);// bind 함수가 호출되면 getaddrinfo 함수에서 반환된 주소 정보가 더 이상 필요하지 않습니다. 

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        system("pause");
        return 1;
    }

    // ***** 클라이언트에서 데이터 보내기 및 받기 ***** //

    const char* sendbuf = "this is a test";
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;

    // Send an initial buffer
    iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
    if (iResult == SOCKET_ERROR) {
        printf("send failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        system("pause");
        return 1;
    }

    printf("Bytes Sent: %ld\n", iResult);

    // shutdown the connection since no more data will be sent
    iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        system("pause");
        return 1;
    }

    // Receive until the peer closes the connection
    do {

        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0)
            printf("Bytes received: %d\n", iResult);
        else if (iResult == 0)
            printf("Connection closed\n");
        else
            printf("recv failed with error: %d\n", WSAGetLastError());

    } while (iResult > 0);

    // cleanup
    closesocket(ConnectSocket);
    WSACleanup();

    system("pause");

    return 0;
}