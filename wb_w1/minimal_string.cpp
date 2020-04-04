#include <iostream>
#include <set>
#include <string>

int main()
{
	std::string str1, str2, str3, output;
	std::cin >> str1 >> str2 >> str3;

	output = str1 < str2 ? str1 : str2;
	output = output < str3 ? output : str3;

	std::cout << output;
	return 0;
}