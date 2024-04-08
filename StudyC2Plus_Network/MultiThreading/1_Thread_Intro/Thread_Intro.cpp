// https://www.youtube.com/watch?v=hCvc9y39RDw&list=RDCMUCs6sf4iRhhE875T1QjG3wPQ&start_radio=1&rv=hCvc9y39RDw&t=15

#include <iostream>
#include <thread>
#include <string>

// ���� : Thread ����
// C++11���� ���� std::thread �� �߰���
// �۾��ڸ� �߰��Ѵ�, �ڵ忡 �帧�� �߰��Ѵ�, ���ο� stack ������ �߰��Ѵ�

void func1(char c)
{
	for (int i = 0; i < 100; i++)
	{
		std::cout << c;
	}
}

class CBase {
public:
	void operator()(std::string s) {
		std::cout << s << std::endl;
	}

	void run(std::string s) {
		std::cout << s << std::endl;
	}

	static void static_run(std::string s) {
		std::cout << s << std::endl;
	}
};

int main()
{
	std::cout << " Start Progream " << std::endl;

	// 1. Function Pointer
	std::thread t1(func1, '+');
	std::thread t2(func1, '-');

	// 2. Lambda Function
	auto lambda_func = [](std::string s) {
		std::cout << s << std::endl;
		};

	std::thread t3(lambda_func, " lambda thread1 ");
	std::thread t4([](std::string s) {
		std::cout << s << std::endl;
		}, " lambda thread2 ");

	// 3. Functor (Function Object)
	std::thread t5((CBase()), " Functor thread ");

	// 4. Non-static member Function
	CBase b;
	std::thread t6(&CBase::run, &b, " Non-static Member thread ");

	// 5. Static member Function
	std::thread t7(&CBase::static_run, " Static Member thread ");

	// �������� �����带 ���ÿ� ���� �����ϸ� � �����尡 ���� ��������� �˼� ����.
	t1.join();// t1 thread�� ����� ������ main thread�� ����Ų��.
	t2.join();// t2 thread�� ����� ������ main thread�� ����Ų��.
	t3.join();// t3 thread�� ����� ������ main thread�� ����Ų��.
	t4.join();// t4 thread�� ����� ������ main thread�� ����Ų��.
	t5.join();// t5 thread�� ����� ������ main thread�� ����Ų��.
	t6.join();// t6 thread�� ����� ������ main thread�� ����Ų��.
	t7.join();// t7 thread�� ����� ������ main thread�� ����Ų��.

	std::cout << " End Progream " << std::endl;
}