#include <iostream>
#include <bitset>
#include <stdio.h>//standard Input Output 표준 입출력 함수 라이브러리

//#include, #define 전처리기

//함수형
//int : 반환 자료형 <-출력
//CalculatorSum : 함수 이름
//(int x, int y) : 매개 변수(파라메타) <-입력
int CalculatorSum(int x, int y)
{//->함수 시작
	int Sum = x + y;

	return Sum;//<-반환값
}//->함수 끝

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
	//함수 - 입력 따른 작업 진행하여 결과를 출력 한다.(입력과 출력없이 작업을 실행하기도함)
	//자판기 - 입력 : 동전, 출력 : 음료수
	//번호표 기계 - 입력 : 없음, 출력 : 번호표
	//호출벨 - 입력 : 없음, 출력 : 없음

	int Sum = CalculatorSum(10, 20);

	for (/*초기 설정*/int i = 0;/*반복 조건 채크*/i < 10;/*반복 후 처리*/++i)
	{
		printf("HelloC++\n");
	}

	int a = 0;
	Sum = 0;
	for (/*초기 설정*/int i = 0;/*반복 조건 채크*/i < 10;/*반복 후 처리*/++i)
	{
		Sum = CalculatorSum(Sum, i);
	}

	// printf("int = %d", 3);
	// printf("float = %f", 3.14f);
	// %d : 부호 있는 10진수 정수
	// %I64d : 부호 있는 10진수 정수(64bit) 
	// %u : 부호 없는 10진수 정수
	// %I64u : 부호 없는 10진수 정수(64bit) 
	// %f : 부호 있는 실수 소수(12.566371)
	// %e, %E : 부호 있는 실수 지수(1.256637e+001)
	// %g, %G : 숫자값의 크기에 따라 f나 e로 출력 ( precision의 자리수를 넘어가면 e 아니면 f )
	// %i : 부호 있는 10진수 정수 (입력시 10진수/8진수/16진수 정수 입력 가능)
	// %X : 부호 없는 16진수 (A~F)로 표시
	// %x : 부호 없는 16진수 (a~f)로 표시
	// %o : 부호 없는 8진수
	// %p : 포인터 값을 16진수로 출력
	// %s : 문자열 출력
	// %c : 단일 문자 출력
	// %x : 부호 없는 16진수
	/*
	%d와 %i의 차이점
	int a;
	scanf("%i", &a); //011을 입력하면 9
	scanf("%d", &a); //011을 입력하면 11
	*/
	printf("%%f의 출력 : %f\n", 12.566371);//소수(12.566371)
	printf("%%e의 출력 : %e\n", 12.566371);//지수(1.256637e+001) e:지수, +001:10을 1번 곱한다, -001:10을 1번 나눈다
	printf("%%c의 출력 : %c\n", 80);//아스키 코드 80 : P


	//std::cout << Sum << std::endl;
	printf("Sum = %d", Sum);

	bool bRun = true;
	while (bRun)
	{
		int num1 = 0, num2 = 0;
		printf("첫 번째 정수를 입력하세요 : ");
		scanf_s("%d", &num1);

		printf("첫 번째 정수를 입력하세요 : ");
		scanf_s("%d", &num2);

		Sum = CalculatorSum(num1, num2);
		printf("Sum = %d", Sum);

		int nInput = 0;
		printf("1)한번더 계산 2)종료 :");
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

	// 지정한 구문 주석			: Ctrl + k, c
	// 지정한 구문 주석 해제	: Ctrl + k, u
	// Alt Drag : 부분 영역

	// 디버깅 시작 및 개속 진행 : F5
	// 중단점 생성 및 해제 : F9
	// 디버깅 중 다음 구문 진행 : F10
	// 디버깅 중 함수 내부 구문 진행 : F11
	// 디버깅 종료 : Shift + F5


	printf("Factorial : %d", Factorial(3));
	printf("Recursion_Factorial : %d", Recursion_Factorial(3));

	return 0;//메인 함수도 결과값이 필요하다 하지만 생략 가능, 0은 정상적으로 실행됐다는 의미
}