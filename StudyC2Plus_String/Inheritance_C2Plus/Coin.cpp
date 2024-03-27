#include "Coin.h"
#include <iostream>

Coin::Coin(): price(0), color(0)
{
	strcpy_s(name, "coin");
}

Coin::~Coin()
{
}
