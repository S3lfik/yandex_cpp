#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix
{
public:

	Matrix()
		: m_num_cols(0)
		, m_num_rows(0)
	{
	}

	Matrix(const int& num_rows, const int& num_cols)
		: m_num_rows(num_rows)
		, m_num_cols(num_cols)
	{
		if (num_rows < 0 || num_cols < 0)
			throw std::out_of_range("Matrix::Matrix");

		m_data = new int* [m_num_rows];

		for (int i = 0; i < m_num_rows; ++i)
		{
			m_data[i] = new int[m_num_cols]();
		}
	}
	Matrix(const Matrix& other)
	{
		m_num_cols = other.GetNumColumns();
		m_num_rows = other.GetNumRows();

		m_data = new int*[m_num_rows];

		for (int i = 0; i < m_num_rows; ++i)
		{
			m_data[i] = new int[m_num_cols]();

			for (int j = 0; j < m_num_cols; ++j)
			{
				m_data[i][j] = other.At(i, j);
			}
		}
	}

	~Matrix()
	{
		for (int i = 0; i < m_num_rows; ++i)
		{
			delete[] m_data[i];
		}

		delete[] m_data;
	}

	void Reset(const int& num_rows, const int& num_cols)
	{
		if (num_rows < 0 || num_cols < 0)
			throw std::out_of_range("Matrix::Reset");

		for (int i = 0; i < m_num_rows; ++i)
		{
			delete[] m_data[i];
		}
		delete[] m_data;

		m_num_rows = num_rows;
		m_num_cols = num_cols;

		m_data = new int*[m_num_rows];

		for (int i = 0; i < m_num_rows; ++i)
		{
			m_data[i] = new int[m_num_cols]();
		}
	}

	const int At(const int& num_rows, const int& num_cols) const
	{
		if ((num_rows >= m_num_rows || num_cols >= m_num_cols) ||
			(num_rows < 0 || num_cols < 0))
			throw std::out_of_range("Matrix::At");

		return m_data[num_rows][num_cols];
	}

	int& At(const int& num_rows, const int& num_cols)
	{
		if ((num_rows >= m_num_rows || num_cols >= m_num_cols) ||
			(num_rows < 0 || num_cols < 0))
			throw std::out_of_range("Matrix::At");

		return m_data[num_rows][num_cols];
	}

	const int GetNumRows() const
	{
		return m_num_rows;
	}

	const int GetNumColumns() const
	{
		return m_num_cols;
	}

protected:
	int m_num_rows;
	int m_num_cols;

	int** m_data;
};

istream& operator>>(istream& iss, Matrix& m)
{
	int rows, cols;
	iss >> rows >> cols;

	m.Reset(rows, cols);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			iss >> m.At(i,j);
		}
	}

	return iss;
}

ostream& operator<<(ostream& oss, const Matrix& m)
{
	int rows = m.GetNumRows();
	int cols = m.GetNumColumns();

	oss << rows << " " << cols << std::endl;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			oss << m.At(i, j) << " ";
		}
		oss << std::endl;
	}

	return oss;
}

bool operator==(const Matrix& lhs, const Matrix& rhs)
{
	int lrows = lhs.GetNumRows();
	int hrows = rhs.GetNumRows();
	int lcols = lhs.GetNumColumns();
	int rcols = rhs.GetNumColumns();

	if (lcols >= rcols ||
		lrows >= hrows)
		return false;

	
	for (int i = 0; i < lcols; ++i)
	{
		for (int j = 0; j < lrows; ++j)
		{
			if (lhs.At(i, j) != rhs.At(i, j))
				return false;
		}
	}

	return true;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
	int lrows = lhs.GetNumRows();
	int hrows = rhs.GetNumRows();
	int lcols = lhs.GetNumColumns();
	int rcols = rhs.GetNumColumns();

	if (lcols != rcols ||
		lrows != hrows)
		throw std::invalid_argument("Matrix::+");
	
	Matrix ret(lhs.GetNumRows(), lhs.GetNumColumns());

	for (int i = 0; i < lrows; ++i)
	{
		for (int j = 0; j < lcols; ++j)
		{
			ret.At(i, j) = rhs.At(i, j) + lhs.At(i, j);
		}
	}

	return ret;
}

int main() {
	Matrix one;
	Matrix two;

	fstream myFile("test.txt");
	myFile >> one >> two;
	cout << one + two << endl;
	return 0;
}
