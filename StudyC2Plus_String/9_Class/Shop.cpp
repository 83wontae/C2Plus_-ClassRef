#include "Shop.h"
#include <iostream>

//::(the scope-resolution operator) ������ ������ ���

CShop::CShop(int value1, int value2) :m_ShopName(L""), m_value1(value1), m_value2(value2)
{
}

CShop::CShop(const wchar_t* _pName, int value1, int value2) :m_ShopName(L""), m_value1(value1), m_value2(value2)
{
	wcscpy_s(m_ShopName, _pName);
	wprintf(L"ShopName=%s �θ� ������ ȣ��!!!\n", m_ShopName);
}

CShop::~CShop()
{
	wprintf(L"ShopName=%s �θ� �ı��� ȣ��!!!\n", m_ShopName);
}

// �ɹ� �Լ�
void CShop::SetValue2(const int& value)
{
	this->m_value2 = value;
}

void CShop::printValue()
{
	wprintf(L"ShopName=%s Value1=%d, Value2=%d\n", m_ShopName, m_value1, m_value2);
}