#include <map>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

std::map< string, string> gBadGlobalMap;

void CHANGE_CAPITAL(const string& country, const string& new_capital);// Ч изменение столицы страны country на new_capital, либо добавление такой страны с такой столицей, если раньше еЄ не было.
void RENAME(const string& old_country_name, const string& new_country_name);// Ч переименование страны из old_country_name в new_country_name.
void ABOUT(const string& country);// Ч вывод столицы страны country.
void DUMP();// Ч вывод столиц всех стран.

int main()
{
	string command = "";
	int commandsNum = 0;

	cin >> commandsNum;

	for (int i = 0; i < commandsNum; ++i)
	{
		cin >> command;

		if (command == "CHANGE_CAPITAL")
		{
			std::string country, newCapital;
			cin >> country >> newCapital;
			CHANGE_CAPITAL(country, newCapital);
		}
		else if (command == "RENAME")
		{
			std::string oldCountryName, newCountryName;
			cin >> oldCountryName >> newCountryName;
			RENAME(oldCountryName, newCountryName);
		}
		else if (command == "ABOUT")
		{
			std::string country;
			cin >> country;
			ABOUT(country);
		}
		else if (command == "DUMP")
		{
			DUMP();
		}

	}

	return 0;
}

void CHANGE_CAPITAL(const string& country, const string& new_capital)
{
	if (!gBadGlobalMap.count(country))
	{
		cout << "Introduce new country " << country << " with capital " << new_capital << endl;
	}
	else
	{
		if (gBadGlobalMap[country] == new_capital)
		{
			cout << "Country " << country << " hasn't changed its capital" << std::endl;
		}
		else
		{
			cout << "Country " << country << " has changed its capital from " 
				<< gBadGlobalMap[country] << " to " << new_capital << std::endl;
		}
	}
	gBadGlobalMap[country] = new_capital;

}

void RENAME(const string& old_country_name, const string& new_country_name)
{
	if (!gBadGlobalMap.count(old_country_name) || gBadGlobalMap.count(new_country_name) || old_country_name == new_country_name)
	{
		cout << "Incorrect rename, skip" << std::endl;
		return;
	}

	string second = gBadGlobalMap[old_country_name];
	cout << "Country " << old_country_name << " with capital " << second << " has been renamed to " 
		<< new_country_name << std::endl;	

	gBadGlobalMap.erase(old_country_name);
	gBadGlobalMap[new_country_name] = second;
}

void ABOUT(const string& country)
{
	if (!gBadGlobalMap.count(country))
	{
		cout << "Country " << country << " doesn't exist" << std::endl;
	}
	else
	{
		cout << "Country " << country << " has capital " << gBadGlobalMap[country] << endl;
	}
	
}

void DUMP()
{
	if (gBadGlobalMap.empty())
	{
		cout << "There are no countries in the world" << endl;
		return;
	}

	for (auto itr : gBadGlobalMap)
	{
		cout << itr.first << "/" << itr.second << endl;
	}
}