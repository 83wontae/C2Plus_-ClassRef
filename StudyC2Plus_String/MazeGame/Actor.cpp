#include "Actor.h"
#include <iostream>
#include "MyEngine.h"

Actor::Actor()
{
	Init(0, 0);
}

Actor::Actor(int NewX, int NewY)
{
	Init(NewX, NewY);
}

Actor::~Actor()
{
}


void Actor::Render()
{
	//static ¸â¹ö ÇÔ¼ö
	//Util::GotoXY(GetX(), GetY());
	//std::cout << GetShape() << std::endl;

	if (Surface && Texture)
	{
		SDL_Rect SrcRect = { 0, 0, Surface->w, Surface->h };
		SDL_Rect DestRect = { GetX() * TileSize, GetY() * TileSize, TileSize, TileSize };

		SDL_RenderCopy(MyEngine::GetRenderer(), Texture, &SrcRect, &DestRect);
	}
	else
	{
		SDL_SetRenderDrawColor(MyEngine::GetRenderer(), Color.r, Color.g, Color.b, Color.a);
		SDL_Rect Rect = { GetX() * TileSize, GetY() * TileSize, TileSize, TileSize };

		SDL_RenderFillRect(MyEngine::GetRenderer(), &Rect);
	}

}

void Actor::BeginPlay()
{
}

inline void Actor::SetActorLocation(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
}

void Actor::Init(int NewX, int NewY)
{
	SetActorLocation(NewX, NewY);

	Surface = nullptr;
	Texture = nullptr;

	Color = SDL_Color();

	ColorKey.r = 255;
	ColorKey.g = 255;
	ColorKey.b = 255;
	ColorKey.a = 255;
}

void Actor::LoadBMP(std::string ImageName)
{
	//RAM
	Surface = SDL_LoadBMP(ImageName.c_str());
	//ColorKey
	SDL_SetColorKey(Surface, 1, SDL_MapRGB(Surface->format, ColorKey.r, ColorKey.g, ColorKey.b));

	//GPU VRAM
	Texture = SDL_CreateTextureFromSurface(MyEngine::GetRenderer(), Surface);
}