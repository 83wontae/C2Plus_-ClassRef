
#include "Text.h"
#include "MyEngine.h"

Text::Text(int NewX, int NewY, std::string NewText, int Size)
{
	Init(NewX, NewY, Size);
	SetText(NewText);
}

Text::~Text()
{
}

void Text::Init(int NewX, int NewY, int Size)
{
	Shape = ' ';

	bIsBlock = false;
	SetActorLocation(NewX, NewY);

	Surface = nullptr;
	Texture = nullptr;

	ZOrder = 100;
	Color = SDL_Color{ 255, 0, 0, 255 };

	ColorKey.r = 255;
	ColorKey.g = 255;
	ColorKey.b = 255;
	ColorKey.a = 255;

	FontSize = Size;

	Font = nullptr;
	Font = TTF_OpenFont("c:\\windows\\Fonts\\gulim.ttc", FontSize);
}

void Text::SetText(std::string NewText)
{
	Content = NewText;
	Surface = TTF_RenderText_Solid(Font, Content.c_str(), Color);
	Texture = SDL_CreateTextureFromSurface(MyEngine::GetRenderer(), Surface);
}

void Text::Render()
{
	int Width = Surface->w;
	int Height = Surface->h;

	SDL_QueryTexture(Texture, NULL, NULL, &Width, &Height);

	SDL_Rect DestRect = { X, Y, Width, Height };

	SDL_RenderCopy(MyEngine::GetRenderer(), Texture, NULL, &DestRect);
}
