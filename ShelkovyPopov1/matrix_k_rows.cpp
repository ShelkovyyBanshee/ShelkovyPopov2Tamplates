#include "Libraries.h"

int* findMatrixKRows(int** matrix, int N)
{
	int* resultMiddle = new int[N];
	int* result = NULL;
	int resultSize = 0;
	int kAmount = 0;
	bool colIsRow = true;

	for(int k = 0; k < N; k++)
	{

		for(int i = 0; i < N; i++)
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

	for(int i = 0; i < kAmount; i++)
	{
		result[i + 1] = resultMiddle[i];
	}
	
	delete[] resultMiddle;

	return result;
}
