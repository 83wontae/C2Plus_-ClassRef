#include "TimerText.h"
#include "MyEngine.h"
#include "World.h"

TimerText::TimerText(int NewX, int NewY, std::string NewText, int Size)
{
	Init(NewX, NewY, Size);
	SetText(NewText);

	ElapseTime = 0;
	ProcessTime = 3000;
}

TimerText::~TimerText()
{
}

void TimerText::Tick()
{
	Text::Tick();

	ElapseTime += GEngine->GetWorld()->GetWorldDeltaSeconds();

	if (ElapseTime >= ProcessTime)
	{
		SetTimerProcess();
	}
}

void TimerText::SetTimerProcess()
{
}
