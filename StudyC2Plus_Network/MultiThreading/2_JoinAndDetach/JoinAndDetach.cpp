// https://www.youtube.com/watch?v=q3-5sDe6lzg&list=RDCMUCs6sf4iRhhE875T1QjG3wPQ&index=2

#include <iostream>
#include <thread>
#include <string>
using namespace std;
// ���� : join, detach, joinable
// join : thread�� ����� ������ main thread�� ���
// joinable : join�� �������� äũ
// detach : thread�� ��� ����

// * ���� thread�� �ι� join �Ǵ� detach�� �ϸ� termination(�۾� ����)
// * thread�� �����ϸ� �ݵ�� join �Ǵ� detach�� ȣ��
// - �ڿ� ���� ����
// - �������� ���� �ֱ� ����
// - �������� ��ȯ�� Ȱ��

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

	//t1.join();// t1 thread�� ����� ������ main thread�� ���

	if (t1.joinable())// join�� �������� äũ
		t1.detach();// t1 thread�� ��� ����

	//if(t1.joinable())// join�� �������� äũ
	//	t1.join();// ���� thread�� �ι� join�� �ϸ� termination(�۾� ����)
	cout << "join() after" << endl;

	this_thread::sleep_for(chrono::seconds(4));
}