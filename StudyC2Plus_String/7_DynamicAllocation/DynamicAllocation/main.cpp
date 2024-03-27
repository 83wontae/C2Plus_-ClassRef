#include <vector>
#include <list>

// C++ 의 컴파일 과정
// C++ 에서 우리가 작성한 소스코드를 실제로 실행할 수 있는 실행 파일로 변환하기 위해서는 총 4 가지 단계를 거쳐야만 합니다.

// 1. 전처리(Preprocessing) 단계 : #include 와 #define 와 같은 전처리기 매크로들을 처리하는 전처리(Preprocessing) 단계
// 2. 컴파일(Compile) 단계 : 각각의 소스 파일들을 어셈블리 명령어로 변환
// 3. 어셈블(Assemble) 단계 : 어셈블리 코드들을 실제 기계어로 이루어진 목적 코드(Object file)로 변환
// 4. 링킹(Linking) 단계 : 각각의 목적 코드들을 한데 모아서 하나의 실행 파일을 생성

// 메모리 영역
// 1. Code 영역 : 실행할 코드가 저장되어있는 영역(기계어로 존재)
// 2. Data 영역 : 전역변수, Static 변수들이 저장, 프로세스가 종료될때 까지 메모리에 저장됨
// 3. Stack 영역 : 지역변수, 매개변수들이 저장, 함수가 호출되면 생성되고 함수가 종료 되면 시스템에 반환
// 4. Heap 영역 : malloc 또는 new 함수 등에 의해서 동적으로 할당되는 영역, malloc() 또는 new 연산자를 통해 할당, free() 또는 delete 연산자를 통해 해제

struct stShop
{
	int Sales;
	int iPhone;
	int GalaxyS23;

	stShop() :Sales(0), iPhone(0), GalaxyS23(0)
	{

	}
};

bool IsSales100(const stShop& vi)
{
	return vi.Sales == 200;
}

int main()
{
	/*
	벡터(vector)
	* 연속적인 메모리를 확보한다.
	* 자신의 요소를 내부의 동적 배열 ( dynamic array )로 복사한다.
	* 임의 접근 연산자를 제공([])하기 때문에 어떠한 값에 접근하든 상수시간(고정된 시간)이 소요된다
	* 동적 배열이기 때문에 배열의 중간에 새로 추가하거나 삭제하면 많은 값이 이동해야하기 때문에 오랜 시간이 걸린다
	* 중간에 추가하는 것이 오버헤드가 크기 때문에 보통 뒷부분에 추가한다 ( push_back )
	* 동적 배열이기 때문에 크기의 확장과 축소가 자유롭지만 재할당 비용은 크다.

	장점
	* 임의접근을 상수시간(고정된 시간)에 가능하다. 따라서 읽기에 매우 강하다.

	단점
	* 중간에 값을 추가/제거하는 비용이 크다
	* 재할당 비용이 크다
	*/
	std::vector<int> vecInt{ 0,1,2,3,4 };// Stack 영역 할당
	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt[1] = 100;
	int nTemp = vecInt[1];// 범위를 벗어나는 인덱스에 접근은 가능하지만 undefined behaviour이며 어떤 값이 들어있을지 알 수 없음
	nTemp = vecInt.at(1);// 문자열의 범위를 벗어나는 인덱스를 접근하려 들면 out of range 예외를 발생
	int* pInt = vecInt.data();//벡터가 소유한 요소를 저장하기 위해 내부적으로 사용하는 메모리 배열에 대한 직접 포인터를 반환
	int vSize = vecInt.size();//벡터의 요소 갯수 반환
	int vCap = vecInt.capacity();//요소 측면에서 표현된 벡터 에 현재 할당된 저장 공간의 크기를 반환

	// vector 배열로 기본 for문법 사용
	for (int i = 0; i < vecInt.size(); i++)
	{
		printf("vecInt[%d] = %d\n", i, vecInt[i]);
	}

	// vector 배열로 기본 for each문법 사용, 변수 복제
	for (int num : vecInt)
	{
		printf("vecInt2 = %d\n", num);
		//num = 11;
	}

	// vector 배열로 기본 for each문법 사용, 레퍼런스 참조
	for (const int& num : vecInt)// const 사용시 수정 불가
	{
		printf("vecInt1 = %d\n", num);
		//num = 11;
	}

	// vector 배열로 for iterator문법 사용
	//for (auto itr = vecInt.begin(); itr != vecInt.end(); itr++)
	for (std::vector<int>::iterator itr = vecInt.begin(); itr != vecInt.end(); itr++)
	{
		printf("itr = %d\n", *itr);
		*itr = 22;
	}

	// vector에서 특정한 원소를 전부 제거하기 
	std::vector<int>::iterator vecIter = vecInt.begin();
	while (vecIter != vecInt.end())
	{
		if (*vecIter == 22)
		{
			vecIter = vecInt.erase(vecIter);
		}
	}

	printf("vecInt size = %I64d\n", vecInt.size());

	/*
	리스트(list)
	* 리스트는 요소들을 양방향 연결리스트의 형태로 관리한다.(Doubly Linked List)
	* 리스트 객체는 앵커라 불리는 포인터 2개를 제공하는데 이는 head와 tail을 가리킨다.
	* 새로운 요소를 삽입하기 위해서는 이 포인터(앵커)를 조작한다.
	* 리스트는 임의 접근([])을 제공하지 않는다. (n번째 요소에 접근하기 위해서 노드들을 거쳐야 하기 때문)
	* 특정 위치에 추가 / 삭제가 자유롭다. (특정 위치를 찾는 시간은 제외)
	* 재할당 연산이 없다.연속적인 메모리가 아니기 때문에(메모리가 제공되는 한) 무한히 추가할 수 있다.

	장점
	* 임의의 위치에 요소를 추가하는 것이 자유롭다(찾아가는 시간 제외) 따라서 쓰기에 매우 강하다
	단점
	* 임의접근이 불가능하기 때문에 선형 탐색하여 위치를 찾는다
	* 원소간의 연결을 위해 추가적인 메모리를 소모한다(다음 노드의 포인터 메모리)
	*/
	std::list<int> listInt{ 0,1,2,3,4 };// Stack 영역 할당
	listInt.push_back(10);// 리스트의 앞쪽에 요소 추가
	listInt.push_front(20);// 리스트의 뒤쪽에 요소 추가
	int lSize = listInt.size();// 리스트의 요소 갯수 반환

	//listInt[0] = 100;// 임의 접근 연산자([])를 사용할수 없음

	// iterator(inner class list에서 시작 주소값 찾기
	std::list<int>::iterator iter = listInt.begin();
	++iter;
	--iter;
	int data = *iter;
	printf("data=%d\n", data);

	// list에서 특정 원소 찾기
	auto it = std::find(listInt.begin(), listInt.end(), 1);
	if (it != listInt.end())
	{
		listInt.insert(it, 2023);
		listInt.emplace(it, 2024);
	}

	// list에서 for each문을 사용하여 원소값 출력하기, 변수 복제
	for (int num : listInt)
	{
		printf("listInt = %d\n", num);
		num = 11;
	}

	// list에서 for each문을 사용하여 원소값 출력하기, 레퍼런스 참조
	for (const int& num: listInt)// const 사용시 수정 불가
	{
		printf("listInt = %d\n", num);
	}

	// 구조체 list에서 find_if를 사용하여 특정 원소 찾기
	std::list<stShop> arrShop;
	stShop temp;
	temp.Sales = 0;
	temp.GalaxyS23 = 0;
	temp.iPhone = 0;
	arrShop.push_back(temp);
	temp.Sales = 100;
	arrShop.push_back(temp);
	temp.Sales = 200;
	arrShop.push_back(temp);
	temp.Sales = 300;
	arrShop.push_back(temp);

	std::list<stShop>::iterator it_shop = std::find_if(arrShop.begin(), arrShop.end()
		, IsSales100);
	//std::list<stShop>::iterator it_shop = std::find_if(arrShop.begin(), arrShop.end()
	//	, [](const stShop& vi) {return vi.Sales == 100; });

	if (it_shop != arrShop.end())
	{
		printf("Find Shop Sales = %d, iPhone = %d, GalaxyS23 = %d\n", it_shop->Sales, it_shop->iPhone, it_shop->GalaxyS23);
		it_shop->iPhone = 1000;
	}

	for (stShop& num : arrShop)
	{
		printf("arrShop Sales = %d, iPhone = %d, GalaxyS23 = %d\n", num.Sales, num.iPhone, num.GalaxyS23);
	}

	/*
	 - 정적 메모리 할당
	정적으로 메모리를 할당하면 컴파일 시 stack 영역에 할당되며, 함수를 빠져나갈 때 소멸된다.
	프로그램 컴파일 시 stack에 얼마만큼의 크기로 할당을 해야하는지 결정되기 때문에, 컴파일 이후 크기가 변경될 수 없다.
	따라서 정적 배열 선언 시 크기를 가변적으로 명시하면 문제가 될 수 있으므로 반드시 상수로 명시해야 한다.

	int a = 0;
	int arr[10];

	 - 동적 메모리 할당
	동적으로 메모리를 할당하는 경우 데이터가 heap 영역에 할당된다.
	위에서 다루었듯이 heap은 프로그래머에 의해 할당(new)되거나 소멸(delete)된다.
	따라서 프로그래머가 원할 때 원하는 크기로 할당할 수 있는 것이다.
	참고로 포인터 변수는 stack에 할당된다.

	int* arr = new int[10];

	*/


	/*
	new & delete
	정적 메모리는 Compile시에 stack 영역에 할당되고 함수를 빠져나올 때 소멸된다.
	반면 동적 메모리는 Runtime 시 프로그래머의 의도대로 heap 영역에 할당되고 소멸된다.
	따라서 동적 메모리를 control 하기 위해 규칙을 정해놓았으며,
	C++에서는 할당 시 new 연산자를 사용하며 소멸 시엔 delete 연산자를 사용한다.
	heap 영역에 동적 할당되는 메모리의 경우 전적으로 프로그래머에 의해 관리되므로,
	사용이 끝난다면 반드시 delete를 해주어야 한다.
	참고로 동적 배열을 delete 하는 경우 배열이라는 것을 명시하기 위해 delete[] 연산자를 사용해야만 한다.
	*/

	/*
	* 동적 할당을 사용하는 이유
	* 정적 할당은 Compile시에 stack 영역에 메모리 할당 하지만
	* 동적 할당을 최초에는 메모리 영역을 차지하지 않고 실행중(Runtime)에 필요할때만 할당되고 소멸 메모리 관리가 유동적
	*/
	int* nA = new int;// heap영역에 할당

	*nA = 1;

	delete nA;// heap영역에서 제거

	//int* nArray = new int[10];// heap영역에 할당
	//int* nArray = new int[10]();// heap영역에 할당
	int* pArray = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};// heap영역에 할당

	for (int i = 0; i < 10; i++)
	{
		printf("nArray[%d]=%d\n", i, pArray[i]);
	}

	delete[] pArray;// heap영역에서 제거

	{
		// 깊은 복사 & 얕은 복사
		int* a = new int(10);
		int* b = new int(20);

		//a = b;// b에 주소값을 a에 넣겠다, b가 가르키고 있는걸 a도 가르키겠다.<-[얕은 복사]
		*a = *b;// b가 가르키고 있는 값을 a가 가르키는 곳으로 복사<-[깊은 복사]

		delete a;
		delete b;
	}
}