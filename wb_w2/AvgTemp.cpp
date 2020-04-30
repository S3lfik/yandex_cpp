#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void AvgTemp()
{
	int n = 0;
	int avg = 0;
	int numOver = 0;
	vector<int> daysOverAvg(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		daysOverAvg.push_back(temp);
		avg += temp;
	}

	if( n > 0)
		avg /= n;
	
	for (auto i : daysOverAvg)
	{
		if (i > avg)
		{
			numOver++;
		}
	}
	cout << numOver << endl;
	for (int i = 0 ; i != daysOverAvg.size(); ++i)
	{
		if (daysOverAvg[i] > avg)
		{
			cout << i << " ";
		}
	}
}

int main()
{
	AvgTemp();
}