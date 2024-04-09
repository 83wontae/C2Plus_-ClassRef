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

int myAccount = 0;
std::mutex m;

void addMoney(char c)
{
	for (int i = 0; i < 100; ++i)
	{
		if (m.try_lock()) {
			myAccount = myAccount + 1;
			m.unlock();
		}

		char str[100];
		sprintf_s(str, sizeof(str), "%c myAccount : %d\n", c, myAccount);
		cout << str;
		this_thread::sleep_for(chrono::milliseconds(10));
	}
}

int main()
{
	std::thread t1(addMoney, 'A');
	std::thread t2(addMoney, 'B');

	t1.join();
	t2.join();

	cout << "myAccount : " << myAccount << endl;
}