#include "BGM.h"

BGM::BGM(std::string BGMName)
{
	Music = Mix_LoadMUS(BGMName.c_str());
}

BGM::~BGM()
{
	Mix_FreeMusic(Music);
}

void BGM::BeginPlay()
{
	Mix_PlayMusic(Music, -1);
}
