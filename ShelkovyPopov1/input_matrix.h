#pragma once
#include "Libraries.h"
#include "print_number.h"
#include "input_number.h"

template <typename T> void printMatrixInputProgress(T** matrix, int Rows, int Cols, int elementsEntered, char cType)
{
	cout << endl;

	for (int row = 0; row < Rows; row++)
	{
		if (row * Cols == elementsEntered) cout << SCS_STYLE << ">>" << D_STYLE;
		else cout << '|';

		for (int col = 0; col < Cols; col++)
		{
			if (row * Cols + col < elementsEntered)
			{
				cout << '\t';
				printNumber(matrix[row][col], cType);
			}
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

template <typename T> T** inputMatrix(int Rows, int Cols, T type, char cType)
{
	T** matrix = new T* [Rows];
	for (int row = 0; row < Rows; row++)
		matrix[row] = new T[Cols];

	T* elInputInfo = NULL;
	T elInputExitCode = 0;
	T el = 0;

	printDataType(cType);
	printSecondProblemSpecialInfo(false);
	printMatrixInputProgress(matrix, Rows, Cols, 0, cType);

	for (int row = 0; row < Rows; row++)
	{
		for (int col = 0; col < Cols; col++)
		{
			while (true)
			{

				cout << IN_STYLE << "Введите элемент матрицы (" << row << ", " << col << "): " << D_STYLE;
				elInputInfo = inputNumber(type, cType);
				elInputExitCode = elInputInfo[0];
				el = elInputInfo[1];
				delete[] elInputInfo;

				system("cls");
				printDataType(cType);
				printSecondProblemSpecialInfo(false);

				if (elInputExitCode != 0)
				{
					printMatrixInputProgress(matrix, Rows, Cols, row * Cols + col, cType);
					cout << IMP_STYLE << "Ошибка ввода:" << D_STYLE;
					if (cType == 'i')
						cout << " элемент должен быть целым числом. Повторите ввод.\n";
					else if (cType == 'f')
						cout << " элемент должен быть числом с плавающей точкой типа float. Например 3.14f. Не забудьте про суффикс f в конце! Повторите ввод.\n";
					else if (cType == 'd')
						cout << " элемент должен быть числом с плавающей точкой. Повторите ввод.\n";
				}
				else
				{
					matrix[row][col] = el;
					printMatrixInputProgress(matrix, Rows, Cols, row * Cols + col + 1, cType);
					break;
				}
			}
		}
	}

	return matrix;
}