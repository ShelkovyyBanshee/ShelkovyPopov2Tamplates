#pragma once
#include "Libraries.h"
#include "matrix_problems.h"
#include "input_matrix.h"
#include "delete_matrix.h"
#include "input_number.h"

template <typename T> void printKRowsInfo(T** matrix, int N, int* kRows, char cType)
{
	int rowsAmount = kRows[0];

	if (rowsAmount == 0)
	{
		cout << "� �������� ������� �� ������� k-�� �����.\n";
		return;
	}

	cout << "��������� " << SP << "k" << D_STYLE << "-�� ������ (�������):\n";

	int k = 0;
	for (int iK = 1; iK < rowsAmount + 1; iK++)
	{
		k = kRows[iK];

		cout << H_STYLE << iK << ")" << D_STYLE << " c����� " << SP << k << D_STYLE << ". �������� ������: ";
		for (int i = 0; i < N - 1; i++)
		{
			printNumber(matrix[k][i], cType);
			cout << ", ";
		}
		printNumber(matrix[k][N - 1], cType);
		cout << "\n";
	}
	cout << endl;
}

template <typename T> void kRowsSubOption(T** matrix, int M, int N, char cType)
{
	int* kRows = NULL;

	if (M != N)
	{
		cout << IMP_STYLE << "���������� ��������� ��������� 1:" << D_STYLE;
		cout << " ��� ���������� ������ 1 �������� ������ ���������� �������.\n";
		delete[] kRows;
		return;
	}

	kRows = findMatrixKRows(matrix, N);
	cout << SCS_STYLE << "����� �� ��������� 1:\n" << D_STYLE;
	printKRowsInfo(matrix, N, kRows, cType);
	cout << endl;
	delete[] kRows;
}

template <typename T> void printRowsWithNegativeInfo(int* iOfCorrectRows, T* sums, int amountOfCorrect, char cType)
{
	for (int i = 0; i < amountOfCorrect; i++)
	{
		cout << H_STYLE << i + 1 << ')' << D_STYLE;
		cout << " ������ " << SP << iOfCorrectRows[i] << D_STYLE << ". �����: ";
		printNumber(sums[i], cType);
		cout << endl;
	}
}

template <typename T> void rowsWithNegativeSubProblem(T** matrix, int Rows, int Cols, char cType)
{
	int* iOfCorrectRows = NULL;
	T* sums = NULL;

	cout << SCS_STYLE << "����� �� ��������� 1:\n" << D_STYLE;

	int amountOfCorrect = countOfNegative(matrix, Rows, Cols);

	if (amountOfCorrect == 0)
	{
		cout << "�� ������� ����� � �������������� ����������.\n\n";
		return;
	}

	iOfCorrectRows = indexesOfNegative(matrix, Rows, Cols);
	sums = sumWithNegative(matrix, Rows, Cols);

	printRowsWithNegativeInfo(iOfCorrectRows, sums, amountOfCorrect, cType);
	cout << endl << endl;

	delete[] iOfCorrectRows;
	delete[] sums;
}

template <typename T> void matrixProblemMenuOption(T t, char cType)
{
	int M = 0;
	int N = 0;
	T** matrix = NULL;

	printDataType(cType);
	cout << H_STYLE << "�� ������� ������ < 2 >\n\n" << D_STYLE;

	M = inputMatrixSize(true, cType);

	system("cls");
	printDataType(cType);

	N = inputMatrixSize(false, cType);

	system("cls");

	matrix = inputMatrix(M, N, t, cType);
	system("cls");
	printDataType(cType);
	printMatrixInputProgress(matrix, M, N, M * N, cType);
	cout << SCS_STYLE << "������� ������� �������!\n\n" << D_STYLE;

	int optionNumber = -1;
	while (optionNumber != 0)
	{
		printSecondProblemSpecialInfo();

		optionNumber = inputProblemNumber(2, true);

		system("cls");
		printDataType(cType);
		printMatrixInputProgress(matrix, M, N, N * M, cType);

		switch (optionNumber)
		{
		case(-1):
			cout << IMP_STYLE << "������ �����:" << D_STYLE;
			cout << " ������������ ����� ������. ������� ����� ������ �� ������ ����.\n\n";
			break;
		case(0):
			break;
		case(1):
			kRowsSubOption(matrix, M, N, cType);
			break;
		case(2):
			rowsWithNegativeSubProblem(matrix, M, N, cType);
			break;
		}

		if (optionNumber > 0) cout << H_STYLE << ">>�������� ������ ��������� ��� ��������� � ����.\n\n" << D_STYLE;
	}

	deleteMatrix(matrix, M);
}