#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "overload.h"
#include <algorithm>
#include <iostream>

// C++ 의 컴파일 과정
// C++ 에서 우리가 작성한 소스코드를 실제로 실행할 수 있는 실행 파일로 변환하기 위해서는 총 4 가지 단계를 거쳐야만 합니다.

// 1. 전처리(Preprocessing) 단계 : #include 와 #define 와 같은 전처리기 매크로들을 처리하는 전처리(Preprocessing) 단계
// 2. 컴파일(Compile) 단계 : 각각의 소스 파일들을 어셈블리 명령어로 변환
// 3. 어셈블(Assemble) 단계 : 어셈블리 코드들을 실제 기계어로 이루어진 목적 코드(Object file)로 변환
// 4. 링킹(Linking) 단계 : 각각의 목적 코드들을 한데 모아서 하나의 실행 파일을 생성

// 메모리 영역
// 1. Code 영역 : 실행할 코드가 저장되어있는 영역(기계어로 존재)
// 2. Data 영역 : 전역변수, Static 변수들이 저장, 프로세스가 종료될때 까지 메모리에 저장됨
// 3. Stack 영역 : 지역변수, 매개변수들이 저장, 함수가 호출되면 생성되고 함수가 종료 되면 시스템에 반환
// 4. Heap 영역 : malloc 또는 new 함수 등에 의해서 동적으로 할당되는 영역, malloc() 또는 new 연산자를 통해 할당, free() 또는 delete 연산자를 통해 해제

struct MyStruct
{
	int num;
	float value;
};

int a = 0;//<- 전역 변수(Data 영역)

//void funTest();
#include "MyFunction.h"
//#include "MyFunction2.h"

int g_num = 0;

extern int g_extern_num;// 전역 변수가 어디엔가 선언되어있을 거라고 미리 알려준다

static int s_num = 0;

int func_static()
{
	static int num = 0;
	++g_num;
	++num;

	return num;
}

int inc_g_static_num()
{
	++g_static_num;

	return g_static_num;
}

int g_extern_num = 0;

int main()
{
	//배열
	//int arrInt[10] = {0};
	int arrInt[10] = {0,1,2,3,4,5,6,7,8,9};
	arrInt[0] = 0;
	arrInt[1] = 10;

	for (int itr : arrInt)
	{
		funTest();
	}

	int a = 0;;//<- 지역 변수(Stack 영역)


	func_static();
	func_static();
	func_static();
	func_static();
	int result = func_static();
	printf("g_num = %d, g = %d\n", g_num, result );


	inc_g_static_num();
	inc_g_static_num();
	inc_g_static_num();
	inc_g_static_num();
	inc_g_static_num();
	print_g_static_num();
	printf("main g_static_num = %d\n", g_static_num);

	++g_extern_num;
	printf("g_extern_num = %d\n", g_extern_num);

	// 함수 오버로드
	add(1, 1);//int 함수 호출
	add(1.0f, 1.0f);//float 함수 호출
	add(1.0, 1.0);//double 함수 호출

	int arr[10] = { 10, 2, 78, 53, 6, 33, 27, 99, 7, 31 };

	std::sort(arr, arr + 10);
	for (int a : arr)
	{
		printf("arr=%d", a);
	}

	system("pause");
}

//void funTest()
//{
//	int a = 0;
//}