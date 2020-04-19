#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

typedef map< string, vector<string>> routeMap;
routeMap gBadBusesIndex;
routeMap gBadStopsIndex;
/*
	NEW_BUS bus stop_count stop1 stop2 ... — добавить маршрут автобуса с названием bus и stop_count остановками с названиями stop1, stop2, ...
	BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса, проходящих через остановку stop.
	STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus со списком автобусов, на которые можно пересесть на каждой из остановок.
	ALL_BUSES — вывести список всех маршрутов с остановками.
*/
vector<string> BUSES_FOR_STOP(const string& busStopName);

vector<string> STOPS_FOR_BUS(const string& busName);

void ALL_BUSES();

void PrintBusesForStop(const string& stop, const string& exclude = "");
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
			//cout << "NEW_BUS---------------------" << endl;;
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

			//cout << "---------------------" << endl;;
		}
		else if (command == "BUSES_FOR_STOP")
		{
			//cout << "BUSES_FOR_STOP---------------------" << endl;;
			string stop;
			cin >> stop;
			PrintBusesForStop(stop);
			//cout << "---------------------" << endl;;
		}
		else if (command == "STOPS_FOR_BUS")
		{
			//cout << "STOPS_FOR_BUS---------------------" << endl;;
			string busName;
			cin >> busName;
			PrintStopsForBus(busName);
			//cout << "---------------------" << endl;;
		}
		else if (command == "ALL_BUSES")
		{
			//cout << "ALL_BUSES---------------------" << endl;;
			ALL_BUSES();
			//cout << "---------------------" << endl;;
		}
	}
	return 0;
}

vector<string> BUSES_FOR_STOP(const string& busStopName)
{
	if (!gBadStopsIndex.count(busStopName))
	{
		// No Stop
		return vector<string>();
	}

	return gBadStopsIndex[busStopName];
}

vector<string> STOPS_FOR_BUS(const string& busName)
{
	if (!gBadBusesIndex.count(busName))
	{
		// No Bus
		return vector<string>();
	}

	return gBadBusesIndex[busName];
}

void ALL_BUSES()
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

void PrintBusesForStop(const string& stop, const string& exclude)
{
	auto buses = BUSES_FOR_STOP(stop);
	if (buses.empty())
	{
		cout << "No stop" << endl;
		return;
	}

	if (buses.size() == 1)
	{
		cout << "no interchange";
	}
	else
	{
		for (auto bus : buses)
		{
			if( bus != exclude)
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
		PrintBusesForStop(stop, bus);
	}
	
}

/*
10 ALL_BUSES BUSES_FOR_STOP Marushkino STOPS_FOR_BUS 32K NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo BUSES_FOR_STOP Vnukovo NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo STOPS_FOR_BUS 272 ALL_BUSES
*/
/*
9 NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo STOPS_FOR_BUS 272 STOPS_FOR_BUS 950 BUSES_FOR_STOP Marushkino BUSES_FOR_STOP Vnukovo BUSES_FOR_STOP Solntsevo 
9
NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo Moskovsky
STOPS_FOR_BUS 272
STOPS_FOR_BUS 950
BUSES_FOR_STOP Marushkino
BUSES_FOR_STOP Vnukovo
BUSES_FOR_STOP Solntsevo

Correct output:
Stop Vnukovo: 32 32K 950
Stop Moskovsky: no interchange
Stop Rumyantsevo: no interchange
Stop Troparyovo: 950
Stop Kokoshkino: no interchange
Stop Marushkino: 32 32K
Stop Vnukovo: 32 32K 272
Stop Peredelkino: 32K
Stop Solntsevo: 32K
Stop Troparyovo: 272
32 32K 950
32 32K 950 272
32K 950
*/