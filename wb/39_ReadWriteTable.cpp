#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;


int main()
{
	ifstream input("input.txt");
	int numRows = 0;
	int numCols = 0;
	if (input.is_open())
	{
		input >> numRows >> numCols;

		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numCols; j++)
			{
				int num = 0;
				input >> num;
				input.ignore(1);
				cout << setw(10) << num;
				
				if( j + 1 != numCols)
				{
					cout << " ";
				}
			}

			if (i + 1 != numRows)
			{
				cout << endl;
			}
		}
	}
	return 0;
}