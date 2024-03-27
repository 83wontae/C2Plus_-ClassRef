#include <iostream>

using namespace std;

struct Storage
{
	int Potato;
	int Onion;
	int Carrot;

	// 함수 이름 : AddVege
	// 파라메타 : int a, int b, int c
	// 반환값 없음
	// 함수 기능 Potato에는 a 누적, Onion에는 b 누적, Carrot에는 c 누적
	void AddVege(int a, int b, int c)
	{
		Potato += a;
		Onion += b;
		Carrot += c;
	}

	// 함수 이름 : MinuesVege
	// 파라메타 : int a, int b, int c
	// 반환값 없음
	// 함수 기능 Potato에는 a 뺀다, Onion에는 b 뺀다, Carrot에는 c 뺀다 
	// Potato, Onion, Carrot 0보다 작아질수 없다
	void MinuesVege(int a, int b, int c)
	{
		Potato -= a;
		if (Potato < 0)
			Potato = 0;
		Onion -= b;
		if (Onion < 0)
			Onion = 0;
		Carrot -= c;
		if (Carrot < 0)
			Carrot = 0;
	}

	// 함수 이름 : MoveStorage
	// 파라메타 : Storage& target
	// 반환값 없음
	// 함수 기능 Storage& target의 채소들을 현재 구조체에 누적
	// Storage& target의 값은 전부 0으로 초기화 합니다.
	void MoveStorage(Storage& target)
	{
		Potato += target.Potato;
		Onion += target.Onion;
		Carrot += target.Carrot;
		target.Potato = 0;
		target.Onion = 0;
		target.Carrot = 0;
	}

	bool Tick()
	{
		int Order = 0;
		int a, b, c = { 0 };
		cout << "감자 : " << Potato << " 양파 : " << Onion << " 당근 : " << Carrot << endl;
		cout << "0) 창고 선택으로 돌아갑니다." << endl;
		cout << "1) 창고에 채소를 넣습니다." << endl;
		cout << "2) 창고에 채소를 꺼냅니다." << endl;
		cin >> Order;
		switch (Order)
		{
		case 0:
			return true; // TargetStorage 변경 처리
			break;
		case 1:
			cout << "감자 양파 당근 순서대로 넣을 채소 수량를 입력하세요." << endl;
			cin >> a >> b >> c;
			AddVege(a, b, c);
			break;
		case 2:
			cout << "감자 양파 당근 순서대로 꺼낼 채소 수량를 입력하세요." << endl;
			cin >> a >> b >> c;
			MinuesVege(a, b, c);
			break;
		}
		return false;
	}
};

int main()
{
	Storage s1 = { 50, 50, 50 };
	Storage s2 = { 100, 100, 100 };
	int TargetStorage = 0;
	int Order = 0;

	while (true)
	{
		system("cls");
		switch (TargetStorage)
		{
		case 1:
		{
			cout << "s1 창고 입니다." << endl;
			bool result = s1.Tick();
			if (result)
				TargetStorage = 0;
		}
		break;

		case 2:
		{
			cout << "s2 창고 입니다." << endl;
			bool result = s2.Tick();
			if (result)
				TargetStorage = 0;
		}
		break;

		default:
			cout << "1) s1 창고" << endl;
			cout << "2) s2 창고" << endl;
			cin >> TargetStorage;
			break;
		}
	}





	// 숫자 하나를 입력 받아서 
	int a, b, c = 0;
	cin >> a >> b >> c;

	// s2에 채소를 s1으로 옴긴다.
	s1.MoveStorage(s2);
	cout << "Potato = " << s1.Potato << endl;
	cout << "Onion = " << s1.Onion << endl;
	cout << "Carrot = " << s1.Carrot << endl;
	cout << "Potato = " << s2.Potato << endl;
	cout << "Onion = " << s2.Onion << endl;
	cout << "Carrot = " << s2.Carrot << endl;
}