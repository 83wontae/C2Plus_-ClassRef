#include <iostream>

using namespace std;

int main()
{
	/*
	* 포인터란?
	* - 다른 변수, 구조체, 클래스 등 객체를 가리키는 변수 
	* TypeName *ptrVar
	* TypeName : 가리킬 값의 자료형
	* ptrVar : 포인터 변수의 이름
	* 
	* ptrVar = &var;
	* *ptrVar = value;
	* & : 주소 계산 연산자
	* *ptrVar : 포인터 ptrVar가 가리키는곳
	*/

	int a = 10;
	int* ptr;

	ptr = &a;
	cout << "ptr이 가리키는 값 : " << *ptr << endl;
	*ptr = 20;
	cout << "변수 a의 값 : " << a << endl;

	/*
	* 동적 메모리 할당
	* - 강제로 메모리에 공간을 할당
	* new 연산자를 이용해서 생성
	* delete 연산자를 이용해서 반납
	* 
	* ptrVar = new TypeName;
	* ptrVar = new TypeName[n];
	* 
	* delete ptrVar;
	* delete [] ptrVar;
	*/

	int* intPtr;
	intPtr = new int;
	*intPtr = 10;

	delete intPtr;
	intPtr = nullptr;// C에서는 NULL == 0을 사용했지만 C++에서는 nullptr 키워드 사용

	int* intArrPtr;
	intArrPtr = new int[4];
	*intArrPtr = 10;
	*(intArrPtr + 1) = 20;
	intArrPtr[2] = 30;

	delete [] intArrPtr;
	intArrPtr = nullptr;

	/*
	* L-value 참조 변수
	* 
	* - 사용방법이 일반 변수와 동일함
	* - 초기화를 통해 반드시 대상이 필요함( 아무것도 참조하지 않은 상태가 발생하지 않는다 )
	* - 참조 변수는 지정된 대상을 변경할수 없음
	*/
	
	int a = 10, b = 20;
	int &aRef = a;
	cout << aRef << endl;
	aRef = 100;
	aRef = b;

	/*
	//포인터 사용 참조
	int a = 10, b = 20;
	int *aRef = &a;
	cout << *aRef << endl;
	*aRef = 100;
	*aRef = b;
	*/

	int x{ 10 };
	const int& xRef = x;
	cout << "xRef = " << xRef << endl;
	//xRef += 10;//error - const로 참조 불가


}