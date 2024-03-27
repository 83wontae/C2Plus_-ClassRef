#include <iostream>
#include <stdio.h>
#include <assert.h>

unsigned int GetWCharLength(const wchar_t* _pString)
{
    int i = 0;

    while (1)
    {
        wchar_t c = *(_pString + i);

        //if (0 == c)
        if ('\0' == c)// 비교 연산자를 사용할때 문자를 앞쪽으로 해서 비교하면 "=" 대입연산자 실수시 빠르게 문제를 파악할수 있다.
        {
            break;
        }

        ++i;
    }

    return i;
}

void StringCat(wchar_t* _pDest, rsize_t size, const wchar_t* _pSource)
{
    int destLen = GetWCharLength(_pDest);
    int sourceLen = GetWCharLength(_pDest);
    if (size < destLen + sourceLen + 1)//Null 공간 1추가
    {
        assert(nullptr);
    }

    for (int i = 0; i < sourceLen + 1; ++i)
    {
        _pDest[destLen + i] = _pSource[i];
    }
}

int StringCmp(const wchar_t* _pLeft, const wchar_t* _pRight)
{
    int leftLen = GetWCharLength(_pLeft);
    int rightLen = GetWCharLength(_pRight);

    int nloop = (leftLen < rightLen) ? leftLen : rightLen;

    for (int i = 0; i < nloop; i++)
    {
        if (_pLeft[i] == _pRight[i])
            continue;

        if (_pLeft[i] < _pRight[i])
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }

    int nLenResult = 0;
    if (leftLen != rightLen)
    {
        nLenResult = (leftLen < rightLen) ? -1 : 1;
    }

    return nLenResult;
}

int main()
{
    _setlocale(LC_ALL, L"korean");//지역화 설정을 전역적으로 적용
    _wsetlocale(LC_ALL, L"korean");//지역화 설정을 전역적으로 적용

    // 아스키 코드표 : https://namu.wiki/w/%EC%95%84%EC%8A%A4%ED%82%A4%20%EC%BD%94%EB%93%9C
    // multi-byte : https://namu.wiki/w/MBCS
    // 국가간의 호환이 되지 않는 방식이기에 다른 시스템으로 보내면 글자가 알아볼 수 없게 깨진다. 
    // 일본어 텍스트 파일을 한글 윈도우에서 열었을 때 소위 말하는 뷁어로 깨지는 것이 대표적인 예시. 
    // 철저히 자국어 표기만을 위한 인코딩이다 보니 외국어 교재 같이 다른 문자체계가 필요한 경우 불편함이 크다.
    char c1 = 65;        //1Byte(0~127)

    // 와이드 문자(Wide character)
    // multi-byte에 문제를 해결하기 위해 나온 것이 유니코드.
    // 세계의 거의 모든 문자를 표현할 수 있기 때문에 최근 2010년대에 들어서 많이 사용되고 있다.
    // 그 중에서도 특히 UTF-8[2]이 널리 쓰인다.
    wchar_t wc1 = 65;    //2Byte( 65536 / 2 = 32000개 )

    printf("c1 = %c\n", c1);
    wprintf(L"wc1 = %c\n", wc1);
    wc1 = ' ';
    wprintf(L"wc1 = %d\n", wc1);

    c1 = 1; 
    printf("c1(1) = %c\n", c1);

    c1 = '1'; 
    printf("c1('1')= %c\n", c1);

    char c2 = 'A'; 
    wchar_t wc2 = L'A';

    char szChar[10] = "abcdefg";
    //wchar_t szwc[7] = L"abcdefg";// Error : 마지막 null 문자열이 필요하기 때문에 1공간이 더 필요하다.
    wchar_t szWChar[10] = L"abcdefg";

    // 한[199 = 11000111, 209 = 11010001] : 앞에 3bit가 110이면 2byte를 사용한다.
    unsigned char szCharWitchHan[10] = "abc한글";//영어는 1Byte, 한글인 경우 2Byte를 사용함. 가변적으로 다루기 쉽지 않다.

    wchar_t szWCharWithHan[10] = L"abc한글";

    // _T 매크로
    // 프로젝트 속성 - 구성 속성 -  고급 - 문자 집합
    // https://learn.microsoft.com/ko-kr/cpp/text/unicode-programming-summary?view=msvc-170

    {
        wchar_t szWChar[20] = L"HelloC++";

        //int len = wcslen(szWChar);// 문자열의 길이 구하기
        int len = GetWCharLength(szWChar);// 문자열의 길이 구하기
        printf("szWChar Len = %d\n", len);


        // 문자열 Secure 함수(_s)
        // 이전 버전에서는 버퍼사이즈를 초과하는 문자열 복사가 시도될 경우, 버퍼사이즈만큼만 복사되고 나머지는 Truncate(잘라냄)됨
        // _s 버전에서는 "다음과 같은 경우"에는 한글자도 복사되지 않으며, 대신 Exception이 발생한다.
        
        //wcscat_s(szWChar, 20, L"aaa");// 문자열 붙이기
        StringCat(szWChar, 20, L"aaa");
        printf("szWChar = %S\n", szWChar);


        // 문자열 비교
        // 앞에 문자가 문자 우선순위가 높으면 : -1
        // 뒤에 문자가 문자 우선순위가 높으면 : 1
        // 두 문자가 같으면  : 0
        int nResult = wcscmp(L"bbcdef", L"cbcdefaaa");
        nResult = StringCmp(L"bbcdef", L"cbcdefaaa");
        printf("wcscmp result = %d\n", nResult);
    }
}
