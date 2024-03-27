#pragma once

#ifndef __Card_H__
#define __Card_H__

#include <iostream>
#include <string>

using namespace std;

enum CardMark
{
	Clover = 0,
	Heart,
	Dia,
	Spade,
};

string GetEnumToCardMarkString(CardMark mark);

struct stCard
{
	CardMark mark;
	int number;
};

#endif // !__Card_H__
