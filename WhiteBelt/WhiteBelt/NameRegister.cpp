#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

struct FirstLastName
{
	string firstName;
	string lastName;
};

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		m_yearlyChange[year].firstName = first_name;
		// добавить факт изменения имени на first_name в год year
	}
	void ChangeLastName(int year, const string& last_name) {
		m_yearlyChange[year].lastName = last_name;
		// добавить факт изменения фамилии на last_name в год year
	}
	string GetFullName(int year) {
		string ret = "";
		FirstLastName nameRet = getCurrentToYear(year);

		if (!nameRet.firstName.empty() && !nameRet.lastName.empty())
		{
			ret = nameRet.firstName + " " + nameRet.lastName;
		}
		else if (!nameRet.firstName.empty())
		{
			ret = nameRet.firstName + " with unknown last name";
		}
		else if (!nameRet.lastName.empty())
		{
			ret = nameRet.lastName + " with unknown first name";
		}
		else
		{
			ret = "Incognito";
		}

		return ret;
	}
private:
	FirstLastName getCurrentToYear(int year) const
	{
		FirstLastName nameRet;
		{
			for (auto itr : m_yearlyChange)
			{
				if (itr.first > year)
				{
					break;
				}
				nameRet.firstName = (!itr.second.firstName.empty()) ? itr.second.firstName : nameRet.firstName;
				nameRet.lastName = (!itr.second.lastName.empty()) ? itr.second.lastName : nameRet.lastName;
			}
		}
		return nameRet;
	}
	
	map<int, FirstLastName> m_yearlyChange;
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}