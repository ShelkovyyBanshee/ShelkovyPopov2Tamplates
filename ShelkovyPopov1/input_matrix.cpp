#include "Libraries.h"

int inputMatrixSize(bool inputFirstSize)
{
	int* inputInfo = NULL;
	int inputExitCode = 0;
	int N = 0;

	char var = inputFirstSize ? 'M' : 'N';

	while(true)
	{
		if (inputFirstSize) cout << "Введите кол-во строк " << SP << "M" << D_STYLE; 
		else cout << "Введите кол-во столбов " << SP << "N" << D_STYLE;

		cout << " <= 8 для матрицы " << SP << "M" << D_STYLE << "x" << SP << "N" << D_STYLE << ": ";
		

		inputInfo = inputInteger();
		inputExitCode = inputInfo[0];
		N = inputInfo[1];
		delete[] inputInfo;

		system("cls");

		if (inputExitCode == -1) 
		{
			cout << IMP_STYLE << "Ошибка ввода:" << D_STYLE;
			cout << " число " << SP << var << D_STYLE << " должно быть целым положительным числом. Повторите ввод.\n";
		} 
		else if (N == 0) 
		{
			cout << IMP_STYLE << "Ошибка ввода:" << D_STYLE;
			cout << " матрица нулевой размерности не имеет смысла ни в одной из задача. Повторите ввод.\n";
		} 
		else if (N < 0) 
		{
			cout << IMP_STYLE << "Ошибка ввода:" << D_STYLE;
			cout << " число " << SP << var << D_STYLE << " должно быть положительным числом.\n";
		} 
		else if (N > 8) 
		{
			cout << IMP_STYLE << "Ошибка ввода:" << D_STYLE;
			cout << " число " << SP << var << D_STYLE << " не должно превышать 8. Повторите ввод.\n";
		} 
		else break;
	}
	
	return N;
}

void printMatrixInputProgress(int** matrix, int Rows, int Cols, int elementsEntered)
{
	cout << endl;

	for (int row = 0; row < Rows; row++)
	{
		if (row * Cols == elementsEntered) cout << SCS_STYLE << ">>" << D_STYLE;
		else cout << '|';

		for (int col = 0; col < Cols; col++)
		{
			if (row * Cols + col < elementsEntered)
				cout << '\t' << matrix[row][col];
			else 
				cout << '\t' << "...";
			if (row * Cols + col == elementsEntered - 1 && col != Cols - 1) 
				cout << SCS_STYLE << "\t>>" << D_STYLE;
			else
				cout << "\t|";
		}

		cout << endl << endl << endl;
	}
}

int** inputMatrix(int Rows, int Cols)
{
	int** matrix = new int*[Rows];
	
	int* elInputInfo = NULL;
	int elInputExitCode = 0;
	int el = 0;

	printMatrixInputProgress(matrix, Rows, Cols, 0);

	for (int row = 0; row < Rows; row++)
	{
		matrix[row] = new int[Cols];

		for (int col = 0; col < Cols; col++)
		{
			
			while (true)
			{
				
				cout << IN_STYLE << "Введите элемент матрицы (" << row << ", " << col << "): " << D_STYLE;
				elInputInfo = inputInteger();
				elInputExitCode = elInputInfo[0];
				el = elInputInfo[1];
				delete[] elInputInfo;

				system("cls");

				if (elInputExitCode != 0) 
				{
					printMatrixInputProgress(matrix, Rows, Cols, row * Cols + col);
					cout << IMP_STYLE << "Ошибка ввода:" << D_STYLE;
					cout << " элемент должен быть целым числом. Повторите ввод.\n";
				} 
				else
				{
					matrix[row][col] = el;
					printMatrixInputProgress(matrix, Rows, Cols, row * Cols + col + 1);
					break;
				}	
			}
		}
	}

	return matrix;
}