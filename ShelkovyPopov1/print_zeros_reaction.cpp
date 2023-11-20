#include "Libraries.h"

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
    else if (iSecond - iFirst == 1)
    {
        cout << "������� �������� ���� ������. ����� �������� ���������� ������ ���� ���� �� 2 �������� ��� �������� ������������." << endl;
    }
    else if (iSecond - iFirst == 2)
    {
        cout << "����� �������� ���������� ������ ���� ���� �� 2 �������� ��� �������� ������������, �� ������ ������ ����." << endl;
    }
}