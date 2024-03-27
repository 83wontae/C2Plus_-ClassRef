#include "Floor.h"

Floor::Floor()
{
	Actor::Init(0, 0);
}

Floor::Floor(int NewX, int NewY, std::string ImageName)
{
	Actor::Init(NewX, NewY);
	LoadBMP(ImageName);
}

Floor::~Floor()
{
}