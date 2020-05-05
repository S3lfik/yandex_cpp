#include <set>
#include <map>
#include <string>
#include <iostream>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m)
{
	set<string> ret;

	for (auto itr : m)
	{
		ret.insert(itr.second);
	}
	return ret;
}