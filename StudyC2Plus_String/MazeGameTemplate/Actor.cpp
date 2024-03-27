#include "Actor.h"
#include <iostream>
#include "Util.h"
#include "MyEngine.h"
#include "World.h"

Actor::Actor()
{
	Init(0, 0);
}

Actor::Actor(int NewX, int NewY)
{
	Init(NewX, NewY);
}

void Actor::Init(int NewX, int NewY)
{
	Shape = ' ';

	bIsBlock = false;
	SetActorLocation(NewX, NewY);

	Surface = nullptr;
	Texture = nullptr;

	ZOrder = 0;
	Color = SDL_Color();

	ColorKey.r = 255;
	ColorKey.g = 255;
	ColorKey.b = 255;
	ColorKey.a = 255;
}



Actor::~Actor()
{
	if (Surface)
	{
		SDL_FreeSurface(Surface);
		Surface = nullptr;
	}

	if (Texture)
	{
		SDL_DestroyTexture(Texture);
		Texture = nullptr;
	}
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

inline void Actor::SetShape(char NewShape)
{
	Shape = NewShape;
}

bool Actor::CanMove(int FutureX, int FutureY)
{
	auto ActorList = MyEngine::GetWorld()->GetActorList();

	for (auto CheckActor : ActorList)
	{
		if (CheckActor->GetX() == FutureX && CheckActor->GetY() == FutureY &&
			CheckActor->bIsBlock)
		{
			return false;
		}
	}

	X = FutureX;
	Y = FutureY;

	return true;
}

void Actor::LoadBMP(std::string ImageName)
{
	//RAM
	Surface = SDL_LoadBMP(ImageName.c_str());
	//ColorKey
	SDL_SetColorKey(Surface, 1, SDL_MapRGB(Surface->format, ColorKey.r, ColorKey.g, ColorKey.b));

	//GPU VRAM
	Texture = SDL_CreateTextureFromSurface(MyEngine::GetRenderer(),
		Surface);
}
