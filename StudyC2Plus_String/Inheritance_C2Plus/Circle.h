#pragma once
#include <iostream>

using namespace std;

class Circle
{
public:
	Circle();
	~Circle();

	virtual void print() {
		cout << name << endl;
	}

	char name[100];

	int mX, mY;
	double mRadius;
};