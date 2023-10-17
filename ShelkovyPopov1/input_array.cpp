#include "Libraries.h"

int inputArraySize()
{
	int* inputInfo = NULL;
	int inputExitCode = 0;
	int size = 0;

	while (true)
	{
		cout << IN_STYLE << "������� ������ �������: " << D_STYLE;

		inputInfo = inputInteger();
		inputExitCode = inputInfo[0];
		size = inputInfo[1];
		delete[] inputInfo;

		system("cls");

		if (inputExitCode == -1)
		{
			cout << IMP_STYLE << "������ �����:" << D_STYLE;
			cout << " ������ ������� ������ ���� ����� ������������� ������. ��������� ����.\n";
		}
		else if (size < 0) 
		{
			cout << IMP_STYLE << "������ �����:" << D_STYLE;
			cout << " ������ ������� ������ ������������� �����������. ��������� ����.\n";
		} 
		else if (size == 0) 
		{
			cout << IMP_STYLE << "������ �����:" << D_STYLE;
			cout << " c������� ������� ������� �� ����� ������ �� � ����� �� �����. ��������� ����.\n";
		}
		else break;	
	}

	return size;
}

void printArrayInputProgress(int* arr, int size, int elementsEntered)
{
	cout << "������� ��� ������� " << SP << "[" << D_STYLE;
	for (int i = 0; i < elementsEntered - 1; i++)
	{
		cout << arr[i] << ", ";
	}

	if (elementsEntered != 0) cout << arr[elementsEntered - 1];

	if (size == elementsEntered)
		cout << SP << "]" << SCS_STYLE << " - ������ ������� ��������!\n" << D_STYLE;
	else if (elementsEntered == 0)
		cout << "..." << SP << ']' << H_STYLE << " (����� �������� ��������� : " << size - elementsEntered << ")\n" << D_STYLE;
	else
		cout << ", ..." << SP << ']' << H_STYLE << " (����� �������� ��������� : " << size - elementsEntered << ")\n" << D_STYLE;
}

int* inputArray(int size)
{
	int* arr = new int[size];
	int* elementInputInfo = NULL;
	int inputExitCode = 0;
	int elementEntered = 0;

	printArrayInputProgress(arr, size, 0);

	for(int i = 0; i < size; i++)
	{
		while(true)
		{
			cout << IN_STYLE << "������� " << i + 1 << " ������� �������: " << D_STYLE;

			elementInputInfo = inputInteger();
			inputExitCode = elementInputInfo[0];
			elementEntered = elementInputInfo[1];
			delete[] elementInputInfo;

			system("cls");

			if (inputExitCode != 0) 
			{
				printArrayInputProgress(arr, size, i);
				cout << IMP_STYLE << "������ �����:" << D_STYLE;
				cout << " ������� ������� ������ ���� ����� ������. ��������� ����.\n";
			} 
			else break;
		}

		arr[i] = elementEntered;
		printArrayInputProgress(arr, size, i + 1);
	}	

	return arr;
}