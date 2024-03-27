#include "Shuffle.h"
#include <iostream>
#include "Common.h"
#include <random>

void Shuffle()
{
	// 카드 섞기
	srand((unsigned int)time(NULL));
	// mt19937 랜덤 엔진
	std::random_device rd;
	std::mt19937 mt(rd.entropy());//시드 값 별로 같은 결과가 나오지않는 거의 완벽에 가까운 랜덤
	//std::mt19937 mt(1234);//seed 값
	std::uniform_int_distribution<int> dist(0, 51);

	for (int i = 0; i < 52; i++)
	{
		int FirstNumber = dist(mt);
		int SecondNumber = dist(mt);

		stCard Temp = cards[FirstNumber];
		cards[FirstNumber] = cards[SecondNumber];
		cards[SecondNumber] = Temp;
	}
}