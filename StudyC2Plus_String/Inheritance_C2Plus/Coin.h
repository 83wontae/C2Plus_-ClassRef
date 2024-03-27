#pragma once
#include "Circle.h"

class Coin : public Circle
{
public:
	Coin();
	~Coin();

	virtual void print() override {
		__super::print();
		//cout << name << " price = " << price << endl;
		cout << "price = " << price << " color = " << color << endl;
	}

	int price;
	int color;
};

