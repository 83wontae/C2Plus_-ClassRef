#include "Result.h"

void Result(stCard First, stCard Second, char HighAndLow)
{
	int FirstPoint = First.number * 10 + First.mark;
	int SecondPoint = Second.number * 10 + Second.mark;

	cout << "FirstCard : " << GetEnumToCardMarkString(First.mark) << " " << First.number << endl;
	cout << "SecondCard : " << GetEnumToCardMarkString(Second.mark) << " " << Second.number << endl;

	if (FirstPoint < SecondPoint)
	{
		switch (HighAndLow)
		{
		case 'H':
			cout << "Chose=" << HighAndLow << endl;
			cout << "You Win" << endl;
			break;
		case 'L':
			cout << "Chose=" << HighAndLow << endl;
			cout << "You Lose" << endl;
			break;
		}
	}
	else
	{
		switch (HighAndLow)
		{
		case 'H':
			cout << "Chose=" << HighAndLow << endl;
			cout << "You Lose" << endl;
			break;
		case 'L':
			cout << "Chose=" << HighAndLow << endl;
			cout << "You Win" << endl;
			break;
		}
	}

}
