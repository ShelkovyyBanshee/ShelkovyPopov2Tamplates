#include <iostream>


int countOfNegative(int** array, int n, int m)
{
	bool fl = true;
	int trueCount = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (array[i][j] < 0)
			{
				fl = false;
			}
		}
		if (fl == false) {
			trueCount++;
			fl = true;
		}
	}
	return trueCount;
}
int* indexesOfNegative(int** array, int n, int m)
{
	int count = countOfNegative(array, n, m);
	int* elements = new int[count];
	int temp = 0;

	bool fl = true;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (array[i][j] < 0)
			{
				fl = false;
			}
		}
		if (fl == false) {
			elements[temp] = i+1;
			temp++;
			fl = true;
		}

	}
	return elements;
};


int* multWithNegative(int** array, int n, int m)
{
	int count = countOfNegative(array, n , m);
	int* elements = new int[count];

	int sum = 0;
	int temp = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (array[i][j] < 0)
			{
				for (int k = 0; k < m; k++)
				{
					sum += array[i][k];
				} break;
			}
		}
		if (sum != 0) {
			elements[temp] = sum;
			temp++;
		}
		sum = 0;

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << array[i][j] << '\t';
		} 
		std::cout << std::endl;
	}
	return elements;
};
