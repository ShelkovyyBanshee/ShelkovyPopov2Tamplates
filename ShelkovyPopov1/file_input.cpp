#include "Libraries.h"

char* getFileName()
{
    char fileName[] = "input.txt";
    int size = (int)strlen(fileName) + 1;
    char* answer = new char[size];

    for (int i = 0; i < size; i++)
    {
        answer[i] = fileName[i];
    }

    return answer;
}

char* readFile(int size)
{
    int index = 0;
    char* words = new char[size + 1];
    char letter;
    ifstream str;

    str.open(getFileName());
    str.seekg(0, ios::beg);

    while (str.get(letter)) 
    {
        words[index] = letter;
        index++;
    }
    str.close();
    return words;
}

int fileSize()
{
    int size = 0;
    ifstream str;

    str.open(getFileName());
    str.seekg(0, ios::end); 
    size = int(str.tellg()); 
    str.seekg(0, ios::beg); 
    str.close();
    return size;
}

