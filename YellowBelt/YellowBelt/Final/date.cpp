#include "Date.h"
#include <sstream>
#include <iomanip>

using namespace std;

istream& EnsureDateSeparator(istream& in_stream, const string& data)
{
	if (in_stream.peek() == '-')
	{
		in_stream.ignore(1);

		if (in_stream.peek() == EOF)
		{
			throw invalid_argument("Wrong date format: " + data);
		}
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

	if (date.month > 12 || date.month < 1)
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