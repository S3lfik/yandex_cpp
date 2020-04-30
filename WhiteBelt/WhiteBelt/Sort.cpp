#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int numCount;
	vector<int> numbers;

	cin >> numCount;

	for (int i = 0; i < numCount; i++)
	{
		int number;
		cin >> number;
		numbers.push_back(number);
	}

	sort(numbers.begin(), numbers.end(), [](const int& lhs, const int& rhs) -> bool
	{
		return (lhs > 0 ? lhs : lhs * -1) < (rhs > 0? rhs : rhs * -1);
	});

	for (const auto& itr : numbers)
	{
		cout << itr << " ";
	}
	return 0;
}
