#include "Libraries.h"

int intPow(int n, int degree)
{
	int result = 1;

	for (; degree != 0; degree--)
	{
		result *= n;
	}

	return result;
}

double doublePow(double d, int degree)
{
	double result = 1.0;

	for (; degree != 0; degree--)
	{
		result *= d;
	}

	return result;
}
