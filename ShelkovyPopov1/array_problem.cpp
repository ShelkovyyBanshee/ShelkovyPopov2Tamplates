#include "Libraries.h"

void printMaxesInfo(int* info)
{
    int maxEl = info[0];
    int amount = info[1];

    cout << "Максимальный элемент массива: " << SP << maxEl << D_STYLE << endl;
    cout << "Найдено таких элементов: " << SP << amount << D_STYLE << endl;
    cout << "Индексы найденных элементов: ";
    for(int i = 2; i < amount + 1; i++)
    {
        cout << info[i] << ", ";
    }
    cout << info[amount + 1] << endl;
}

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
    else if (iSecond - iFirst == 2)
    {
        cout << "нулевые элементы идут подряд. Между нулевыми элементами должно быть хотя бы 2 элемента для рассчёта произведения." << endl;
    }
    else if (iSecond - iFirst == 2)
    {
        cout << "между нулевыми элементами должно быть хотя бы 2 элемента для рассчёта произведения, но найден только один." << endl; 
    }
}


void arrayProblemMenuOption()
{
    cout << H_STYLE << "ВЫ ВЫБРАЛИ ЗАДАЧУ < 1 >\n" << D_STYLE;

    int* arr = NULL;
    int size = inputArraySize();

    system("cls");
    arr = inputArray(size);
    cout << endl;

    int optionNumber = -1;
    int* answer = NULL;
    int* indexesZeros = NULL;

    while(optionNumber != 0)
    {
        printFirstProblemSpecialInfo();

        optionNumber = inputProblemNumber(3, true);

        system("cls");

        cout << SCS_STYLE << "Введённый массив: " << D_STYLE;
        printArray(arr, size);

        switch(optionNumber)
        {
        case(-1):
            cout << IMP_STYLE << "Ошибка ввода:" << D_STYLE;
            cout << " некорректный номер задачи. Введите номер задачи из списка ниже.\n\n";
            break;
        case(0):
            break;
        case(1):
            cout << endl << SCS_STYLE << "ОТВЕТ НА ПОДЗАДАЧУ 1:" << D_STYLE << endl;
            answer = maxOfElements(arr, size);
            printMaxesInfo(answer);
            cout << endl;
            delete[] answer;
            break;
        case(2):
            cout << endl << SCS_STYLE << "ОТВЕТ НА ПОДЗАДАЧУ 2:" << D_STYLE << endl;
            indexesZeros = getIndexesOfZsPair(arr, size);
            if (!checkZerosPair(indexesZeros))
            {
                printZerosWrongInputInfo(indexesZeros);
            }
            else
            {
                answer = multiplyZero(arr, size);
                cout << "Найденное произведение: " << answer[0] << endl;
                cout << "Индексы первых двух нулевых элементов: " << answer[1] << " " << answer[2] << endl;
                delete[] answer;
            }
            cout << endl;
            delete[] indexesZeros;
            break;
        case(3):
            cout << endl << SCS_STYLE << "ОТВЕТ НА ПОДЗАДАЧУ 3:" << D_STYLE << endl;
            answer = oddEvenITransformArray(arr, size);
            cout << "Введённый массив:\t";
            printArray(arr, size);
            cout << endl;
            cout << "Преобразованный массив:\t";
            printArray(answer, size);
            cout << endl << endl;
            delete[] answer;
            break;
        }

        if (optionNumber > 0) cout << H_STYLE << ">>Выберите другую подзадачу или вернитесь в меню.\n\n" << D_STYLE;
    }

    delete[] arr;
}