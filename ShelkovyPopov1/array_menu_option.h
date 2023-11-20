#pragma once

#include "Libraries.h"
#include "input_array.h"
#include "array_problems.h"
#include "print_array.h"
#include "print_number.h"

template <typename T> void printMaxesInfo(T maxEl, int* info, char cType)
{
    int amount = info[0];

    cout << "Максимальный элемент массива: " << SP;
    printNumber(maxEl, cType);
    cout << D_STYLE << endl;
    cout << "Найдено таких элементов: " << SP << amount << D_STYLE << endl;
    cout << "Индексы найденных элементов: ";
    for (int i = 1; i < amount; i++)
    {
        cout << info[i] << ", ";
    }
    cout << info[amount] << endl;
}


template <typename T> void arrayProblemMenuOption(T type, char cType)
{
    printDataType(cType);
    cout << H_STYLE << "ВЫ ВЫБРАЛИ ЗАДАЧУ < 1 >\n\n" << D_STYLE;
    
    T* arr = NULL;
    int size = inputArraySize(cType);

    system("cls");
    arr = inputArray(size, type, cType);
    cout << endl;

    int optionNumber = -1;
    int* answerOne = NULL;
    T answerTwo = 0;
    T* answerThree = NULL;
    
    T maxEl = 0;
    int* indexesZeros = NULL;

    system("cls");
    printDataType(cType);
    cout << SCS_STYLE << "Введённый массив: " << D_STYLE;
    printArray(arr, size, cType);
    printFirstProblemSpecialInfo();
    while (optionNumber != 0)
    {
        optionNumber = inputProblemNumber(3, true);

        system("cls");

        printDataType(cType);
        cout << SCS_STYLE << "Введённый массив: " << D_STYLE;
        printArray(arr, size, cType);
        printFirstProblemSpecialInfo();

        switch (optionNumber)
        {
        case(-1):
            cout << IMP_STYLE << "Ошибка ввода:" << D_STYLE;
            cout << " некорректный номер задачи. Введите номер задачи из списка ниже.\n\n";
            break;
        case(0):
            break;
        case(1):
            cout << endl << SCS_STYLE << "ОТВЕТ НА ПОДЗАДАЧУ 1:" << D_STYLE << endl;
            answerOne = maxOfElements(arr, size);
            maxEl = arr[answerOne[1]];
            printMaxesInfo(maxEl, answerOne, cType);
            cout << endl;
            delete[] answerOne;
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
                answerTwo = multiplyZero(arr, size);
                cout << "Найденное произведение: ";
                printNumber(answerTwo, cType);
                cout << endl << "Индексы первых двух нулевых элементов: " << indexesZeros[0] << " " << indexesZeros[1] << endl;
            }
            cout << endl;
            delete[] indexesZeros;
            break;
        case(3):
            cout << endl << SCS_STYLE << "ОТВЕТ НА ПОДЗАДАЧУ 3:" << D_STYLE << endl;
            answerThree = oddEvenITransformArray(arr, size);
            cout << "Введённый массив:\t";
            printArray(arr, size, cType);
            cout << endl;
            cout << "Преобразованный массив:\t";
            printArray(answerThree, size, cType);
            cout << endl << endl;
            delete[] answerThree;
            break;
        }

        if (optionNumber > 0) cout << H_STYLE << ">>Выберите другую подзадачу или вернитесь в меню.\n\n" << D_STYLE;
    }

    delete[] arr;
}