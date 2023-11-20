#pragma once

#include "Libraries.h"


template <typename T> T findMaxElInArray(T* pArray, int size) //max element
{
    T maxEl = pArray[0];
    for (int i = 1; i < size; i++)
    {
        if (pArray[i] > maxEl)
            maxEl = pArray[i];
    }

    return maxEl;
}

template <typename T> int countEl(T el, T* pArray, int size)
{
    int result = 0;

    for (int i = 0; i < size; i++) 
    {
        if (pArray[i] == el)
            result++;
    }

    return result;
}

template <typename T> int* maxOfElements(T* pArray, int size) // max = {count, index of elements}
{
    T tMax = findMaxElInArray(pArray, size);
    int* result = NULL;
    int countMax = countEl(tMax, pArray, size);

    result = new int[countMax + 1];
    result[0] = countMax;

    int t = 1;
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

// функция возвращает индексы нулевых элементов. -1 вместо индекса, если элемент не встретился

template <typename T> int* getIndexesOfZsPair(T* elements, int size)
{
    bool wasFirst = false;
    int* indexesOfZs = new int[2]{ -1, -1 };

    for (int i = 0; i < size && !(wasFirst && indexesOfZs[1] != -1); i++)
    {
        if (elements[i] == 0)
        {
            indexesOfZs[wasFirst ? 1 : 0] = i;
            wasFirst = true;
        }
    }

    return indexesOfZs;
}


template <typename T> T multiplyZero(T* pArray, const int size) // resOfFunction = {multBetweenZero}
{
    int* positionZero = getIndexesOfZsPair(pArray, size);
    T composition = 1;

    T result;

    for (int i = positionZero[0] + 1; i < positionZero[1]; i++)
    {
        composition *= pArray[i];
    }

    result = composition;

    delete[] positionZero;

    return result;

}


template <typename T> T* oddEvenITransformArray(T* pArray, int size)
{
    T* resultArray = new T[size];
    int iR = 0;

    for (int i = 0; i < size; i += 2, iR++)
    {
        resultArray[iR] = pArray[i];
    }

    for (int i = 1; i < size; i += 2, iR++)
    {
        resultArray[iR] = pArray[i];
    }

    return resultArray;

}
