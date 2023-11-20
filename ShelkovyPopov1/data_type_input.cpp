#include "Libraries.h"

char inputIFDChar()
{
	char* input = inputString(2);
	int len = (int)strlen(input);
	char sym = input[0];
	delete[] input;

	if (len == 1 && (sym == 'f' || sym == 'i' || sym == 'd')) return sym;
	else return '\0';
}

char inputDataType(int problemNumber)
{
	char result = '-';
	while(true)
	{
		cout << H_STYLE << "ВЫ ВЫБРАЛИ ЗАДАЧУ <" << problemNumber << ">\n\n" << D_STYLE;
		if (problemNumber == 1)
			printFirstProblemSpecialInfo(false);
		else
			printSecondProblemSpecialInfo(false);
		
		cout << H_STYLE << "ВЫБЕРИТЕ ТИП ДАННЫХ В ";
		cout << ((problemNumber == 1) ? "МАССИВЕ" : "МАТРИЦЕ");
		cout << ":\n" << D_STYLE;
		cout << "\n>> i - целый тип int\n";
		cout << "\n>> f - число с плавающей точкой float\n";
		cout << "\n>> d - число с плавающей точкой double\n";

		if (result == '\0') cout << IMP_STYLE << "Ошибка ввода:" << D_STYLE << "Команда не опознана. Вы должны ввести один из трёх символов: i, f, d\n";

		cout << SP << "Введите символ типа: " << D_STYLE;
		
		result = inputIFDChar();

		if (result != '\0')
			break;

		system("cls");
	}
	
	return result;
}

