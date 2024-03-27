#pragma once

//함수이름 funcFmulit
//파라메타 int a, int b
//반환값 int
//a에 b승에 값을 구해서 반환 한다.
inline int funcFmulit(int a, int b)
{
	int result = 1;
	for (int i = 0; i < b; ++i)
	{
		result *= a;
	}
	return result;
}

