#include "MyFunction.h"
#include <stdio.h>

static int s_num = 0;

void funTest()// �Լ��̸� ���� + F12 : ����, ���� ��ȯ
{
	int a = 0;
	++g_extern_num;
}

void print_g_static_num()
{
	printf("MyFunction g_static_num = %d\n", g_static_num);
}
