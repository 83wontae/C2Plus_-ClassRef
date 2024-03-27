#include <iostream>
#include <bitset>
#include <stdio.h>//standard Input Output 표준 입출력 함수 라이브러리

void memFunc(int* a)
{
	*a = 100;
}

int g_X = 100;

void PrintValuePoint(const int* value)
{
	//value = nullptr;// 포인터 주소 값이 변경할수 있다.
	//value = 10;
	printf("value=%d\n", *value);
}

void PrintValueRef(const int& value)
{
	//value = 10;
	printf("value=%d\n", value);
}

int main()
{
	int i = 100;
	float f = 1.0f;

	// 포인터 자료형 변수(4byte)
	// C언어, C++을 사용하시는 많은 분들이 0, NULL 이렇게 널을 사용, C++11부터는 nullptr을 사용
	// https://learn.microsoft.com/ko-kr/cpp/extensions/nullptr-cpp-component-extensions?view=msvc-170
	int* pi = nullptr;// nullptr 키워드 : 포인터 주소값 초기화 처리
	pi = &i;// &:엔퍼센트를 붙이면 메모리 주소값
	int* pi2 = (int*)&f;// &:엔퍼센트

	*pi = 101;
	printf("i = %d\n", i);
	printf("pi = %d\n", *pi);

	printf("pi2 = %d\n", *pi2);

	// 포인터 size
	// 아키텍처에 따라 다르다
	// x32 환경에서는 4byte, x64 환경에서는 8byte
	// 1GB = 1024MB
	// 1MB = 1024KB
	// 1KB = 1024Byte
	// 1Byte = 8Bit
	// x32 환경에서는 42억개 주소값을 지정가능 4GB 이상의 메모리 주소를 커버하기는 부족(x86은 이를 문제를 보완)

	int* pInt = nullptr;	// 8byte
	char* pChar = nullptr;	// 8byte
	short* pShort = nullptr;// 8byte
	printf("pInt size = %I64d\n", sizeof(pInt));
	printf("pChar size = %I64d\n", sizeof(pChar));
	printf("pShort size = %I64d\n", sizeof(pShort));

	int arr[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	pInt = arr;
	printf("pInt = %d\n", *pInt);
	pInt += 1;// 다음 주소값을 가르킨다
	printf("pInt = %d\n", *pInt);

	short sArr[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	int* pA = (int*)sArr;

	int result = *((short*)(pA + 2));//int(4Byte) 2번 이동 = short(2Byte) 4번 이동
	printf("pInt = %d\n", result);

	char cArr[2] = { 1, 1 };//short(0000 0001 0000 0001) = 257
	short* pS = (short*)cArr;
	result = *pS;
	printf("pInt = %d\n", result);

	int nTemp = 0;
	memFunc(&nTemp);
	printf("nTemp = %d\n", nTemp);

	// const
	// 실수를 줄일수 있다. 디버깅 횟수가 줄어든다.
	// 변수를 상수화 한다.
	const int cint = 100;//const 상수화

	int value;
	int* pValue = &value;
	//const int* pValue = &value;// 포인터가 가르키는 내용을 수정 불가, 포인터 값 수정 가능, 참조는 가능
	//int const* pValue = &value;// 포인터가 가르키는 내용을 수정 불가, 포인터 값 수정 가능, 참조는 가능
	//int* const pValue = &value;// 포인터가 가르키는 내용을 수정 가능, 포인터 값 수정 불가, 참조는 가능
	//const int* const pValue = &value;// 포인터가 가르키는 내용을 수정 불가, 포인터 값 수정 불가, 참조는 가능
	//int const* const pValue = &value;// 포인터가 가르키는 내용을 수정 불가, 포인터 값 수정 불가, 참조는 가능

	*pValue = 2;
	pValue = (int*)&cint;
	*pValue = 50;
	printf("pValue=%d\n", *pValue);

	PrintValueRef(*pValue);

	return 0;
}