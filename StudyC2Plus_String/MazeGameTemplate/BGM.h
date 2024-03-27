#pragma once
#include "Actor.h"
#include "SDL_mixer.h"

class BGM : public Actor
{
public:
	BGM(std::string BGMName);
	virtual ~BGM();

	virtual void BeginPlay() override;
	virtual void Tick() override {} 
	virtual void Render() override {}

protected:
	Mix_Music* Music;
};

