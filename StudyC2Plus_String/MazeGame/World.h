#pragma once
#include <vector>
#include "SDL.h"
#include <memory>

class Actor;

class World
{
public:
	World();
	virtual ~World();

	void SpawnActor(std::shared_ptr<Actor> NewActor);
	void DestroyActor(std::shared_ptr<Actor> DestroyActor);

	void Tick();

	void Render();

	Uint64 GetWorldDeltaSeconds() { return DeltaSeconds; };

protected:
	std::vector<std::shared_ptr<Actor>> ActorList;

	Uint64 LastTick;
	Uint64 DeltaSeconds;
};

