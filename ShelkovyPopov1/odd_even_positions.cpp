#include "Libraries.h"

int* oddEvenITransformArray(int* pArray, int size)
{
	int* resultArray = new int[size];
	int iR = 0;

	for (int i = 1; i < size; i += 2, iR++) 
	{ 
		resultArray[iR] = pArray[i];
	}

	for (int i = 0; i < size; i += 2, iR++)
	{
		resultArray[iR] = pArray[i];
	}

	return resultArray;

}
