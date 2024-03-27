#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "overload.h"
#include <algorithm>
#include <iostream>

// C++ �� ������ ����
// C++ ���� �츮�� �ۼ��� �ҽ��ڵ带 ������ ������ �� �ִ� ���� ���Ϸ� ��ȯ�ϱ� ���ؼ��� �� 4 ���� �ܰ踦 ���ľ߸� �մϴ�.

// 1. ��ó��(Preprocessing) �ܰ� : #include �� #define �� ���� ��ó���� ��ũ�ε��� ó���ϴ� ��ó��(Preprocessing) �ܰ�
// 2. ������(Compile) �ܰ� : ������ �ҽ� ���ϵ��� ����� ��ɾ�� ��ȯ
// 3. �����(Assemble) �ܰ� : ����� �ڵ���� ���� ����� �̷���� ���� �ڵ�(Object file)�� ��ȯ
// 4. ��ŷ(Linking) �ܰ� : ������ ���� �ڵ���� �ѵ� ��Ƽ� �ϳ��� ���� ������ ����

// �޸� ����
// 1. Code ���� : ������ �ڵ尡 ����Ǿ��ִ� ����(����� ����)
// 2. Data ���� : ��������, Static �������� ����, ���μ����� ����ɶ� ���� �޸𸮿� �����
// 3. Stack ���� : ��������, �Ű��������� ����, �Լ��� ȣ��Ǹ� �����ǰ� �Լ��� ���� �Ǹ� �ý��ۿ� ��ȯ
// 4. Heap ���� : malloc �Ǵ� new �Լ� � ���ؼ� �������� �Ҵ�Ǵ� ����, malloc() �Ǵ� new �����ڸ� ���� �Ҵ�, free() �Ǵ� delete �����ڸ� ���� ����

struct MyStruct
{
	int num;
	float value;
};

int a = 0;//<- ���� ����(Data ����)

//void funTest();
#include "MyFunction.h"
//#include "MyFunction2.h"

int g_num = 0;

extern int g_extern_num;// ���� ������ ��𿣰� ����Ǿ����� �Ŷ�� �̸� �˷��ش�

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
	//�迭
	//int arrInt[10] = {0};
	int arrInt[10] = {0,1,2,3,4,5,6,7,8,9};
	arrInt[0] = 0;
	arrInt[1] = 10;

	for (int itr : arrInt)
	{
		funTest();
	}

	int a = 0;;//<- ���� ����(Stack ����)


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

	// �Լ� �����ε�
	add(1, 1);//int �Լ� ȣ��
	add(1.0f, 1.0f);//float �Լ� ȣ��
	add(1.0, 1.0);//double �Լ� ȣ��

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