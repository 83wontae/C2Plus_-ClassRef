#include <stdio.h>
#include <iostream>


int main()
{
	_wsetlocale(LC_ALL, L"Korean");

	// 2에 배수 출력하기(0~100)
	// 0 2 4 6 8 ~ 96 98 100
	//for (int i = 0; i <= 50; i += 2)
	//{
	//	printf("%d ", i);
	//}

	// n은 숫자 하나를 입력 받기
	// n에 배수 출력하기(0~100)
	//int n = 2;
	//printf("\n숫자하나를 입력해 주세요! : ");
	//scanf_s("%d", &n);
	//for (int i = 0; i <= 50; i += n)
	//{
	//	printf("%d ", i);
	//}

	// (0~100) 2에 배수에 갯수 출력
	//int cnt = 0;
	//for (int i = 0; i <= 50; i += 2)
	//{
	//	if (i == 0)
	//	{
	//		continue;
	//	}
	//	// cnt = cnt + 1;
	//	// cnt += 1;
	//	cnt++;
	//}
	//printf("cnt=%d ", cnt);


	// abcdef를 역으로 출력하기 fedcba
	wchar_t szwchar[20] = L"abcdef";
	int size = wcslen(szwchar);// 문자열 길이 구하기(iostream 라이브러리 함수)
	printf("size=%d\n", size);
	for (int i = 1; i <= size; ++i)
	{
		printf("%c", szwchar[size - i]);
	}
	
	for (int i = size; i >= 0; --i)
	{
		printf("%c", szwchar[i - 1]);
	}


	// wchar_t 형으로 문자 입력 받기
	// "szWCharInput"이름을 가진
	// "wchar_t" 변수형을 
	// [20]의 크기로 생성하고 
	// L"" 값을 초기값으로 넣는다.
	wchar_t szWCharInput[20] = L"";
	// wscanf_s는 입력을 받는 기능을 사용하겠다.
	// L"%ls" 변수형태로 입력을 받겠다.
	// "szWCharInput"변수에 입력한 값을 넣어주겠다.
	// "(unsigned)_countof(szWCharInput)"는 값을 넣을 변수에 크기
	wscanf_s(L"%ls", szWCharInput, (unsigned)_countof(szWCharInput));
	// wprintf는 출력을 하는 기능 사용하겠다.
	// L"szWCharInput=%s"문자 형태로 출력하겠다.
	// %s위치에 szWCharInput 값을 출력하겠다.
	wprintf(L"szWCharInput=%s\n", szWCharInput);

	// 입력 받은 문자열에서 'a'문자 갯수 출력
	int size = wcslen(szWCharInput);
	int cnt = 0;
	for (int i = 0; i < size; ++i)
	{
		if (szWCharInput[i] == 'a')
		{
			cnt++;
		}
	}
	printf("cnt=%d\n", cnt);
}