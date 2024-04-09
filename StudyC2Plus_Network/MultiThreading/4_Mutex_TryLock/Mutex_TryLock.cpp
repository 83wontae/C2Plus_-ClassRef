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