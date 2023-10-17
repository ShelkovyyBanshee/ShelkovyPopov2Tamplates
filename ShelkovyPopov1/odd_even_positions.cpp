#include <iostream>
using namespace std;

int* changeArray(int* pArray, int size) {
	int* oddAndEvenAnswer = new int[size];
	int count = 0;

	for (int i=0;i<size;i++) { //Odd
		if (i % 2 == 1) {
			oddAndEvenAnswer[count] = pArray[i];
			count++;
		}
	}

	for (int i = 0; i < size; i++) { //Even
		if (i % 2 == 0) {
			oddAndEvenAnswer[count] = pArray[i];
			count++;
		}
	}
	return oddAndEvenAnswer;

}
