#include <iostream>
#include "Card.h"
#include "Common.h"
#include "Initialize.h"
#include "Shuffle.h"

/*
1. 52개의 카드를 가지고 시작
2. 게임이 시작되면 카드 하나를 오픈
3. 플레이어는 다음카드가
오픈된 카드보다 높은 카드인지
낮은 카드인지에 대하여 배팅을 한다
4. 선택 맞다면 승리 틀리면 패배
5. 카드는 1이 가장 낮고 K가 가장 높다
6. 문양은 스페이트 > 다이아 > 하트 > 클로버
순으로 높다.
*/

using namespace std;

// 함수이름 : CompareCard
// 파라메타 : const stCard& CardA, const stCard& CardB
// 반환값 : bool
// 함수기능 : CardA와 CardB를 비교하여 CardA가 크다면 true 작으면 false 반환
bool CompareCard(const stCard& CardA, const stCard& CardB)
{
	// CardA와 CardB를 비교하여 CardA가 크다면 true 작으면 false 반환
	// 위와 같이 출력한다.
	// (크기 비교 조건) Number : 1 ~ 13 숫자가 높을수록 높은 카드
	// (크기 비교 조건) Number가 같다면 
	// 스페이트 > 다이아 > 하트 > 클로버 순으로 높을수록 높은 카드
	int CardAScore = CardA.number * 10 + CardA.mark;
	int CardBScore = CardB.number * 10 + CardB.mark;
	// if (CardA.number * 10 + CardA.mark > CardB.number * 10 + CardB.mark) {
	if (CardAScore > CardBScore) {
		return true;
	}
	else {
		return false;
	}
}

// 함수이름 : GameResult
// 파라메타 : 
// const stCard& CardA = 비교할 stCard형 변수 
// const stCard& CardB = 비요할 stCard형 변수
// const char& chChoose = 선택한 문자
// 반환값 : 없음
// 함수기능 
// chChoose가 'H'고 (CardB > CardA) 이면 "승리" 출력 아니면 "패배" 출력
// chChoose가 'L'고 (CardB < CardA) 이면 "승리" 출력 아니면 "패배" 출력
void GameResult(const stCard& CardA, const stCard& CardB, const char& chChoose, 
	int& money, const int& beatMoney)
{
	switch (chChoose)
	{
	case 'H':
		if (CompareCard(CardA, CardB)) {
			cout << "패배" << endl;
		}
		else {
			cout << "승리" << endl;
			money += beatMoney * 2;
		}
		break;
	case 'L':
		if (CompareCard(CardA, CardB)) {
			cout << "승리" << endl;
			money += beatMoney * 2;
		}
		else {
			cout << "패배" << endl;
		}
		break;
	}

}

enum EnGameState
{
	Ready = 0,
	Beating,
	Playing
};

void main()
{
	int money = 10000;
	int beatMoney = 0;
	// 배팅하는 기능을 추가해 봅시다.
	// Ready에서 'Y'를 입력하면 Beating으로 진행한다.
	// "얼마를 배팅하시겠습니까?"라고 텍스트 출력합니다.
	// 배팅할 금액을 입력 합니다.
	// 승리시 배팅 금액에 2배를 money에 추가 , 패배시 배팅 금액을 money에서 차감

	Initialize(); // 카드 52장의 정보를 넣어준다.
	bool IsPlaying = true;
	EnGameState gs = Ready;
	
	while (IsPlaying)
	{
		switch (gs)
		{
		case Ready:
			cout << "소지금 : " << money << endl;
			cout << "게임을 플레이 하시겠습니까?(Y/N)" << endl;
			char chPlaying;
			cin >> chPlaying;
			switch (chPlaying)
			{
			case 'Y':
				gs = Beating;
				system("cls");
				break;
			case 'N':
				IsPlaying = false;
				break;
			default:
				break;
			}
			break;

		case Beating:
			cout << "소지금 : " << money << endl;
			cout << "얼마를 배팅하시겠습니까?" << endl;
			cin >> beatMoney;
			money -= beatMoney;
			gs = Playing;
			break;

		case Playing:
			Shuffle(); // 카드를 섞는다.

			// 0번 카드 출력
			cout << "첫번째 카드 : ";
			cards[0].printCard();
			cout << "put 'H' or 'L'?";
			char chChoose = ' ';
			cin >> chChoose;

			GameResult(cards[0], cards[1], chChoose, money, beatMoney);

			cout << "두번째 카드 : ";
			cards[1].printCard();
			gs = Ready;
			break;
		}
	}
}