#include <iostream>

int main()
{
	int a, b;

	std::cin >> a >> b;

	for (int i = a; i <= b; )
	{
		if (i % 2 == 0)
		{
			std::cout << i << " ";
			i += 2;
			continue;
		}
		++i;
	}
	return 0;
}