#include <vector>

using namespace std;

std::vector<int> Reversed(const vector<int>& v)
{
	std::vector<int> buff;

	for (auto r_it = v.rbegin() ; r_it != v.rend(); ++r_it)
	{
		buff.push_back(*r_it);
	}
	
	return buff;
}