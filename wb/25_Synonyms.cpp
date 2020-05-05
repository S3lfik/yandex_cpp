#include <map>
#include <set>
#include <string>
#include <iostream>

using namespace std;

map<string, set<string>> gBadGlobalSynonyms;

bool checkSynonyms(const string& str1, const string& str2);
int count(const string& str);

int main()
{
	string command = "";
	int commandsNum = 0;

	cin >> commandsNum;

	for (int i = 0; i < commandsNum; i++)
	{
		cin >> command;

		if (command == "ADD")
		{
			string word1, word2;
			cin >> word1 >> word2;
			gBadGlobalSynonyms[word1].insert(word2);
			gBadGlobalSynonyms[word2].insert(word1);
		}
		else if (command == "COUNT")
		{
			string word;
			cin >> word;
			cout << count(word) << endl;
		}
		else if (command == "CHECK")
		{
			string word1, word2;
			cin >> word1 >> word2;

			if (checkSynonyms(word1, word2))
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}			
		}			
	}

	return 0;
}

bool checkSynonyms(const string& str1, const string& str2)
{
	if (gBadGlobalSynonyms.count(str1))
	{
		if (gBadGlobalSynonyms[str1].count(str2))
			return true;
	}

	return false;
}

int count(const string& str)
{
	return gBadGlobalSynonyms[str].size();
}