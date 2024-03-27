#include <stdio.h>

// 상속
// 기존 클래스에 기능 추가하거나 재정의하여 새로운 클래스를 정의하는 기능
// 생물 - 기본 최상위 클래스 라고 정의
// 동물 : 생물 + 움직인다 기능을 추가
// -동물은 생물의 기능을 상속 받음
// 포유류 : 동물 + 젖먹이를 한다 기능을 추가
// -포유류는 동물 기능을 상속 받음
// 사람 : 포유류 + 지적 능력 기능을 추가
// -사람은 포유류의 기능을 상속 받음

class CBase
{
public:
	CBase(int x = 1, int y = 2) :m_X(x), m_Y(y) {
		printf("부모 클래스(CBase) 생성\n");
	}

	~CBase(){
		printf("부모 클래스(CBase) 파괴\n");
	}

	// 가상 함수( virtual function )
	// 자식 클래스에서 재정의 할 것으로 기대하는는 맴버 함수
	// 함수 앞에 virtual 키워드를 붙있다. 
	/*
	virtual void printValue()
	{
		printf("m_X=%d\n", m_X);
	}
	*/

public:
	int m_X;
	int m_Y;
};

// 상속 방법 : ": public CBase"와 같이 클래스 뒤에 상속할 부모 클래스를 선언
class CChild : public CBase
{
public:
	// ":"에 뒤에 부모클래스(CBase(x))를 넣어서 부모클래스이 생성자 호출
	// 부모 클래스에 생성자가 먼저 호출 후 자식 생성자가 호출됨
	CChild(int x = 1, int y = 2, int z = 3):m_Z(z), CBase(x, y){
		printf("자식 클래스(CChild) 생성\n");
	}

	// 자식 파괴자 먼저 호출 후 부모 파괴자 호출됨
	~CChild(){
		printf("자식 클래스(CBase) 파괴\n");
	}
	/*
	virtual void printValue() override
	{
		printf("m_X=%d, m_Z=%d\n", m_X, m_Z);

		CBase::printValue();// 부모에서의 처리 호출 - 부모의 클래스에서 스코프 연산으로 함수 호출
	}
	*/

public:
	int m_Z;
};

// Upcasting(업케스팅)
// 자식 -> 부모로 별다른 연산자 없이 자동으로 케스팅(읽어지는) 되는 방법
void printObject(CBase** pBase, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("xpos=%d, ypos=%d\n", pBase[i]->m_X, pBase[i]->m_Y);
	}
}

int main()
{
	/*
	CBase base(10);
	base.m_X = 100;
	base.printValue();

	CChild child(10, 20);
	child.m_X = 200;// 상속 받은 부모에 기능을 그대로 사용 가능
	child.printValue();
	*/

	/*
	CChild* pArrChild = new CChild[10];
	printObject(pArrChild, 10);
	delete[] pArrChild;
	*/

	CBase** pArrBase = new CBase * [10];
	for (int i = 0; i < 10; i++)
	{
		pArrBase[i] = new CChild;
	}
	printObject(pArrBase, 10);
	for (int i = 0; i < 10; i++)
	{
		delete pArrBase[i];
	}
	delete[]pArrBase;
}