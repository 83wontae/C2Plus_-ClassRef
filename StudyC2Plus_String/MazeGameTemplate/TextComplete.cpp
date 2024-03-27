#include "TextComplete.h"
#include "MyEngine.h"
#include "World.h"

TextComplete::TextComplete(int NewX, int NewY, std::string NewText, int Size, int Time)
{
	Init(NewX, NewY, Size);
	SetText(NewText);

	ElapseTime = 0;
	ProcessTime = Time;
}

void TextComplete::Tick()
{
	TimerText::Tick();
}

void TextComplete::SetTimerProcess()
{
	GEngine->UnloadLevel();
	GEngine->LoadLevel("level02.map");
}
