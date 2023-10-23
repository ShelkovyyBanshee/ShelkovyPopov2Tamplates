#include "Libraries.h"

int countWordsByLen(char* file, int fileSize, int maxSize) // [10, 0, 10 17] kolp poplp
{
	int currWordCount = 0;
	int result = 0;

	for(int i = 0; i < fileSize; i++)
	{
		char sym = file[i];

		if (isLetter(sym))
		{
			currWordCount += 1;
		}
		else
		{
			if (currWordCount > 0 && currWordCount <= maxSize)
			{
				result += 1;
			}

			currWordCount = 0;
		}
	}

	if (currWordCount > 0 && currWordCount <= maxSize) 
		result += 1;

	return result;
}

int* getStartIOfCorrectWords(char* file, int fileSize, int maxSize)
{
	int resultLen = countWordsByLen(file, fileSize, maxSize) + 1;
	int* result = new int[resultLen];
	int resI = 1;

	result[0] = resultLen - 1;

	int currWordCount = 0;
	int currWordStartI = 0;

	for (int i = 0; i < fileSize; i++)
	{
		char sym = file[i];
		if (isLetter(sym))
		{
			currWordCount += 1;
		}
		else
		{
			if (currWordCount > 0 && currWordCount <= maxSize)
			{
				result[resI] = currWordStartI;
				resI++;
			}

			currWordStartI = i + 1;
			currWordCount = 0;
		}
	}

	if (currWordCount > 0 && currWordCount <= maxSize)
		result[resI] = currWordStartI;

	return result;
}