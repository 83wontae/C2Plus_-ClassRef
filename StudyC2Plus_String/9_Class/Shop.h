#pragma once

class CShop
{
public:
	CShop(int value1 = 0, int value2 = 0);
	CShop(const wchar_t* _pName, int value1 = 0, int value2 = 0);
	~CShop();

private:
	int m_value2;
protected:
public:
	// �ɹ� ����
	int m_value1;
	wchar_t m_ShopName[20];

	// �ɹ� �Լ�
	void SetValue2(const int& value);

	virtual void printValue();

	const CShop& operator =(const CShop& Other)
	{
		m_value1 = Other.m_value1;
		m_value2 = Other.m_value2;

		return *this;
	}

	const CShop& operator +(const CShop& Other)
	{
		return CShop(m_value1 + Other.m_value1, m_value2 + Other.m_value2);
	}
};