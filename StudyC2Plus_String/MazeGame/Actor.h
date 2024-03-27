#pragma once
#include "SDL.h"
#include <iostream>

class Actor
{
public:
	Actor();
	Actor(int NewX, int NewY);
	virtual ~Actor();

	virtual void Init(int NewX, int NewY);

	//순수 가상함수, 자식 클래스에서 무조건 재정의 해야 됨
	//인터페이스를 강제 하기 위해서 사용을 합니다.
	virtual void Tick() = 0;
	virtual void Render();
	virtual void BeginPlay();


	inline virtual void SetActorLocation(int NewX, int NewY);
	inline virtual int GetX() { return X; }
	inline virtual int GetY() { return Y; }

	void LoadBMP(std::string ImageName);

protected:
	int X;
	int Y;
	SDL_Color Color;
	SDL_Color ColorKey;//Alpha 처리 투명하게
	int TileSize = 64;

	SDL_Surface* Surface;
	SDL_Texture* Texture;
};

