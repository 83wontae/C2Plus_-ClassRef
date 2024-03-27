#include <iostream>
#include "funcSum.h"
#include "funcMinues.h"
#include "funcMulti.h"
#include "funcDivid.h"
#include "funcSum3.h"
#include "funcRemain.h"
#include "funcAverage.h"
#include "funcFmulit.h"

using namespace std;

// multi2(5) == 5*5
// multi2(5+1) == 5+1*5+1
#define multi2(x) x*x

int main()
{
	int r = multi2(5 + 1);
	cout << r << endl;

	int Sum = 0;//Sum이라는 int형 변수를 생성하고 0으로 초기화
	int a, b = 0;
	char c = 0;

	funcSum(Sum, 10);

	while (true)
	{
		//"1 + 1"형식으로 입력 받는다.
		cin >> a >> c >> b;


		// c에 기호에 따라 ( + ,- ,* ,/ ,% ) 연산을 하도록 만드세요 
		switch (c)
		{
		case '+':
			Sum = a + b;
			break;
		case '-':
			Sum = a - b;
			break;
		case '*':
			Sum = a * b;
			break;
		case '/':
			Sum = a / b;
			break;
		case '%':
			Sum = a % b;
			break;
		case '^':
			//승수 구하기
			//2 ^ 5 = 2*2*2*2*2
			Sum = funcFmulit(a, b);
			break;
		default:
			break;
		}

		//입력한 공식에 맞는 Sum 값을 출력 하세요
		cout << a << c << b << "=" << Sum << endl;
	}
}