#pragma once
#include "Actor.h"
#include "SDL_ttf.h"

class Text : public Actor
{
public:
	Text() {}
	Text(int NewX, int NewY, std::string NewText, int Size);
	virtual ~Text();

	void Init(int NewX, int NewY, int Size);

	void SetText(std::string NewText);
	virtual void Render() override;

	virtual void Tick() override {}

	std::string Content;

protected:
	TTF_Font* Font;
	int FontSize;
};

