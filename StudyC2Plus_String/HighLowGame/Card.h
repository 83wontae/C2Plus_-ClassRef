#pragma once
#include <iostream>
#include <string>

#define Max 52

using namespace std;

enum CardMark
{
	Clover = 0,
	Heart,
	Dia,
	Spade
};

struct stCard
{
	CardMark mark;
	int number;

	// 함수 이름 : printCard
	// 파라메타 : 없음
	// 반환값 : 없음
	// Mark = Spade Number = 7 <--- 이렇게 화면에 출력하는 함수를 만드시오
	void printCard()
	{
		cout << "Mark = " << GetStrMark() << " Number = " << number << endl;
	}

	string GetStrMark()
	{
		switch (mark)
		{
		case Clover:	return "Clover";	break;
		case Heart:	return "Heart";	break;
		case Dia:		return "Dia";		break;
		case Spade:	return "Spade";	break;
		default:		return "";			break;
		}
	}

	
};

