#include <stdio.h>
#include <iostream>

class CName
{
public:
	CName(const wchar_t* name):szName(nullptr), len(0)
	{
		len = wcslen(name) + 1;
		szName = new wchar_t[len];
		wcscpy_s(szName, len, name);
	}

	// 복사 생성자 및 복사 할당 연산자(C++)
	// 파라메타로 (const CName& Other) 와 같이 자산의 클래스 타입을 레퍼러스로 받으면 복사 생성자
	CName(const CName& Other):szName(nullptr), len(0)
	{
		if (szName != nullptr)
		{
			delete[] szName;
		}

		// Other.szName을 복사해서 szName에 넣는다.(깊은 복사)
		len = wcslen(Other.szName) + 1;
		szName = new wchar_t[len];
		wcscpy_s(szName, len, Other.szName);
	}

	~CName()
	{
		delete[] szName;
	}

	wchar_t* GetName() {
		return szName;
	}

	const CName& operator=(const CName& Other)
	{
		//szName = Other.szName;//Other.szName이 가리키고 있는 곳을 szName도 가리키게 하겠다.(얕은 복사)
		//len = Other.len;

		if (szName != nullptr)
		{
			delete[] szName;
		}

		// Other.szName을 복사해서 szName에 넣는다.(깊은 복사)
		len = wcslen(Other.szName) + 1;
		szName = new wchar_t[len];
		wcscpy_s(szName, len, Other.szName);
		return *this;
	}

	wchar_t* szName;
	size_t len;
};

int main()
{
	_wsetlocale(LC_ALL, L"korean");

	CName name1(L"원태");
	CName name2(L"김철수");

	name1 = name2;// 대입 연산자 처리

	CName name3 = name1;

	wprintf(L"name1=%s", name1.GetName());
}