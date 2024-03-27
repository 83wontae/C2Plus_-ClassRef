#pragma once
#include "Actor.h"

class Wall : public Actor
{
public:
	Wall();
	Wall(int NewX, int NewY, std::string ImageName);
	virtual ~Wall();
	virtual void Init(int NewX, int NewY) override;
	virtual void Tick() override { }

	virtual void Render() override;
};

