#include <iostream>
using namespace std;
int* maxOfElements(int* pArray, const int size) // max = {maxElement, count, {index of elements}}
{
    int count = 0;
    int tmax = 0;
    int* tempMax = new int[size];

    int t = 0;
    int* max = new int[count + 2];

    for (int i = 0; i < size; i++) //находим макс
    {
        if (pArray[i] > tmax)
        {
            tmax = pArray[i];
        }
    }

    for (int i = 0; i < size; i++) //находим количество макс
    {
        if (pArray[i] == tmax)
        {
            count++;
        }
    }



    for (int i = 0; i < size; i++)
    {
        if (pArray[i] == tmax)
        {
            tempMax[t] = i;
            t++;
        }
    }

    //cout << count + 2 << endl;
    max[0] = tmax;
    max[1] = count;

    for (int i = 2; i < (count + 2); i++) //создаем массив
    {
        max[i] = tempMax[i - 2];
    }

    delete[]tempMax;

    return max;
}