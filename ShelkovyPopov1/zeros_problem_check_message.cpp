#include "Libraries.h"

void printCheckResultZsProblem(int resultOfCheck)
{
	switch(resultOfCheck)
	{
	case(1):
		cout << "Вы не ввели ни одного нулевого элемента. Должно быть 2 нулевых элемента. Повторите ввод.";
		break;
	case(2):
		cout << "Вы ввели только один нулевой элемент. Должно быть 2 нулевых элемента. Повторите ввод.";
		break;
	case(3):
		cout << "Для расчёта произведения необходимо хотя бы 2 элемента между нулями. Повторите ввод.";
	}
}