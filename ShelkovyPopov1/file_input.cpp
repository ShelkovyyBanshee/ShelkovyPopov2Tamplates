#include "Libraries.h"

char* nameOfFile() //name of file
{
    char fileName[] = "TextFile.txt";
    int size = (int)strlen(fileName);
    char* answer = new char[size];

    for (int i = 0; i < size; i++)
    {
        answer[i] = fileName[i];
    }

    return answer;
}

char* FileRead(int size) //read and write file
{
    int index = 0;
    char* words = new char[size + 1];
    char letter;
    ifstream str;

    str.open(nameOfFile());
    str.seekg(0, ios::beg);

    while (str.get(letter)) //read
    {
        words[index] = letter;
        index++;
    }
    str.close();
    return words;
}

int volumeOfFile()// size of file
{
    int size = 0;
    ifstream str;

    str.open(nameOfFile());
    str.seekg(0, ios::end); // end of file
    size = int(str.tellg()); // size of file
    str.seekg(0, ios::beg); // return to begin of file
    str.close();
    return size;
}