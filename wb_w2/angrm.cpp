#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


bool Compare(const string& lhs, const string& rhs)
{
	if (lhs.size() != rhs.size())
		return false;

	map<char, int> mlhs, mrhs;
	for (auto i : lhs)
	{
		mlhs[i]++;
	}

	for (auto i : rhs)
	{
		mrhs[i]++;
	}

	return std::equal(mlhs.begin(), mlhs.end(), mrhs.begin());
}

int main()
{
	int callsCount = 0;
	string one, two;

	cin >> callsCount;

	for (int i = 0; i < callsCount; i++)
	{
		cin >> one >> two;

		if (Compare(one, two))
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
		cout << endl;
	}

	return 0;
}