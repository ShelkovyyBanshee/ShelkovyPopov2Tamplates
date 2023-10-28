#include "Libraries.h"

bool isDigit(char c)
{
	return c >= 48 && c <= 57;
}

bool isInteger(char* str)
{
	int n = (int)strlen(str);
	int startIndex = 0;

	if (n == 0) return false;

	if (str[0] == '-') startIndex += 1;
	
	for (int i = startIndex; i < n; i++)
	{
		char c = str[i];
		if (!isDigit(c)) return false;
	}
	return true;
}

bool isFractionalOrInteger(char* str)
{
	int n = (int)strlen(str) - 1;
	int startIndex = 0;
	bool wasPoint = false;

	if (str[0] == '-') startIndex += 1;

	for (int i = startIndex; i < n; i++)
	{
		char c = str[i];
		if (!isDigit(c))
		{
			if ((c == '.' || c == ',') && !wasPoint) wasPoint = true;
			else return false;
		}
	}

	return true;
}

bool isLetter(char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= 'à' && c <= 'ÿ') || (c >= 'À' && c <= 'ß');
}