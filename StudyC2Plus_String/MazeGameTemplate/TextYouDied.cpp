#include "TextYouDied.h"
#include "MyEngine.h"
#include "World.h"

TextYouDied::TextYouDied(int NewX, int NewY, std::string NewText, int Size, int Time)
{
	Init(NewX, NewY, Size);
	SetText(NewText);

	ElapseTime = 0;
	ProcessTime = Time;
}

void TextYouDied::Tick()
{
	TimerText::Tick();
}

void TextYouDied::SetTimerProcess()
{
	GEngine->Stop();
}
