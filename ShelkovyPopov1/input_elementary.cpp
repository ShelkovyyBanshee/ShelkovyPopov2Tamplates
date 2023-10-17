#include "Libraries.h"

char* inputString(int symCount)
{
	char* string = new char[symCount + 1];
	cin.getline(string, symCount + 1);

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return string;
}

// первое значение возвращаемого динамического массива - код выполнения ввода
// 0 - успешный ввод
// -1 - неуспешный ввод
// втоорое значение - введённое число (по умолчанию 0)
int* inputInteger()
{
	int* result = new int[2]{ -1, 0 };
	char* input = inputString(11);

	if (isInteger(input))
	{
		result[0] = 0;
		result[1] = strToInt(input);
	}

	delete[] input;

	return result;
}