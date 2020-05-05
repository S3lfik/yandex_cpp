#include <vector>
#include <string>
#include <iostream>
using namespace std;

typedef vector<string> activities;

const vector<int> MONTH_LENGTHS{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/* add activity to the given day*/
void ADD(vector<activities>& month, const int day, const string& activity);

/* Print all palnned activity at the given day*/
void DUMP(const vector<activities>& month, const int day);

/* Move to the next month */

void NEXT(vector<activities> & month, const int nextMonthSize);


int main()
{
	int currentMonth = 0;
	int numberOfOperations = 0;
	string operation = "";
	
	int day = 0;
	activities dailyActivities;
	vector<activities> monthlyActivities(MONTH_LENGTHS[currentMonth]);


	cin >> numberOfOperations;

	for (int i = 0; i < numberOfOperations; ++i)
	{
		cin >> operation;
		if (operation == "ADD")
		{
			string activity = "";
			cin >> day >> activity;
			ADD(monthlyActivities, day, activity);
		}
		else if (operation == "DUMP")
		{
			cin >> day;
			DUMP(monthlyActivities, day);
		}
		else if (operation == "NEXT")
		{
			(currentMonth >= 11 ? currentMonth = 0 : ++currentMonth);
				
			NEXT(monthlyActivities, MONTH_LENGTHS[currentMonth]);
		}

	}



	return 0;
}

/* add activity to the given day*/
void ADD(vector<activities>& month, const int day, const string& activity)
{
	month[day-1].push_back(activity);
}

/* Print all palnned activity of the given day*/
void DUMP(const vector<activities>& month, const int day)
{
	cout << month[day - 1].size() << " ";
	for (auto itr : month[day-1])
	{
		cout << itr << " ";
	}
	cout << endl;
}

void NEXT(vector<activities> & month, const int nextMonthSize)
{
	if (month.size() < nextMonthSize)
	{
		month.resize(nextMonthSize, {});
	}
	else
	{
		activities lastDayActivities;

		for (int i = nextMonthSize; i != month.size(); ++i)
		{
			lastDayActivities.insert(lastDayActivities.end(), month[i].begin(), month[i].end());
		}
		month.resize(nextMonthSize);
		month.back().insert(month.back().end(), lastDayActivities.begin(), lastDayActivities.end());
	}

}

//12 ADD 5 Salary ADD 31 Walk ADD 30 WalkPreparations NEXT DUMP 5 DUMP 28 NEXT DUMP 31 DUMP 30 DUMP 28 ADD 28 Payment DUMP 28