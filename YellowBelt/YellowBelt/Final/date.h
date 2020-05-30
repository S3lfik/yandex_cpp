#pragma once
#include <iostream>
#include <string>
#include <sstream>


struct Date
{
	int year;
	int month;
	int day;
};

std::istream& EnsureDateSeparator(std::istream& in_stream, const std::string& data);

std::istream& operator>>(std::istream& in_stream, Date& out_date);
std::ostream& operator<<(std::ostream& output, const Date& data);

bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
bool operator<(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);

Date ParseDate(std::istream& is);