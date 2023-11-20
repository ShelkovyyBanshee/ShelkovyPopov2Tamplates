#include "Libraries.h"

int inputArraySize(char cType)
{
	int* inputInfo = NULL;
	int inputExitCode = 0;
	int size = 0;

	printFirstProblemSpecialInfo(false);

	while (true)
	{
		cout << IN_STYLE << "Введите размер массива: " << D_STYLE;

		inputInfo = inputInteger();
		inputExitCode = inputInfo[0];
		size = inputInfo[1];
		delete[] inputInfo;

		system("cls");
		printDataType(cType);
		printFirstProblemSpecialInfo(false);

		if (inputExitCode == -1)
		{
			cout << IMP_STYLE << "Ошибка ввода:" << D_STYLE;
			cout << " размер массива должен быть целым положительным числом. Повторите ввод.\n";
		}
		else if (size < 0) 
		{
			cout << IMP_STYLE << "Ошибка ввода:" << D_STYLE;
			cout << " нельзя создать массив отрицательной размерности. Повторите ввод.\n";
		} 
		else if (size == 0) 
		{
			cout << IMP_STYLE << "Ошибка ввода:" << D_STYLE;
			cout << " cоздание пустого массива не имеет смысла ни в одной из задач. Повторите ввод.\n";
		}
		else break;	
	}

	return size;
}

