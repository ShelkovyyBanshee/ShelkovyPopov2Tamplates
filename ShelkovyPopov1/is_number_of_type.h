#pragma once

#include "Libraries.h"

template <typename T> bool isNumberOfType(char* str, T type, char cType)
{
	int n = (int)strlen(str);
	int startIndex = 0;
	bool wasPoint = false;

	bool isFractional = cType == 'f' || cType == 'd';

	if (str[0] == '-') startIndex += 1;

	if (cType == 'f')
	{
		if (str[n - 1] != 'f' || n - 1 == 0)
			return false;
		n -= 1;
	}

	for (int i = startIndex; i < n; i++)
	{
		char c = str[i];
		if (!isDigit(c))
		{
			if ((c == '.' || c == ',') && !wasPoint && i != n - 1)
			{
				if (isFractional) wasPoint = true;
				else return false;
			} 
			else return false;
		}
	}

	return (cType == 'f' || cType == 'd') == wasPoint;
}