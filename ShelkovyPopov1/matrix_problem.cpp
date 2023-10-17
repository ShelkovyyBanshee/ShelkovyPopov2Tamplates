#include "Libraries.h"

void kRowsSubOption(int** matrix, int M, int N)
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
	printKRowsInfo(matrix, N, kRows);
	cout << endl;
	delete[] kRows;
}

void printKRowsInfo(int** matrix, int N, int* kRows)
{
	int rowsAmount = kRows[0];

	if (rowsAmount == 0)
	{
		cout << "� �������� ������� �� ������� k-�� �����.\n";
		return;
	}

	cout << "��������� " << SP << "k" << D_STYLE << "-�� ������(�������) :\n";

	int k = 0;
	for (int iK = 1; iK < rowsAmount + 1; iK++)
	{
		k = kRows[iK];

		cout << H_STYLE << iK << ")" << D_STYLE << " c����� " << SP << k << D_STYLE << ": ";
		for (int i = 0; i < N - 1; i++)
		{
			cout << matrix[k][i] << ", ";
		}
		cout << matrix[k][N - 1] << ";\n";
	}
	cout << endl;
}

void matrixProblemMenuOption()
{
	int M = 0;
	int N = 0;
	int** matrix = NULL;

	cout << H_STYLE << "�� ������� ������ < 2 >\n" << D_STYLE;

	M = inputMatrixSize(true);
	N = inputMatrixSize(false);

	system("cls");

	matrix = inputMatrix(M, N);
	cout << SCS_STYLE << "������� ������� �������!\n\n" << D_STYLE;

	int optionNumber = -1;
	while (optionNumber != 0)
	{
		printSecondProblemSpecialInfo();

		optionNumber = inputProblemNumber(2, true);

		system("cls");
		printMatrixInputProgress(matrix, M, N, N * M);

		switch (optionNumber)
		{
		case(-1):
			cout << IMP_STYLE << "������ �����:" << D_STYLE;
			cout << " ������������ ����� ������. ������� ����� ������ �� ������ ����.\n\n";
			break;
		case(0):
			break;
		case(1):
			kRowsSubOption(matrix, M, N);
			break;
		case(2):
			cout << SCS_STYLE << "����� �� ��������� 2:\n" << D_STYLE;
			break;
		}

		if (optionNumber > 0) cout << H_STYLE << ">>�������� ������ ��������� ��� ��������� � ����.\n\n" << D_STYLE;
	}
	
	deleteMatrix(matrix, N);
}