#include <iostream>

int main()
{
	float a, b, c, x, y, ret;

	std::cin >> a >> b >> c >> x >> y;

	ret = a;

	if (a > b && a <= c)
	{
		ret = a - (a / 100 * x);
	}
	else if (a > c)
	{
		ret = a - (a / 100 * y);
	}

	std::cout << ret << std::endl;
	return 0;
}