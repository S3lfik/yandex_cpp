#pragma once
#include <iostream>
#include <string>


struct Date
{
	int year;
	int month;
	int day;
};

Date ParseDate(const std::string& data);

std::istream& EnsureDateSeparator(std::istream& in_stream, const std::string& data);

std::istream& operator>>(std::istream& in_stream, Date& out_date);

bool operator<(const Date& rhs, const Date& lhs);

std::ostream& operator<<(std::ostream& output, const Date& data);