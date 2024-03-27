#include <stdio.h>

// c++ 의 컴파일
// c++에서 사람이 작성한 소스코드를 컴퓨터가 읽을수 있는 코드로 변환하여 실행할수 있는 파일로 변환하는 과정

// 1. 전처리(Preprocessing) 단계 : #include 와 #define 과 같은 전처리기 매크로들을 처리하는 단계
// 2. 컴파일(Compile) 단계 : 각각의 소스 파일들을 어셈블리 명령어로 변환
// 3. 어셈블(Assemble) 단계 : 어셈블리 코드들을 실제 기계어로 이루어진 목적 코드(Object file)로 변환하는 단계
// 4. 링킹(Linking) 단계 : 각각의 목적 코드들을 한데 모아서 하나의 실행 파일을 생성하는 단계

// 메모리 영역
// 1. Code 영역 : 실행할 코드가 저장되어있는 영역(기계어로 존재)
// 2. Data 영역 : 전역변수, Static 변수들이 저장, 프로세스가 종료될때 까지 메모리에 저장됨
// 3. Stack 영역 : 지역변수, 매개변수들이 저장, 함수가 호출되면 생성되고 함수가 종료되면 시스템에 반환
// 4. Heap 영역 : malloc 또는 new 함수에 의해서 동적으로 할당되는 영역, malloc() 또는 new 연산자로 할당, free() 또는 delete 연사자로 해제

int g_money = 0;//전역 변수

static int s_money = 0;

#include "money.h"
#include "calcFunc.h"

struct fruitShop
{
	// 구조체 내부 선언한 변수는 구조체 사라지지 않으면 안 사라진다.
	int index;
	int appleA;
	int mangoA;
	int strawberryA;

	// 구조체 생성자 ":"이 구문 오른쪽에 변수에 초기값을 셋팅한다.
	fruitShop() : index(0), appleA(1000), mangoA(1000), strawberryA(1000)
	{

	}

	// 구조체에 함수 생성
	void SetFruitValue(int apple, int mange, int strawberry)
	{
		int appleB = apple;// SetFruitValue 함수가 종료되면 사라진다.
		appleA = apple;
		mangoA = mange;
		strawberryA = strawberry;
	}

	void printShopValue()
	{
		printf("%d번째 과일가게 가격 사과:%d, 망고:%d, 딸기:%d\n", index, appleA, mangoA, strawberryA);
	}
};

struct PhoneShop
{
	int iPhone;
	int zFlip;
	int GalaxyS23;
	int GalaxyFold;

	PhoneShop()
	{
		iPhone = 0;
		zFlip = 0;
		GalaxyS23 = 0;
		GalaxyFold = 0;
	}
	
	void setPhoneValue(int niPhone, int nzFlip, int nGalaxyS23, int nGalaxyFold)
	{
		iPhone = niPhone;
		zFlip = nzFlip;
		GalaxyS23 = nGalaxyS23;
		GalaxyFold = nGalaxyFold;
	}

	void printShopValue()
	{
		printf("핸드폰가게 가격 아이폰:%d, 플립:%d, 겔럭시:%d, 폴드:%d\n"
			, iPhone, zFlip, GalaxyS23, GalaxyFold);
	}
};

// 1 + 1 = 2
int Add(int a, int b)
{
	printf("int형 Add가 사용되었습니다.\n");
	return a + b;
}

// 1.2 + 1.3 = 1.5
float Add(float a, float b)
{
	printf("float형 Add가 사용되었습니다.\n");
	return a + b;
}

double Add(double a, double b)
{
	printf("double형 Add가 사용되었습니다.\n");
	return a + b;
}

int main()
{
	int t_money = 0;//지역 변수
	addMoney(100);
	addMoney(100);
	addMoney(100);
	addMoney(100);
	addMoney(100);

	printf("main t_money=%d\n", t_money);
	printf("main g_money=%d\n", g_money);
	printf("1+1 Sum=%d\n", AddNum(1, 1));

	Add(1, 1);
	Add(1.0f, 1.0f);//f를 붙이고 실수를 쓰면 float형
	Add(1.0, 1.0);//f를 붙이지 않고 실수를 쓰면 double형

	// 배열
	// int arrInt[10] = { 0 };// 배열 생성 및 전부 0으로 초기화
	// int arrInt[10] = { 0, };// 배열 생성 및 전부 0으로 초기화
	int arrInt[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };// 배열 생성 및 각각에 배열에 초기값 넣는 방법
	arrInt[0] = 10;// 배열 0번째에 값 넣기
	arrInt[4] = 40;// 배열 4번째에 값 넣기
	arrInt[9] = 90;// 0번 부터 배열이 시작 되므로 마지막 배열은 9번째

	for (int i = 0; i < 10; i++)
	{
		printf("%d번째 배열 값은 %d입니다.\n", i, arrInt[i]);// 2개 이상의 파라메타 출력 방법
	}

	int number = 0;
	for (int value : arrInt)
	{
		printf("for each %d번째 배열 값은 %d입니다.\n", number, value);
		number++;
	}

	// Struct에 사용
	// fruitShop : 변수형
	// shop : 변수의 이름
	fruitShop shop[3];

	// Struct 함수 사용법
	shop[0].index = 0;
	shop[0].SetFruitValue(1000, 2000, 3000);
	shop[1].index = 1;
	shop[1].SetFruitValue(1100, 2100, 3100);
	shop[2].index = 2;
	shop[2].SetFruitValue(900, 1900, 2900);

	for (fruitShop stValue : shop)
	{
		stValue.printShopValue();
	}

	// Struct PhoneShop
	// int iPhone;
	// int zFlip;
	// int GalaxyS23;
	// int GalaxyFold;
	// PhoneShop[0] iPhone=100, zFlip=90, GalaxyS23=80, GalaxyFold=150
	// PhoneShop[1] iPhone=110, zFlip=100, GalaxyS23=90, GalaxyFold=160
	// PhoneShop[2] iPhone=90, zFlip=80, GalaxyS23=70, GalaxyFold=140
	// PhoneShop[0], PhoneShop[1], PhoneShop[2]에 가격을 출력

	PhoneShop stPhoneShop[3];
	stPhoneShop[0].setPhoneValue(100, 90, 80, 150);
	stPhoneShop[1].setPhoneValue(110, 100, 90, 160);
	stPhoneShop[2].setPhoneValue(90, 80, 70, 140);

	for (PhoneShop value : stPhoneShop)
	{
		value.printShopValue();
	}
}