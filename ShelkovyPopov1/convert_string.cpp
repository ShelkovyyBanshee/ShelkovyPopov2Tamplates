#include "Libraries.h"

int charToInt(char c)
{
	return (int)c - 48;
}

int strToInt(char* str)
{
	int result = 0;
	int nDigits = 0;
	int startI = 0;
	int signK = 1;

	for(;str[nDigits] != '\0'; nDigits++) {}

	if (nDigits > 0 && str[0] == '-') 
	{
		startI = 1;
		signK = -1;
	}

	for(int i = startI; i < nDigits; i++)
		result += charToInt(str[i]) * intPow(10, nDigits - 1 - i);

	result *= signK;

	return result;
}

double strToDouble(char* str)
{
	double result = 0.0;
	return result;
}
