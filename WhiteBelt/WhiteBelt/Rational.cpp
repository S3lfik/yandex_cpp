#include <iostream>
using namespace std;

class Rational {
public:
	Rational() {
		m_numerator = 0;
		m_denominator = 1;
	}

	Rational(int numerator, int denominator) {
		if (!numerator)
		{
			m_numerator = 0;
			m_denominator = 1;
		}
		else
		{
			int sign = (numerator * denominator) > 0 ? 1 : -1;
			int gcd = getGCD(numerator, denominator);
			m_numerator = abs(numerator / gcd) * sign;
			m_denominator = abs(denominator / gcd);
		}		
	}

	int Numerator() const {
		return m_numerator;
	}

	int Denominator() const {
		return m_denominator;
	}

private:
	int getGCD(int lhs, int rhs) const
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

	// Добавьте поля
	int m_numerator;
	int m_denominator;
};

int main() {
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

	cout << "OK" << endl;
	return 0;
}
