#pragma once
#include "Actor.h"
#include "SDL.h"

class Player : public Actor
{
public:
	Player();
	Player(int NewX, int NewY, std::string ImageName);
	virtual ~Player();

	virtual void Init(int NewX, int NewY) override;

	virtual void Tick() override;

	virtual void Render() override;

	void CheckGoal();

protected:
	Uint64 ElapseTime;
	Uint64 ProcessTime;
	int SpriteIndex;
	int SpriteDirection;
};

