#pragma once
#include "Libraries.h"

template <typename T> void deleteMatrix(T** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}