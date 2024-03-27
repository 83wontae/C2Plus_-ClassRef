#include "Shuffle.h"
#include <iostream>

using namespace std;

void Shuffle()
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < MAX; ++i)
	{
		int FirstNumber = rand() % MAX;
		int SecondNumber = rand() % MAX;

		//Swap
		stCard Temp = Cards[FirstNumber];
		Cards[FirstNumber] = Cards[SecondNumber];
		Cards[SecondNumber] = Temp;
	}
	/*
	for (int i = 0; i < MAX; ++i)
	{
		cout << Cards[i].mark + " " << Cards[i].number << endl;
	}
	*/
}
