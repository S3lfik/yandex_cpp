#pragma once
#include <string>
#include <vector>


/*
Check is the string is palindrome
*/
bool IsPalindrom(const std::string& str)
{
	if (str.size() < 2)
		return true;

	size_t halfSize = str.size() * 0.5f;
	for (size_t i = 0; i != halfSize; ++i)
	{
		if ((str[i] != str[str.size() - i - 1]) && (i != str.size() - 1 -i))
			return false;
	}

	return true;
}


/*
Return all palindromes from a vector of strings, which length exceeds minLength 
*/
std::vector<std::string> PalindromFilter(const std::vector< std::string >& words, const int minLength)
{
	std::vector<std::string> ret;

	for (auto word : words)
	{
		if (word.length() < static_cast<size_t>(minLength))
		{
			continue;
		}

		if (IsPalindrom(word))
		{
			ret.push_back(word);
		}
	}

	return ret;	
}