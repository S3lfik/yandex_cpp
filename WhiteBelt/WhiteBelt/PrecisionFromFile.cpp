#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream input("input.txt");

	while (!input.eof())
	{
		double dnum = 0.0;
		input >> dnum;

		cout << fixed << setprecision(3);
		cout << dnum << endl;
	}


	return 0;
}