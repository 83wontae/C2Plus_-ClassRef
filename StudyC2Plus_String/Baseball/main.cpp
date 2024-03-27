#include <iostream>

using namespace std;

int main()
{
	int a[3] = { 1, 2, 3 };
	int b[3] = { 0 };

	while (1)
	{
		cin >> b[0] >> b[1] >> b[2];

		system("cls");

		//스트라이크 갯수 구하기
		int cntS = 0;
		int cntB = 0;
		for (int i = 0; i < 3; ++i)
		{
			if (a[i] == b[i])
			{
				cntS++;
			}

			for (int j = 0; j < 3; ++j)
			{
				if (i == j)
					continue; // 아래쪽 코드를 진행하지 않고, 다음 for문을 실행한다.

				if (a[i] == b[j])
				{
					cntB++;
					break; // for문의 실행을 중단 시킨다.
				}
			}
		}
		cout << endl;

		//결과 출력
		if (cntS == 0 && cntB == 0)
		{
			cout << "OUT" << endl;
		}
		else if (cntS == 3)
		{
			cout << "Homerun" << endl;
		}
		else
		{
			cout << "S : " << cntS << " B : " << cntB << endl;
		}
	}
}