#include "Shop.h"
#include <iostream>

//::(the scope-resolution operator) 스코프 연산자 사용

CShop::CShop(int value1, int value2) :m_ShopName(L""), m_value1(value1), m_value2(value2)
{
}

CShop::CShop(const wchar_t* _pName, int value1, int value2) :m_ShopName(L""), m_value1(value1), m_value2(value2)
{
	wcscpy_s(m_ShopName, _pName);
	wprintf(L"ShopName=%s 부모 생성자 호출!!!\n", m_ShopName);
}

CShop::~CShop()
{
	wprintf(L"ShopName=%s 부모 파괴자 호출!!!\n", m_ShopName);
}

// 맴버 함수
void CShop::SetValue2(const int& value)
{
	this->m_value2 = value;
}

void CShop::printValue()
{
	wprintf(L"ShopName=%s Value1=%d, Value2=%d\n", m_ShopName, m_value1, m_value2);
}