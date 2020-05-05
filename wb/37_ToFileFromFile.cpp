#include <fstream>
#include <iostream>

#include <string>

using namespace std;

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");

	if (input.is_open() && output.is_open())
	{
		string line = "";
		while (getline(input, line))
		{
			output << line << endl;
		}
	}
	return 0;
}