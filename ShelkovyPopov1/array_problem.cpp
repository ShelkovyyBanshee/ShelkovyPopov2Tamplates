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

void arrayProblemMenuOption()
{
    cout << H_STYLE << "ВЫ ВЫБРАЛИ ЗАДАЧУ < 1 >\n" << D_STYLE;

    int* arr = NULL;
    int size = inputArraySize();

    system("cls");

    arr = inputArray(size);
    cout << endl;

    int optionNumber = -1;
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
            int* answer = maxOfElements(arr, size);
            printMaxesInfo(answer);
            cout << endl;
            delete[] answer;
            break;
        case(2):
            cout << endl << SCS_STYLE << "ОТВЕТ НА ПОЗАДАЧУ 2:" << D_STYLE << endl;
        case(3):
            cout << endl << SCS_STYLE << "ОТВЕТ НА ПОЗАДАЧУ 3:" << D_STYLE << endl;
        }

        if (optionNumber > 0) cout << H_STYLE << ">>Выберите другую подзадачу или вернитесь в меню.\n\n" << D_STYLE;
    }

    delete[] arr;
}