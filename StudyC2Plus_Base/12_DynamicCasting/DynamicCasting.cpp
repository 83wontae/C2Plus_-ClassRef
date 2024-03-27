#include <stdio.h>
#include <iostream>

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


// x64일 경우 클래스 크기를 8/16/24/32 순으로 8Byte 간격으로 할당
// RTTI공간 할당 8Byte + 4Byte = 12Byte
// 12Byte 담을수 있는 최소한의 공간은 16Byte
class CBase{
public:
	// 가상 함수
	// virtual 키워드를 함수 앞에 붙인다.
	// 자식 클래스에서 함수를 override를 해서 재구현 가능
	// 가상 함수가 되면 RTTI정보를 가리키는 포인터 변수 공간 8Byte(x64 기준) 할당
	// RTTI 포인터는 해당 클래스에 정보를 가리키게 됨
	// 런타임중 동적으로 할당
	// dynamic_cast시 클래스의 크기를 참조하는게 아니라 추가로 할당된 RTTI 포인터에 클래스의 정보를 참조
	virtual void printX()	{
		printf("X=%d", m_X);
	}
	int m_X = 10;
};

// RTTI공간 할당 8Byte + 8Byte = 16Byte
// 16Byte 담을수 있는 최소한의 공간은 24Byte
class CChild1 : public CBase
{
public:
	void printY()
	{
		printf("Y=%d", m_Y);
	}
	int m_Y = 20;
};

class CChild2 : public CBase
{
public:
	void printZ()
	{
		printf("Z=%d", m_Z);
	}
	int m_Z = 20;
};

int main()
{
	// RTTI(Run Time Type Information/Identification)

	int64_t i64 = sizeof(CBase);
	printf("CBase Size=%I64d\n", i64);// sizeof : 객체에 크기 반환 기능
	printf("CChild1 Size=%I64d\n", sizeof(CChild1));// sizeof : 객체에 크기 반환 기능

	int64_t* pB = (int64_t*)new CBase;
	int64_t* pC = (int64_t*)new CChild1;
	printf("pB[0]=%I64d, pB[1]=%d\n", pB[0], (int)pB[1]);
	printf("pC[0]=%I64d, pC[1]=%d, pC[2]=%d\n", pC[0], (int)pC[1], (int)pC[2]);

	delete pB;
	delete pC;

	CBase* pBase[] = { new CChild1, new CChild2 };

	for (CBase* pTemp : pBase)
	{
		pTemp->printX();

		// dynamic_cast
		// <CChild1*> : 캐스팅(형변환)할 클래스 타입
		// (pTemp) : 캐스팅(형변환)할 객체
		// CChild1* pChild : 형변환 결과 반환값(캐스팅 성공시 캐스팅된 객체 반환, 캐스팅 실패시 nullptr 반환)
		CChild1* pChild = dynamic_cast<CChild1*>(pTemp);
		if (pChild == nullptr)
			continue;

		pChild->printY();
	}

	for (CBase* pTemp : pBase) {
		delete pTemp;
	}
}