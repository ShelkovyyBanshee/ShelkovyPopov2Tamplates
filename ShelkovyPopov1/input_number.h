#pragma once
#include "Libraries.h"
#include "is_number_of_type.h"
#include "string_to_number.h"

template <typename T> T* inputNumber(T type, char cType)
{
	T* result = new T[2]{ -1, 0 };
	char* input = NULL;

	if (cType == 'i')
		input = inputString(11);
	else if (cType == 'f')
		input = inputString(19);
	else
		input = inputString(26);

	if (isNumberOfType(input, type, cType))
	{
		result[0] = 0;
		result[1] = strToNumber(input, type);
	}

	delete[] input;

	return result;
}