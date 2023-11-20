#pragma once
#include "Libraries.h"

template <typename T> void printNumber(T number, char cType)
{
	if (abs((double)number) > doublePow(10.0, 26))
	{
		if (cType == 'f')
			cout << "0.0f";
		else
			cout << "0.0";
	} 
	else cout << number;

	if ((cType == 'f' || cType == 'd') && (T)(int)number == number)
		cout << ".0";

	if (cType == 'f') cout << 'f';
}