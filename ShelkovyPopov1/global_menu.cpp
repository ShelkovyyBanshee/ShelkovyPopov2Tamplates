#include "Libraries.h"
#include "array_menu_option.h"
#include "matrix_menu_option.h"

void runGlobalMenu()
{
    const int PROBLEMS_AMOUNT = 3;

    bool programClosed = false;
    int problemChoice = -1;
    char dataType = '0';

    setlocale(LC_ALL, "Russian");

    printProblemsMenu();

    while (!programClosed)
    {
        problemChoice = inputProblemNumber(PROBLEMS_AMOUNT);

        if (problemChoice == -1)
        {
            system("cls");
            printProblemsMenu();
            cout << IMP_STYLE << "ќшибка ввода:" << D_STYLE;
            cout << " некорректный номер задачи. ¬ведите число от 1 до " << PROBLEMS_AMOUNT;
            cout << " или 0, чтобы завершить программу." << endl;
            continue;
        }

        system("cls");

        dataType = '0';

        if (problemChoice <= 2 && problemChoice > 0)
        {
            dataType = inputDataType(problemChoice);
            system("cls");
        }

        switch (problemChoice)
        {
        case(0):
            programClosed = true;
            break;
        case(1):
            if (dataType == 'i')
                arrayProblemMenuOption(1, dataType);
            else if (dataType == 'f')
                arrayProblemMenuOption(1.0f, dataType);
            else if (dataType == 'd')
                arrayProblemMenuOption(1.0, dataType);
            break;
        case(2):
            if (dataType == 'i')
                matrixProblemMenuOption(1, dataType);
            else if (dataType == 'f')
                matrixProblemMenuOption(1.0f, dataType);
            else if (dataType == 'd')
                matrixProblemMenuOption(1.0, dataType);
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