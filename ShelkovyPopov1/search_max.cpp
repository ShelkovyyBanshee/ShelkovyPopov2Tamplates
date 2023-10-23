#include "Libraries.h"

int findMaxElInArray(int* pArray, int size)
{
    int maxEl = pArray[0];
    for (int i = 1; i < size; i++)
    {
        if (pArray[i] > maxEl)
            maxEl = pArray[i];
    }

    return maxEl;
}

int* maxOfElements(int* pArray, int size) // max = {maxElement, count, index of elements}
{
    int countMax = 0;
    int tMax = findMaxElInArray(pArray, size);
    int* result = NULL; 


    for (int i = 0; i < size; i++) //находим количество макс
    {
        if (pArray[i] == tMax)
            countMax++;
    }
    
    result = new int[countMax + 2];
    result[0] = tMax;
    result[1] = countMax;

    int t = 2;
    for (int i = 0; i < size; i++)
    {
        if (pArray[i] == tMax)
        {
            result[t] = i;
            t++;
        }
    }

    return result;
}