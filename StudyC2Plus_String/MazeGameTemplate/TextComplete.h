#pragma once
#include "TimerText.h"
class TextComplete : public TimerText
{
public:
	TextComplete(int NewX, int NewY, std::string NewText, int Size, int Time);
	virtual ~TextComplete() {}

	virtual void Tick() override;

	virtual void SetTimerProcess() override;
};

