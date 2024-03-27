#include <iostream>
#include <bitset>
#include <stdio.h>//standard Input Output ǥ�� ����� �Լ� ���̺귯��

//#include, #define ��ó����

//�Լ���
//int : ��ȯ �ڷ��� <-���
//CalculatorSum : �Լ� �̸�
//(int x, int y) : �Ű� ����(�Ķ��Ÿ) <-�Է�
int CalculatorSum(int x, int y)
{//->�Լ� ����
	int Sum = x + y;

	return Sum;//<-��ȯ��
}//->�Լ� ��

int Factorial(int num)
{
	int temp = 1;
	for (int i = num; i > 0; --i)
	{
		temp *= i;
	}

	return temp;
}

int Recursion_Factorial(int num)
{
	if (num == 1)
	{
		return 1;
	}

	return num * Recursion_Factorial(num - 1);
}

int main()
{
	//�Լ� - �Է� ���� �۾� �����Ͽ� ����� ��� �Ѵ�.(�Է°� ��¾��� �۾��� �����ϱ⵵��)
	//���Ǳ� - �Է� : ����, ��� : �����
	//��ȣǥ ��� - �Է� : ����, ��� : ��ȣǥ
	//ȣ�⺧ - �Է� : ����, ��� : ����

	int Sum = CalculatorSum(10, 20);

	for (/*�ʱ� ����*/int i = 0;/*�ݺ� ���� äũ*/i < 10;/*�ݺ� �� ó��*/++i)
	{
		printf("HelloC++\n");
	}

	int a = 0;
	Sum = 0;
	for (/*�ʱ� ����*/int i = 0;/*�ݺ� ���� äũ*/i < 10;/*�ݺ� �� ó��*/++i)
	{
		Sum = CalculatorSum(Sum, i);
	}

	// printf("int = %d", 3);
	// printf("float = %f", 3.14f);
	// %d : ��ȣ �ִ� 10���� ����
	// %I64d : ��ȣ �ִ� 10���� ����(64bit) 
	// %u : ��ȣ ���� 10���� ����
	// %I64u : ��ȣ ���� 10���� ����(64bit) 
	// %f : ��ȣ �ִ� �Ǽ� �Ҽ�(12.566371)
	// %e, %E : ��ȣ �ִ� �Ǽ� ����(1.256637e+001)
	// %g, %G : ���ڰ��� ũ�⿡ ���� f�� e�� ��� ( precision�� �ڸ����� �Ѿ�� e �ƴϸ� f )
	// %i : ��ȣ �ִ� 10���� ���� (�Է½� 10����/8����/16���� ���� �Է� ����)
	// %X : ��ȣ ���� 16���� (A~F)�� ǥ��
	// %x : ��ȣ ���� 16���� (a~f)�� ǥ��
	// %o : ��ȣ ���� 8����
	// %p : ������ ���� 16������ ���
	// %s : ���ڿ� ���
	// %c : ���� ���� ���
	// %x : ��ȣ ���� 16����
	/*
	%d�� %i�� ������
	int a;
	scanf("%i", &a); //011�� �Է��ϸ� 9
	scanf("%d", &a); //011�� �Է��ϸ� 11
	*/
	printf("%%f�� ��� : %f\n", 12.566371);//�Ҽ�(12.566371)
	printf("%%e�� ��� : %e\n", 12.566371);//����(1.256637e+001) e:����, +001:10�� 1�� ���Ѵ�, -001:10�� 1�� ������
	printf("%%c�� ��� : %c\n", 80);//�ƽ�Ű �ڵ� 80 : P


	//std::cout << Sum << std::endl;
	printf("Sum = %d", Sum);

	bool bRun = true;
	while (bRun)
	{
		int num1 = 0, num2 = 0;
		printf("ù ��° ������ �Է��ϼ��� : ");
		scanf_s("%d", &num1);

		printf("ù ��° ������ �Է��ϼ��� : ");
		scanf_s("%d", &num2);

		Sum = CalculatorSum(num1, num2);
		printf("Sum = %d", Sum);

		int nInput = 0;
		printf("1)�ѹ��� ��� 2)���� :");
		scanf_s("%d", &nInput);

		switch (nInput)
		{
		case 1:
			continue;
			break;
		case 2:
			bRun = false;
			break;
		default:
			break;
		}
	}

	// ������ ���� �ּ�			: Ctrl + k, c
	// ������ ���� �ּ� ����	: Ctrl + k, u
	// Alt Drag : �κ� ����

	// ����� ���� �� ���� ���� : F5
	// �ߴ��� ���� �� ���� : F9
	// ����� �� ���� ���� ���� : F10
	// ����� �� �Լ� ���� ���� ���� : F11
	// ����� ���� : Shift + F5


	printf("Factorial : %d", Factorial(3));
	printf("Recursion_Factorial : %d", Recursion_Factorial(3));

	return 0;//���� �Լ��� ������� �ʿ��ϴ� ������ ���� ����, 0�� ���������� ����ƴٴ� �ǹ�
}