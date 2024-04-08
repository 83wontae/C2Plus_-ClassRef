// https://learn.microsoft.com/ko-kr/windows/win32/winsock/getting-started-with-winsock

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "Ws2_32.lib")// 링커에 Ws2_32.lib 파일요청( Winsock을 사용하는 애플리케이션은 Ws2_32.lib 라이브러리 파일과 연결 필요 )

#define DEFAULT_PORT "27015" // 사용할 포트 번호 선언
#define DEFAULT_BUFLEN 512 // 수신 버퍼 크기

int main() {
	WSADATA wsaData;// windows socket에 대한 정보

	int iResult;

	// addrinfo : socket 프로그래밍에서 주소 정보 저장 구조체
	struct addrinfo* result = NULL, * ptr = NULL, hints;

	// 서버가 클라이언트 연결을 수신 대기 socket
	SOCKET ListenSocket = INVALID_SOCKET;

	// Initialize Winsock
	// WSAStartup : WS2_32.dll 사용을 시작
	// MAKEWORD(2, 2) : Winsock 버전 2.2를 요청
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));// hints 메모리 초기화
	// AF_INET : IPv4 주소 패밀리를 지정
	hints.ai_family = AF_INET; 
	// SOCK_STREAM (TCP - Transmission Control Protocol):
	// 연결형 프로토콜로, 신뢰성있는 데이터 전송을 보장합니다.
	// 연결을 설정하고 데이터를 전송한 후, 연결을 종료하기 전까지 상태를 유지합니다.
	// 데이터의 순서가 보장되며, 전송되는 데이터에 대한 에러 확인과 재전송을 지원합니다.
	// 양방향 통신을 지원하며, 스트림 형태로 데이터를 전송합니다.
	// 연결 설정, 연결 유지, 연결 해제 등의 오버헤드가 있지만, 안정적인 데이터 전송을 보장합니다.
	// 예시: 웹 브라우징, 파일 전송, 이메일 등에 사용됩니다.
	hints.ai_socktype = SOCK_STREAM;
	// IPPROTO_TCP : TCP 프로토콜 을 지정
	hints.ai_protocol = IPPROTO_TCP;
	// AI_PASSIVE는 "수동적인"이라는 의미를 가지며, 이 옵션을 사용하면 해당 주소가 수동적인 것으로 설정된다
	// 즉, 주소가 특정 호스트나 인터페이스를 나타내는 것이 아니라, 소켓이 수신 대기 상태
	// IP 주소 필드를 "0.0.0.0"으로 설정하는 것과 동일
	// bind() 함수를 호출할 때 AI_PASSIVE 옵션을 사용하면 소켓이 어떤 인터페이스나 호스트에도 바인딩되지 않음
	// 모든 네트워크 인터페이스에 대해 수신 대기 상태로 들어간다고 지정한다
	// 이것은 특히 서버 프로그램에서 사용한다
	// 서버는 클라이언트의 연결을 수락하기 위해 모든 네트워크 인터페이스에서 수신 대기 상태에 있어야 하기 때문이다
	hints.ai_flags = AI_PASSIVE;

	// Resolve the local address and port to be used by the server
	// getaddrinfo : IP, port를 이용하여 네트워크 주소 정보를 가져오는 데 사용
	// &hints : 가져올 주소에 대한 힌트 제공
	// &result : 가져온 주소 정보를 저장
	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed: %d\n", iResult);
		WSACleanup();// WSAStartup : WS2_32.dll 사용을 종료
		return 1;
	}

	// ***** 소켓 생성[ socket() ] - TCP 소켓을 생성 한다. *****
	// Create a SOCKET for the server to listen for client connections
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET) {
		printf("Error at socket(): %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();// WSAStartup : WS2_32.dll 사용을 종료
		return 1;
	}

	// ***** 소켓 바인딩[ bind() ] - 소켓에 포트번호를 부여 *****
	// 서버가 클라이언트 연결을 허용하려면 시스템 내의 네트워크 주소에 바인딩되어야 합니다. 
	// 언바운드 소켓(unbound socket) : 아직 특정 주소와 연결되지 않은 소켓
	// Setup the TCP listening socket
	iResult = bind(ListenSocket/*바인딩할 소켓*/, result->ai_addr/*주소*/, (int)result->ai_addrlen/*주소 길이*/);
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);// bind 함수가 호출되면 getaddrinfo 함수에서 반환된 주소 정보가 더 이상 필요하지 않습니다. 
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	freeaddrinfo(result);// bind 함수가 호출되면 getaddrinfo 함수에서 반환된 주소 정보가 더 이상 필요하지 않습니다. 

	// ***** 소켓에서 수신 대기[ listen() ] *****
	// SOMAXCONN : 최대 연결 대기열의 크기, 특정 시스템에 따라 다를 수 있지만, 일반적으로는 충분히 큰 값으로 정의
	if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
		printf("Listen failed with error: %ld\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	// ***** 연결 수락[ accept() ] *****
	// 클라이언트 연결 대기 socket
	SOCKET ClientSocket = INVALID_SOCKET;

	// Accept a client socket
	// ListenSocket은 클라이언트의 연결 요청을 새로운 소켓 ClientSocket에 넘긴다.
	// 두 번째와 세 번째 매개변수는 클라이언트의 주소 정보를 저장하기 위한 포인터
	ClientSocket = accept(ListenSocket, NULL, NULL);
	if (ClientSocket == INVALID_SOCKET) {
		printf("accept failed: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	// No longer need server socket
	closesocket(ListenSocket);

	// ***** 서버에서 데이터 수신 및 보내기[ recv(), send() ] *****
	int iSendResult;
	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;

	// Receive until the peer shuts down the connection
	do {

		iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
		if (iResult > 0) {
			printf("Bytes received: %d\n", iResult);

			// Echo the buffer back to the sender
			iSendResult = send(ClientSocket, recvbuf, iResult, 0);
			if (iSendResult == SOCKET_ERROR) {
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(ClientSocket);
				WSACleanup();
				return 1;
			}
			printf("Bytes sent: %d\n", iSendResult);
		}
		else if (iResult == 0)
			printf("Connection closing...\n");
		else {
			printf("recv failed: %d\n", WSAGetLastError());
			closesocket(ClientSocket);
			WSACleanup();
			return 1;
		}

	} while (iResult > 0);

	// ***** 서버 연결 끊기 *****
	// shutdown the send half of the connection since no more data will be sent
	iResult = shutdown(ClientSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed: %d\n", WSAGetLastError());
		closesocket(ClientSocket);
		WSACleanup();
		return 1;
	}

	closesocket(ListenSocket);// socket 제거

	WSACleanup();// WSAStartup : WS2_32.dll 사용을 종료

	system("pause");

	return 0;
}