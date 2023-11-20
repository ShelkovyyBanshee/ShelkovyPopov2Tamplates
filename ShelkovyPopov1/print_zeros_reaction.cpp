#include "Libraries.h"

void printZerosWrongInputInfo(int* indexesOfPair)
{
    int iFirst = indexesOfPair[0];
    int iSecond = indexesOfPair[1];

    cout << IMP_STYLE << "Невозможно решить задачу: " << D_STYLE;

    if (iFirst == -1)
    {
        cout << "в введённом массиве не найдено нулевых элементов." << endl;
        cout << "Для решения задачи в массиве должно быть 2 нулевых элемента." << endl;
    }
    else if (iSecond == -1)
    {
        cout << "в введённом массиве только один нулевой элемент." << endl;
        cout << "Для решения задачи в массиве должно быть 2 нулевых элемента." << endl;
    }
    else if (iSecond - iFirst == 1)
    {
        cout << "нулевые элементы идут подряд. Между нулевыми элементами должно быть хотя бы 2 элемента для рассчёта произведения." << endl;
    }
    else if (iSecond - iFirst == 2)
    {
        cout << "между нулевыми элементами должно быть хотя бы 2 элемента для рассчёта произведения, но найден только один." << endl;
    }
}