#include <stdio.h>
#include <iostream>

class CName
{
public:
	CName();
	CName(const wchar_t* str);

	// ���� ������ �� ���� �Ҵ� ������(C++)
	// https://learn.microsoft.com/ko-kr/cpp/cpp/copy-constructors-and-copy-assignment-operators-cpp?view=msvc-170
	// (const CName& Other) : �Ķ��Ÿ�� �ڽ� Ŭ���� Ÿ���� ���۷����� ������ ���� ������
	CName(const CName& Other);

	~CName();

	wchar_t* GetName()
	{
		return strName;
	}

	// ���� �Ҵ� ������
	CName& operator=(const CName& Other)
	{
		// ���� �Ҵ� �����ڿ��� ���� ���� ó��
		if (strName != nullptr)
		{
			delete[] strName;
		}

		strName = nullptr;
		len = wcslen(Other.strName) + 1;
		strName = new wchar_t[len];
		wcscpy_s(strName, len, Other.strName);

		return *this;
	}

private:
	wchar_t* strName;
	size_t len;
};

CName::CName():strName(nullptr), len(0)
{
}

CName::CName(const wchar_t* str)
{
	strName = nullptr;
	len = wcslen(str) + 1;
	strName = new wchar_t[len];
	wcscpy_s(strName, len, str);
}

CName::CName(const CName& Other)
{
	// ���� ������
	// ���� �����ڿ��� ���� ���� ó��
	strName = nullptr;
	len = wcslen(Other.strName) + 1;
	strName = new wchar_t[len];
	wcscpy_s(strName, len, Other.strName);
}

CName::~CName()
{
	delete[] strName;
}

int main()
{
	_wsetlocale(LC_ALL, L"korean");//����ȭ ������ ���������� ����

	CName name1(L"����\n");
	wprintf(L"%s", name1.GetName());
	CName name2 = name1;// ���� ����� �Ǿ��ִٸ� ����
	wprintf(L"%s", name2.GetName());
	CName name3;
	name3 = name1;
	wprintf(L"%s", name3.GetName());
}