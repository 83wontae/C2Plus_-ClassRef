#pragma once
#include "TimerText.h"

class TextYouDied : public TimerText
{
public:
	TextYouDied(int NewX, int NewY, std::string NewText, int Size, int Time);
	virtual ~TextYouDied() {}

	virtual void Tick() override;

	virtual void SetTimerProcess() override;
};

