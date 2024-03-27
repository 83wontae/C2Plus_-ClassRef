#include <iostream>
#include "Counter.h"//class Counter

using namespace std;

void g(const Counter& c)
{
	//const로 클래스를 참조하면 호출하는 클래스에 함수의 형태 또한 const여야 한다.
	cout << "Counter = " << c.getCount() << endl;
}

int main()
{
	int a = 0;
	Counter c1;
	c1.counting();
	c1.counting();
	cout << "c1 Count = " << c1.getCount() << endl;
	c1.counting();
	g(c1);
}