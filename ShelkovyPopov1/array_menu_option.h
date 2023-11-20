#pragma once

#include "Libraries.h"
#include "input_array.h"
#include "array_problems.h"
#include "print_array.h"
#include "print_number.h"

template <typename T> void printMaxesInfo(T maxEl, int* info, char cType)
{
    int amount = info[0];

    cout << "������������ ������� �������: " << SP;
    printNumber(maxEl, cType);
    cout << D_STYLE << endl;
    cout << "������� ����� ���������: " << SP << amount << D_STYLE << endl;
    cout << "������� ��������� ���������: ";
    for (int i = 1; i < amount; i++)
    {
        cout << info[i] << ", ";
    }
    cout << info[amount] << endl;
}


template <typename T> void arrayProblemMenuOption(T type, char cType)
{
    printDataType(cType);
    cout << H_STYLE << "�� ������� ������ < 1 >\n\n" << D_STYLE;
    
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
    cout << SCS_STYLE << "�������� ������: " << D_STYLE;
    printArray(arr, size, cType);
    printFirstProblemSpecialInfo();
    while (optionNumber != 0)
    {
        optionNumber = inputProblemNumber(3, true);

        system("cls");

        printDataType(cType);
        cout << SCS_STYLE << "�������� ������: " << D_STYLE;
        printArray(arr, size, cType);
        printFirstProblemSpecialInfo();

        switch (optionNumber)
        {
        case(-1):
            cout << IMP_STYLE << "������ �����:" << D_STYLE;
            cout << " ������������ ����� ������. ������� ����� ������ �� ������ ����.\n\n";
            break;
        case(0):
            break;
        case(1):
            cout << endl << SCS_STYLE << "����� �� ��������� 1:" << D_STYLE << endl;
            answerOne = maxOfElements(arr, size);
            maxEl = arr[answerOne[1]];
            printMaxesInfo(maxEl, answerOne, cType);
            cout << endl;
            delete[] answerOne;
            break;
        case(2):
            cout << endl << SCS_STYLE << "����� �� ��������� 2:" << D_STYLE << endl;
            indexesZeros = getIndexesOfZsPair(arr, size);
            if (!checkZerosPair(indexesZeros))
            {
                printZerosWrongInputInfo(indexesZeros);
            }
            else
            {
                answerTwo = multiplyZero(arr, size);
                cout << "��������� ������������: ";
                printNumber(answerTwo, cType);
                cout << endl << "������� ������ ���� ������� ���������: " << indexesZeros[0] << " " << indexesZeros[1] << endl;
            }
            cout << endl;
            delete[] indexesZeros;
            break;
        case(3):
            cout << endl << SCS_STYLE << "����� �� ��������� 3:" << D_STYLE << endl;
            answerThree = oddEvenITransformArray(arr, size);
            cout << "�������� ������:\t";
            printArray(arr, size, cType);
            cout << endl;
            cout << "��������������� ������:\t";
            printArray(answerThree, size, cType);
            cout << endl << endl;
            delete[] answerThree;
            break;
        }

        if (optionNumber > 0) cout << H_STYLE << ">>�������� ������ ��������� ��� ��������� � ����.\n\n" << D_STYLE;
    }

    delete[] arr;
}