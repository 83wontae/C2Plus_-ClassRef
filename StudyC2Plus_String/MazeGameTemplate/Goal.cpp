#include "Goal.h"

Goal::Goal()
{
	Init(0, 0);
}

Goal::Goal(int NewX, int NewY, std::string ImageName)
{
	Init(NewX, NewY);
	LoadBMP(ImageName);
}

Goal::~Goal()
{
}

void Goal::Init(int NewX, int NewY)
{
	Actor::Init(NewX, NewY);
	X = NewX;
	Y = NewY;
	Shape = 'G';
	Color.r = 0xff;
	Color.g = 0xff;
	Color.b = 0x00;
	Color.a = 0xff;
	ZOrder = 1;
}
