#include "Initialize.h"
#include <iostream>
#include <string>

using namespace std;

void Initialize()
{
	for (int i = 0; i < MAX; ++i)
	{
		int j = i / 13;
		switch (j)
		{
		case 0:
			Cards[i].mark = Spade;
			break;
		case 1:
			Cards[i].mark = Dia;
			break;
		case 2:
			Cards[i].mark = Heart;
			break;
		case 3:
			Cards[i].mark = Clover;
			break;
		default:
			break;
		}
		Cards[i].number = i % 13 + 1;
	}
}
