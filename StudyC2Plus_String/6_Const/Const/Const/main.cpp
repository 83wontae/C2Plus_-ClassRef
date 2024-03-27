#include <stdio.h>

struct stInBody		//8*4byte(x64�ϰ�� 8byte�������� ũ�� ����)
{
	int age;		//4byte
	double hegint;	//8byte
	float weight;	//4byte
	float fat;		//4byte
	float muscle;	//4byte
};

void PrintInBody(const stInBody* inBody)
{
	// inBody = nullptr;//�Ķ��Ÿ ������ ���� O
	// inBody->age = 30;//Error(const Ű����� ���� ���� �Ұ�)
	printf("age = %d\n", inBody->age);
	printf("hegint = %f\n", inBody->hegint);
	printf("weight = %f\n", inBody->weight);
	printf("fat = %f\n", inBody->fat);
	printf("muscle = %f\n", inBody->muscle);
}

void PrintInBody2(const stInBody& inBody)
{
	// stInBody a;
	// inBody = a;//�Ķ��Ÿ ������ ���� X
	//inBody.age = 30;//Error(const Ű����� ���� ���� �Ұ�)
	printf("age = %d\n", inBody.age);
	printf("hegint = %f\n", inBody.hegint);
	printf("weight = %f\n", inBody.weight);
	printf("fat = %f\n", inBody.fat);
	printf("muscle = %f\n", inBody.muscle);
}

int main()
{
	// const Ű����
	// https://www.youtube.com/watch?v=MSgzBYKbGTI
	// �����ϰ� �Ǽ� Ȯ���� �ٿ��� 
	// �⺻ ��� : ������ ������ �ʴ� ���ȭ �ϱ�� ����Ѵ�.
	// �����Ϸ� ����ȭ �������� �������Ϳ� ������� ����, ���� �ּҿ��� ���� �о���� ����
	// volatile�� �������� ����ȭ�� ���� Ȯ������ ���� ��¥�� �ּ� ���� ���� Ȯ��
	// volatile const int MAX_LEVEL = 99;//<--�� ����ϸ� MAX_LEVEL ���� �����
	const int MAX_LEVEL = 99;
	//MAX_LEVEL = 60;//<---Error : ����̹Ƿ� ������ �� ����

	int* plevel = nullptr;
	//const int* plevel = nullptr;// const Ű���尡 ������(*) �տ� �ִ� ���, �����Ͱ� ����Ű�� �ִ� ���� ���� ���� �Ҽ� ����.
	//int const* plevel = nullptr;// const Ű���尡 ������(*) �տ� �ִ� ���, �����Ͱ� ����Ű�� �ִ� ���� ���� ���� �Ҽ� ����.
	//int* const plevel = nullptr;// const Ű���尡 ������(*) �ڿ� �ִ� ���, plevel ������ ���� �Ҽ� ����.
	//const int* const plevel = nullptr;// const Ű���尡 ������(*) �յڿ� �ִ� ���, ������ �ּ�, ������ ���� ���� �Ҽ� ����
	//int const* const plevel = nullptr;// const Ű���尡 ������(*) �յڿ� �ִ� ���, ������ �ּ�, ������ ���� ���� �Ҽ� ����.

	plevel = (int*)&MAX_LEVEL;//<--- ���� �� ���� �ִ�. �ϸ� �ȵ�.
	*plevel = 2;

	printf("plevel = %d\n", *plevel);
	printf("MAX_LEVEL = %d\n", MAX_LEVEL);

	stInBody body;
	body.age = 40;
	body.fat = 30;
	body.muscle = 20;
	body.hegint = 170;
	body.weight = 70;
	int size = sizeof(body);
	printf("stInBody Size = %d\n", size);
	PrintInBody(&body);
}