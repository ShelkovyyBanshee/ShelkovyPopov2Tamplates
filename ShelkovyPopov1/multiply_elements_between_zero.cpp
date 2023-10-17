#include <iostream>

using namespace std;

void outElements(int *pArray, int size) {
	for (int i = 0; i < size; i++) {
		cout << pArray[i] << ' ';
	}
	cout << endl;
}

int* multyZero(int* pArray, const int size) // resOfFunction = {multBetweenZero, positionOfZero1, positionOfZero1}
{
	int* positionZero = new int[2];
	int tempCountZero = 0;
	int resultMultiply = 1;

	int* resOfFunction = new int[3];

	for (int i = 0; i < size; i++)
	{

		if (pArray[i] == 0 && tempCountZero < 2)
		{
			positionZero[tempCountZero] = i;
			tempCountZero++;
			continue;
		}

		if (tempCountZero == 1)
		{
			resultMultiply *= pArray[i];
		}
	}

	resOfFunction[0] = resultMultiply;
	resOfFunction[1] = positionZero[0] + 1;
	resOfFunction[2] = positionZero[1] + 1;
	delete[] positionZero;

	return resOfFunction;

}


