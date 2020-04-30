#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class FunctionPart
{
public:
	FunctionPart(const char _operation, const double& _operand)
	{
		operation = _operation;
		operand = _operand;
	}

	double apply(double input) const
	{
		double ret = 0.0;
		if (operation == '+')
		{
			ret = input + operand;
		}
		else if (operation == '-')
		{
			ret = input - operand;
		}
		else if (operation == '*')
		{
			ret = input * operand;
		}
		else if (operation == '/')
		{
			ret = input / operand;
		}
		return ret;
	}

	void invert()
	{
		if (operation == '+')
			operation = '-';
		else if (operation == '-')
			operation = '+';
		else if (operation == '*')
			operation = '/';
		else if (operation == '/')
			operation = '*';
	}

private:
	char operation;
	double operand;
};

class Function
{
public:
	void AddPart(char operation, double operand)
	{
		functionParts.push_back({ operation, operand });
	}

	double Apply(double val) const
	{
		for (auto itr : functionParts)
		{
			val = itr.apply(val);
		}
		return val;
	}

	void Invert()
	{
		for (auto& itr : functionParts)
		{
			itr.invert();
		}
		reverse(functionParts.begin(), functionParts.end());
	}

private:
	vector<FunctionPart> functionParts;
};