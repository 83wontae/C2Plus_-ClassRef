#include <iostream>

using namespace std;

//함수 이름 : standardWeight
//맴버 변수 : float height
//리턴 값 : float
//공식 : (height - 100) * 0.9
float standardWeight(float hegiht)
{
	return (hegiht - 100) * 0.9;
}

//함수 이름 : GetBMI
//맴버 변수 : float weight, float standardWeight
//리턴 값 : float
//공식 : (weight - standardWeight)  * 100 / standardWeight
float GetBMI(float weight, float standardWeight)
{
	return (weight - standardWeight) * 100 / standardWeight;
}

int main()
{
	/*
	//초를 입력받아 시 / 분 / 초의 형태로 나타내시오.
	int gSec = 0;
	cin >> gSec;

	int hour = gSec / 3600;
	int min = gSec / 60 % 60;
	int sec = gSec % 60;

	cout << hour << "시 " << min << "분 " << sec << "초" << endl;
	*/

	float weight, height;
	cin >> weight >> height;

	//standardWeight, GetBMI를 사용해서 bmi를 구하기
	float bmi = GetBMI(weight, standardWeight(height));

	/*
	*	bmi에 따른 등급 판정
		등급	비만도 수치
		10이하				정상
		10초과 20이하	과체중
		20 초과			비만
	*/
	cout << "bmi = "  << int(bmi) << endl;
	if (10 >= bmi)
	{
		cout << "정상" << endl;
	}
	else if (20 >= bmi && bmi > 10)
	{
		cout << "과체중" << endl;
	}
	else// 나머지 값은 20 초과 일수 밖에 없다
	{
		cout << "비만" << endl;
	}

	// 낮은 숫자 순서대로 출력
	int arr[10] = { 10, 3, 76, 54, 42, 13, 34, 28, 99, 7 };

	for (int i = 0; i < 10; ++i)
	{
		int lowest = i;
		for (int j = i+1; j < 10; ++j)
		{
			if (arr[lowest] > arr[j])
				lowest = j;
		}

		int temp = arr[lowest];
		arr[lowest] = arr[i];
		arr[i] = temp;
	}

	for (int itr : arr)
	{
		cout << itr << " ";
	}
}