#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

typedef map<int, set<string> > stopsAndNumber;
stopsAndNumber gBadGlobalMap;

pair<bool, int> insertToMap(set<string>& stops);

int main()
{
	string stopName = "";
	int commandsNum;

	cin >> commandsNum;

	for (int i = 0; i < commandsNum; ++i)
	{
		int stopsNum = 0;
		set<string> stops;
		cin >> stopsNum;
		
		for (int j = 0; j < stopsNum; ++j)
		{
			string stopName;
			cin >> stopName;
			stops.insert(stopName);
		}
		auto res = insertToMap(stops);

		if (res.first)
		{
			cout << "New bus " << res.second << endl;
		}
		else
		{
			cout << "Already exists for " << res.second << endl;
		}
		
	}
	return 0;
}

pair<bool, int> insertToMap(set<string>& stops)
{
	pair<bool, int> ret = { false, 0 };
	pair<int, set<string>> val = { 0, stops };
	auto found = find_if(gBadGlobalMap.begin(), gBadGlobalMap.end(), [val](pair<int, set<string>> lhs)->bool
	{
		return val.second == lhs.second;
	});

	if (found == gBadGlobalMap.end())
	{
		int index = gBadGlobalMap.size() + 1;
		gBadGlobalMap[index] = stops;
		ret = { true, index };
	}
	else
	{
		ret = { false, (*found).first };
	}

	return ret;
}

/*
4 2 Marushkino Kokoshkino 1 Kokoshkino 2 Marushkino Kokoshkino 2 Kokoshkino Marushkino
*/