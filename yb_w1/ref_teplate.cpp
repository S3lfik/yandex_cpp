#include <iostream>
#include <map>
#include <string>
#include <exception>
#include <algorithm>


template <typename Key, typename Val>
Val& GetRefStrict(std::map<Key, Val>& in, const Key& key)
{
	if ( !in.count(key) )
	{
		throw std::runtime_error("no such element");
	}

	return in.at(key);
}

/*
int main()
{
	std::map<std::string, char> l = { {"hello", 'c'} };
	std::string key = "hello";
	char& citem = GetRefStrict(l, key);
	citem = 'd';
	std::cout << l["hello"] << std::endl;
	
	std::map<int, double> n = { {0, 2.5} };
	double& ditem = GetRefStrict(n, 0);
	ditem = 3.5;
	std::cout << n[0] << std::endl;

	std::map<int, std::string> m = { {0, "value"} };
	std::string& item = GetRefStrict(m, 0);
	item = "newvalue";
	std::cout << m[0] << std::endl; // выведет newvalue
	return 0;
}*/