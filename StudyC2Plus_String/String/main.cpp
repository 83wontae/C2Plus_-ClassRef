#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

char* copyString(const char* str)
{
	char* result = new char[strlen(str) + 1];
	strcpy_s(result, strlen(str) + 1, str);
	return result;
}

char* appendStrings(const char* str1, const char* str2, const char* str3)
{
	int size = strlen(str1) + strlen(str2) + strlen(str3) + 1;
	cout << "size = " << size << endl;
	char* result = new char[size];
	strcpy_s(result, size, str1); // 문자열을 복사
	strcat_s(result, size, str2); // 문자열을 붙이기
	strcat_s(result, size, str3); // 문자열을 붙이기
	return result;
}

string_view extractExtension(string_view fileName);

int main()
{
	/*
	- C++ STL에서 제공하는 클래스로, 문자열을 다루는 클래스
	- C에서는 char* 또는 char[] 의 형태로 문자열을 다뤘다면, C++에서는 문자열을 하나의 변수 type처럼 사용하며, 문자열을 훨씬 다양하고 쉽게 다룰 수 있게 해 준다. 
	- char* , char[] 과 다르게 문자열의 끝에 '\0' 문자가 들어가지 않으며, 문자열의 길이를 동적으로 변경 가능하다. 
	*/

	string strA("12");
	string strB("34");
	string strC("ABCDEF");
	printf("strA = %s\n", strA.c_str());

	char* c = appendStrings("Hello1", "Hello2", "Hello3");
	cout << c << endl;
	size_t s1 = sizeof(c);
	size_t s2 = strlen(c);
	cout << "sizeof = " << s1 << " strlen = " << s2 << endl;

	const char* str = "Hello \"World\"!";
	const char* str1 = R"(Hello "World"!)";
	const char* str2 = "Line1\nLine2";
	const char* str3 = 
R"(Line1
Line2)";
	cout << str3 << endl;

	//------------------[string]-------------------//
	string A("12");
	string B("34");
	string C;
	A += B;
	cout << A << endl;// 문자열 + 연산자 가능

	string myString = "hello";
	myString += ", there";// += 연산자 가능
	string myOtherString = myString;// 대입 연산자 가능
	if (myString == myOtherString) {// 비교 연산자 가능
		myOtherString[0] = 'H';
	}
	cout << myString << endl;
	cout << myOtherString << endl;

	auto temp = 1.0f;
	auto string1 = "Hello World";// char* string1
	auto string2 = "Hello World"s;// string string2

	long double d = 3.14L;
	string string3 = to_string(d);// 숫자->문자 변환

	const string toParse = " 123USD";
	size_t index = 0;
	int value = stoi(toParse, &index);// 문자->숫자 변환
	cout << "Parsed value: " << value << endl;
	cout << "First non-parsed character: " << toParse[index] << "'" << endl;

	/*
	string_view는 c++ 17에서 추가되었습니다. 
	 string_view는 다양한 문자열 타입을 전달 받을 수 있는 안전하면서 효과적인 방법을 제공합니다. 

	 내부적으로 문자열에 대한 pointer와 길이만 가지므로 임시객체를 생성하지 않고 문자열을 
	 사용 할 수 있습니다. 

	 주의 할점은 string_view는 내부적으로 null 종료 문자를 가지지 않습니다. 
	 (사실 string 타입류는 size를 들고 있기 때문에 null문자가 없어도 됩니다. )

	 또한 원본 데이터에 대한 변경을 방지합니다.
	 string_view를 사용시에 주의 할 점은 원본 데이터에 대한 객체의 수명을 제어 할 수 없기 때문에
	 호출 하는 주체가 원본 데이터의 안정성을 보장 해 줘야 합니다.
	*/

	string str11 = "Hello";
	string_view sv = " world";
	auto result = str11 + sv.data();


	string fileName = R"(c:\temp\myfile.ext)";
	cout << "C++ string: " << extractExtension(fileName) << endl;

	const char* cString = R"(c:\temp\myfile.ext)";
	cout << "C string: " << extractExtension(cString) << endl;

	cout << "Literal: " << extractExtension(R"(c:\temp\myfile.ext)") << endl;
}

string_view extractExtension(string_view fileName)
{
	return fileName.substr(fileName.rfind('.'));
}