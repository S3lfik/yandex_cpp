#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <map>
#include <string>

using namespace std;

namespace
{
	struct Student
	{
		string firtName;
		string lastName;

		uint32_t day;
		uint32_t month;
		uint32_t year;
	};
}

class RequestProcessor
{
public:
	RequestProcessor() = default;
	void Run();
private:
	void ProcessWriteRequest(const uint16_t requestsNum);
	void ProcessReadRequest(const uint16_t requestsNum) const;

	vector<Student> m_students;
};

void RequestProcessor::Run()
{
	uint16_t requestsNum = 0;
	cin >> requestsNum;

	m_students.reserve(requestsNum);

	ProcessWriteRequest(requestsNum);
	cin >> requestsNum;
	ProcessReadRequest(requestsNum);
}

void RequestProcessor::ProcessWriteRequest(const uint16_t requestsNum)
{
	for (uint16_t i = 0; i != requestsNum; ++i)
	{
		Student st;

		cin >> st.firtName >> st.lastName
			>> st.day >> st.month >> st.year;

		m_students.push_back(st);
	}
}

void RequestProcessor::ProcessReadRequest(const uint16_t requestsNum) const
{
	string requestType = "";
	int studetsIndex = 0;
	Student st;

	for (uint16_t i = 0; i != requestsNum; ++i)
	{
		cin >> requestType >> studetsIndex;

		if (studetsIndex < 1 || studetsIndex > m_students.size())
		{
			cout << "bad request";

			if (i != requestsNum - 1)
			{
				cout << endl;
			}
			continue;
		}

		if (requestType == "name")
		{
			st = m_students[studetsIndex-1];
			cout << st.firtName << " " << st.lastName;
		}
		else if (requestType == "date")
		{
			st = m_students[studetsIndex-1];
			cout << st.day << "." << st.month << "." << st.year;
		}
		else
		{
			cout << "bad request";
		}

		if (i != requestsNum - 1)
		{
			cout << endl;
		}
	}
}

int main()
{
	RequestProcessor rp;
	rp.Run();
}