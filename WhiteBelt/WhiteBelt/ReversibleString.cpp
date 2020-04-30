#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class ReversibleString
{
public:
	ReversibleString()
	{}

	ReversibleString(const string& str)
		:m_string(str)
	{}

	void Reverse()
	{
		reverse(m_string.begin(), m_string.end());
	};

	string ToString() const
	{
		return m_string;
	}
private:
	string m_string;
};