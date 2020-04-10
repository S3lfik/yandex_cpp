#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum class Lang {
	DE, FR, IT
};

struct Region {
	string std_name;
	string parent_std_name;
	map<Lang, string> names;
	int64_t population;
};

struct RegionComparator
{
	bool operator()(const Region& lhs, const Region& rhs) const
	{
		return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
			tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
	}
};

int FindMaxRepetitionCount(const vector<Region>& regions)
{
	int ret = 0;

	std::map<Region, int, RegionComparator> regions_count;
	

	for (auto region : regions)
	{
		regions_count[region] += 1;
	}

	for (auto region : regions_count)
	{
		if (region.second > ret)
		{
			ret = region.second;
		}
	}
	
	return ret;
}

int main()
{
	std::vector<Region> vTest = { {
		  "Moscow",
		  "Russia",
		  {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
		  89
	}, {
		"Russia",
		"Eurasia",
		{{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
		89
	}, {
		"Moscow",
		"Russia",
		{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
		89
	}, {
		"Moscow",
		"Russia",
		{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
		89
	}, {
		"Russia",
		"Eurasia",
		{{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
		89
	} };

	std::cout << FindMaxRepetitionCount(vTest);
	return 0;
}