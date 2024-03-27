#pragma once
#include <iostream>


using namespace std;
// 클래스 이름 : Student
// 맴버변수 :
// private:
// string mName, int mClassNum, int mScore;
// 모든 맴버 변수를 생성자에서 
// string name, int classNum, int score 파라메타를 받아서 초기화 합니다.

class Student
{
	string mName;
	int mClassNum;
	int nScore;

public:
	Student(string name, int classNum, int score) :
		mName(name), mClassNum(classNum), nScore(score) {};

	//함수 이름 : PrintInfo
	//파라메타 : 없음
	//반환값 : 없음
	//함수 기능 : cout << "이름 : " << mName << ", " << mClassNum << " 점수: " << nScore << endl;
	void PrintInfo()
	{
		cout << "이름 : " << mName << ", " << mClassNum << " 점수: " << nScore << endl;
	}

	string GetName() { return mName; };
	int GetClassNum() { return mClassNum; };
	int GetScore() { return nScore; };

};

