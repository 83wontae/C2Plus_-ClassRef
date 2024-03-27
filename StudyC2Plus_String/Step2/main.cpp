#include <iostream>
#include "Counter.h"
#include "Counter2.h"
#include "VecF.h"

using namespace std;

int main()
{
	//객체 생성 방법
	//디폴트 생성자 - 매개변수 없음
	Counter cnt1[4];
	Counter* pCnt = new Counter[10];
	delete[] pCnt;

	//디폴트 생성자 - 매개변수 있음
	Counter2 cnt2{ 999 };
	Counter2 cnt3[3] = { Counter2(9), Counter2(9), Counter2(9) };
	//Counter2 cnt2[3];//error
	//Counter2* pCnt = new Counter2[10];//error

	//복사 생성자 - 같은 객체를 복사해서 생성한다
	Counter2 cnt4{ cnt2 };// cnt2가 cnt4로 복사된다.
	Counter2 cnt5 = cnt2;// cnt2가 cnt5로 복사된다.

	//복사 생성자의 문제점 - 얕은 복사(shallow copy)
	float a[3] = { 1,2,3 };
	VecF v1(3, a);
	VecF v2(v1);		//v1을 복사해서 v2를 생성한다.

	//복사 생성자의 문제점 - 메모리 낭비
	/*
	* add 함수에서 tmp변수를 생성하고 복사됨
	* 2번 new, memcpy가 실행이되고 비용이 많이 들기때문에
	* 절약할 필요가 있음 이동 생성자를 사용하면 절약 가능
	*/
	float p1[3] = { 1,2,3 };
	float p2[3] = { 2,4,6 };
	VecF v3(3, p1);
	VecF v4(3, p2);
	VecF v5(v3.add(v4)); //v3와 v4를 더한 값으로 v5를 생성하겠다.

	//L-value와 R-value
	//int a1 = 10;
	//int b1 = a1;
	//L-value : 다시 사용할수 있는 값( a, b )
	//R-valeu : 한번 사용하고 버려지는 값( 10 )
	//& : L-value 참조 기호
	//&& : R-value 참조 기호

	int a1 = 10;
	int& aRef = a1;		// L-value 참조로 L-value는 가능
	//int& aa = 10;		// 오류 : L-value 참조로 R-value를 참조할수 없음
	const int& bb = 20;	// 상수 L-value 참조로는 R-value 참조 가능

	int&& c = 30;			// R-value 참조로 R-value를 참조 가능
	//int&& d = a1;		// 오류 : R-value 참조로 L-value를 참조 할수 없음

	VecF v6(3);
	VecF v7(3);
	VecF&& vRef1 = v6.add(v7);// 반환되는 값은 R-value이므로 참조 가능(pointer R-value : pR-value)
}