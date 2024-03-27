/*
#include <iostream>
#include <cstring>

#pragma warning(disable:4996)

using namespace std;

char* copyString(const char* str)
{
	int len = strlen(str);
	char* result = new char[len];
	char* result2 = new char[1];
	char* result3 = new char[10];
	char* result4 = new char[20];
	strcpy(result, str);
	cout << result << endl;
	return result;
}

char* copyString_s(const char* str)
{
	int len = sizeof(str);
	char* result = new char[len];
	strcpy_s(result, sizeof(str), str);
	cout << result << endl;
	return result;
}

char* appendStrings(const char* str1, const char* str2, const char* str3)
{
	char* result = new char[strlen(str1) + strlen(str2) + strlen(str3)];
	strcpy(result, str1);
	strcat(result, str2);
	strcat(result, str3);
	cout << result << endl;
	return result;
}

char* appendStrings_s(const char* str1, const char* str2, const char* str3)
{
	char* result = new char[strlen(str1) + strlen(str2) + strlen(str3)];
	strcpy_s(result, sizeof(str1), str1);
	strcat_s(result, sizeof(result) + sizeof(str2), str2);
	strcat_s(result, sizeof(result) + sizeof(str3), str3);
	cout << result << endl;
	return result;
}

int main()
{
	//char* str1 = copyString("hello");
	char* str1 = copyString_s("hello ");
	char* str2 = appendStrings_s("hello ", "world ", "c++");
	const char* strSeq1 = R"d-char-sequence(r-char-sequence)d-char-sequence";
	const char* strSeq2 = R"-(r-char-sequence)-";
	const char* strSeq3 = R"-(Embedded )" characters)-";
	cout << strSeq1 << endl;
	cout << strSeq2 << endl;
	cout << strSeq3 << endl;
}
*/