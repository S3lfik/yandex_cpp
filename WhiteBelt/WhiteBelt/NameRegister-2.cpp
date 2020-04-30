#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <utility>
#include <exception>

using namespace std;

struct FullName
{
	string firstName;
	string lastName;
};

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		firstNameYearly[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		lastNameYearly[year] = last_name;
	}
	string GetFullName(int year) {
		FullName fullName = getFullNameByYear(year);

		return composeOutput(fullName.firstName, fullName.lastName);
	}
	string GetFullNameWithHistory(int year) {
		vector<string> firstNames = getNameChangesByYear(year, firstNameYearly);
		vector<string> lastNames = getNameChangesByYear(year, lastNameYearly);

		firstNames.shrink_to_fit();
		lastNames.shrink_to_fit();

		return composeOutput(stringifyNamesHistory(firstNames), stringifyNamesHistory(lastNames));
	}

private:
	string composeOutput(const string& fname, const string& lname)
	{
		string ret = "";
		if (!fname.empty() && !lname.empty())
		{
			ret = fname + " " + lname;
		}
		else if (!fname.empty())
		{
			ret = fname + " with unknown last name";
		}
		else if (!lname.empty())
		{
			ret = lname + " with unknown first name";
		}
		else
		{
			ret = "Incognito";
		}

		return ret;
	}

	FullName getFullNameByYear(int year) const
	{
		FullName nameRet;
		
		nameRet.firstName = findNameByYear(year, firstNameYearly);
		nameRet.lastName = findNameByYear(year, lastNameYearly);

		return nameRet;
	}

	string stringifyNamesHistory(const std::vector<string>& names)
	{
		string ret = "";
		string prevName;
		if (names.empty())
		{
			return ret;
		}
		
		ret += names.front();
		prevName = names.front();

		if (names.size() == 1)
			return ret;


		string history = "";
		
		for (auto itr : names)
		{
			if (itr != prevName)
			{
				history += itr + ", ";
				prevName = itr;
			}
		}
		if (!history.empty())
		{
			history = history.substr(0, history.find_last_of(","));
			history = " (" + history + ")";
			ret += history;
		}		

		return ret;
	}
	
	static string findNameByYear(const int year, const map<int, string>& collection)
	{
		string ret = "";
		for (auto itr : collection)
		{
			if (itr.first <= year)
			{
				ret = itr.second;
			}
			else
			{
				break;
			}
		}
		return ret;
	}

	static vector<string> getNameChangesByYear(const int year, const map<int, string>& collection)
	{
		vector<string> ret;

		for (auto itr : collection)
		{
			if (itr.first <= year)
			{
				ret.push_back(itr.second);
			}
			else
				break;
		}
		ret.shrink_to_fit();

		reverse(ret.begin(), ret.end());		

		return ret;
	}

	map<int, string> firstNameYearly;
	map<int, string> lastNameYearly;
};