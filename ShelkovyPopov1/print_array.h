#pragma once
#include "Libraries.h"
#include "print_number.h"

template <typename T> void printArray(T* arr, int size, char cType)
{
	cout << SP << "[" << D_STYLE;
	for (int i = 0; i < size - 1; i++)
	{
		printNumber(arr[i], cType);
		cout << ", ";
	}

	printNumber(arr[size - 1], cType);
	cout << SP << ']' << D_STYLE << endl;
}