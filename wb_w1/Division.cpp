#include <iostream>

void divide(const int& a, const int& b)
{
	int ret = 0;
	
	if (b == 0)
	{
		std::cout << "Impossible";
		return;
	}

	if (a > b)
	{
		ret = a / b;
	}
	else if (b > a)
	{
		ret = 0;
	}
	else
	{
		ret = 1;
	}

	std::cout << ret;
}

int main()
{
	int a, b;
	std::cin >> a >> b;

	divide(a, b);

	return 0;
}