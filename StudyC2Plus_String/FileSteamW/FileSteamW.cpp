#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class CStudent
{
	wchar_t* name;
	int age = 0;
	float score = 0;

	void printInfo()
	{
		cout << "name = " << name << " score = " << score << " age = " << age << endl;
	}
};

void wcharCutHalfwithKey(wchar_t* source, wchar_t key, wchar_t*& leftstr, wchar_t*& rightstr)
{
	wchar_t* ptr = wcschr(source, key);
	if (ptr == nullptr)
		return;

	size_t keyIndex = ptr - source;
	size_t sourceLength = wcslen(source);

	int leftsize = keyIndex + 1;
	leftstr = new wchar_t[leftsize];
	wcsncpy_s(leftstr, leftsize, source, leftsize - 1);

	// rightstr에 오른쪽 부분 복사
	int rightsize = sourceLength - keyIndex;
	rightstr = new wchar_t[sourceLength - keyIndex];
	wcsncpy_s(rightstr, rightsize, source + leftsize, rightsize - 1);

	//int index =  find(key);
	//leftstr = source.substr(0, index);
	//rightstr = source.substr(index + 1);
}


vector<wchar_t*> wcharCutByKey(vector<wchar_t*>& arrStr, wchar_t* source, char key)
{
	wchar_t* leftstr = nullptr;
	wchar_t* rightstr = nullptr;

	int sourceLen = wcslen(source) + 1;
	wchar_t* pfindtarget = new wchar_t[sourceLen];
	wcscpy_s(pfindtarget, sourceLen, source);
	while (true)
	{
		wchar_t* ptr = wcschr(pfindtarget, key);
		if (ptr == nullptr)
			break;

		wcharCutHalfwithKey(pfindtarget, ' ', leftstr, rightstr);
		arrStr.push_back(leftstr);

		delete[] pfindtarget;
		pfindtarget = rightstr;
	}

	arrStr.push_back(pfindtarget);

	return arrStr;
}

int main()
{
	wifstream file("writeFile.txt");
	std::vector<wchar_t*> vecChar;
	if (file.is_open()) {
		wchar_t* readline = nullptr;
		std::streamsize size = 0;
		while (file.getline(readline, size))
		{
			vecChar.push_back(readline);
		}
		file.close();
	}
	else {
		cout << "파일 읽기를 실패했습니다." << endl;
	}
	/*
	wchar_t wchar[100] = L"asd fas ds fad sf";
	wchar_t* leftstr = nullptr;
	wchar_t* rightstr = nullptr;

	vector<wchar_t*> arrwchar;
	wcharCutByKey(arrwchar, wchar, ' ');

	for (wchar_t* wch : arrwchar)
	{
		delete[] wch;
	}
	*/


	//wcharCutHalfwithKey(wchar, ' ', leftstr, rightstr);
	//wprintf(L"leftstr=%s\n", leftstr);
	//wprintf(L"rightstr=%s\n", rightstr);

	//if (leftstr) delete[] leftstr;
	//if (rightstr) delete[] rightstr;
}