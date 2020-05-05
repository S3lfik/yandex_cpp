#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int getGCD(int lhs, int rhs)
{
	lhs = abs(lhs);
	rhs = abs(rhs);
	while (lhs > 0 && rhs > 0)
	{
		if (lhs > rhs)
		{
			lhs %= rhs;
		}
		else
		{
			rhs %= lhs;
		}
	}
	return lhs + rhs;
}

class Rational {
public:
	Rational() {
		m_numerator = 0;
		m_denominator = 1;
	}

	Rational(int numerator, int denominator) {
		if (!denominator)
		{
			throw invalid_argument(string(numerator + "/" + denominator));
		}
		if (!numerator)
		{
			m_numerator = 0;
			m_denominator = 1;
		}
		else
		{
			shortenRationalParts(numerator, denominator);
			m_numerator = numerator;
			m_denominator = denominator;
		}		
	}

	int Numerator() const {
		return m_numerator;
	}

	int Denominator() const {
		return m_denominator;
	}

private:

	void shortenRationalParts(int& num, int& denom) const
	{
		int sign = (long(num) * long(denom)) > 0 ? 1 : -1;
		int gcd = getGCD(num, denom);
		num = abs(num / gcd) * sign;
		denom = abs(denom / gcd);
	}

	int m_numerator;
	int m_denominator;
};

Rational operator+(const Rational& lhs, const Rational& rhs)
{
	int num, denom;
	if (lhs.Denominator() == rhs.Denominator())
	{
		denom = lhs.Denominator();
		num = lhs.Numerator() + rhs.Numerator();
	}
	else
	{
		num = lhs.Numerator() * rhs.Denominator() + lhs.Denominator() * rhs.Numerator();
		denom = lhs.Denominator() * rhs.Denominator();
	}

	return Rational(num, denom);
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
	if (!rhs.Numerator())
	{
		throw domain_error("zero division");
	}
	return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
	return lhs + Rational(-rhs.Numerator(), rhs.Denominator());
}

bool operator==(const Rational& lhs, const Rational& rhs)
{
	
	return (lhs.Numerator() == rhs.Numerator())
		&& (lhs.Denominator() == rhs.Denominator());
}

bool operator!=(const Rational& lhs, const Rational& rhs)
{
	return !(lhs == rhs);
}

istream& operator>>(istream& input, Rational& r)
{
	int num = 0;
	int denom = 0;
	char delim = 0;

	if( input)
	{
		input >> num >> delim >> denom;
		if( input && delim == '/')
			r = Rational(num, denom);
	}
	
	return input;
}

ostream& operator<<(ostream& output, const Rational& r)
{
	output << r.Numerator() << "/" << r.Denominator();

	return output;
}

bool operator<(const Rational& lhs, const Rational& rhs)
{
	return (lhs - rhs).Numerator() < 0;
}

int main() 
{
	{
		const Rational r(3, 10);
		if (r.Numerator() != 3 || r.Denominator() != 10) {
			cout << "Rational(3, 10) != 3/10" << endl;
			return 1;
		}
	}

	{
		const Rational r(8, 12);
		if (r.Numerator() != 2 || r.Denominator() != 3) {
			cout << "Rational(8, 12) != 2/3" << endl;
			return 2;
		}
	}

	{
		const Rational r(-4, 6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(-4, 6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(4, -6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(4, -6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(-4, -6);
		if (r.Numerator() != 2 || r.Denominator() != 3) {
			cout << "Rational(-4, -6) != 2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(0, 15);
		if (r.Numerator() != 0 || r.Denominator() != 1) {
			cout << "Rational(0, 15) != 0/1" << endl;
			return 4;
		}
	}

	{
		const Rational defaultConstructed;
		if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
			cout << "Rational() != 0/1" << endl;
			return 5;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a + b;
		bool equal = c == Rational(2, 1);
		if (!equal) {
			cout << "2/3 + 4/3 != 2" << endl;
			return 2;
		}
	}

	{
		Rational a(5, 7);
		Rational b(2, 9);
		Rational c = a - b;
		bool equal = c == Rational(31, 63);
		if (!equal) {
			cout << "5/7 - 2/9 != 31/63" << endl;
			return 3;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a * b;
		bool equal = c == Rational(8, 9);
		if (!equal) {
			cout << "2/3 * 4/3 != 8/9" << endl;
			return 1;
		}
	}

	{
		Rational a(5, 4);
		Rational b(15, 8);
		Rational c = a / b;
		bool equal = c == Rational(2, 3);
		if (!equal) {
			cout << "5/4 / 15/8 != 2/3" << endl;
			return 2;
		}
	}

	{
		ostringstream output;
		output << Rational(-6, 8);
		if (output.str() != "-3/4") {
			cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
			return 1;
		}
	}

	{
		istringstream input("5/7");
		Rational r;
		input >> r;
		bool equal = r == Rational(5, 7);
		if (!equal) {
			cout << "5/7 is incorrectly read as " << r << endl;
			return 2;
		}
	}

	{
		istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;
		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
			return 3;
		}

		input >> r1;
		input >> r2;
		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
			return 4;
		}
	}

	{
		const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
		if (rs.size() != 3) {
			cout << "Wrong amount of items in the set" << endl;
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs) {
			v.push_back(x);
		}
		if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
			cout << "Rationals comparison works incorrectly" << endl;
			return 2;
		}
	}

	{
		map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2) {
			cout << "Wrong amount of items in the map" << endl;
			return 3;
		}
	}

	try {
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	}
	catch (invalid_argument&) {
	}

	try {
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	}
	catch (domain_error&) {
	}

	cout << "OK" << endl;

	cout << "OK" << endl;
	return 0;
}
