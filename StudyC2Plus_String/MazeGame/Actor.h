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

	//���� �����Լ�, �ڽ� Ŭ�������� ������ ������ �ؾ� ��
	//�������̽��� ���� �ϱ� ���ؼ� ����� �մϴ�.
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
	SDL_Color ColorKey;//Alpha ó�� �����ϰ�
	int TileSize = 64;

	SDL_Surface* Surface;
	SDL_Texture* Texture;
};

