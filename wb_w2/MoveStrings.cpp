#include <vector>
#include <string>

using namespace std;

void MoveStrings(std::vector<std::string>& src, std::vector<std::string>& dest)
{
	for (auto str : src)
	{
		dest.push_back(str);
	}
	src.clear();
}