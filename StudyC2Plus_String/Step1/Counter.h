#pragma once// 한번만 컴파일 하도록 해준다.

/*
캡슐화
객체의 내부 구현부와 외부 사용자 부분을 분리
내부는 은닉하여 가릴수 있고
사용자 부분만 노출해서 사용에 편리하도록 함
*/

/*
클래스 이름 : Counter
- 숫자를 1씩 증가시킬 수 있다. ( 입력 : 없다 , 출력 : 없다 )
- 0으로 초기화를 할수 있다. ( 입력 : 없다 , 출력 : 없다 )
- 현재 카운팅한 값을 알려준다. ( 입력 : 없다 , 출력 : int count )
*/

class Counter
{
//private: //기본이 접근 불가능
	int count; // 카운팅하는 값을 저장

public:
	Counter() : count{ 0 }//()를 사용 가능 하지만 {}를 사용하면 명확한 값을 사용해야 되기때문에 안전
	{
		count = 0;
	}

	// count 를 1씩 증가
	void counting()
	{
		count++;
	}

	// count 가 0으로 초기화 된다.
	void reset()
	{
		count = 0;
	}

	// count 값을 알려준다.
	int getCount() const
	{
		return count;
	}


public: // 모든 곳에서 접근 가능
private: // 접근 불가능
protected: // 상속 관계에서는 접근 가능

};