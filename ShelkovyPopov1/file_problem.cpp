#include "Libraries.h"

void printWords(int* startIndexes, char* text, int textSize)
{
	int iAmount = startIndexes[0];
	int startI = 0;
	for (int iI = 1; iI < iAmount + 1; iI++)
	{
		startI = startIndexes[iI];
		for (int i = startI; i < textSize + 1; i++)
		{
			char sym = text[i];
			if (isLetter(sym) || isDigit(sym)) cout << sym;
			else break;
		}

		if (iI == iAmount) cout << '.' << endl;
		else cout << ", " << endl;
	}

	cout << endl;
}

void printCharArray(char* arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << arr[i];
	}
	cout << endl;
}

void fileProblemMenuOption()
{
	int size = fileSize();
	char* file = readFile(size);
	int* answer = getStartIOfCorrectWords(file, size, 4);
	int wordsAmount = answer[0];

	system("cls");
	cout << "ÂÂÅÄ¨ÍÍÛÉ ÔÀÉË:" << endl << endl;
	printCharArray(file, size);
	cout << endl << endl;
	cout << SCS_STYLE << "ÎÒÂÅÒ ÇÀÄÀ×È:" << D_STYLE << endl;

	ifstream fileOpen;
	fileOpen.open(getFileName());

	if (fileOpen.fail())
		cout << IMP_STYLE << "Îøèáêà: " << D_STYLE << "Íåâîçìîæíî îòêðûòü ôàéë." << endl;
	else if (size == 0)
		cout << IMP_STYLE << "Îøèáêà: " << D_STYLE << "Ôàéë ïóñò." << endl;
	else if (wordsAmount == 0)
		cout << "Íå íàéäåíî ïîäõîäÿùèõ ñëîâ." << endl;
	else
	{
		cout << "Íàéäåíî ïîäõîäÿùèõ ñëîâ: " << SP << wordsAmount << D_STYLE << endl << endl;
		cout << SP << "ÍÀÉÄÅÍÍÛÅ ÑËÎÂÀ: " << D_STYLE << endl;
		printWords(answer, file, size - 1);
	}

	fileOpen.close();
	delete[] answer;
	delete[] file;
	waitForInput();
}