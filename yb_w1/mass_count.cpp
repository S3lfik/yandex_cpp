#include <iostream>
#include <fstream>

int main()
{
	int count, density;
	uint64_t total_vol = 0;;
	std::fstream myFile("test.txt");

	std::cin >> count >> density;
	for ( int i = 0; i < count; ++i)
	{
		uint64_t w, h, d;
		std::cin >> w >> h >> d;
		total_vol += w * h * d * density;
	}

	std::cout << total_vol;

	return 0;
}