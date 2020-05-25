#pragma once
#include <map>
#include <set>
#include <string>

#include "date.h"

class DataBase
{
public:
	void Add(const Date& date, const std::string& ev);
	void Delete(const Date& date, const std::string& ev = "");
	void Find(const Date& date) const;
	void Print() const;

private:
	std::map <Date, std::set<std::string> > data;
};