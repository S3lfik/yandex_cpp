int Factorial(const int& val)
{
	if (val <= 1)
	{
		return 1;
	}

	int ret = 1 * val;
	ret *= Factorial(val - 1);

	return ret;
}