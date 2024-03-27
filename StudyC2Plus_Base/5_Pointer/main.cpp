#include <stdio.h>

void BuyItem(int* Money, int price)
{
	// int* Money는 메모리 복제가 일어나지 않는다.
	// 메모리에 효율적인 관리, 데이터 참조가 편리하다.
	*Money -= price;
}

enum ePhoneType
{
	iPhone = 0,
	Galaxys23,
	GalaxyFold,
	GalaxyZ
};

struct stPhoneShop
{
	int iPhoneCnt;
	int Galaxys23;
	int GalaxyFold;
	int GalaxyZ;

	void printPhoneCnt()
	{
		printf("iPhone=%d, Galaxys23=%d, GalaxyFold=%d, GalaxyZ=%d\n",
			iPhoneCnt, Galaxys23, GalaxyFold, GalaxyZ);
	}
};

void BuyPhone(ePhoneType phoneType, stPhoneShop* pPS)
{
	switch (phoneType)
	{
	case ePhoneType::iPhone:
		pPS->iPhoneCnt--;//포인트로 참조하는 구조체에 변수는 "->"키워드로 참조한다.
		break;
	case ePhoneType::Galaxys23:
		pPS->Galaxys23--;//포인트로 참조하는 구조체에 변수는 "->"키워드로 참조한다.
		break;
	case ePhoneType::GalaxyFold:
		pPS->GalaxyFold--;//포인트로 참조하는 구조체에 변수는 "->"키워드로 참조한다.
		break;
	case ePhoneType::GalaxyZ:
		pPS->GalaxyZ--;//포인트로 참조하는 구조체에 변수는 "->"키워드로 참조한다.
		break;
	default:
		break;
	}
}

//Number 받아서 화면에 출력한다.
void printNumber(const int* number)
{
	// number = nullptr;// 포인터 주소 값을 변경할수 있다.
	// *number = 2;
	printf("print number=%d\n", *number);
}

void printNumber2(const int& number)
{
	//number = nullptr;
	//number = 4;
	printf("print number=%d\n", number);
}

void printPhoneShop(const stPhoneShop* ps)
{
	printf("print iPhoneCnt=%d\n", ps->iPhoneCnt);
}

void printPhoneShop(const stPhoneShop& ps)
{
	printf("print iPhoneCnt=%d\n", ps.iPhoneCnt);
}

int main()
{
	int a = 0;//4Byte
	int b = 0;
	// 포인터를 사용하는 이유
	// 메모리에 효율적인 관리, 데이터 참조가 편리하다.
	// int* pA : 포인터 변수의 선언(pA에 들어가있는 주소에 int형의 크기 만큼 참조 하겠다)
	// nullptr : 포인터 변수의 초기화 값(주소값이 비어있음)
	// 이전에는 NULL을 사용했는데 NULL = 0을 의미 그래서 0이랑 의미가 동일해서 문제 발생
	// 주소값이 비어있음이라는 명확한 의미를 가진 nullptr 사용
	// 포인터에 크기(x32에는 4Byte, x64에는 8Byte)
	int* pA = nullptr;
	pA = &a;//a주소값을 pA에 넣는다.
	// * : 레퍼런트 참조한다.(주소가 가르키고 있는 값을 참조한다)
	b = *pA;	//b에 pA가 가르키고 있는 주소에 값을 넣는다.
	*pA = 10;	//pA가 가르키고 있는 주소에 값을 10으로 변경한다.

	//----------------------------------------------------------------------------------//

	int num1 = 0;
	int num2 = 0;
	int* pNum = nullptr;
	pNum = &num1;	//pNum에 num1에 주소 값을 넣는다.(pNum은 num1을 가르키고 있는 상태)
	printf("pNum=%d\n", *pNum);//num1 값인 0
	*pNum = 20;		//pNum이 가르키고 있는 num1에 20을 넣는다.
	printf("pNum=%d\n", *pNum);//num1 값인 20
	pNum = &num2;	//pNum에 num2에 주소 값을 넣는다.(pNum은 num2을 가르키고 있는 상태)
	printf("pNum=%d\n", *pNum);//num2 값인 0
	*pNum = 30;		//pNum이 가르키고 있는 num2에 30을 넣는다.
	printf("pNum=%d\n", *pNum);//num2 값인 30
	printf("num1=%d num2=%d\n", num1, num2);

	//----------------------------------------------------------------------------------//
	int Money = 10000;

	BuyItem(&Money, 1000);
	printf("MyMoney=%d\n", Money);

	stPhoneShop stPS;
	stPS.iPhoneCnt = 100;
	stPS.Galaxys23 = 100;
	stPS.GalaxyFold = 100;
	stPS.GalaxyZ = 100;

	BuyPhone(ePhoneType::Galaxys23, & stPS);
	stPS.printPhoneCnt();

	//-------------------------------------------------------------------------------------//
	// 배열과 포인터

	int arrInt[10] = { 0,10,20,30,40,50,60,70,80,90 };
	int* pInt = nullptr;// pInt에 들어가있는 주소에 int형의 크기 만큼 참조 하겠다
	pInt = arrInt;
	printf("pInt=%d\n", *pInt);
	pInt += 1;//다음 배열 포인터에 주소를 가리킨다.
	printf("pInt=%d\n", *pInt);

	short arrS[10] = { 0,10,20,30,40,50,60,70,80,90 };
	pInt = (int*)arrS;//(int*)를 사용해서 int*로 강제로 형변환(Cast)한다.
	pInt += 1;//pInt가 int*이므로 int(4Byte)만큼 다음 주소 값을 참조한다.
	short* pS = (short*)pInt;//int(4Byte)만큼 이동한 주소 값은 Short(2Byte) 2번 이동한 값
	printf("pS=%d\n", *pS);

	// x32 아키텍쳐 = x86 아키텍쳐
	// int32(4Byte) = 0 ~ 4,294,967,295(Byte)

	// 아래 배열을 낮은 숫자 순서대로 출력
	int arr[10] = { 10, 2, 78, 53, 6, 33, 27, 99, 7, 31 };

	for (int i = 0; i < 10; i++)
	{
		int lowestIndex = i;// 가장 낮은 index 저장

		for (int j = i + 1; j < 10; j++)
		{
			if (arr[lowestIndex] > arr[j])
			{
				// lowestIndex와 j를 순서대로 비교
				// j index에 값이 낮으면 j는 새로운 lowestIndex
				lowestIndex = j;
			}
		}
		// j for문이 종료되면 lowestindex에는 가장 낮은 수의 index 값이 저장
		// i 는 순차적으로 돌면서 가장 낮은 수가 들어가야됨
		// lowestindex 값과 i index에 값을 교체한다.
		int temp = arr[i];
		arr[i] = arr[lowestIndex];
		arr[lowestIndex] = temp;
	}

	for (int a : arr)
	{
		printf("num:%d\n", a);
	}

	// const 상수화
	// 실수를 줄일수 있어서 디버깅 횟수를 줄일수 있다.(디버깅 : 버그를 찾거나 수정하는 모든 행위)
	const int cint = 100;//상수
	
	int value = 0;
	int value2 = 0;
	int* pValue = &value;
	//const int* pValue = &value;// 포인터가 가르키는 내용 수정 불가, 포인터 값 수정 가능, 참조 가능
	//int const* pValue = &value;// 포인터가 가르키는 내용 수정 불가, 포인터 값 수정 가능, 참조 가능
	//int* const pValue = &value;// 포인터가 가르키는 내용 수정 가능, 포인터 값 수정 불가, 참조 가능
	//const int* const pValue = &value;// 포인터가 가르키는 내용 수정 불가, 포인터 값 수정 불가, 참조 가능
	//int const* const pValue = &value;// 포인터가 가르키는 내용 수정 불가, 포인터 값 수정 불가, 참조 가능

	*pValue = 2;
	pValue = &value2;
	printf("pValue=%d\n", *pValue);

	printNumber(&value);
	printNumber2(value);
}