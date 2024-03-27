#include <iostream>
#include <vector>
#include <array>
#include <string>
#include "Card.h"
#include "Common.h"
#include "Shuffle.h"
#include "Initialize.h"
#include "Result.h"

using namespace std;

enum EnGameState
{
	Ready = 0,
	Playing
};

int main()
{
	Initialize();
	int i = 0;
	char HighAndLow = 'H';
	char KeepPlay = 'Y';
	EnGameState gs = Ready;
	bool Running = true;


	while(Running)
	{
		switch (gs)
		{
		case Ready:
			cout << "Do you Wanna Play?(Y/N)" << endl;

			cin >> KeepPlay;

			switch (KeepPlay)
			{
			case 'Y':
				gs = Playing;
				Shuffle();
				system("cls");
				break;
			case 'N':
				Running = false;
				continue;
				break;
			default:
				system("cls");
				continue;
				break;
			}
			break;
		case Playing:
			cout << "FirstCard : " << GetEnumToCardMarkString(Cards[i].mark) + " " << Cards[i].number << endl;
			cout << "SecondCard is High(H) & Low(L)? " << endl;

			cin >> HighAndLow;

			switch (HighAndLow)
			{
			case 'H':
				break;
			case 'L':
				break;
			default:
				system("cls");
				continue;
				break;
			}

			system("cls");

			Result(Cards[i], Cards[i + 1], HighAndLow);

			gs = Ready;

			i++;
			break;
		default:
			break;
		}
	}
}