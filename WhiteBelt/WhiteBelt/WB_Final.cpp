#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;
  

struct Date
{
	int year;
	int month;
	int day;
};

istream& EnsureDateSeparator(istream& in_stream, const string& data);

istream& operator>>(istream& in_stream, Date& out_date);

bool operator<(const Date& rhs, const Date& lhs);

ostream& operator<<(ostream& output, const Date& data);

class DataBase
{
public:
	void Add(const Date& date, const string& ev);
	void Delete(const Date& date, const string& ev = "");
	void Find(const Date& date) const;
	void Print() const;

private:
	map <Date, set<string> > data;
};

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

istream& EnsureDateSeparator(istream& in_stream, const string& data)
{
	if (in_stream.peek() == '-')
	{
		in_stream.ignore(1);
	}
	else
	{
		throw invalid_argument("Wrong date format: " + data);
	}

	return in_stream;
}

istream& operator>>(istream& in_stream, Date& out_date)
{
	string data;
	in_stream >> data;
	stringstream input(data);
	Date date{ -1,-1,-1 };

	input >> date.year;

	EnsureDateSeparator(input, data);
	input >> date.month;

	EnsureDateSeparator(input, data);
	input >> date.day;

	if (!input.eof())
	{
		throw invalid_argument("Wrong date format: " + data);
	}

	if (date.month > 12 || date.month < 0)
	{
		throw invalid_argument("Month value is invalid: " + to_string(date.month));
	}
	if (date.day > 31 || date.day < 1)
	{
		throw invalid_argument("Day value is invalid: " + to_string(date.day));
	}

	out_date = date;

	return in_stream;
}

bool operator<(const Date& rhs, const Date& lhs)
{
	int rsum = rhs.year * 31 * 12 + rhs.month * 31 + rhs.day;
	int lsum = lhs.year * 31 * 12 + lhs.month * 31 + lhs.day;
	return rsum < lsum;
}

ostream& operator<<(ostream& output, const Date& data)
{
	output << setw(4) << setfill('0') << data.year << "-" << setw(2) << data.month << "-" << setw(2) << data.day;
	return output;
}


void executeRequest(DataBase& db, const string& request)
{
	if (request.empty())
	{
		return;
	}

	stringstream input(request);

	Date date;
	string sEvent;
	string command;
	
	input >> command;

	if (command == "Add" )
	{
		input >> date >> sEvent;
		db.Add(date, sEvent);
	}
	else if (command == "Del")
	{
		input >> date;
		if (!input.eof())
		{
			input >> sEvent;
		}
		db.Delete(date, sEvent);
	}
	else if (command == "Find")
	{
		input >> date;
		db.Find(date);
	}
	else if (command == "Print")
	{
		db.Print();
	}
	else
	{
		throw invalid_argument("Unknown command: " + command);
	}
}

int main()
{
	DataBase db;
	string command;

	//ifstream file("input.txt");
	
	while (cin.good())
	{
		try
		{
			getline(cin, command);
			executeRequest(db, command);
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
	}	
	
	return 0;
}