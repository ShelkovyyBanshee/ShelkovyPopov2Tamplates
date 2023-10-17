#include "Libraries.h"

// ������� ���������� ������� ������� ���������. -1 ������ �������, ���� ������� �� ����������
int* getIndexesOfZsPair(int* elements, int size)
{
	bool wasFirst = false;
	int* indexesOfZs = new int[2] {-1, -1};

	for(int i = 0; i < size && !(wasFirst && indexesOfZs[1] != -1); i++)
	{
		if (elements[i] == 0)
		{
			indexesOfZs[wasFirst ? 1 : 0] = i;
			wasFirst = true;
		}
	}

	return indexesOfZs;
}