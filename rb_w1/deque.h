#pragma once

#include <vector>
#include <iostream>
#include <exception>

using namespace std;

/*
	����������� � ������������� ����� At(size_t index), ������������ ����������� ���������� out_of_range, ���� ������ ������ ��� ����� ���������� ��������� � ����;;
	����������� � ������������� ������ ������� Front � Back, ������������ ������ �� ������ � ��������� ������� ���� ��������������;
	������ PushFront � PushBack.
*/

template <typename T>
class Deque
{
public:

	Deque()
	{}

	size_t Size() const
	{
		return (m_frontVec.size() + m_backVec.size());
	}

	bool Empty() const
	{
		return Size() == 0;
	}

	T& operator[](size_t index)
	{
		return At(index);
	}

	const T& operator[](size_t index) const
	{
		return At(index);
	}

	T& At(size_t index)
	{
		if (index >= m_frontVec.size() + m_backVec.size())
		{
			throw std::out_of_range("");
		}

		size_t returnIndex = index;
		if (index < m_frontVec.size())
		{
			returnIndex = m_frontVec.size() - 1 - index;
			return m_frontVec[returnIndex];
		}
		else
		{
			returnIndex = index - m_frontVec.size();
		}

		return m_backVec[returnIndex];
	}

	const T& At(size_t index) const
	{
		if (index >= m_frontVec.size() + m_backVec.size())
		{
			throw std::out_of_range("");
		}

		size_t returnIndex = index;
		if (index < m_frontVec.size())
		{
			returnIndex = m_frontVec.size() - 1 - index;
			return m_frontVec[returnIndex];
		}
		else
		{
			returnIndex = index - m_frontVec.size();
		}

		return m_backVec[returnIndex];
	}

	T& Front()
	{
		if (m_frontVec.empty() && !m_backVec.empty())
		{
			return m_backVec[0];
		}

		return At(0);
	}

	T& Back()
	{
		if (m_backVec.empty() && !m_frontVec.empty())
		{
			return m_frontVec[0];
		}
		return m_backVec.back();
		//return At(Size() - 1);
	}

	const T& Front() const
	{
		if (m_frontVec.empty() && !m_backVec.empty())
		{
			return m_backVec[0];
		}

		return At(0);
	}

	const T& Back() const
	{
		if (m_backVec.empty() && !m_frontVec.empty())
		{
			return m_frontVec[0];
		}
		return m_backVec.back();
	}

	void PushFront(const T& obj)
	{
		m_frontVec.push_back(obj);
	}
	void PushBack(const T& obj)
	{
		m_backVec.push_back(obj);
	}

private:
	std::vector<T> m_frontVec;
	std::vector<T> m_backVec;
};
