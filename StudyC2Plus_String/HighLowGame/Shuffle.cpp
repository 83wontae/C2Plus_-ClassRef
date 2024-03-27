#include "Shuffle.h"
#include <iostream>
#include "Common.h"
#include <random>

void Shuffle()
{
	// ī�� ����
	srand((unsigned int)time(NULL));
	// mt19937 ���� ����
	std::random_device rd;
	std::mt19937 mt(rd.entropy());//�õ� �� ���� ���� ����� �������ʴ� ���� �Ϻ��� ����� ����
	//std::mt19937 mt(1234);//seed ��
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