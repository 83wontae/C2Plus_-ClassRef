#include <stdio.h>

struct stInBody		//8*4byte(x64일경우 8byte기준으로 크기 증가)
{
	int age;		//4byte
	double hegint;	//8byte
	float weight;	//4byte
	float fat;		//4byte
	float muscle;	//4byte
};

void PrintInBody(const stInBody* inBody)
{
	// inBody = nullptr;//파라메타 변수를 변경 O
	// inBody->age = 30;//Error(const 키워드로 인해 변경 불가)
	printf("age = %d\n", inBody->age);
	printf("hegint = %f\n", inBody->hegint);
	printf("weight = %f\n", inBody->weight);
	printf("fat = %f\n", inBody->fat);
	printf("muscle = %f\n", inBody->muscle);
}

void PrintInBody2(const stInBody& inBody)
{
	// stInBody a;
	// inBody = a;//파라메타 변수를 변경 X
	//inBody.age = 30;//Error(const 키워드로 인해 변경 불가)
	printf("age = %d\n", inBody.age);
	printf("hegint = %f\n", inBody.hegint);
	printf("weight = %f\n", inBody.weight);
	printf("fat = %f\n", inBody.fat);
	printf("muscle = %f\n", inBody.muscle);
}

int main()
{
	// const 키워드
	// https://www.youtube.com/watch?v=MSgzBYKbGTI
	// 안전하고 실수 확률을 줄여줌 
	// 기본 기능 : 변수를 변하지 않는 상수화 하기로 약속한다.
	// 컴파일러 최적화 과정에서 레지스터에 상수값을 저장, 실재 주소에서 값을 읽어오지 않음
	// volatile는 레지스터 최적화를 통해 확인하지 말고 진짜로 주소 가서 값을 확인
	// volatile const int MAX_LEVEL = 99;//<--을 사용하면 MAX_LEVEL 값이 변경됨
	const int MAX_LEVEL = 99;
	//MAX_LEVEL = 60;//<---Error : 상수이므로 변경할 수 없음

	int* plevel = nullptr;
	//const int* plevel = nullptr;// const 키워드가 포인터(*) 앞에 있는 경우, 포인터가 가르키고 있는 곳의 값을 변경 할수 없다.
	//int const* plevel = nullptr;// const 키워드가 포인터(*) 앞에 있는 경우, 포인터가 가르키고 있는 곳의 값을 변경 할수 없다.
	//int* const plevel = nullptr;// const 키워드가 포인터(*) 뒤에 있는 경우, plevel 변수를 변경 할수 없다.
	//const int* const plevel = nullptr;// const 키워드가 포인터(*) 앞뒤에 있는 경우, 포인터 주소, 변수값 전부 변경 할수 없다
	//int const* const plevel = nullptr;// const 키워드가 포인터(*) 앞뒤에 있는 경우, 포인터 주소, 변수값 전부 변경 할수 없다.

	plevel = (int*)&MAX_LEVEL;//<--- 변경 할 수도 있다. 하면 안됨.
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