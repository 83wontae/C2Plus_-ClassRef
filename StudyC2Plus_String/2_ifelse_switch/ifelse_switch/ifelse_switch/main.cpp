#include <iostream>
#include <bitset>

#define ACHIEVE_LEVEL_10 0b00000001;//1		(0x01)
#define ACHIEVE_LEVEL_20 0b00000010;//2		(0x02)
#define ACHIEVE_LEVEL_30 0b00000100;//4		(0x04)
#define ACHIEVE_LEVEL_40 0b00001000;//8		(0x08)
#define ACHIEVE_LEVEL_50 0b00010000;//16	(0x10)
#define ACHIEVE_LEVEL_60 0b00100000;//32	(0x20)
#define ACHIEVE_LEVEL_70 0b01000000;//64	(0x40)
#define ACHIEVE_LEVEL_80 0b10000000;//128	(0x80)

//int64
#define ACHIEVE_1	0x00000001;
#define ACHIEVE_2	0x00000002;
#define ACHIEVE_3	0x00000004;
#define ACHIEVE_4	0x00000008;

#define ACHIEVE_5	0x00000010;
#define ACHIEVE_6	0x00000020;
#define ACHIEVE_7	0x00000040;
#define ACHIEVE_8	0x00000080;

#define ACHIEVE_9	0x00000100;
#define ACHIEVE_10	0x00000200;
#define ACHIEVE_11	0x00000400;
#define ACHIEVE_12	0x00000800;


int main()
{
	// 비교 연산자
	// ==, !=, >, >=, <, <=
	bool bResult = (10 == 11);

	// 삼항 연산자
	int nResult = (10 == 11) ? 10 : 30;

	std::cout << bResult << std::endl;
	std::cout << nResult << std::endl;

	std::cout << "what is your Score? ";
	int Score = 0;
	int grade = 0;
	std::cin >> Score;

	//if else 구문
	if (Score >= 90)
	{
		std::cout << "A" << std::endl;
		grade = 1;
	}
	else if (Score >= 80)
	{
		std::cout << "B" << std::endl;
		grade = 2;
	}
	else if (Score >= 70)
	{
		std::cout << "C" << std::endl;
		grade = 3;
	}
	else if (Score >= 60)
	{
		std::cout << "D" << std::endl;
		grade = 4;
	}
	else if (Score >= 50)
	{
		std::cout << "E" << std::endl;
		grade = 5;
	}
	else
	{
		std::cout << "F" << std::endl;
		grade = 6;
	}

	int gradePoint = 0;
	//Switch 구문
	switch (grade)
	{
	case 1:
		gradePoint = 10;
		break;
	case 2:
		gradePoint = 9;
		break;
	case 3:
		gradePoint = 8;
		break;
	case 4:
		gradePoint = 7;
		break;
	case 5:
		gradePoint = 6;
		break;
	case 6:
		gradePoint = 5;
		break;
	default:
		break;
	}

	//비트 연산자
	//C++ 11부터 숫자 앞에 0b를 붙이면 2진법 표기 가능(0b00001111)
	//앞에 0를 붙이면 8진법 표기 가능(0123)
	//앞에 0x를 붙이면 16진법 표기 가능(0xFF)
	int a = 0123;
	int b = 0xFF;
	std::cout << "a = " << a << std::endl;

	//비트 연산자
	//곱(&) : 둘 다 1이면 1, 아니면 0
	//합(|) : 둘 중에 하나라도 1이면 1, 아니면 0
	//XOR(^) : 둘이 같으면 1, 다르면 0
	//반전(~) : 0이면 1, 1이면 0
	char MyAchieve = 0b10100011;
	MyAchieve = MyAchieve | 0b00001000;
	std::cout << std::bitset<8>(MyAchieve) << std::endl;

	bool IsEnable = MyAchieve & 0b00010000;
	std::cout << IsEnable << std::endl;

	//비트를 뺄때는 반전 시켜서 논리곱
	MyAchieve = MyAchieve & ~0b00001000;
	std::cout << std::bitset<8>(MyAchieve) << std::endl;
}