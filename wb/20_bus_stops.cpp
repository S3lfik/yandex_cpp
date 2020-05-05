#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

typedef map< string, vector<string>> routeMap;
routeMap gBadBusesIndex;
routeMap gBadStopsIndex;

void PrintAllBuses();
void PrintBusesForStop(const string& stop);
void PrintStopsForBus(const string& bus);

int main()
{
	string command = "";
	int commandsCount = 0;

	cin >> commandsCount;

	for (int i = 0; i < commandsCount; ++i)
	{
		cin >> command;

		if (command == "NEW_BUS")
		{
			string routeName = "";
			int stopsNumber = 0;
			cin >> routeName >> stopsNumber;

			if (gBadBusesIndex.count(routeName))
			{
				std::cout << "duplication detected!" << std::endl;
			}
			for (int i = 0; i < stopsNumber; i++)
			{
				string stop;
				cin >> stop;
				
				gBadBusesIndex[routeName].push_back(stop);
				gBadStopsIndex[stop].push_back(routeName);
			}

		}
		else if (command == "BUSES_FOR_STOP")
		{
			string stop;
			cin >> stop;
			PrintBusesForStop(stop);
		}
		else if (command == "STOPS_FOR_BUS")
		{
			string busName;
			cin >> busName;
			PrintStopsForBus(busName);
		}
		else if (command == "ALL_BUSES")
		{
			PrintAllBuses();
		}
	}
	return 0;
}

void PrintAllBuses()
{
	if (!gBadBusesIndex.size())
	{
		cout << "No buses" << endl;
		return;
	}

	for (auto busLine : gBadBusesIndex)
	{
		cout << "Bus "<< busLine.first << ": ";
		for (auto stop : busLine.second)
		{
			cout << stop << " ";
		}
		cout << endl;
	}
	
}

void PrintBusesForStop(const string& stop)
{
	
	if (!gBadStopsIndex.count(stop))
	{
		cout << "No stop" << endl;
		return;
	}
	else
	{
		for (auto bus : gBadStopsIndex[stop])
		{
				cout << bus << " ";
		}
	}
	cout << endl;
}

void PrintStopsForBus(const string& bus)
{
	if (!gBadBusesIndex.count(bus))
	{
		cout << "No bus" << endl;;
		return;
	}
	
	for (auto stop : gBadBusesIndex[bus])
	{
		cout << "Stop " << stop << ": ";
		if (gBadStopsIndex[stop].size() == 1)
		{
			cout << "no interchange" << endl;
		}
		else
		{
			for (auto busIter : gBadStopsIndex[stop])
			{
				if (bus != busIter)
					cout << busIter << " ";
			}
			cout << endl;
		}
	}
}