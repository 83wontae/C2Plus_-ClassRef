//https://www.youtube.com/watch?v=eZ8yKZo-PGw&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp&index=4

#include <iostream>
#include <thread>
#include <mutex>
#include <cstdio> // sprintf_s ���� ���̺귯��
using namespace std;
// ���� : Mutex
// Mutual Exclusion(��ȣ ����)
// ���� �Ұ����� �ڿ��� ���� ����� ���ϱ� ���� ���
// Race Condition(���� ����)
// 
// x = x + 1			c++ code
// LDR reg, [x]	;		load value of x from memory
// ADD reg, reg, #1;	Increment ( x + 1 )
// STR reg, [x];		store x into memory
// 
// T1, T2���� ���ÿ� ���ϱ� ó���ҽ� ������ ���� load �ϱ� ������ ������ �߻�

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
		int lockResult = std::try_lock(mX, mY);// ���� : -1, ���� : 0 �Ǵ� lock ������ mutex index number
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