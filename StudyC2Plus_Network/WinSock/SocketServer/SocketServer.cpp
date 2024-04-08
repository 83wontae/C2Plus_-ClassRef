// https://learn.microsoft.com/ko-kr/windows/win32/winsock/getting-started-with-winsock

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "Ws2_32.lib")// ��Ŀ�� Ws2_32.lib ���Ͽ�û( Winsock�� ����ϴ� ���ø����̼��� Ws2_32.lib ���̺귯�� ���ϰ� ���� �ʿ� )

#define DEFAULT_PORT "27015" // ����� ��Ʈ ��ȣ ����
#define DEFAULT_BUFLEN 512 // ���� ���� ũ��

int main() {
	WSADATA wsaData;// windows socket�� ���� ����

	int iResult;

	// addrinfo : socket ���α׷��ֿ��� �ּ� ���� ���� ����ü
	struct addrinfo* result = NULL, * ptr = NULL, hints;

	// ������ Ŭ���̾�Ʈ ������ ���� ��� socket
	SOCKET ListenSocket = INVALID_SOCKET;

	// Initialize Winsock
	// WSAStartup : WS2_32.dll ����� ����
	// MAKEWORD(2, 2) : Winsock ���� 2.2�� ��û
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));// hints �޸� �ʱ�ȭ
	// AF_INET : IPv4 �ּ� �йи��� ����
	hints.ai_family = AF_INET; 
	// SOCK_STREAM (TCP - Transmission Control Protocol):
	// ������ �������ݷ�, �ŷڼ��ִ� ������ ������ �����մϴ�.
	// ������ �����ϰ� �����͸� ������ ��, ������ �����ϱ� ������ ���¸� �����մϴ�.
	// �������� ������ ����Ǹ�, ���۵Ǵ� �����Ϳ� ���� ���� Ȯ�ΰ� �������� �����մϴ�.
	// ����� ����� �����ϸ�, ��Ʈ�� ���·� �����͸� �����մϴ�.
	// ���� ����, ���� ����, ���� ���� ���� ������尡 ������, �������� ������ ������ �����մϴ�.
	// ����: �� ����¡, ���� ����, �̸��� � ���˴ϴ�.
	hints.ai_socktype = SOCK_STREAM;
	// IPPROTO_TCP : TCP �������� �� ����
	hints.ai_protocol = IPPROTO_TCP;
	// AI_PASSIVE�� "��������"�̶�� �ǹ̸� ������, �� �ɼ��� ����ϸ� �ش� �ּҰ� �������� ������ �����ȴ�
	// ��, �ּҰ� Ư�� ȣ��Ʈ�� �������̽��� ��Ÿ���� ���� �ƴ϶�, ������ ���� ��� ����
	// IP �ּ� �ʵ带 "0.0.0.0"���� �����ϴ� �Ͱ� ����
	// bind() �Լ��� ȣ���� �� AI_PASSIVE �ɼ��� ����ϸ� ������ � �������̽��� ȣ��Ʈ���� ���ε����� ����
	// ��� ��Ʈ��ũ �������̽��� ���� ���� ��� ���·� ���ٰ� �����Ѵ�
	// �̰��� Ư�� ���� ���α׷����� ����Ѵ�
	// ������ Ŭ���̾�Ʈ�� ������ �����ϱ� ���� ��� ��Ʈ��ũ �������̽����� ���� ��� ���¿� �־�� �ϱ� �����̴�
	hints.ai_flags = AI_PASSIVE;

	// Resolve the local address and port to be used by the server
	// getaddrinfo : IP, port�� �̿��Ͽ� ��Ʈ��ũ �ּ� ������ �������� �� ���
	// &hints : ������ �ּҿ� ���� ��Ʈ ����
	// &result : ������ �ּ� ������ ����
	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed: %d\n", iResult);
		WSACleanup();// WSAStartup : WS2_32.dll ����� ����
		return 1;
	}

	// ***** ���� ����[ socket() ] - TCP ������ ���� �Ѵ�. *****
	// Create a SOCKET for the server to listen for client connections
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET) {
		printf("Error at socket(): %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();// WSAStartup : WS2_32.dll ����� ����
		return 1;
	}

	// ***** ���� ���ε�[ bind() ] - ���Ͽ� ��Ʈ��ȣ�� �ο� *****
	// ������ Ŭ���̾�Ʈ ������ ����Ϸ��� �ý��� ���� ��Ʈ��ũ �ּҿ� ���ε��Ǿ�� �մϴ�. 
	// ��ٿ�� ����(unbound socket) : ���� Ư�� �ּҿ� ������� ���� ����
	// Setup the TCP listening socket
	iResult = bind(ListenSocket/*���ε��� ����*/, result->ai_addr/*�ּ�*/, (int)result->ai_addrlen/*�ּ� ����*/);
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);// bind �Լ��� ȣ��Ǹ� getaddrinfo �Լ����� ��ȯ�� �ּ� ������ �� �̻� �ʿ����� �ʽ��ϴ�. 
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	freeaddrinfo(result);// bind �Լ��� ȣ��Ǹ� getaddrinfo �Լ����� ��ȯ�� �ּ� ������ �� �̻� �ʿ����� �ʽ��ϴ�. 

	// ***** ���Ͽ��� ���� ���[ listen() ] *****
	// SOMAXCONN : �ִ� ���� ��⿭�� ũ��, Ư�� �ý��ۿ� ���� �ٸ� �� ������, �Ϲ������δ� ����� ū ������ ����
	if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
		printf("Listen failed with error: %ld\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	// ***** ���� ����[ accept() ] *****
	// Ŭ���̾�Ʈ ���� ��� socket
	SOCKET ClientSocket = INVALID_SOCKET;

	// Accept a client socket
	// ListenSocket�� Ŭ���̾�Ʈ�� ���� ��û�� ���ο� ���� ClientSocket�� �ѱ��.
	// �� ��°�� �� ��° �Ű������� Ŭ���̾�Ʈ�� �ּ� ������ �����ϱ� ���� ������
	ClientSocket = accept(ListenSocket, NULL, NULL);
	if (ClientSocket == INVALID_SOCKET) {
		printf("accept failed: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	// No longer need server socket
	closesocket(ListenSocket);

	// ***** �������� ������ ���� �� ������[ recv(), send() ] *****
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

	// ***** ���� ���� ���� *****
	// shutdown the send half of the connection since no more data will be sent
	iResult = shutdown(ClientSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed: %d\n", WSAGetLastError());
		closesocket(ClientSocket);
		WSACleanup();
		return 1;
	}

	closesocket(ListenSocket);// socket ����

	WSACleanup();// WSAStartup : WS2_32.dll ����� ����

	system("pause");

	return 0;
}