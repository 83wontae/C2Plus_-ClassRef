#include <iostream>
#include <Windows.h>

using namespace std;

// 함수 이름 : printTo100
// 동작 : 0~100까지 출력
// 입력값 : 없음
// 출력값 : 없음
void printTo100()
{
	int number[1000] = { 0 };

	for (int i = 0; i < 100; ++i)
	{
		number[i] = i;
		cout << number[i] << endl;
	}
}

// 함수 이름 : printToEven
// 동작 : 0~100까지 짝수 출력
// 입력값 : 없음
// 출력값 : 없음
void printToEven()
{
	int number[1000] = { 0 };

	for (int i = 0; i < 50; ++i)
	{
		// i     = 0,  1,  2, 3, 4,  5,   6,  7,  8,  9, 10...
		// i * 2 = 0,  2,  4, 6, 8, 10, 12, 14, 16,

		number[i] = i * 2;
		cout << number[i] << endl;
	}
}

// 함수 이름 : printToOdd
// 동작 : 0~100까지 홀수 출력
// 입력값 : 없음
// 출력값 : 없음
void printToOdd()
{
	int number[1000] = { 0 };

	for (int i = 0; i < 50; ++i)
	{
		// i     = 0,  1,  2, 3, 4,  5,   6,  7,  8,  9, 10...
		// i * 2 = 0,  2, 4, 6, 8, 10, 12, 14, 16,
		// i * 2 + 1 = 1, 3, 5, 7, 9, 11, 13, 15, 17,

		number[i] = i * 2 + 1;
		cout << number[i] << endl;
	}
}

// 함수 이름 : printTo3Dra
// 동작 : 0~100까지 3배수 출력
// 입력값 : 없음
// 출력값 : 없음
void printTo3Dra()
{
	int number[1000] = { 0 };

	//number에 0~100까지 3의 배수 출력
	for (int i = 0; i < 34; ++i)
	{
		// i     = 0,  1,  2, 3, 4,  5,   6,  7,  8,  9, 10...
		// i * 2 = 0,  2,  4, 6, 8, 10, 12, 14, 16,

		number[i] = i * 3;
		cout << number[i] << endl;
	}
}

// 함수 이름 : printTo3multi
// 동작 : 0~100까지 3승수 출력
// 입력값 : 없음
// 출력값 : 없음
void printTo3multi()
{
	int number[1000] = { 0 };

	for (int i = 0; i < 10; ++i)
	{
		number[i] = 1;
		// 3//1번, 3*3//2번, 3*3*3//3번, 3*3*3*3//4번 
		for (int j = 0; j < i; ++j)// j가 i번까지 실행하면서 3을 곱해준다.
		{
			number[i] *= 3;
		}
		cout << number[i] << endl;
	}

	//// i0 = 3
	//// i1 = i0 * 3//i0=3
	//// i2 = i1 * 3//i1=9
	//// i3 = i2 * 3//i2=27
	//// i4 = i3 * 3//
	//// i5 = i4 * 3//
	//number[0] = 3;
	//for (int i = 1; i < 10; ++i)
	//{
	//	number[i] = number[i - 1] * 3;
	//	cout << number[i - 1] << endl;
	//}
}
// 함수 이름 : printToGogodan
// 동작 : n의 구구단 * 9 까지 출력
// 입력값 : int n
// 출력값 : 없음
void printToGogodan(int n)
{
	for (int i = 2; i <= 9; ++i)
	{
		int result = n * i;
		cout << n << " * " << i << " = " << result << endl;
	}
	/*
	// cout << number[i] << endl;
	// "2 * " << i << " = " <<  <<
	// 2 * 1 = 2
	// 2 * 2 = 4
	// 2 * 3 = 6
	// 2 * 4 = 8
	// 2 * 5 = 10
	// 2 * 6 = 12
	// 2 * 7 = 14
	// 2 * 8 = 16
	// 2 * 9 = 18
	for (int j = 2; j <= 9; ++j)
	{
		for (int i = 1; i <= 9; ++i)
		{
			int result = j * i;
			cout << j << " * " << i << " = " << result << endl;
		}
	}

	// 숫자 하나를 입력 받아서
	// 그 숫자에 2~9 구구단 출력
	// 10을 입력 받았다고 한다면
	// 10 * 1 = 10
	// 10 * 2 = 20
	// 10 * 3 = 30
	// 10 * 4 = 40
	// 10 * 5 = 50
	// 10 * 6 = 60
	// 10 * 7 = 70
	// 10 * 8 = 80
	// 10 * 9 = 90

	int a = { 0 };
	cin >> a;

	for (int i = 2; i <= 9; ++i)
	{
		int result = a * i;
		cout << a << " * " << i << " = " << result << endl;
	}
	*/
}
// 함수 이름 : printFactorial
// 동작 : n!을 구한 결과값을 반환한다.
// 입력값 : int n
// 출력값 : int
int printFactorial(int n)
{
	int result = 1;
	for (int i = 1; i <= n; ++i)
	{
		result *= i;
	}

	return result;
}

int main()
{
	//x를 Location X라고 가정하고 +방향으로 갔다가 - 방향으로 개속 움직이게 해주자
	int x = { 0 };
	bool IsMoveRight = true;

	while (1)
	{
		system("cls");
		cout << x << endl;

		if (IsMoveRight)
		{
			//오른쪽으로 이동(+방향)
			x++;
			if (x >= 20)
			{
				IsMoveRight = false;
			}
		}
		else
		{
			//왼쪽으로 이동(-방향)
			x--;
			if (x <= 0)
			{
				IsMoveRight = true;
			}
		}

		Sleep(100);
	}
}