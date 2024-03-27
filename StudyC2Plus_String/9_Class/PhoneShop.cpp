#include "PhoneShop.h"
#include <stdio.h>

CPhoneShop::CPhoneShop(const wchar_t* _pName, int value1, int value2):CShop(_pName, value1, value2)
{
	m_iPhoneValue = 0;
	m_GalaxyS23Value = 0;
}

CPhoneShop::CPhoneShop(const wchar_t* _pName, int value1, int value2, int iPhoneValue, int GalaxyS23Value)
	: CShop(_pName, value1, value2)
	, m_iPhoneValue(iPhoneValue)
	, m_GalaxyS23Value(GalaxyS23Value)
{
	wprintf(L"ShopName=%s 자식 생성자2 호출!!!\n", m_ShopName);
}

CPhoneShop::~CPhoneShop()
{
	wprintf(L"ShopName=%s 자식 파괴자 호출!!!\n", m_ShopName);
}

void CPhoneShop::printValue()
{
	CShop::printValue();

	wprintf(L"m_iPhoneValue=%d, m_GalaxyS23Value=%d\n", m_iPhoneValue, m_GalaxyS23Value);
}
