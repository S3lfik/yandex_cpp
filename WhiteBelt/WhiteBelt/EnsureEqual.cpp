#include <exception>
#include <string>
#include <iostream>

using namespace std;


void EnsureEqual(const string& left, const string& right)
{
	if (left != right)
	{
		string msg = left + " != " + right;
		throw runtime_error(msg);
	}
}