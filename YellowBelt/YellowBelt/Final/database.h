#pragma once
#include <map>
#include <vector>
#include <set>
#include <string>
#include <ostream>
#include <algorithm>

#include "date.h"

struct Entry
{
	Date date;
	std::string event;
};


class Database
{
public:
	void Add(const Date& date, const std::string& ev);

	template<class Predicate>
	std::vector<Entry> FindIf(Predicate predicate) const;

	template<class Predicate>
	unsigned RemoveIf(Predicate predicate);

	Entry Last(const Date& date) const;

	void Print(std::ostream & os) const;

private:
	std::map <Date, std::pair<std::set<std::string> , std::vector<std::string>>> data;
};

std::ostream& operator<<(std::ostream& os, const Entry& entry);

template<class Predicate>
std::vector<Entry> Database::FindIf(Predicate predicate) const
{
	std::vector<Entry> result;
	for (const auto& entry : data)
	{
		for (const auto& ev : entry.second.second)
		{
			if (predicate(entry.first, ev))
			{
				result.push_back({ entry.first, ev });
			}
		}
	}
	
	return result;
}

template<class Predicate>
unsigned Database::RemoveIf(Predicate predicate)
{
	unsigned delCount = 0;
	std::vector<Date> datesWithNoEvents;
	for (auto& entry : data)
	{
		auto itr = --entry.second.second.end();
		auto partitionIt = entry.second.second.end();
		while ("madness")
		{
			if (predicate(entry.first, *itr))
			{
				std::cerr << "Debug: RemoveIf removed: " << entry.first << *itr << std::endl;
				entry.second.first.erase(*itr);
				partitionIt = std::stable_partition(entry.second.second.begin(), partitionIt, 
					[itr](const std::string& str)
				{
					return str == *itr;
				});
				++delCount;
			}

			if (itr != entry.second.second.begin())
			{
				--itr;
			}
			else
				break;
		}
		entry.second.second.erase(partitionIt, entry.second.second.end());

		// Store a date to be removed if it has no events left
		if (entry.second.first.empty())
		{
			datesWithNoEvents.push_back(entry.first);
		}
	}

	// Remove dates with no events left 
	for (const auto& emptyDate : datesWithNoEvents)
	{
		data.erase(emptyDate);
	}

	return delCount;
}

