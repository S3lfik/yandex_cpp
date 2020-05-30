#include "database.h"
#include <iostream>
#include <algorithm>

using namespace std;

void Database::Add(const Date& date, const string& ev)
{
	if (!ev.empty())
	{
		if (!data[date].first.count(ev))
		{
			std::cerr << "Debug: Add " << Entry{ date, ev } << endl;
			data[date].first.insert(ev);
			data[date].second.push_back(ev);
		}
	}
}

Entry Database::Last(const Date& date) const
{
	std::cerr << "Debug: Last " << date << endl;
	auto last = data.upper_bound(date);

	if (last == data.begin())
	{
		throw invalid_argument("");
	}
	--last;
	std::cerr << "Debug: Last: " << Entry{last->first, last->second.second[last->second.second.size() - 1]} << endl;
	return {last->first, last->second.second[last->second.second.size() - 1]};
}

void Database::Print(std::ostream& os) const
{
	for (auto date : data)
	{
		for (auto ev : date.second.second)
		{
			os << Entry{date.first, ev} << endl;
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Entry& entry)
{
	os << entry.date << " " << entry.event;
	return os;
}