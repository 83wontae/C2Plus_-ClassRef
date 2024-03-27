#include <iostream>
#include <bitset>
#include <stdio.h>//standard Input Output ǥ�� ����� �Լ� ���̺귯��

void memFunc(int* a)
{
	*a = 100;
}

int g_X = 100;

void PrintValuePoint(const int* value)
{
	//value = nullptr;// ������ �ּ� ���� �����Ҽ� �ִ�.
	//value = 10;
	printf("value=%d\n", *value);
}

void PrintValueRef(const int& value)
{
	//value = 10;
	printf("value=%d\n", value);
}

int main()
{
	int i = 100;
	float f = 1.0f;

	// ������ �ڷ��� ����(4byte)
	// C���, C++�� ����Ͻô� ���� �е��� 0, NULL �̷��� ���� ���, C++11���ʹ� nullptr�� ���
	// https://learn.microsoft.com/ko-kr/cpp/extensions/nullptr-cpp-component-extensions?view=msvc-170
	int* pi = nullptr;// nullptr Ű���� : ������ �ּҰ� �ʱ�ȭ ó��
	pi = &i;// &:���ۼ�Ʈ�� ���̸� �޸� �ּҰ�
	int* pi2 = (int*)&f;// &:���ۼ�Ʈ

	*pi = 101;
	printf("i = %d\n", i);
	printf("pi = %d\n", *pi);

	printf("pi2 = %d\n", *pi2);

	// ������ size
	// ��Ű��ó�� ���� �ٸ���
	// x32 ȯ�濡���� 4byte, x64 ȯ�濡���� 8byte
	// 1GB = 1024MB
	// 1MB = 1024KB
	// 1KB = 1024Byte
	// 1Byte = 8Bit
	// x32 ȯ�濡���� 42�ﰳ �ּҰ��� �������� 4GB �̻��� �޸� �ּҸ� Ŀ���ϱ�� ����(x86�� �̸� ������ ����)

	int* pInt = nullptr;	// 8byte
	char* pChar = nullptr;	// 8byte
	short* pShort = nullptr;// 8byte
	printf("pInt size = %I64d\n", sizeof(pInt));
	printf("pChar size = %I64d\n", sizeof(pChar));
	printf("pShort size = %I64d\n", sizeof(pShort));

	int arr[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	pInt = arr;
	printf("pInt = %d\n", *pInt);
	pInt += 1;// ���� �ּҰ��� ����Ų��
	printf("pInt = %d\n", *pInt);

	short sArr[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	int* pA = (int*)sArr;

	int result = *((short*)(pA + 2));//int(4Byte) 2�� �̵� = short(2Byte) 4�� �̵�
	printf("pInt = %d\n", result);

	char cArr[2] = { 1, 1 };//short(0000 0001 0000 0001) = 257
	short* pS = (short*)cArr;
	result = *pS;
	printf("pInt = %d\n", result);

	int nTemp = 0;
	memFunc(&nTemp);
	printf("nTemp = %d\n", nTemp);

	// const
	// �Ǽ��� ���ϼ� �ִ�. ����� Ƚ���� �پ���.
	// ������ ���ȭ �Ѵ�.
	const int cint = 100;//const ���ȭ

	int value;
	int* pValue = &value;
	//const int* pValue = &value;// �����Ͱ� ����Ű�� ������ ���� �Ұ�, ������ �� ���� ����, ������ ����
	//int const* pValue = &value;// �����Ͱ� ����Ű�� ������ ���� �Ұ�, ������ �� ���� ����, ������ ����
	//int* const pValue = &value;// �����Ͱ� ����Ű�� ������ ���� ����, ������ �� ���� �Ұ�, ������ ����
	//const int* const pValue = &value;// �����Ͱ� ����Ű�� ������ ���� �Ұ�, ������ �� ���� �Ұ�, ������ ����
	//int const* const pValue = &value;// �����Ͱ� ����Ű�� ������ ���� �Ұ�, ������ �� ���� �Ұ�, ������ ����

	*pValue = 2;
	pValue = (int*)&cint;
	*pValue = 50;
	printf("pValue=%d\n", *pValue);

	PrintValueRef(*pValue);

	return 0;
}