#include <iostream>
#include <cmath>


int main()
{
	/* 
	Ax^2 + Bx + C = 0
	*/
	
	float a, b, c;
	float root1, root2, discr;

	std::cin >> a >> b >> c;

	discr = (b * b) - (4 * a * c);

	//std::cout << "discr = " << discr << std::endl;

	if (!a)
	{
		if ( b )
		{
			root1 = (-c) / b;
			std::cout << root1;
		}			
	}
	else if (discr == 0)
	{
		root1 = (-b - std::sqrt(discr)) / (2 * a);
		std::cout << root1;
	}
	else if (discr > 0)
	{
		root1 = (-b + std::sqrt(discr)) / (2 * a);
		root2 = (-b - std::sqrt(discr)) / (2 * a);
		std::cout << root1 << " " << root2;
	}	
	
	return 0;
}