#include "database.h"
#include <iostream>
#include <algorithm>

using namespace std;

void Database::Add(const Date& date, const string& ev)
{
	if (!ev.empty())
	{
		auto insertRet = data[date].insert(ev);
		if(insertRet.second)
		{
			eventsIndex[date].push_back(insertRet.first);
		}
	}
}

Entity Database::Last(const Date& date) const
{
	std::cerr << "Debug: Last " << date << endl;
	auto last = eventsIndex.upper_bound(date);

	if (last == eventsIndex.begin())
	{
		throw invalid_argument("");
	}
	--last;
	std::cerr << "Debug: Last: " << Entity{ last->first, *last->second.back() };
	
	return { last->first, *last->second.back() };
}

void Database::Print(std::ostream& os) const
{
	for (auto date : eventsIndex)
	{
		for (auto ev : date.second)
		{
			os << Entity{date.first, *ev} << endl;
		}
	}
}

