#include "Card.h"

string GetEnumToCardMarkString(CardMark mark)
{
	switch (mark)
	{
	case Spade:
		return "Spade";
		break;
	case Dia:
		return "Dia";
		break;
	case Heart:
		return "Heart";
		break;
	case Clover:
		return "Clover";
		break;
	}

	return "";
}
