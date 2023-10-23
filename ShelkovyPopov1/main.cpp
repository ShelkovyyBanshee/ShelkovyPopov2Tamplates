#include "Libraries.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    char test[] = "я люблю играть в футбол, когда мой брат, очень хороший, парень, спит на диване.";
    int len = strlen(test);
    char* testD = new char[len + 1];
    for(int i = 0; i < len; i++)
    {
        testD[i] = test[i];
    }

    cout << isLetter('л') << endl;
    int* arr = getStartIOfCorrectWords(testD, len, 4);
    cout << countWordsByLen(testD, len, 4);
    
    printArray(arr, arr[0]);
    cout << endl;
    printWords(arr, testD, len);
    delete[] arr;
    delete[] testD;
    //runGlobalMenu();
}