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
