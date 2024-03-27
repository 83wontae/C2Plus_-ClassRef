#include "Player.h"
#include "MyEngine.h"
#include "World.h"
#include "Goal.h"
#include "TextComplete.h"

Player::Player()
{
	Init(0, 0);	
}

Player::Player(int NewX, int NewY, std::string ImageName)
{
	Init(NewX, NewY);
	LoadBMP(ImageName);
}

Player::~Player()
{
}

void Player::Init(int NewX, int NewY)
{
	Actor::Init(NewX, NewY);
	Shape = 'P';
	Color.r = 0xff;
	Color.g = 0x00;
	Color.b = 0x00;
	Color.a = 0xff;

	ZOrder = 2;

	Surface = nullptr;
	Texture = nullptr;

	ColorKey.r = 255;
	ColorKey.g = 0;
	ColorKey.b = 255;

	ElapseTime = 0;
	ProcessTime = 500;

	SpriteIndex = 0;
	SpriteDirection = 0;
}

void Player::Tick()
{
	ElapseTime += MyEngine::GetWorld()->GetWorldDeltaSeconds();

	if (ElapseTime >= ProcessTime)
	{
		SpriteIndex++;
		SpriteIndex = SpriteIndex % 5;
		ElapseTime = 0;
	}

	if (MyEngine::GetEvent().type == SDL_KEYDOWN)
	{
		switch (MyEngine::GetEvent().key.keysym.sym)
		{
		case SDLK_LEFT:
			if (CanMove(X - 1, Y))
			{
				CheckGoal();
			}
			SpriteDirection = 0;
			break;
		case SDLK_RIGHT:
			if (CanMove(X + 1, Y))
			{
				CheckGoal();
			}
			SpriteDirection = 1;
			break;
		case SDLK_UP:
			if (CanMove(X, Y - 1))
			{
				CheckGoal();
			}
			SpriteDirection = 2;
			break;
		case SDLK_DOWN:
			if (CanMove(X, Y + 1))
			{
				CheckGoal();
			}
			SpriteDirection = 3;
			break;
		}
	}
}

void Player::Render()
{
	int SpriteWidth = Surface->w / 5;
	int SpriteHeight = Surface->h / 5;
	int SpriteIndexX = SpriteIndex;
	int SpriteIndexY = SpriteDirection;
	int StartX = SpriteWidth * SpriteIndexX;
	int StartY = SpriteHeight * SpriteIndexY;
	SDL_Rect SrcRect = { StartX, StartY, SpriteWidth, SpriteHeight };
	SDL_Rect DestRect = { GetX() * TileSize, GetY() * TileSize, TileSize, TileSize };

	SDL_RenderCopy(MyEngine::GetRenderer(), Texture, &SrcRect, &DestRect);
}

void Player::CheckGoal()
{
	for (auto Object : MyEngine::GetWorld()->GetActorList())
	{
		std::shared_ptr<Goal> CheckGoal = std::dynamic_pointer_cast<Goal>(Object);

		if (CheckGoal)
		{
			if (Object->GetX() == X && Object->GetY() == Y)
			{
				GEngine->SpawnActor(std::make_shared<TextComplete>(100, 200, "Complete", 100, 3000));
				break;
			}
		}
	}
}

