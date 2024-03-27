#pragma once
#include "Shop.h"

class CPhoneShop : public CShop
{
public:
	CPhoneShop(const wchar_t* _pName, int value1 = 0, int value2 = 0);
	CPhoneShop(const wchar_t* _pName, int value1, int value2, int iPhoneValue, int GalaxyS23Value);
	~CPhoneShop();

	virtual void printValue() override;

	int m_iPhoneValue;
	int m_GalaxyS23Value;
};