#include <string>

using namespace std;

struct Course
{
	string value;
	explicit Course(const string& course)
	{
		value = course;
	}
};

struct Specialization
{
	string value;
	explicit Specialization(const string& spec)
	{
		value = spec;
	}
};

struct Week
{
	string value;
	explicit Week(const string& week)
	{
		value = week;
	}
};

struct LectureTitle {
	string specialization;
	string course;
	string week;
	LectureTitle(const Specialization& s, const Course& c, const Week& w)
		: specialization(s.value)
		, course(c.value)
		, week(w.value)
	{}
};

