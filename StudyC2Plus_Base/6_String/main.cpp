#include <stdio.h>
#include <iostream>
#include <assert.h>

//_pString="abcdefg";
unsigned int GetStringLength(const wchar_t* _pString)
{
	int i = 0;

	while (1)
	{
		wchar_t c = *(_pString + i);//순차적인 주소값에 문자를 저장

		//if (c == 0)
		if (c == '\0')
		{
			break;
		}

		++i;
	}

	return i;
}

// _Dest : "abcde"
// _pSource : "fghij\0"
void StringCat(wchar_t* _Dest, unsigned int size, const wchar_t* _pSource)
{
	int destLen = GetStringLength(_Dest);
	int sourceLen = GetStringLength(_pSource);
	if (size < destLen + sourceLen + 1)// \0 공간 1개가 더 필요
	{
		assert(nullptr);
	}

	for (int i = 0; i < sourceLen + 1; i++)
	{
		*(_Dest + destLen + i) = *(_pSource + i);
		//_Dest[destLen + i] = _pSource[i];
	}
}

int StringCmp(const wchar_t* _pLeft, const wchar_t* _pRight)
{
	int LeftLen = GetStringLength(_pLeft);
	int RightLen = GetStringLength(_pRight);

	// 가장 긴 문자의 길이 만큼만 비교한다.
	// 문장에 마지막 \0와 비교하기 때문에
	int nLoop = (LeftLen > RightLen) ? LeftLen : RightLen;

	for (int i = 0; i < nLoop; i++)
	{
		if (_pLeft[i] == _pRight[i])// 문자 같으면 크기비교 결과를 실행하지 않고 다시 for문을 실행
			continue;

		return (_pLeft[i] > _pRight[i]) ? 1 : -1;// 크기비교 결과를 반환
	}

	//if(LeftLen != RightLen)
	//{
	//	// left가 길면 1, right 길면 -1
	//	return (LeftLen > RightLen) ? 1 : -1;// 크기비교 결과를 반환
	//}

	return 0;//모든 문자가 같고 길이도 같다
}

int main()
{
	// 문자 처리
	// 아스키 코드 링크 : https://namu.wiki/w/%EC%95%84%EC%8A%A4%ED%82%A4%20%EC%BD%94%EB%93%9C
	// multi-byte
	// 127개 아스키 코드 문자 표기, 문자에 따라 가변형으로 크기가 변경됨
	// 국가간의 호환이 되지 않는 방식으로 다른 시스템으로 보내면 글자를 알아볼 수 없게 깨짐
	// 일본어 텍스트 파일을 한글 윈도우에서 열었을 때 뷁어로 깨지는 현상이 예시
	// 철저히 자국어 표기만을 위한 인코딩. 외국어 교재 같이 다른 문자체계가 필요한 경우 불편함
	char c1 = 'a';//1Byte(0~255), 한글자 일때는 ' '사용
	printf("c1=%c\n", c1);// 한글자 char 출력시 %c 사용

	setlocale(LC_ALL, "korean");// multi-byte 언어 설정

	char arrC1[10] = "abc한글";//영어는 1Byte, 한글은 2Byte 사용, 문자열 일때는 " "사용
	printf("arrC1=%s\n", arrC1);// 문자열 char 출력시 %s 사용

	// 와이드 문자(wide character)
	// multi-byte에 문제를 해결하기 위해 나온 유니코드 방식
	// 세계의 거의 모든 문자를 표현할 수 있기 때문에 최근에 많이 사용됨
	// 가장 자주 사용하는 방식은 UTF-8이 있다
	// 2Byte(0~65535)에서 앞에 검증용 1bit를 제외하면 32767개 표현가능
	// wchar_t형에 문자를 넣을때 앞에 L을 붙인다.

	wchar_t wc1 = L'a';
	wprintf(L"wc1=%c\n", wc1);// wchar_t형을 출력할때는 wprintf를 사용, 출력 문자열 앞에 L을 붙인다.

	_wsetlocale(LC_ALL, L"korean");// 와이드 문자 언어 설정

	wchar_t arrWC1[10] = L"abc한글";// wchar_t배열에 문자열을 넣을때 앞에 L을 붙인다.
	wprintf(L"arrWC1=%s\n", arrWC1);// wchar_t형을 출력할때는 wprintf를 사용, 출력 문자열 앞에 L을 붙인다.

	wchar_t szWChar[10] = L"abcdefghi";//마지막에 문자에 마지막이라는 표기로 '\0'문자가 들어간다.
	wprintf(L"szWChar=%s\n", szWChar);

	wchar_t szWCharLen[20] = L"abcdefg";
	int size = wcslen(szWCharLen);// 문자열 길이 구하기(iostream 라이브러리 함수)
	size = GetStringLength(szWCharLen);// 문자열 길이 구하기
	printf("szWCharLen size=%d\n", size);

	//wcscat_s(szWCharLen, 20, L"hij");// 문자열 붙이기(iostream 라이브러리 함수)
	StringCat(szWCharLen, 20, L"hij");// 문자열 붙이기(iostream 라이브러리 함수)
	wprintf(L"szWCharLen=%s\n", szWCharLen);

	wcscpy_s(szWCharLen, L"abcdef");// 앞쪽 문자열에 뒤에 문자열 복사해서 넣는다.

	int nResult = wcscmp(L"abcdef", L"abidef");//같으면 0, 앞에 문자순번이 빠르면 1, 뒤에 문자순번이 빠르면 -1
	nResult = StringCmp(L"abcdef", L"abidef");//같으면 0, 앞에 문자순번이 빠르면 1, 뒤에 문자순번이 빠르면 -1
	printf("nResult=%d\n", nResult);
}