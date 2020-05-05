#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

class SortedStrings {
public:
	void AddString(const string& s) {
		m_strings.insert(s);
	}
	vector<string> GetSortedStrings() {
		vector<string> ret;
		ret.assign(m_strings.begin(), m_strings.end());
		return ret;
	}
private:
	multiset<string> m_strings;
};