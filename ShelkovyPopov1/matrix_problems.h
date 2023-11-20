#pragma once
#include "Libraries.h"


template <typename T> int* findMatrixKRows(T** matrix, int N) //{numOfMatch, indexes of rows/cols{...}}
{
	int* resultMiddle = new int[N];
	int* result = NULL;
	int resultSize = 0;
	int kAmount = 0;
	bool colIsRow = true;

	for (int k = 0; k < N; k++)
	{

		for (int i = 0; i < N; i++)
		{
			if (matrix[k][i] != matrix[i][k])
			{
				colIsRow = false;
				break;
			}
		}

		if (colIsRow)
		{
			resultMiddle[kAmount] = k;
			kAmount += 1;
		}

		colIsRow = true;
	}

	resultSize = kAmount + 1;
	result = new int[resultSize];
	result[0] = kAmount;

	for (int i = 0; i < kAmount; i++)
	{
		result[i + 1] = resultMiddle[i];
	}

	delete[] resultMiddle;

	return result;
}

template <typename T> int countOfNegative(T** matrix, int Rows, int Cols)
{
	bool wasNegative = false;
	int trueCount = 0;

	for (int row = 0; row < Rows; row++)
	{
		for (int col = 0; col < Cols; col++)
		{
			if (matrix[row][col] < 0)
			{
				wasNegative = true;
			}
		}

		if (wasNegative)
		{
			trueCount++;
			wasNegative = false;
		}
	}

	return trueCount;
}

template <typename T> int* indexesOfNegative(T** matrix, int Rows, int Cols) //{it's INDEXES(integer)}
{
	int negativeCount = countOfNegative(matrix, Rows, Cols);
	int* correctRows = new int[negativeCount];
	int temp = 0;

	bool wasNegative = false;

	for (int row = 0; row < Rows; row++)
	{
		for (int col = 0; col < Cols; col++)
		{
			if (matrix[row][col] < 0)
			{
				wasNegative = true;
			}
		}

		if (wasNegative)
		{
			correctRows[temp] = row + 1;
			temp++;
			wasNegative = false;
		}

	}
	return correctRows;
};

template <typename T> T* sumWithNegative(T** matrix, int Rows, int Cols) //{rows/cols - sum(of type of data){...}}
{
	int negativeCount = countOfNegative(matrix, Rows, Cols);
	T* result = new T[negativeCount];

	T sum = 0;
	int temp = 0;

	for (int row = 0; row < Rows; row++)
	{
		for (int col = 0; col < Cols; col++)
		{
			if (matrix[row][col] < (T)0)
			{
				for (int i = 0; i < Cols; i++)
				{
					sum += matrix[row][i];
				}
				break;
			}
		}

		if (sum != (T)0)
		{
			result[temp] = sum;
			temp++;
		}

		sum = 0;
	}

	return result;
}
