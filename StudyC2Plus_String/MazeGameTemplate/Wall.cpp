#include "Wall.h"
#include "SDL.h"

Wall::Wall()
{
	Init(0, 0);
}

Wall::Wall(int NewX, int NewY, std::string ImageName)
{
	Init(NewX, NewY);
	LoadBMP(ImageName);
}

Wall::~Wall()
{
}

void Wall::Init(int NewX, int NewY)
{
	Actor::Init(NewX, NewY);
	Shape = '*';
	Color.r = 0x80;
	Color.g = 0x3a;
	Color.b = 0x30;
	Color.a = 0xff;
	ZOrder = 1;
	bIsBlock = true;
}

void Wall::Render()
{
	Actor::Render();
}
