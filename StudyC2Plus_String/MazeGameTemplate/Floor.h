#pragma once
#include "Actor.h"
#include <string>

class Floor : public Actor
{
public:
	Floor();
	Floor(int NewX, int NewY, std::string ImageName);
	virtual ~Floor();

	virtual void Tick() override { }

	virtual void Init(int NewX, int NewY) override;

};

