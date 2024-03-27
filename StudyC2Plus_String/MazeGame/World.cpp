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
	//�ڷ� ���� Actor����Ʈ���� ���� ����Ʈ���� ����
	ActorList.erase(find(ActorList.begin(), ActorList.end(), DestroyActor));
	//�޸𸮿��� ������ ����
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