#include <iostream>
#include <set>
#include <string>

int main()
{
	int entryNum = 0;
	std::set<std::string> strings;
	std::cin >> entryNum;

	for (int i = 0; i < entryNum; i++)
	{
		std::string buff = "";

		std::cin >> buff;
		strings.insert(buff);
	}

	std::cout << strings.size();



	return 0;
}