//https://www.youtube.com/watch?v=eZ8yKZo-PGw&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp&index=4

#include <iostream>
#include <thread>
#include <mutex>
#include <cstdio> // sprintf_s 포함 라이브러리
using namespace std;
// 제목 : Mutex
// Mutual Exclusion(상호 배제)
// 공유 불가능한 자원의 동시 사용을 피하기 위해 사용
// Race Condition(경쟁 조건)
// 
// x = x + 1			c++ code
// LDR reg, [x]	;		load value of x from memory
// ADD reg, reg, #1;	Increment ( x + 1 )
// STR reg, [x];		store x into memory
// 
// T1, T2에서 동시에 더하기 처리할시 동일한 값을 load 하기 때문에 문제가 발생

int X = 0, Y = 0;
std::mutex mX, mY;

void IncrementValue(int& value, std::mutex& m, const char* desc)
{
	for (int i = 0; i < 5; ++i)
	{
		m.lock();
		value = value + 1;
		m.unlock();

		char str[100];
		sprintf_s(str, sizeof(str), "%s = %d\n", desc, value);
		cout << str;
		this_thread::sleep_for(chrono::seconds(1));
	}
}

void consumeXY()
{
	int useCount = 5;
	int XplusY = 0;
	while (1) {
		int lockResult = std::try_lock(mX, mY);// 성공 : -1, 실패 : 0 또는 lock 실패한 mutex index number
		if (lockResult == -1)
		{
			if (X != 0 && Y != 0)
			{
				--useCount;
				XplusY += X + Y;
				X = Y = 0;

				char str[100];
				sprintf_s(str, sizeof(str), "XplusY = %d\n", XplusY);
				cout << str;
			}
			mX.unlock();
			mY.unlock();
			if (useCount <= 0) break;
		}
	}
}

int main()
{
	std::thread t1(IncrementValue, std::ref(X), std::ref(mX), "A");
	std::thread t2(IncrementValue, std::ref(Y), std::ref(mY), "B");
	std::thread t3(consumeXY);

	t1.join();
	t2.join();
	t3.join();
}