#include <iostream>
#include <bitset>

int main()
{
	//0000 0000(양수), 1000 0000(음수)
	//0000 0001(1) + 1111 1111(-1) = 0000 0000;
	//0111 1111(127) + 1000 0001(-127) = 0000 0000;
	//char에 255를 대입하면 1111 1111 = -1
	//unsigned char에 255를 대입하면 1111 1111 = 255
	
	//-128 ~ 127(1byte)
	signed char c = -1;

	//0 ~ 255(1byte)
	unsigned char uc = 255;

	std::cout << std::bitset<8>(c) << std::endl;

	//-32,768 ~ 32,767(2byte)
	signed short s = -1;

	//0 ~ 65,535(2byte)
	unsigned short us = 1;

	//-2,147,483,648 ~ 2,147,483,647(4byte)
	signed long l = -1;

	//0 ~ 4,294,967,295(4byte)
	unsigned long ul = 1;

	//int 형 설명 자료
	//C언어가 1972년에 출시 8bit 아키텍쳐
	//인텔의 CPU 프로세서 80286(16bit)아키텍쳐의 출시가 1982년
	
	//적어도 16bit(2byte) 범위를 포함 할 수 있습니다.
	//최초 16bit 아키텍쳐 일때는 16bit
	//32bit 이상 아키텍쳐 일때는 32bit
	//크로스플랫폼 개발시 Windows 가 포함되어 있는 환경이라면 가급적 long 을 사용하지 말고 (int , long long) 
	//또는 C99 표준에서 추가된 stdint.h 에 포함된 (int32_t, int64_t) 자료형을 사용하는걸 권장
	//자료형(short int = __int32, long int = long)
	//short int 는 short 과 동일하고 long int 는 long 과 동일하다.
	//자료형(long long = __int64, long long int)
	//long long, long long int 타입은 8byte(64bit) 자료형으로 long long int 에서 int 는 생략이 가능하다.
	//https://learn.microsoft.com/ko-kr/cpp/cpp/data-type-ranges?view=msvc-170

	signed int i = -1;

	//0 ~ 4,294,967,295
	unsigned int ui = 1;

	//4byte(32bit)
	signed float f = -1.0f;
	f = -1.f;

	//8byte(64bit)
	signed double d = 0.0;
	f = 0.;

	//부동 소수점
	//https://ko.wikipedia.org/wiki/%EB%B6%80%EB%8F%99%EC%86%8C%EC%88%98%EC%A0%90
	//10진수 21.8125를 정규화된 이진수로 나타낸다고 해보자.
	//소수점 위의(21.)10 = (10101)2이고, 소수점 아래(0.8125)x10 = (0.1101)x2 이다.
	//즉, (21.8125)x10 = (10101.1101)x2이며, 
	//이를 정규화하면 0.101011101×2^5이다.지수의 5를 이진법으로 바꾸면 101이다.
	//따라서, 32비트 정규화된 부동소수점수로 나타낸다면 맨 앞 비트의 부호는 0(양)이고, 
	//지수부 부호는 0(양)이며,
	//지수부(승수) 나머지 6개 비트는 000101, 가수부는 101011101000…이 된다.
	//이것을 결합하면(0/부호/0000 0101/지수/1010 1110 1000 0000 0000 000/가수/)2가 된다.

	//0001 0000 = 1 이라면
	//0000 1000 = 0.5 이다.( 0000 1000 + 0000 1000 = 0001 0000 )
	//0000 0100 = 0.25
	//0000 0010 = 0.125
	//0000 0001 = 0.0625
	//0000 1101 = 0.8125

	//실수는 정밀도 float보다 double이 더 정밀하다.
	//연산시 반드시 같은 자료형으로 변환하여 연산 할것
	f = (float)i + f;
	f = float(10) + f;
	f = (float)(10 + f);


	//대입 연산자
	// = 
	
	//연산자
	//산술 연산자
	// +, -, *, /, %(모듈러스)
	// ++, --
	int sum = 1 + 1;
	sum += 10;
	int minus = 1 - 1;
	minus -= 10;
	int multiply = 10 * 10;
	int divide = 10 / 2;//10 * 0.5f;

	//실수 끼리 나머지 연산 불가(etc 11.0f % 2.0f) 몇번째 소수점자리에서 연산을 해야할지 알수 없음 
	//즉, 둘다 정수 일때만 가능
	float remain = 11 % 2;

	sum++;//후치
	++sum;//전치
	minus--;
	--minus;

	sum = 10;
	int resultL = ++sum;
	int resultR = sum++;

	std::cout << "L = " << resultL << " R = " << resultR << " sum = " << sum << std::endl;

	//논리 연산자
	//&&(AND), ||(OR), !(NOT)
	//0 : false(0)
	//0이 아닌 값 : true(1)
	int nResult = true;
	bool bResult = true;

	bResult = 10 && 20;
	bResult = 1 || 0;
	bResult = !1;
}