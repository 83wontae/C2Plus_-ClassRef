#include <stdio.h>
#include <iostream>

int cSum(int a, int b) {
	return a + b;
}

int cMinus(int a, int b) {
	return a - b;
}

int cMulti(int a, int b) {
	return a * b;
}

float cDivide(float a, float b) {
	return a / b;
}

enum InputType
{
	Quit = 0,
	Sum,
	Minus,
	Multi,
	Divide
};

void ScanfinputNum(int& a, int& b)
{
	printf("\n숫자 하나를 입력하세요:");
	scanf_s("%d", &a);
	printf("\n숫자 하나 더 입력하세요:");
	scanf_s("%d", &b);
}

int main()
{
	bool bRun = true;

	while (bRun)
	{
		InputType nInput = InputType::Quit;
		int a = 0, b = 0;
		printf("어떤 연산을 하시겠습니까? 0)종료 1)더하기 2)빼기 3)곱하기 4)나누기 : ");
		scanf_s("%d", &nInput);

		system("cls");

		switch (nInput)
		{
		case InputType::Quit:
			bRun = false;
			break;

		case InputType::Sum:
			ScanfinputNum(a, b);
			printf("\nSum 결과는 %d 입니다.\n", cSum(a, b));
			break;

		case InputType::Minus:
			ScanfinputNum(a, b);
			printf("\nMinus 결과는 %d 입니다.\n", cMinus(a, b));
			break;

		case InputType::Multi:
			ScanfinputNum(a, b);
			printf("\nMulti 결과는 %d 입니다.\n", cMulti(a, b));
			break;

		case InputType::Divide:
			ScanfinputNum(a, b);
			printf("\nDivide 결과는 %f 입니다.\n", cDivide(a, b));
			break;

		default:
			break;
		}
	}
}