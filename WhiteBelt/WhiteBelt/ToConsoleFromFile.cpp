#include <fstream>
#include <iostream>

#include <string>

using namespace std;

int main()
{
	fstream file("input.txt");

	if(file.is_open())
	{
		string line = "";
		while (getline(file, line))
		{
			cout << line << endl;
		}
	}
	return 0;
}