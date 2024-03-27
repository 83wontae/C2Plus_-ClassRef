#include "Initialize.h"
#include "Common.h"

void Initialize()
{
	//카드 정보 넣어주기
	//0번--> 크1, 크2, 크3, 크4, 크5, 크6, 크7, 크8, 크9, 크10, 크11, 크12, 크13
	// 하1, 하2, 하3, 하4, 하5, 하6, 하7, 하8, 하9, 하10, 하11, 하12, 하13
	// 다1, 다2, 다3, 다4, 다5, 다6, 다7, 다8, 다9, 다10, 다11, 다12, 다13	
	// 스1, 스2, 스3, 스4, 스5, 스6, 스7, 스8, 스9, 스10, 스11, 스12, 스13<--51번
	for (int i = 0; i < 52; ++i)
	{
		int j = i / 13;
		switch (j)
		{
		case 0:
			cards[i].mark = Clover;
			break;
		case 1:
			cards[i].mark = Heart;
			break;
		case 2:
			cards[i].mark = Dia;
			break;
		case 3:
			cards[i].mark = Spade;
			break;
		}

		cards[i].number = (i % 13) + 1;
	}
}