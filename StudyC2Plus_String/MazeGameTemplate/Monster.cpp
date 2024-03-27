#include "Monster.h"
#include "MyEngine.h"
#include "World.h"
#include "Player.h"
#include "TextYouDied.h"
#include <memory>

Monster::Monster()
{
	Init(0, 0);
}

Monster::Monster(int NewX, int NewY, std::string ImageName)
{
	Init(NewX, NewY);
	LoadBMP(ImageName);
}

Monster::~Monster()
{
}

void Monster::Init(int NewX, int NewY)
{
	Actor::Init(NewX, NewY);
	Shape = 'E';
	Color.r = 0x81;
	Color.g = 0x18;
	Color.b = 0x82;
	Color.a = 0xff;

	ZOrder = 3;
	srand((unsigned int)time(nullptr));

	ElapseTime = 0;
	ProcessTime = 100;
}

void Monster::Tick()
{
	ElapseTime += MyEngine::GetWorld()->GetWorldDeltaSeconds();
	
	if (ProcessTime <= ElapseTime)
	{
		int Direction = rand() % 4;
		switch (Direction)
		{
		case 0:
			CanMove(X - 1, Y);
			break;
		case 1:
			CanMove(X + 1, Y);
			break;
		case 2:
			CanMove(X, Y - 1);
			break;
		case 3:
			CanMove(X, Y + 1);
			break;
		}

		ElapseTime = 0;
	}

	//isGameOver
	for (auto Object : MyEngine::GetWorld()->GetActorList())
	{
		//STL C++
		//Player* CheckPlayer = dynamic_cast<Player>(Object);
		//UE
		//Player* CheckPlayer = Cast<Player>(Object);
		std::shared_ptr<Player> CheckPlayer = std::dynamic_pointer_cast<Player>(Object);

		if (CheckPlayer)
		{
			if (Object->GetX() == X && Object->GetY() == Y)
			{
				//MyEngine::GetEngine()->Stop();
				GEngine->SpawnActor(std::make_shared<TextYouDied>(100, 200, "You Died!", 100, 3000));
				break;
			}
		}
	}
}


