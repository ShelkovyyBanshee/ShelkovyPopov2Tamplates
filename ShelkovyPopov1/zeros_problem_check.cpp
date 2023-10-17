#include "Libraries.h"

int zerosProblemCheck(int* elements, int size)
{
	int result = 0;
	int* indexesOfZs = getIndexesOfZsPair(elements, size);
	int elementsBetweenZs = indexesOfZs[1] - indexesOfZs[0];
	
	if (indexesOfZs[0] == -1 && indexesOfZs[1] == -1)
		result = 1;
	else if (indexesOfZs[1] == -1)
		result = 2;
	else if (elementsBetweenZs >= 0)
		result = 3;
	else
		result = 0;

	delete[] indexesOfZs;
	return result;
}