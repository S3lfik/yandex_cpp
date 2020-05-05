#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	std::string input;

	std::cin >> input;
	
	size_t pos1, pos2;
	pos1 = input.find_first_of("f");
	
	if (pos1 != std::string::npos)
	{
		pos2 = input.find_first_of("f", pos1+1);

		if (pos2 != std::string::npos)
		{
			std::cout << pos2;
		}
		else
		{
			std::cout << -1;
		}
	}
	else
	{
		std::cout << -2;
	}
	
	return 0;
}