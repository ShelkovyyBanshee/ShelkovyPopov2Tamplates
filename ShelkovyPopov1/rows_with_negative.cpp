#include <iostream>


int countOfNegative(int** matrix, int Rows, int Cols)
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

int* indexesOfNegative(int** matrix, int Rows, int Cols)
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
}


int* sumWithNegative(int** matrix, int Rows, int Cols)
{
	int negativeCount = countOfNegative(matrix, Rows, Cols);
	int* result = new int[negativeCount];

	int sum = 0;
	int temp = 0;

	for (int row = 0; row < Rows; row++)
	{
		for (int col = 0; col < Cols; col++)
		{
			if (matrix[row][col] < 0)
			{
				for (int i = 0; i < Cols; i++)
				{
					sum += matrix[row][i];
				} 
				break;
			}
		}

		if (sum != 0) 
		{
			result[temp] = sum;
			temp++;
		}

		sum = 0;
	}

	return result;
}
