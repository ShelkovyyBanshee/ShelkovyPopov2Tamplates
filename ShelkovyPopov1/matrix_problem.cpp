#include "Libraries.h"

void kRowsSubOption(int** matrix, int M, int N)
{
	int* kRows = NULL;

	if (M != N)
	{
		cout << IMP_STYLE << "Невозможно выполнить подзадачу 1:" << D_STYLE;
		cout << " для выполнения задачи 1 подходит только квадратная матрица.\n";
		delete[] kRows;
		return;
	}

	kRows = findMatrixKRows(matrix, N);
	cout << SCS_STYLE << "ОТВЕТ НА ПОДЗАДАЧУ 1:\n" << D_STYLE;
	printKRowsInfo(matrix, N, kRows);
	cout << endl;
	delete[] kRows;
}

void printKRowsInfo(int** matrix, int N, int* kRows)
{
	int rowsAmount = kRows[0];

	if (rowsAmount == 0)
	{
		cout << "В заданной матрице не найдено k-ых строк.\n";
		return;
	}

	cout << "Найденные " << SP << "k" << D_STYLE << "-ые строки(столбцы) :\n";

	int k = 0;
	for (int iK = 1; iK < rowsAmount + 1; iK++)
	{
		k = kRows[iK];

		cout << H_STYLE << iK << ")" << D_STYLE << " cтрока " << SP << k << D_STYLE << ": ";
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

	cout << H_STYLE << "ВЫ ВЫБРАЛИ ЗАДАЧУ < 2 >\n" << D_STYLE;

	M = inputMatrixSize(true);
	N = inputMatrixSize(false);

	system("cls");

	matrix = inputMatrix(M, N);
	cout << SCS_STYLE << "Матрица успешно введена!\n\n" << D_STYLE;

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
			cout << IMP_STYLE << "Ошибка ввода:" << D_STYLE;
			cout << " некорректный номер задачи. Введите номер задачи из списка ниже.\n\n";
			break;
		case(0):
			break;
		case(1):
			kRowsSubOption(matrix, M, N);
			break;
		case(2):
			cout << SCS_STYLE << "ОТВЕТ НА ПОДЗАДАЧУ 2:\n" << D_STYLE;
			break;
		}

		if (optionNumber > 0) cout << H_STYLE << ">>Выберите другую подзадачу или вернитесь в меню.\n\n" << D_STYLE;
	}
	
	deleteMatrix(matrix, N);
}