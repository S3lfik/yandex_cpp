#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
	int strCount;
	vector<string> strs;

	cin >> strCount;

	for (int i = 0; i < strCount; i++)
	{
		string str;
		cin >> str;
		strs.push_back(str);
	}

	sort(strs.begin(), strs.end(), [](const string& lhs, const string& rhs) -> bool
	{
		size_t minSize = min(lhs.size(), rhs.size());
		for (int i = 0; i < minSize; ++i)
		{
			if(tolower(lhs[i]) != tolower(rhs[i]))
				return tolower(lhs[i]) < tolower(rhs[i]);
		}
		// lhs is lower, bc is shorter.. probably :D
		return true;
	});

	for (const auto& itr : strs)
	{
		cout << itr << " ";
	}
	return 0;
}
