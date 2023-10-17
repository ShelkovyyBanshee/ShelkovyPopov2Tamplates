#include "Libraries.h"

void printArray(int* arr, int size)
{
	cout << SP << "[" << D_STYLE;

	for(int i = 0; i < size - 1; i++)
	{
		cout << arr[i] << ", ";
	}

	cout << arr[size - 1] << SP << ']' << D_STYLE << endl;
}