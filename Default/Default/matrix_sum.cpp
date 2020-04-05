#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix
{
public:

	Matrix()
	{
		// zero columns
		// zero rows
	}

	Matrix(const int& num_rows, const int& num_cols)
	{
		// std::out_of_range if negative parameters
	}

	void Reset(const int& num_rows, const int& num_cols)
	{
		// reset current Matrix to the given parameters

		// std::out_of_range if negative parameters
	}

	const int At(const int& num_rows, const int& num_cols) const
	{
		return 0;
	}

	int& At(const int& num_rows, const int& num_cols)
	{
		int ret;
		return ret;
	}

	const int GetNumRows() const
	{}

	const int GetNumColumns() const
	{}

protected:
	int m_num_rows;
	int m_num_cols;
};

istream& operator>>(istream& iss, Matrix& m)
{
	return iss;
}

ostream& operator<<(ostream& oss, const Matrix& m)
{
	return oss;
}

bool operator==(const Matrix& lhs, const Matrix& rhs)
{
	return false;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
	return Matrix();
}

int main() {
	Matrix one;
	Matrix two;

	cin >> one >> two;
	cout << one + two << endl;
	return 0;
}
