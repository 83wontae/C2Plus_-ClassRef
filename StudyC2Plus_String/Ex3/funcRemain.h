#pragma once

//함수이름 funcRemain
//파라메타 int &Sum, int a
//반환값 없음
//Sum에 a를 나눈 나머지를 넣는다.
inline void funcRemain(int& Sum, int a)
{
	Sum %= a;
}

