#include <vector>
#include <utility>
#include <iostream>

using namespace std;


template <typename T>
class Table
{
	size_t m_rows, m_cols;
	std::vector< std::vector<T> > m_data;
public:
	Table(size_t rows, size_t cols)
		: m_rows(rows)
		, m_cols(cols)
	{
		auto col = std::vector<T>(m_cols);
		m_data = std::vector< std::vector<T> >(m_rows, col);
	}
	void Resize(size_t rows, size_t cols)
	{
		auto col = std::vector<T>(cols);
		
		for (auto& itr : m_data)
		{
			itr.resize(cols);
			itr.shrink_to_fit();
		}

		m_data.resize(rows, col);
		m_data.shrink_to_fit();
		m_rows = rows;
		m_cols = cols;
	}

	std::pair<size_t, size_t> Size() const
	{
		return { m_rows, m_cols };
	}

	std::vector<T>& operator[](const size_t& num)
	{
		return m_data[num];
	}

	std::vector<T> operator[](const size_t& num) const
	{
		return m_data[num];
	}
};
/*
void TestTable() {
  Table<bool> t(10, 10);

  for (int i = 0; i < 10; ++i)
  {
	  for (int j = 0; j < 10; ++j)
	  {
		  std::cout << t[i][j] << " ";
	  }
	  std::cout << std::endl;
  }
  std::cout << std::endl;
  t.Resize(15, 15);

  for (int i = 0; i < 15; ++i)
  {
	  for (int j = 0; j < 15; ++j)
	  {
		  std::cout << t[i][j] << " ";
	  }
	  std::cout << std::endl;
  }

  int a = 5;
}

int main() {
	TestTable();
	return 0;
}
*/