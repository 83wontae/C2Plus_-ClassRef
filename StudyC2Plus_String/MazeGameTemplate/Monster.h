#pragma once
#include "Actor.h"
class Monster : public Actor
{
public:
	Monster();
	Monster(int NewX, int NewY, std::string ImageName);
	virtual ~Monster();
	virtual void Init(int NewX, int NewY) override;

	virtual void Tick() override;

	Uint64 ElapseTime;
	Uint64 ProcessTime;
};

