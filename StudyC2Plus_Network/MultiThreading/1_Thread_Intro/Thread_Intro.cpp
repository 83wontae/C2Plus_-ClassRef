// https://www.youtube.com/watch?v=hCvc9y39RDw&list=RDCMUCs6sf4iRhhE875T1QjG3wPQ&start_radio=1&rv=hCvc9y39RDw&t=15

#include <iostream>
#include <thread>
#include <string>

// 제목 : Thread 생성
// C++11에서 부터 std::thread 가 추가됨
// 작업자를 추가한다, 코드에 흐름을 추가한다, 새로운 stack 공간을 추가한다

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

	// 여러개의 쓰레드를 동시에 같이 생성하면 어떤 쓰레드가 먼저 실행될지는 알수 없다.
	t1.join();// t1 thread가 종료될 때까지 main thread를 대기시킨다.
	t2.join();// t2 thread가 종료될 때까지 main thread를 대기시킨다.
	t3.join();// t3 thread가 종료될 때까지 main thread를 대기시킨다.
	t4.join();// t4 thread가 종료될 때까지 main thread를 대기시킨다.
	t5.join();// t5 thread가 종료될 때까지 main thread를 대기시킨다.
	t6.join();// t6 thread가 종료될 때까지 main thread를 대기시킨다.
	t7.join();// t7 thread가 종료될 때까지 main thread를 대기시킨다.

	std::cout << " End Progream " << std::endl;
}