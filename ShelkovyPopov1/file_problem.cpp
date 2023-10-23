#include "Libraries.h"

void printWords(int* startIndexes, char* text, int textSize)
{
	int iAmount = startIndexes[0];
	int startI = 0;
	for (int iI = 1; iI < iAmount; iI++)
	{
		startI = startIndexes[iI];
		for (int i = startI; i < textSize; i++)
		{
			char sym = text[i];
			if (isLetter(sym)) cout << sym;
			else break;
		}

		if (iI == iAmount - 1) cout << '.';
		else cout << ", ";
	}

	cout << endl;
}

void fileProblemMenuOption()
{

}