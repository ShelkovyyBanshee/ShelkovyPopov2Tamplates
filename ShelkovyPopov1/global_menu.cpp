#include "Libraries.h"

void runGlobalMenu()
{
    const int PROBLEMS_AMOUNT = 3;

    bool programClosed = false;
    int problemChoice = -1;

    setlocale(LC_ALL, "Russian");

    printProblemsMenu();

    while (!programClosed)
    {
        problemChoice = inputProblemNumber(PROBLEMS_AMOUNT);

        if (problemChoice == -1)
        {
            system("cls");
            printProblemsMenu();
            cout << IMP_STYLE << "������ �����:" << D_STYLE;
            cout << " ������������ ����� ������. ������� ����� �� 1 �� " << PROBLEMS_AMOUNT;
            cout << " ��� 0, ����� ��������� ���������." << endl;
            continue;
        }

        system("cls");

        switch (problemChoice)
        {
        case(0):
            programClosed = true;
            break;
        case(1):
            arrayProblemMenuOption();
            break;
        case(2):
            matrixProblemMenuOption();
            break;
        case(3):
            fileProblemMenuOption();
            break;
        }

        if (problemChoice <= PROBLEMS_AMOUNT && problemChoice > 0)
        {
            system("cls");
            printProblemsMenu();
        }
    }
}