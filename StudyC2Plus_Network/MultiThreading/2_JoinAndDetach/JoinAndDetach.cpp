// https://www.youtube.com/watch?v=q3-5sDe6lzg&list=RDCMUCs6sf4iRhhE875T1QjG3wPQ&index=2

#include <iostream>
#include <thread>
#include <string>
using namespace std;
// 제목 : join, detach, joinable
// join : thread가 종료될 때까지 main thread를 대기
// joinable : join이 가능한지 채크
// detach : thread를 즉시 종료

// * 같은 thread를 두번 join 또는 detach을 하면 termination(작업 종료)
// * thread를 생성하면 반드시 join 또는 detach를 호출
// - 자원 누수 방지
// - 스레드의 생명 주기 관리
// - 스레드의 반환값 활용

void run(int count)
{
	while (count-- > 0)
	{
		cout << "Count" << count << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
}

int main()
{
	std::thread t1(run, 10);
	cout << "join() before" << endl;

	//t1.join();// t1 thread가 종료될 때까지 main thread를 대기

	if (t1.joinable())// join이 가능한지 채크
		t1.detach();// t1 thread를 즉시 종료

	//if(t1.joinable())// join이 가능한지 채크
	//	t1.join();// 같은 thread를 두번 join을 하면 termination(작업 종료)
	cout << "join() after" << endl;

	this_thread::sleep_for(chrono::seconds(4));
}