#include "Libraries.h"

int* multiplyZero(int* pArray, const int size) // resOfFunction = {multBetweenZero, positionOfZero1, positionOfZero1}
{
	int* positionZero = getIndexesOfZsPair(pArray, size);
	int composition = 1;

	int* result = new int[3];

	for (int i = positionZero[0] + 1; i < positionZero[1]; i++)
	{
		composition *= pArray[i];
	}

	result[0] = composition;
	result[1] = positionZero[0];
	result[2] = positionZero[1];
	delete[] positionZero;

	return result;

}


