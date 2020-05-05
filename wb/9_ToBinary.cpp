#include <iostream>
#include <string>

int main()
{
	int in;
	std::cin >> in;

	int it1 = in;
	
	std::string buff;
	while (it1 > 0)
	{
		buff.append(std::to_string(it1 % 2));
		it1 /= 2;
	}
	if (!in)
	{
		buff.append("0");
	}

	for ( auto itr = buff.rbegin() ; itr != buff.rend(); ++itr )
	{
		std::cout << *itr ;
	}
	
	
	return 0;
}