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
	strcpy_s(result, size, str1); // ���ڿ��� ����
	strcat_s(result, size, str2); // ���ڿ��� ���̱�
	strcat_s(result, size, str3); // ���ڿ��� ���̱�
	return result;
}

string_view extractExtension(string_view fileName);

int main()
{
	/*
	- C++ STL���� �����ϴ� Ŭ������, ���ڿ��� �ٷ�� Ŭ����
	- C������ char* �Ǵ� char[] �� ���·� ���ڿ��� �ٷ�ٸ�, C++������ ���ڿ��� �ϳ��� ���� typeó�� ����ϸ�, ���ڿ��� �ξ� �پ��ϰ� ���� �ٷ� �� �ְ� �� �ش�. 
	- char* , char[] �� �ٸ��� ���ڿ��� ���� '\0' ���ڰ� ���� ������, ���ڿ��� ���̸� �������� ���� �����ϴ�. 
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
	cout << A << endl;// ���ڿ� + ������ ����

	string myString = "hello";
	myString += ", there";// += ������ ����
	string myOtherString = myString;// ���� ������ ����
	if (myString == myOtherString) {// �� ������ ����
		myOtherString[0] = 'H';
	}
	cout << myString << endl;
	cout << myOtherString << endl;

	auto temp = 1.0f;
	auto string1 = "Hello World";// char* string1
	auto string2 = "Hello World"s;// string string2

	long double d = 3.14L;
	string string3 = to_string(d);// ����->���� ��ȯ

	const string toParse = " 123USD";
	size_t index = 0;
	int value = stoi(toParse, &index);// ����->���� ��ȯ
	cout << "Parsed value: " << value << endl;
	cout << "First non-parsed character: " << toParse[index] << "'" << endl;

	/*
	string_view�� c++ 17���� �߰��Ǿ����ϴ�. 
	 string_view�� �پ��� ���ڿ� Ÿ���� ���� ���� �� �ִ� �����ϸ鼭 ȿ������ ����� �����մϴ�. 

	 ���������� ���ڿ��� ���� pointer�� ���̸� �����Ƿ� �ӽð�ü�� �������� �ʰ� ���ڿ��� 
	 ��� �� �� �ֽ��ϴ�. 

	 ���� ������ string_view�� ���������� null ���� ���ڸ� ������ �ʽ��ϴ�. 
	 (��� string Ÿ�Է��� size�� ��� �ֱ� ������ null���ڰ� ��� �˴ϴ�. )

	 ���� ���� �����Ϳ� ���� ������ �����մϴ�.
	 string_view�� ���ÿ� ���� �� ���� ���� �����Ϳ� ���� ��ü�� ������ ���� �� �� ���� ������
	 ȣ�� �ϴ� ��ü�� ���� �������� �������� ���� �� ��� �մϴ�.
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