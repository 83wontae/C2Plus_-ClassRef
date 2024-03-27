#include "MyFunction.h"
#include <stdio.h>

static int s_num = 0;

void funTest()// 함수이름 선택 + F12 : 선언, 정의 전환
{
	int a = 0;
	++g_extern_num;
}

void print_g_static_num()
{
	printf("MyFunction g_static_num = %d\n", g_static_num);
}
