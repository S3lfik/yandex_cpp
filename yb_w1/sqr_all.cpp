#include <iostream>
#include <map>
#include <vector>
#include <utility>


template <typename T>
T Sqr(const T& in)
{
	return in * in;
}

template <typename Key, typename Value> 
std::pair<Key, Value> Sqr(const std::pair<Key, Value>& in);

template <typename Val>
std::vector<Val> Sqr(const std::vector<Val>& in);

template <typename Key, typename Value>
std::map<Key, Value> Sqr(const std::map<Key, Value>& in);


template <typename Key, typename Value>
std::pair<Key, Value> Sqr(const std::pair<Key, Value>& in)
{
	return std::pair<Key, Value> { Sqr(in.first), Sqr(in.second) };
}


template <typename Val>
std::vector<Val> Sqr(const std::vector<Val>& in)
{
	std::vector<Val> ret;

	for (auto iter : in)
	{
		ret.push_back(Sqr(iter));
	}

	return ret;
}

template <typename Key, typename Value>
std::map<Key, Value> Sqr(const std::map<Key, Value>& in)
{
	std::map<Key, Value> ret;

	for (auto iter : in)
	{
		ret[iter.first] = Sqr(iter.second);
	}

	return ret;
}

int main()
{
	return 0;
}