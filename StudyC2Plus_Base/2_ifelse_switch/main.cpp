#include <iostream>
#include <stdio.h>
#include <bitset>

// c++ 의 컴파일
// c++에서 사람이 작성한 소스코드를 컴퓨터가 읽을수 있는 코드로 변환하여 실행할수 있는 파일로 변환하는 과정

// 1. 전처리(Preprocessing) 단계 : #include 와 #define 과 같은 전처리기 매크로들을 처리하는 단계
// 2. 컴파일(Compile) 단계 : 각각의 소스 파일들을 어셈블리 명령어로 변환
// 3. 어셈블(Assemble) 단계 : 어셈블리 코드들을 실제 기계어로 이루어진 목적 코드(Object file)로 변환하는 단계
// 4. 링킹(Linking) 단계 : 각각의 목적 코드들을 한데 모아서 하나의 실행 파일을 생성하는 단계


// 메모리 영역
// 1. Code 영역 : 실행할 코드가 저장되어있는 영역(기계어로 존재)
// 2. Data 영역 : 전역변수, Static 변수들이 저장, 프로세스가 종료될때 까지 메모리에 저장됨
// 3. Stack 영역 : 지역변수, 매개변수들이 저장, 함수가 호출되면 생성되고 함수가 종료되면 시스템에 반환
// 4. Heap 영역 : malloc 또는 new 함수에 의해서 동적으로 할당되는 영역, malloc() 또는 new 연산자로 할당, free() 또는 delete 연사자로 해제

#define LEVEL1_REWARD_10 0b00000001;// 1
#define LEVEL1_REWARD_20 0b00000010;// 2
#define LEVEL1_REWARD_30 0b00000100;// 4
#define LEVEL1_REWARD_40 0b00001000;// 8
#define LEVEL1_REWARD_50 0b00010000;// 16
#define LEVEL1_REWARD_60 0b00100000;// 32

int main()
{
	{
		//int a = 0;
		//std::cin >> a;
		//std::cout << a << "을 입력하셨습니다.";
	}

	{
		// %d : 부호 있는 10진수 정수
		// %I64d : 부호 있는 10진수 정수(8Byte)
		// %u : 부호 없는 10진수 정수
		// %I64u : 부호 없는 10진수 정수(8Byte)
		// %f : 부호 있는 실수(12345.6789);
		// %e, %E : 부호 있는 실수(1.23456789e+005)
		// %i : 부호 있는 10진수 정수(10진수/8진수/16진수 입력 가능)
		// %x : 부호 없는 16진수 정수(0123456789abcdef)
		// %X : 부호 없는 16진수 정수(0123456789ABCDEF)
		// %o : 부호 없는 8진수
		// %p : 포인터 값을 16진수로 표기
		// %c : 단일 문자 출력

		//int a = 0, b = 0;
		//scanf_s("%d %d", &a, &b);
		//printf("a더하기 b는? %d", a+b);
	}

	//bool bReulst = true;

	//if (bReulst)
	//{
	//	printf("참이다.");
	//}
	//else
	//{
	//	printf("거짓이다.");
	//}

	//int Score = 0;
	//printf("Score를 입력해주세요 : ");
	//scanf_s("%d", &Score);
	//if (Score >= 90)
	//{
	//	printf("A학점");
	//}
	//else if(Score >= 80)	
	//{
	//	printf("B학점");
	//}	
	//else if (Score >= 70)
	//{	
	//	printf("C학점");
	//}
	//else if (Score >= 60)
	//{
	//	printf("D학점");
	//}
	//else if (Score >= 50)
	//{
	//	printf("E학점");
	//}
	//else
	//{
	//	printf("F학점");
	//}

	//int backNumber = 0;
	//scanf_s("%d", &backNumber);

	//switch (backNumber)
	//{
	//	case 10:
	//		//break;
	//	case 11:
	//		// 11일때 실행
	//		printf("포수");
	//		break;

	//	case 8:
	//	case 9:
	//	{
	//		// 11일때 실행
	//		printf("투수");
	//	}
	//	break;

	//	default:
	//	{
	//		// 위에 cast가 모두 아니면 실행
	//		printf("후보");
	//	}
	//	break;
	//}

	int light = 0;
	// scanf_s로 light 값을 입력
	// light 가 true(1) 이면 "파랑" 출력(printf)
	// light 가 false(0) 이면 "빨강" 출력(printf)
	//scanf_s("%d", &light);
	//if (light)
	//{
	//	printf("파랑");
	//}
	//else
	//{
	//	printf("빨강");
	//}


	int nInput = 0;
	// scanf_s로 nInput 값을 입력
	// nInput 값이 100보다 크면 "100보다 크다" 출력(printf)
	// nInput 값이 100보다 작으면 "100보다 작다" 출력(printf)
	//scanf_s("%d", &nInput);
	//if (nInput > 100)
	//{
	//	printf("100보다 크다");
	//}
	//else if (nInput < 100)
	//{
	//	printf("100보다 작다");
	//}

	int myScore = 0, otherScore = 0;
	// scanf_s로 myScore, otherScore 값을 입력
	// myScore가 otherScore 크면 "3점" 출력(printf);
	// myScore가 otherScore 같으면 "1점" 출력(printf);
	// myScore가 otherScore 작으면 "0점" 출력(printf);
	//scanf_s("%d %d", &myScore, &otherScore);
	//if (myScore > otherScore)
	//{
	//	printf("3점");
	//}
	//else if (myScore == otherScore)
	//{
	//	printf("1점");
	//}
	//else if (myScore < otherScore)
	//{
	//	printf("0점");
	//}


	int nCode = 0;
	// scanf_s로 nCode 값을 입력
	// nCode 가 1이나 3 이면 "남자" 출력(printf)
	// nCode 가 2이나 4 이면 "여자" 출력(printf)
	//scanf_s("%d", &nCode);
	//switch (nCode)
	//{
	//case 1:
	//case 3:
	//	printf("남자");
	//	break;

	//case 2:
	//case 4:
	//	printf("여자");
	//	break;

	//default:
	//	break;
	//}


	int nCode2 = 0;
	// scanf_s로 nCode2 값을 입력
	// nCode2 가 1이나 2 이면 "2000년 미만 출생" 출력(printf)
	// nCode2 가 3이나 4 이면 "2000년 이후 출생" 출력(printf)

	//scanf_s("%d", &nCode2);
	//switch (nCode2)
	//{
	//case 1:
	//case 2:
	//	printf("2000년 미만 출생");
	//	break;

	//case 3:
	//case 4:
	//	printf("2000년 이후 출생");
	//	break;

	//default:
	//	break;
	//}

	// 비트 연산자
	// C++ 11버전 부터 숫자 앞에 0b를 붙이면 2진법 표기 가능
	// 2진법 표기 : 앞에 0b를 붙인다 (0b01011101)
	// 8진법 표기 : 앞에 0을 붙인다 (0123)
	// 16진법 표기 : 앞에 0x를 붙인다 (0xFF) (A:10, B:11, C:12, D:13, E:14, F:15)
	int A = 0b01011101;
	int B = 0123;
	int C = 0xFF;
	printf("2진법(0b01011101) : %d\n", A);
	printf("8진법(0123) : %d\n", B);
	printf("16진법(0xFF) : %d\n", C);

	// 비트 연산 기호
	// 곱(&) : 둘 다 1이면 1, 아니면 0
	// 합(|) : 둘 중에 하나라도 1이면 1, 아니면 0
	// XOR(^) : 둘이 같으면 0, 아니면 1
	// 반전(~) : 0이면 1, 1이면 0
	char bitNum = 0b01001010;
	char bitResult = 0;
	bitResult = bitNum & 0b11010100;

	// 0b01001010
	//+0b11010100
	// 0b01000000
	std::cout << std::bitset<8>(bitResult) << std::endl;// std::endl은 개행(printf에 \n과 같다)

	// 0b01001010
	//+0b11010100
	// 0b11011110
	bitResult = bitNum | 0b11010100;
	std::cout << std::bitset<8>(bitResult) << std::endl;// std::endl은 개행(printf에 \n과 같다)

	// 0b01001010
	//+0b11010100
	// 0b01100001
	bitResult = bitNum ^ 0b11010100;
	std::cout << std::bitset<8>(bitResult) << std::endl;// std::endl은 개행(printf에 \n과 같다)

	bitResult = ~0b11010100;
	std::cout << std::bitset<8>(bitResult) << std::endl;// std::endl은 개행(printf에 \n과 같다)

	
	char MyReward = 0b00000000;

	// 비트 1로 설정
	MyReward = MyReward | LEVEL1_REWARD_10;// LEVEL1_REWARD_10;
	//0b01011000
	//0b00000001
	//0b01011001
	std::cout << "MyReward Enable = " << std::bitset<8>(MyReward) << std::endl;

	// 비트 활성화 되어있는지 채크
	bool isEnable = false;
	//0b01011001
	//0b00000001
	//0b00000001
	isEnable = MyReward & LEVEL1_REWARD_10;
	std::cout << "MyReward Check = " << isEnable << std::endl;

	// 비트 0으로 설정
	MyReward = MyReward & ~LEVEL1_REWARD_10;
	//0b10110011
	//0b11111101
	//0b10110001
	std::cout << "MyReward Disable = " << std::bitset<8>(MyReward) << std::endl;
}