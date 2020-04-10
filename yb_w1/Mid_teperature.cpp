#include <iostream>
#include <vector>
#include <fstream>

int main()
{
	int days_num;
	int64_t sum = 0, mid_temp;
	std::vector<int> temperature_days;
	std::vector<int> over_mid;

	std::fstream myFile("test.txt");

	std::cin >> days_num;

	for (int i = 0; i < days_num; ++i)
	{
		int temp;
		std::cin >> temp;
		temperature_days.push_back(temp);
		sum += temp;
	}

	if (days_num > 0)
	{
		mid_temp = sum / days_num;
		int days_count = 0;
		for (size_t it = 0; it < temperature_days.size(); ++it)
		{
			if (temperature_days[it] > mid_temp)
			{
				++days_count;
			}
		}
		std::cout << days_count << std::endl;
		for (size_t it = 0; it < temperature_days.size(); ++it)
		{
			if (temperature_days[it] > mid_temp)
				std::cout << it << " ";
		}
	}
	else
		std::cout << 0;
	
	return 0;
}