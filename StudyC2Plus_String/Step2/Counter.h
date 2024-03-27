#pragma once

/*
*  Counter 클래스 정의
*  
* 맴버변수
*  int value //value 값은 생성자에서 초기화 한다.
* 
* 함수
* public:
* void reset(); //value 값을 0으로 초기화 한다
* void count(); //value 값을 1씩 증가 시킨다
* int getValue() const; // value값을 return 한다.
*/

class Counter
{
	int value;

public:
	Counter() : value{ 0 }	{
	}

	void reset()	{
		value = 0;
	}

	void count()	{
		value++;
	}

	int getValue() const	{
		return value;
	}
};

