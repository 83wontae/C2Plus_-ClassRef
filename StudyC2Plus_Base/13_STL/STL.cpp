#include <stdio.h>
#include <vector>
#include <list>

struct stMonster
{
	int index = 0;//몬스터 타입
};

bool IsFindMonIndex(const stMonster& mon) {
	return mon.index == 3;// 만약 mon.index가 3이면 true반환, 아니면 false반환
}

class CShop
{
public:
	int isOpen = false;
};

int main()
{
	// STL
	// 고정되지 않은 유동적인 배열
	// 배열 생성하면서 처음부터 공간을 점유하지 않고 필요할때 마다 늘리고 줄일수있는 배열
	
	/*
	* 백터(vector) - 스택(Stack) 구조
	* 연속적인 메모리를 확보한다.
	* 자신의 요소를 내부의 동적 배열(dynamic array)로 복사한다.
	* 임의 접근 연산자를 제공([])하기 때문에 어떠한 값에 접근하든 상수시간(고정된 시간)이 소요된다.
	* 동적 배열이기 때문에 배열의 중간에 새로 추가하거나 삭제하면 많은 값이 이동해야하기 때문에 오랜 시간이 걸린다.
	* 중간에 추가하는 것이 오버헤드가 크기 때문에 보통 뒷부분에 추가한다( push_back )
	* 동적 배열이기 때문에 크기의 확장과 축소가 자유롭지만 재할당 비용은 크다.
	* 
	* 장점
	* - 임의 접근을 상수시간(고정된 시간)에 가능하므로, 읽기 속도가 매우 빠르다.
	* 
	* 단점
	* - 중간에 값을 추가/제거하는 비용이 크다
	* - 재할당 비용이 크다
	*/

	//std::vector<int> : int형에 vector 배열
	//vecint : vector 배열에 이름
	//{ 0,1,2,3,4 } : vecint에 초기값 넣기
	//std::vector<int> vecint{ 0,1,2,3,4 };
	//int vectorSize = vecint.size();// 백터의 요소 갯수 반환
	//int vec0 = vecint[0];// [] 명확한 위치를 넣어서 접근 가능
	//int* pData = vecint.data();// 백터 배열 실재 데이터 메모리 공간에 주소(포인터)를 반환
	//int vCap = vecint.capacity();// 데이터 크기 측면에서에 저장 공간 크기를 반환
	//printf("vecint capacity=%d\n", vCap);
	//for (int i = 0; i < vecint.size(); i++)
	//{
	//	printf("vecint[%d]=%d\n", i, vecint[i]);
	//}

	//for (int value : vecint)// 값 복사 방식으로 값을 변경하면은 원본 데이터는 수정 안됨
	//{
	//	value = 0;
	//	printf("vecint=%d\n", value);
	//}

	//for (int& value : vecint)// 레퍼런스 참조 방식으로 값을 변경하면은 원본 데이터 변경
	//{
	//	value = 1;
	//	printf("Ref vecint=%d\n", value);
	//}

	//for (const int& value : vecint)// 레퍼런스 참조시 const 변수로 참조하면 값 변경 불가능
	//{
	//	// value = 0;
	//	printf("vecint=%d\n", value);
	//}

	//std::vector<int> vecInt{ 0,1,2,3,4,5,6,7,8,9 };
	//std::vector<int>::iterator vecIter = vecInt.begin();
	//// vecIter++;// 오른쪽으로 다음 배열에 위치를 가리키겠다.
	//vecIter += 2;// 오른쪽으로 2번 이동한 배열에 위치를 가리키겠다.
	//vecIter--;
	//// vecInt.end();// 배열 끝이라는 의미(마지막 배열은 아니다)
	//vecInt.push_back(100);// 배열에 마지막에 100 요소를 추가하겠다
	//for (std::vector<int>::iterator iter = vecInt.begin(); iter != vecInt.end(); ++iter)
	//{
	//	printf("iter=%d\n", *iter);
	//}

	//vecInt.pop_back();// 마지막 배열에 요소를 제거하겠다.
	//vecIter = vecInt.begin();
	//while (vecIter != vecInt.end())
	//{
	//	printf("while iter=%d\n", *vecIter);
	//	vecIter++;
	//}
	//printf("vecInt size=%d\n", int(vecInt.size()));

	//vecIter = vecInt.begin();
	//while (vecIter != vecInt.end())
	//{
	//	if (*vecIter == 5)
	//	{
	//		vecIter = vecInt.erase(vecIter);//vecIter가 가리키고 있는 배열 요소 제거하겠다.
	//	}
	//	else
	//	{
	//		vecIter++;
	//	}
	//}

	//vecIter = vecInt.begin();
	//while (vecIter != vecInt.end())
	//{
	//	printf("while iter=%d\n", *vecIter);
	//	vecIter++;
	//}
	 

	/*
	* 리스트(list)
	* 리스트는 요소들을 양방향 연결리스트의 형태로 관리한다.(Doubly linked List)
	* 리스트 객체는 앵커라 불리는 포인터 2개를 제공하는데 이는 head와 tail을 가리킨다.
	* 새로운 요소를 삽입하기 위해서는 이 포인터(앵커)를 조작한다.
	* 리스트는 임의 접근([])을 제공하지 않는다. (n번째 요소에 접근하기 위해서 노드들을 거쳐야 하기 때문)
	* 특정 위치에 추가/삭제가 자유롭다. (특정 위치를 찾는 시간은 제외)
	* 재할당 연산이 없다. 연속적인 메모리가 아니기 때문에(메모리가 제공되는 한) 무한히 추가할수 있다.
	* 
	* 장점
	* - 임의의 위치에 요소를 추가하는 것이 자유롭다(특정 위치를 찾는 시간은 제외) 따라서 쓰기에 매우 강하다
	* 
	* 단점
	* - 임의접근이 불가능하기 때문에 선형 탐색하여 위치를 찾는다.
	* - 원소간의 연결을 위해 추가적인 메모리를 소모한다(다음 노드의 포인터 메모리)
	*/
	
	// std::list<int> : 리스트로 생성할 변수형
	// listInt : 생성할 리스트에 이름
	// { 0,1,2,3,4 }; : 리스트에 기본값
	//std::list<int> listInt{ 0,1,2,3,4 };

	//for (int value : listInt )
	//{
	//	value = 0;
	//	printf("List Value=%d\n", value);
	//}

	//for (const int& value : listInt)
	//{
	//	printf("List Value=%d\n", value);
	//}

	//std::list<int>::iterator listIter = listInt.begin();
	//printf("listIter=%d\n", *listIter);
	//for (std::list<int>::iterator iter = listInt.begin(); iter != listInt.end(); ++iter)
	//{
	//	printf("For List Value=%d\n", *iter);
	//}

	//listIter = listInt.begin();
	//while (listIter != listInt.end())
	//{
	//	printf("While List Value=%d\n", *listIter);
	//	listIter++;
	//}
	
	std::list<int> listInt{ 10,7,31,22,75 };
	listInt.push_back(100);// 리스트에 뒤쪽에 값을 추가 연결한다.
	listInt.push_front(200);// 리스트에 앞쪽에 값을 추가 연결한다.

	listInt.pop_back();// 리스트에 뒤쪽에 값을 제거한다.
	listInt.pop_front();// 리스트에 앞쪽 값을 제거한다.

	// 리스트에서 특정 원소 찾기
	std::list<int>::iterator it = std::find(listInt.begin(), listInt.end(), 22);
	if (it != listInt.end())
	{
		// 찾았다.
		printf("Find List Value=%d\n", *it);
		// listInt.erase(it);// 리스트 안에 특정 요소 제거하기
		int value = 2023;
		// listInt.insert(it, value);// 특정 요소 앞쪽에 새로운 요소 끼워넣기
		// listInt.emplace(it, 2024);// 특정 요소 앞쪽에 새로운 요소 끼워넣기
	}
	else
	{
		// 못 찾았다.
		printf("Find List Fail!\n");
	}

	for (const int& value : listInt)
	{
		printf("List Value=%d\n", value);
	}

	// 구조체 배열 find_if로 특정 요소 찾기
	std::list<stMonster> arrMon;

	for (int i = 1; i < 6; ++i)
	{
		stMonster temp;
		temp.index = i + 10;
		arrMon.push_back(temp);
	}

	std::list<stMonster>::iterator monIter;
	// monIter = std::find_if(arrMon.begin(), arrMon.end(), IsFindMonIndex);
	monIter = std::find_if(arrMon.begin(), arrMon.end()
		, [](const stMonster& mon)
		{
			return mon.index == 12;
		});

	if (monIter != arrMon.end())	{
		// 찾았다
		printf("monIter index=%d\n", monIter->index);
	}
	else {
		// 못찾음
		printf("monIter find Fail!\n");
	}

	for (const stMonster& value : arrMon)
	{
		printf("Monster index=%d\n", value.index);
	}
}