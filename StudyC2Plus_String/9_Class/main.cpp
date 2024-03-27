#include <iostream>
#include <stdio.h>
#include "Shop.h"
#include "PhoneShop.h"

struct stMyStruct
{

};

// Class(����, �ڷ���)
// ����� ���� Type
// C�� Struct�� Ȯ��� ����
// C++�� Ŭ������ �� ���� �׼��� ������(private, protected �Ǵ� public)�� ���� 
// �׼����� ����Ǵ� ����� ������ �� �Լ��� �ִ� ����� ���� ���� �Ǵ� ������ �����Դϴ�.
// �׼��� �����ڸ� ����Ͽ� ������ �� �Լ��� ����� �� ĸ��ȭ ��� �Ѵ�.
// �ѱ۷� �����ϸ� ��Ʋ���ϴ� �� ��, ��밡���� ��ü�� �ƴ�
// ��ü�� �����ϱ� ���� ����� ��Ÿ����.

// ��ü(Object)
// Class�� ����ؼ� �����Ȱ� ��ü��� �Ѵ�.
// Class�� ������ �������� �����ǰ� �޸𸮿��� ������ ������

// ��ü ���� ���α׷��� 
// ��ü ���� ���α׷����� ��ǻ�� ���α׷��� ��ɾ��� ������� ���� �ð����� ��� ���� ���� ������ ����, 
// �� "��ü"���� �������� �ľ��ϰ��� �ϴ� ���̴�. 
// ������ ��ü�� �޽����� �ְ�ް�, �����͸� ó���� �� �ִ�.
class CMyClass
{
// ���� ������
// private: �ܺο��� ���� �Ұ�(�⺻������ �ƹ��͵� ������ �ȵ������� private)
// protected : ��Ӱ����� �� ������ ����, �̿ܿ��� ���� �Ұ�
// public: ��𼭵� ������ ����
public:
	// ������
	// Ŭ������ �����Ҷ� ȣ���
	// ���� ���� �ʾƵ� �⺻ �����ڰ� ����
	// �����ڵ� public�� �ƴϸ� ȣ�� �Ұ���(�ݵ�� public���� ����)
	CMyClass(int value1 = 0, int value2 = 0):m_value1(value1), m_value2(value2)
	{
		//m_value1 = 0;
		//m_value2 = 0;
	}

	// �ı���
	// Ŭ������ �ı��ɶ� ȣ���
	// ���� ���� �ʾƵ� �⺻ �ı��ڰ� ����
	// �ı��ڵ� public�� �ƴϸ� ȣ�� �Ұ���(�ݵ�� public���� ����)
	~CMyClass()
	{
	}

private:
	int m_value2;
protected:
public:
	// �ɹ� ����
	int m_value1;

	// �ɹ� �Լ�
	void SetValue2(const int& value)
	{
		// this�� ����� Ŭ���� ��ü ������ �ǹ���
		// this Ű���带 ����Ͽ� ȣ���ϴ°� �⺻ ����
		// ���������� ������ �ص� ��� ����
		this->m_value2 = value;
	};

	void printValue()
	{
		printf("Value1=%d, Value2=%d\n", m_value1, m_value2);
	}

	// ������ �����ε�(Operator Overloading)
	// ���� ������ (�⺻������ ������)
	// const CMyClass& : �������� ��ȯ�� ������
	// operator = : �����ε� �� ������
	// (const CMyClass& Other) : �����ʿ� �Էµ� ������
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
	_wsetlocale(LC_ALL, L"korean");//����ȭ ������ ���������� ����

	{
		int num = 100;
		// ���۷��� ���� ���
		// ������ ������ 4Byte�� ������ ������ �ּ� ���� ����
		int* pNum = &num;
		printf("&pNum != &num ? %d\n", (int(&pNum) != int(&num)));
		// ���۷��� ������ ���� ����� �ּ� ���� �����ϴ�.
		int& refNum = num;
		printf("&refNum == &num ? %d\n", (int(&refNum) == int(&num)));
	}

	CMyClass myClass;
	myClass.m_value1 = 10;
	//myClass.value2 = 20;// private ������ ���� �Ұ�
	myClass.SetValue2(20);// �⺻������ ������ private���� �����ϰ� �Լ��� ����Ͽ� �����ϰ� �ϴ°� �ùٸ� ����

	CMyClass myClass1, myClass2;
	myClass1.SetValue2(200);// ���� SetValue2�� ȣ�� ������ this�� myClass1
	myClass2.SetValue2(300);// ���� SetValue2�� ȣ�� ������ this�� myClass2

	myClass1 = myClass2;

	CMyClass myClass3;
	myClass3 = myClass1 + myClass2;
	myClass3.printValue();

	//Shop.h, Shop.cpp ���� ���� Ŭ���� ����
	CShop shopA(L"���¼�", 100, 200);
	shopA.printValue();

	CPhoneShop phoneShop(L"��������", 300, 400, 500, 600);
	phoneShop.printValue();

	// ���ɽ���(Upcasting)
	// �ڽ� Ŭ���� ������ -> �θ� Ŭ���� ������ (������ ����ȯ)
	// �ڽ� Ŭ������ ����ų ���� ������ �ڽ� Ŭ������ ������ ����� ���� �Ұ�
	printShop(&phoneShop);// CPhoneShop -> CShop ���� ����ȯ
}