#include <iostream>
#include "Header.h"
using namespace std;


int main() {
	int n, m;
	cin >> n;
	cin >> m;
	int** pArray = new int* [n];
	for (int i = 0; i < n; i++) {
		pArray[i] = new int[m];
	}
	for (int i = 0; i<n;i++) 
	{
		for (int j =0;j< m; j++) 
		{
			cin >> pArray[i][j];
		}
	}
	int *sums = multWithNegative(pArray, n, m);
	int* ind = indexesOfNegative(pArray, n, m);
	outElements(sums, countOfNegative(pArray, n, m));
	outElements(ind, countOfNegative(pArray, n, m));
	return 0;
}
 