#include <stdio.h>
#include <iostream>

class CName
{
public:
	CName();
	CName(const wchar_t* str);

	// 복사 생성자 및 복사 할당 연산자(C++)
	// https://learn.microsoft.com/ko-kr/cpp/cpp/copy-constructors-and-copy-assignment-operators-cpp?view=msvc-170
	// (const CName& Other) : 파라메타로 자신 클래스 타입을 레퍼런스로 받으면 복사 생성자
	CName(const CName& Other);

	~CName();

	wchar_t* GetName()
	{
		return strName;
	}

	// 복사 할당 연산자
	CName& operator=(const CName& Other)
	{
		// 복사 할당 연산자에서 깊은 복사 처리
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
	// 복사 생성자
	// 복사 생성자에서 깊은 복사 처리
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
	_wsetlocale(LC_ALL, L"korean");//지역화 설정을 전역적으로 적용

	CName name1(L"원태\n");
	wprintf(L"%s", name1.GetName());
	CName name2 = name1;// 얕은 복사로 되어있다면 에러
	wprintf(L"%s", name2.GetName());
	CName name3;
	name3 = name1;
	wprintf(L"%s", name3.GetName());
}