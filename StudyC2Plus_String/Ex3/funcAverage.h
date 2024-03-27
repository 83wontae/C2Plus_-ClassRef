#pragma once

//함수이름 funcAverage
//파라메타 int &Sum, int a, int b, int c
//반환값 없음
//Sum에 a, b, c에 평균 값을 넣으시오
inline void funcAverage(int& Sum, int a, int b, int c)
{
	Sum = (a + b + c) / 3;
}

