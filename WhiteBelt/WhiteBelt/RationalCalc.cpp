#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <exception>

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
			throw invalid_argument("");
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
		throw domain_error("");
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

//-------------------------------------------------------

Rational calculate(const Rational& lhs, const Rational& rhs, char operation)
{
	Rational ret;
	switch (operation)
	{
	case '+':
		ret = lhs + rhs;
		break;
	case '-':
		ret = lhs - rhs;
		break;
	case '*':
		ret = lhs * rhs;
		break;
	case '/':
		ret = lhs / rhs;
		break;
	default:
		break;
	}

	return ret;
}

void readRequest(Rational& out_a, Rational& out_b, char& out_oper)
{
		cin >> out_a;
		cin >> out_oper;
		cin >> out_b;
}

int main() 
{
	Rational a, b, result;
	char operation;

	try
	{
		readRequest(a, b, operation);
		result = calculate(a, b, operation);
		cout << result;
	}
	catch (invalid_argument& e)
	{
		cout << "Invalid argument" << endl;
	}
	catch (domain_error& e)
	{
		cout << "Division by zero" << endl;
	}	

	return 0;
}
