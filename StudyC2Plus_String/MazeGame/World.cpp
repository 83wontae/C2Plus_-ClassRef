#include "World.h"
#include "Actor.h"
#include <algorithm>

World::World()
{
}

World::~World()
{
	for (auto CurrentActor : ActorList)
	{
		CurrentActor = nullptr;
	}

	ActorList.clear();
}

void World::SpawnActor(std::shared_ptr<Actor> NewActor)
{
	ActorList.push_back(NewActor);

	//sort(ActorList.begin(), ActorList.end(), Actor::Compare);
}

void World::DestroyActor(std::shared_ptr<Actor> DestroyActor)
{
	//자료 구조 Actor리스트에서 관리 리스트에서 삭제
	ActorList.erase(find(ActorList.begin(), ActorList.end(), DestroyActor));
	//메모리에서 실제로 삭제
	//delete DestroyActor;
	DestroyActor = nullptr;
}

void World::Tick()
{
	DeltaSeconds = SDL_GetTicks() - LastTick;

	for (auto SelectedActor : ActorList)
	{
		SelectedActor->Tick();
	}
}

void World::Render()
{
	for (auto SelectedActor : ActorList)
	{
		SelectedActor->Render();
	}

	LastTick = SDL_GetTicks();
}