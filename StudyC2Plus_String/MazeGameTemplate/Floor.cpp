#include "Floor.h"

Floor::Floor()
{
	Init(0, 0);
}

Floor::Floor(int NewX, int NewY, std::string ImageName)
{
	Init(NewX, NewY);
	LoadBMP(ImageName);
}

Floor::~Floor()
{
}

void Floor::Init(int NewX, int NewY)
{
	Actor::Init(NewX, NewY);
	Shape = ' ';
	Color.r = 0xE6;
	Color.g = 0xE6;
	Color.b = 0xE6;
	Color.a = 0xff;
	ZOrder = 0;
}
