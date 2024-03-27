#include <stdio.h>
#include <iostream>

class CBase {
public:
	int a = 1;
};

class CChild1 : public CBase {
public:
	void printB() {
		printf("CChild1::f()=%f\n", b);
	}

	float b = 3.14f;
};

class CChild2 : public CBase {
public:
	void printB() {
		printf("CChild2::f()=%d\n", c);
	}

	int c = 3;
};

int main()
{
	CBase* pBase = new CChild1;
	//b->printB();// b는 Base* 이기 때문에 printB에 접근이 불가능

	// 기본적인 케스팅 방법
	// 강제로 CBase* 포인터에 메모리를 CChild* 포인터 메모리 틀에 맞춰 읽어온다.
	CChild1* pChild1 = (CChild1*)pBase;
	pChild1->printB();
	// 아래와 같이 포인트를 잘못 가르키는 실수을 할 경우 문제가 생길 수 있다.
	// 강제로 int* 포인터에 메모리를 CChild*에 맞춘다. 
	// 서로 맞지 않아 문제가 생김 하지만 문제 없이 컴파일됨
	// 어디서 문제가 발생했는지 찾기 어려움
	int* a = new int(0);
	pChild1 = (CChild1*)a;

	// static_cast: 정적 (컴파일 단계에서 변환)
	// 강제로 int* 포인터에 메모리를 CChild*에 맞추려고 하면 컴파일 불가
	// 에러 "잘못된 형식 변환입니다."
	// child = static_cast<CChild*>(a);
	// CBase*는 정상적으로 읽기 변환 가능
	pChild1 = static_cast<CChild1*>(pBase);
	pChild1->printB();

	// static_cast는 부모의 형태만 확인, 컴파일 단계에서 실행되므로 어떤 형태가 들어올지 알수 없음
	// 자식이 다르면 확인하지 않기 때문에 에러X, 컴파일 문제X 정상적으로 빌드됨
	// 어디서 문제가 발생했는지 찾기 어려움
	// 반드시 캐스팅하는 대상의 형태를 확인해야함
	CBase* pBase2 = new CChild1;
	CChild2 *pChild2 = static_cast<CChild2*>(pBase2);
	pChild2->printB();// CChild1의 3.14f값을 CChild2의 int형으로 메모리를 읽어서 출력

	// float을 int형으로 강제로 메모리를 읽어서 출력해서 3.14f의 int 형태의 값 확인
	float pF = 3.14f;
	int* pI = (int*)&pF;
	printf("b=%d", *pI);

	delete pBase;
	delete pBase2;
}