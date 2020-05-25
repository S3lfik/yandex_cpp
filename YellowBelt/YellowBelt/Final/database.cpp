#include "database.h"
#include <iostream>

using namespace std;

void DataBase::Add(const Date& date, const string& ev)
{
	if (!ev.empty())
	{
		data[date].insert(ev);
	}
}

void DataBase::Delete(const Date& date, const string& ev)
{
	if (data.count(date))
	{
		if (ev.empty())
		{
			size_t removeCount = data[date].size();
			data.erase(date);
			cout << "Deleted " << removeCount << " events" << endl;
		}
		else
		{
			size_t erased = 0;

			erased = data[date].erase(ev);

			if (erased)
			{
				cout << "Deleted successfully" << endl;
			}
			else
			{
				cout << "Event not found" << endl;
			}
		}
	}
	else
	{
		if (ev.empty())
		{
			cout << "Deleted 0 events" << endl;
		}
		else
		{
			cout << "Event not found" << endl;
		}
	}
}

void DataBase::Find(const Date& date) const
{
	if (data.count(date))
	{
		for (auto ev : data.at(date))
		{
			cout << ev << endl;
		}
	}
}

void DataBase::Print() const
{
	for (auto date : data)
	{
		for (auto ev : date.second)
		{
			cout << date.first << " " << ev << endl;
		}
	}
}