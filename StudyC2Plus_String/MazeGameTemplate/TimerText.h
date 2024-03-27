#pragma once
#include "Text.h"
class TimerText :  public Text
{
public:
	TimerText() {}
	TimerText(int NewX, int NewY, std::string NewText, int Size);
	virtual ~TimerText();

	virtual void Tick() override;

	virtual void SetTimerProcess();

protected:
	Uint64 ElapseTime;
	Uint64 ProcessTime;
};

