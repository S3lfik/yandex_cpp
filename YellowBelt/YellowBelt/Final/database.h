#pragma once
#include <map>
#include <vector>
#include <set>
#include <string>
#include <ostream>
#include <algorithm>

#include "entity.h"

class Database
{
public:
	void Add(const Date& date, const std::string& ev);

	template<class Predicate>
	std::vector<Entity> FindIf(Predicate predicate) const;

	template<class Predicate>
	unsigned RemoveIf(Predicate predicate);

	Entity Last(const Date& date) const;

	void Print(std::ostream & os) const;

private:
	std::map <Date, std::vector< std::set< std::string>::const_iterator > > eventsIndex;
	std::map <Date, std::set< std::string > > data;
};

std::ostream& operator<<(std::ostream& os, const Entity& entry);

template<class Predicate>
std::vector<Entity> Database::FindIf(Predicate predicate) const
{
	std::vector<Entity> result;
	for (const auto& index : eventsIndex)
	{
		for (const auto& ev : index.second)
		{
			if (predicate(index.first, *ev))
			{
				result.push_back({ index.first, *ev });
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
	for (auto& entity : eventsIndex)
	{
		auto partitionIt = std::stable_partition(entity.second.begin(), entity.second.end(), 
			[&entity, predicate](const std::set< std::string>::const_iterator& evIt)
		{
			return predicate(entity.first, *evIt);
		});

		delCount += partitionIt - entity.second.begin();

		for (auto itr = entity.second.begin(); itr != partitionIt; ++itr)
		{
			data.at(entity.first).erase(*itr);
		}

		entity.second.erase(entity.second.begin(), partitionIt);

		// Mark a date with no events as empty and pending to remove
		if (data.at(entity.first).empty())
		{
			datesWithNoEvents.push_back(entity.first);
		}
	}

	// Remove dates with no events left 
	for (const auto& emptyDate : datesWithNoEvents)
	{
		data.erase(emptyDate);
		eventsIndex.erase(emptyDate);
	}

	return delCount;
}

