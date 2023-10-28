#include "Libraries.h"

void printMaxesInfo(int* info)
{
    int maxEl = info[0];
    int amount = info[1];

    cout << "������������ ������� �������: " << SP << maxEl << D_STYLE << endl;
    cout << "������� ����� ���������: " << SP << amount << D_STYLE << endl;
    cout << "������� ��������� ���������: ";
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

    cout << IMP_STYLE << "���������� ������ ������: " << D_STYLE;

    if (iFirst == -1)
    {
        cout << "� �������� ������� �� ������� ������� ���������." << endl;
        cout << "��� ������� ������ � ������� ������ ���� 2 ������� ��������." << endl;
    }   
    else if (iSecond == -1)
    {
        cout << "� �������� ������� ������ ���� ������� �������." << endl;
        cout << "��� ������� ������ � ������� ������ ���� 2 ������� ��������." << endl;
    }
    else if (iSecond - iFirst == 2)
    {
        cout << "������� �������� ���� ������. ����� �������� ���������� ������ ���� ���� �� 2 �������� ��� �������� ������������." << endl;
    }
    else if (iSecond - iFirst == 2)
    {
        cout << "����� �������� ���������� ������ ���� ���� �� 2 �������� ��� �������� ������������, �� ������ ������ ����." << endl; 
    }
}


void arrayProblemMenuOption()
{
    cout << H_STYLE << "�� ������� ������ < 1 >\n" << D_STYLE;

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

        cout << SCS_STYLE << "�������� ������: " << D_STYLE;
        printArray(arr, size);

        switch(optionNumber)
        {
        case(-1):
            cout << IMP_STYLE << "������ �����:" << D_STYLE;
            cout << " ������������ ����� ������. ������� ����� ������ �� ������ ����.\n\n";
            break;
        case(0):
            break;
        case(1):
            cout << endl << SCS_STYLE << "����� �� ��������� 1:" << D_STYLE << endl;
            answer = maxOfElements(arr, size);
            printMaxesInfo(answer);
            cout << endl;
            delete[] answer;
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
                answer = multiplyZero(arr, size);
                cout << "��������� ������������: " << answer[0] << endl;
                cout << "������� ������ ���� ������� ���������: " << answer[1] << " " << answer[2] << endl;
                delete[] answer;
            }
            cout << endl;
            delete[] indexesZeros;
            break;
        case(3):
            cout << endl << SCS_STYLE << "����� �� ��������� 3:" << D_STYLE << endl;
            answer = oddEvenITransformArray(arr, size);
            cout << "�������� ������:\t";
            printArray(arr, size);
            cout << endl;
            cout << "��������������� ������:\t";
            printArray(answer, size);
            cout << endl << endl;
            delete[] answer;
            break;
        }

        if (optionNumber > 0) cout << H_STYLE << ">>�������� ������ ��������� ��� ��������� � ����.\n\n" << D_STYLE;
    }

    delete[] arr;
}