#include <iostream>
#include <string>
#include <charconv>

using namespace std;

string_view extractExtension(string_view fileName)
{
	return fileName.substr(fileName.rfind('.'));
}

void handleExtension(const string& extension)
{

}

int main()
{
	auto string1 = "Hello World";
	auto string2 = "Hello World"s;

	long double d = 3.14L;
	string s = to_string(d);

	const string toParse = " 123USD";
	size_t index = 0;
	int value = stoi(toParse, &index);
	cout << "Parsed value: " << value << endl;
	cout << "First non-parsed character: '" << toParse[index] << "'" << endl;

	std::string out1(10, ' ');
	auto result = to_chars(out1.data(), out1.data() + out1.size(), 12345);
	if (result.ec == std::errc())
	{
		/*제대로 변환된 경우*/
		cout << out1 << endl;
	}

	std::string out2(10, ' ');
	auto [ptr, ec] = to_chars(out2.data(), out2.data() + out2.size(), 12345);
	if (ec == std::errc())
	{
		/*제대로 변환된 경우*/
		cout << out2 << endl;
	}

	int nResult = 0;
	auto [ptr2, ec2] = from_chars(out1.data(), out1.data() + out1.size(), nResult);
	if (ec2 == std::errc())
	{
		cout << nResult << endl;
	}

	float fResult = 0.0f;
	string outF = "5.210000e+09";
	auto [ptr3, ec3] = from_chars(outF.data(), outF.data() + outF.size(), fResult, chars_format::scientific);
	if (ec3 == std::errc())
	{
		cout << fResult << endl;
	}

	//str_view

	string str = "Hello";
	string_view sv = " world";
	auto strResult = str + sv.data();

	string fileName = R"(c:\temp\myfile.ext)";
	cout << "C++ string: " << extractExtension(fileName) << endl;

	const char* cString = R"(c:\temp\myfile.ext)";
	cout << "C string: " << extractExtension(cString) << endl;

	//이렇게 하면
	cout << "Literal: " << extractExtension(R"(c:\temp\myfile.ext)") << endl;

	//아래와 같이 할필요 없다.
	const char* raw = R"(c:\temp\myfile.ext)";
	size_t length = 20;
	cout << "Raw: " << extractExtension(string_view(raw, length)) << endl;

	//handleExtension(extractExtension("myfile.ext"));
	handleExtension(extractExtension("myfile.ext").data());
	handleExtension(string(extractExtension("myfile.ext")));

	auto sv2 = "My string_view"sv;
}