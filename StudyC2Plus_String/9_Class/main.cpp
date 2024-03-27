#include <iostream>
#include <stdio.h>
#include "Shop.h"
#include "PhoneShop.h"

struct stMyStruct
{

};

// Class(변수, 자료형)
// 사용자 정의 Type
// C의 Struct의 확장된 개념
// C++의 클래스는 세 가지 액세스 지정자(private, protected 또는 public)에 의해 
// 액세스가 제어되는 멤버로 데이터 및 함수가 있는 사용자 정의 유형 또는 데이터 구조입니다.
// 액세스 지정자를 사용하여 데이터 및 함수를 만드는 걸 캡슐화 라고도 한다.
// 한글로 번역하면 형틀이하는 뜻 즉, 사용가능한 객체가 아님
// 객체를 생성하기 위한 모양을 나타낸다.

// 객체(Object)
// Class를 사용해서 생성된걸 객체라고 한다.
// Class에 선언한 변수들이 생성되고 메모리에서 공간을 차지함

// 객체 지향 프로그래밍 
// 객체 지향 프로그래밍은 컴퓨터 프로그램을 명령어의 목록으로 보는 시각에서 벗어나 여러 개의 독립된 단위, 
// 즉 "객체"들의 모임으로 파악하고자 하는 것이다. 
// 각각의 객체는 메시지를 주고받고, 데이터를 처리할 수 있다.
class CMyClass
{
// 접근 지정자
// private: 외부에서 접근 불가(기본적으로 아무것도 선언이 안되있으면 private)
// protected : 상속관계일 때 접근이 가능, 이외에는 접근 불가
// public: 어디서든 접근이 가능
public:
	// 생성자
	// 클래스가 생성할때 호출됨
	// 선언 하지 않아도 기본 생성자가 존재
	// 생성자도 public이 아니면 호출 불가능(반드시 public으로 선언)
	CMyClass(int value1 = 0, int value2 = 0):m_value1(value1), m_value2(value2)
	{
		//m_value1 = 0;
		//m_value2 = 0;
	}

	// 파괴자
	// 클래스가 파괴될때 호출됨
	// 선언 하지 않아도 기본 파괴자가 존재
	// 파괴자도 public이 아니면 호출 불가능(반드시 public으로 선언)
	~CMyClass()
	{
	}

private:
	int m_value2;
protected:
public:
	// 맴버 변수
	int m_value1;

	// 맴버 함수
	void SetValue2(const int& value)
	{
		// this는 실행된 클래스 객체 본인을 의미함
		// this 키워드를 사용하여 호출하는게 기본 구조
		// 내부적으로 생략을 해도 상관 없음
		this->m_value2 = value;
	};

	void printValue()
	{
		printf("Value1=%d, Value2=%d\n", m_value1, m_value2);
	}

	// 연산자 오버로딩(Operator Overloading)
	// 대입 연산자 (기본적으로 생성됨)
	// const CMyClass& : 왼쪽으로 반환될 변수형
	// operator = : 오버로딩 할 연산자
	// (const CMyClass& Other) : 오른쪽에 입력될 변수형
	const CMyClass& operator =(const CMyClass& Other)
	{
		m_value1 = Other.m_value1;
		m_value2 = Other.m_value2;

		return *this;
	}

	const CMyClass& operator +(const CMyClass &Other)
	{
		return CMyClass(m_value1 + Other.m_value1, m_value2 + Other.m_value2);
	}
};

void printShop(CShop* shop)
{
	shop->printValue();
}

int main()
{
	_wsetlocale(LC_ALL, L"korean");//지역화 설정을 전역적으로 적용

	{
		int num = 100;
		// 레퍼런스 참조 기능
		// 포인터 참조는 4Byte의 포인터 변수의 주소 값을 참조
		int* pNum = &num;
		printf("&pNum != &num ? %d\n", (int(&pNum) != int(&num)));
		// 레퍼런스 참조는 원본 대상의 주소 값과 동일하다.
		int& refNum = num;
		printf("&refNum == &num ? %d\n", (int(&refNum) == int(&num)));
	}

	CMyClass myClass;
	myClass.m_value1 = 10;
	//myClass.value2 = 20;// private 변수는 접근 불가
	myClass.SetValue2(20);// 기본적으로 변수는 private으로 선언하고 함수를 사용하여 접근하게 하는게 올바른 구조

	CMyClass myClass1, myClass2;
	myClass1.SetValue2(200);// 여기 SetValue2가 호출 됬을때 this는 myClass1
	myClass2.SetValue2(300);// 여기 SetValue2가 호출 됬을때 this는 myClass2

	myClass1 = myClass2;

	CMyClass myClass3;
	myClass3 = myClass1 + myClass2;
	myClass3.printValue();

	//Shop.h, Shop.cpp 파일 분할 클래스 구현
	CShop shopA(L"원태숍", 100, 200);
	shopA.printValue();

	CPhoneShop phoneShop(L"원태폰숍", 300, 400, 500, 600);
	phoneShop.printValue();

	// 업케스팅(Upcasting)
	// 자식 클래스 포인터 -> 부모 클래스 포인터 (묵시적 형변환)
	// 자식 클래스를 가리킬 수는 있지만 자식 클래스의 고유한 멤버에 접근 불가
	printShop(&phoneShop);// CPhoneShop -> CShop 으로 형변환
}