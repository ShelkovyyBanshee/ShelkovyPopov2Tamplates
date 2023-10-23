#include "Libraries.h"

bool checkZerosPair(int* indexesOfPair)
{
	return indexesOfPair[0] != -1 && indexesOfPair[1] != -1 && abs(indexesOfPair[0] - indexesOfPair[1]) > 2;
}