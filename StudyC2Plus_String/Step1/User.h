#pragma once
#include "Counter.h"//class Counter

class User
{
public:
	void KillMonster()
	{
		//Counter.counting();//X
		m_Counter.counting();
	}

	Counter m_Counter;
};