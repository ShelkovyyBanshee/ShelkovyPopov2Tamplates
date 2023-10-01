
#include <iostream>
using namespace std;
#include "menu_functions.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    while(true)
    {
        printProblemsMenu();
        int a;
        cin >> a;
    }
}

