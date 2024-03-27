#pragma once
#include "SDL.h"
#include <iostream>

class Actor
{
public:
	//오버로딩, 생성자 오버로딩
	Actor();
	Actor(int NewX, int NewY);

	virtual void Init(int NewX, int NewY);


	virtual ~Actor();

	//순수 가상함수, 자식 클래스에서 무조건 재정의 해야 됨
	//인터페이스를 강제 하기 위해서 사용을 합니다.
	virtual void Tick() = 0; 
	virtual void Render();
	virtual void BeginPlay();
	
	inline virtual void SetActorLocation(int NewX, int NewY);
	inline virtual void SetShape(char NewShape);
	inline virtual char GetShape() { return Shape; }
	inline virtual int GetX() { return X; }
	inline virtual int GetY() { return Y; }

	bool operator <(Actor& RHS)
	{
		return this->ZOrder < RHS.ZOrder;
	}

	inline static bool Compare(std::shared_ptr<Actor> LHS, std::shared_ptr<Actor> RHS)
	{
		return LHS->ZOrder < RHS->ZOrder;
	}

	bool CanMove(int FutureX, int FutureY);

	void LoadBMP(std::string ImageName);

protected:
	int X;
	int Y;
	char Shape;
	SDL_Color Color;
	SDL_Color ColorKey;
	int TileSize = 64;

	int ZOrder;

	SDL_Surface* Surface;
	SDL_Texture* Texture;


public:
	bool bIsBlock;
};

