#include "Libraries.h"

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
        }

        if (optionNumber > 0) cout << H_STYLE << ">>Выберите другую подзадачу или вернитесь в меню.\n\n" << D_STYLE;
    }

    delete[] arr;
}