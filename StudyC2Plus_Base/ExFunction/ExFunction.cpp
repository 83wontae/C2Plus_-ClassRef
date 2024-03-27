#include <stdio.h>
#include "Sum.h"
#include "Minus.h"
#include "Multi.h"
#include "Divide.h"

//함수이름 Average
//파라메타 int &Sum, int a, int b, int c
//반환값 없음
//레퍼런스 변수 Sum으로 a, b, c에 평균 값을 반환
void Average(int& Sum, int a, int b, int c)
{
	Sum = a + b + c / 3;
}

//함수이름 ArraySum
//파라메타 int* arr, int length
//반환 값 : int
//배열 "arr" 와 배열의 길이 "length"를 파라메타로 받아서 모든 배열의 합을 반환
int ArraySum(int* arr, int length)
{
	int sum = 0;
	for (int i = 0; i < length; ++i)
	{
		sum += arr[i];
	}

	return sum;
}

// 클래스 이름 : CShop
// 맴버 변수 : m_value(기본값:0)
// 맴버 함수 추가 : printValue
// printValue 함수 결과 : "Value=%d"로 m_value 출력
class CShop
{
public:
	int m_value;

	void printValue()
	{
		printf("Value=%d\n", m_value);
	}
};

// 클래스 이름 : CPhoneShop
// 부모 클래스 : CShop
// 맴버 변수 : int m_PhoneCnt
// 맴버 변수 : int m_PhonePrice
// 생성자 파라메타 : int PhoneCnt ( m_PhoneCnt에 값 적용 )
// 생성자 파라메타 : int PhonePrice ( m_PhonePrice에 값 적용 )
// printValue 함수 결과 : "Value=%d"로 m_PhoneCnt * m_PhonePrice출력
class CPhoneShop : public CShop
{
public:

	CPhoneShop(int PhoneCnt, int PhonePrice):m_PhoneCnt(PhoneCnt), m_PhonePrice(PhonePrice)
	{

	}

	void printValue()
	{
		printf("Value=%d\n", m_PhoneCnt * m_PhonePrice);
	}

	int m_PhoneCnt;
	int m_PhonePrice;
};

// 클래스 이름 : CFruitShop
// 부모 클래스 : CShop
// 맴버 변수 : int m_FruitCnt
// 맴버 변수 : int m_FruitPrice
// 생성자 파라메타 : int FruitCnt ( m_FruitCnt에 값 적용 )
// 생성자 파라메타 : int FruitPrice ( m_FruitPrice에 값 적용 )
// printValue 함수 결과 : "Value=%d"로 m_FruitCnt * m_FruitPrice출력
class CFruitShop : public CShop
{
public:
	CFruitShop(int FruitCnt, int FruitPrice):m_FruitCnt(FruitCnt), m_FruitPrice(FruitPrice)
	{

	}

	void printValue()
	{
		printf("Value=%d", m_FruitCnt * m_FruitPrice);
	}

	int m_FruitCnt;
	int m_FruitPrice;
};



int main()
{
	// printf로 "Sum=%d\n"로 Sum함수 결과 출력
	// printf로 "Minus=%d\n"로 Minus함수 결과 출력
	// printf로 "Multi=%d\n"로 Multi함수 결과 출력
	// printf로 "Divid=%d\n"로 Divid함수 결과 출력

	int sum = Sum(1, 1);
	//Minus();
	//Multi();
	//Divid();

	// CPhoneShop(10, 100) 생성 후 객체에 printValue 출력
	CPhoneShop PhoneShop(10, 100);
	PhoneShop.printValue();

	// CFruitShop(10, 100) 생성 후 객체에 printValue 출력
	CFruitShop FruitShop(10, 100);
	FruitShop.printValue();
}