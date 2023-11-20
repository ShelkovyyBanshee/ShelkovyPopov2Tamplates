#pragma once
#include "Libraries.h"

template <typename T> T strToNumber(char* str, T type)
{
	T result = 0;
	int nDigits = 0;
	int nIntDigits = 0;
	int nAfterPointDigits = 0;
	int startI = 0;
	T signK = 1;

	bool intCounted = false;
	for (;str[nDigits] != '\0' && str[nDigits] != 'f'; nDigits++)
	{
		if (str[nDigits] == '.' || str[nDigits] == ',')
		{
			intCounted = true;
			continue;
		}

		if (!intCounted)
			nIntDigits += 1;
		else
			nAfterPointDigits += 1;
	}

	if (nDigits > 0 && str[0] == '-')
	{
		startI = 1;
		signK = -1;
	}

	bool wasPoint = false;
	for (int i = startI; i < nDigits; i++)
	{
		if (str[i] == '.' || str[i] == ',')
		{
			wasPoint = true;
			continue;
		}

		if (!wasPoint)
			result += (T)charToInt(str[i]) * (T)intPow(10, nIntDigits - 1 - i);
		else
			result += (T)charToInt(str[i]) / (T)intPow(10, i - nIntDigits);
	}
		

	result *= signK;

	return result;
}
