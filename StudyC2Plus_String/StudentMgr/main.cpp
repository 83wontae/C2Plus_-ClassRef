#include <iostream>
#include "Student.h"
#include <vector>
#include <map>

using namespace std;

unsigned int UniqueID = 0;

unsigned int CreateUniqueID()
{
	return ++UniqueID;
}

int main()
{
	int mgrType = 0;
	vector<Student> vecStudent;
	map<unsigned int, Student> mapStudent;

	string name = "";
	int classNum = 0;
	int score = 0;

	while (true)
	{
		switch (mgrType)
		{
		case 1:
		{
			//위에 3개 값을 입력 받아서 vecStudent에 개속 추가하도록 만들어 보세요
			cout << "이름을 입력하세요" << endl;
			cin >> name;
			cout << "반을 입력하세요" << endl;
			cin >> classNum;
			cout << "점수을 입력하세요" << endl;
			cin >> score;
			Student aaa = { name, classNum, score };
			//vecStudent.push_back(aaa);
			mapStudent.insert({ CreateUniqueID(), aaa });
			mgrType = 0;
		}
		break;

		case 2:
		{
			unsigned int index = 0;
			// int index 값을 하나 받아서 해당 index에 학생 정보를 제거하도록 구현합니다.
			cout << "제거할 학생의 이름을 입력하세요" << endl;
			cin >> index;
			//vecStudent.erase(vecStudent.begin() + index);

			if (mapStudent.find(index) != mapStudent.end())
			{
				mapStudent.erase(index);
			}

			mgrType = 0;
		}
		break;

		case 3:
		{
			unsigned int uniqueID = 0;
			cout << "찾을 학생의 UniqueID를 입력하세요" << endl;
			// string name 값을 받아서 이름이 같은 학생을 찾아서 출력하시오.
			cin >> uniqueID;
			/*
			for (int i = 0; i < vecStudent.size(); ++i)
			{
				if (vecStudent[i].GetName() != name)
					continue;

				cout << "index = " << i << " ";
				vecStudent[i].PrintInfo();
			}
			*/

			//find가 성공 했다면 찾은 객체의 map 주소 반환 
			//find가 실패 했다면 map에 마지막 주소 반환
			auto iter = mapStudent.find(uniqueID);
			if (iter != mapStudent.end())
			{
				iter->second.PrintInfo();
			}
			mgrType = 0;
		}
		break;

		case 4:
		{
			//for (auto iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
			for (auto iter : mapStudent)
			{
				cout << "UniqueID = " << iter.first << " ";
				iter.second.PrintInfo();
			}
			/*
			for (int i = 0; i < vecStudent.size(); ++i)
			{
				cout << "index = " << i << " ";
				vecStudent[i].PrintInfo();
			}
			*/
			/*
			for (Student s : vecStudent)
			{
				s.PrintInfo();
			}
			*/
			mgrType = 0;
		}
		break;

		default:
			cout << "[StudentManager]" << endl;
			cout << "1) Add Student" << endl;
			cout << "2) Delete Student" << endl;
			cout << "3) Find Student" << endl;
			cout << "4) Print All Student" << endl;
			cin >> mgrType;
			break;
		}
		

		
	}
}