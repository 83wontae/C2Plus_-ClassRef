#include <stdio.h>
#include <iostream>

class CBase { // 가상 함수가 하나라도 있면 "다형성 클래스" 라고 한다.
public:
	// 가상 함수
	// virtual 키워드를 함수 앞에 붙인다.
	// 자식 클래스에서 함수를 override를 해서 재구현 가능
	// RTTI (Run Time Type Information/Identification) 구조로 변경됨
	// RTTI 란?
	// 가상 함수가 되면은 추가적으로 "공간"이 할당이됨
	// 추가로 할당된 공간에는 클래스의 정보를 가리키게 됨
	// dynamic_cast시 클래스의 크기를 참조하는게 아니라 추가로 할당된 공간에는 클래스의 정보를 참조
	virtual void printX() {
		printf("CBase printX=%d\n", x);
	}

	int x = 10;
};

class CChild1 : public CBase {
public:
	void printY() {
		printf("CBase printY=%d\n", y);
	}

	int y = 20;
};

class CChild2 : public CBase {
public:
	void printZ() {
		printf("CBase printZ=%d\n", z);
	}

	int z = 30;
};

int main()
{
	// dynamic_cast : 동적 (런타임에 캐스팅)
	// RTTI (Run Time Type Information/Identification)
	printf("CBase Size=%I64d\n", sizeof(CBase));// CBase 클래스 크기 출력
	printf("CBase Size=%I64d\n", sizeof(CChild1));// CChild1 클래스 크기 출력

	int64_t* a = (int64_t*)new CBase;
	printf("a[0]=%I64d, a[1]=%d\n", a[0], (int)a[1]);// CBase 클래스 크기 출력

	int64_t* b = (int64_t*)new CChild1;
	printf("a[0]=%I64d, a[1]=%d, a[2]=%d\n", b[0], (int)b[1], (int)b[2]);// CBase 클래스 크기 출력

	delete a;
	delete b;

	CBase* pBase[] = { new CChild1(), new CChild2() };

	for (CBase* pB : pBase)
	{
		pB->printX();

		CChild1* pChild = dynamic_cast<CChild1*>(pB);// dynamic_cast 캐스팅 후 결과 값으로 포인트를 받는다.
		if (pChild != nullptr)// 정상적으로 메모리를 읽었다면 객체의 포인터 값이 들어가 있고 아니면, nullptr 값이 들어있다.
		{
			pChild->printY();
		}
	}

	for (CBase* pB : pBase)
	{
		delete pB;
	}
}