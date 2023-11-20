#pragma once
#include "Libraries.h"
#include "input_number.h"
#include "print_number.h"

template <typename T> void printArrayInputProgress(T* arr, int size, int elementsEntered, char cType)
{
	cout << "������� ��� ������� " << SP << "[" << D_STYLE;
	for (int i = 0; i < elementsEntered - 1; i++)
	{
		printNumber(arr[i], cType);
		cout << ", ";
	}

	if (elementsEntered != 0) 
		printNumber(arr[elementsEntered - 1], cType);

	if (size == elementsEntered)
		cout << SP << "]" << SCS_STYLE << " - ������ ������� ��������!\n" << D_STYLE;
	else if (elementsEntered == 0)
		cout << "..." << SP << ']' << H_STYLE << " (����� �������� ��������� : " << size - elementsEntered << ")\n" << D_STYLE;
	else
		cout << ", ..." << SP << ']' << H_STYLE << " (����� �������� ��������� : " << size - elementsEntered << ")\n" << D_STYLE;
}

template <typename T> T* inputArray(int size, T t, char cType)
{
	T* arr = new T[size];
	T* elementInputInfo = NULL;
	T inputExitCode = 0;
	T elementEntered = 0;

	printDataType(cType);
	printFirstProblemSpecialInfo(false);
	printArrayInputProgress(arr, size, 0, cType);

	for (int i = 0; i < size; i++)
	{
		while (true)
		{
			cout << IN_STYLE << "������� " << i + 1 << " ������� �������: " << D_STYLE;

			elementInputInfo = inputNumber(t, cType);
			inputExitCode = elementInputInfo[0];
			elementEntered = elementInputInfo[1];
			delete[] elementInputInfo;

			system("cls");
			printDataType(cType);
			printFirstProblemSpecialInfo(false);

			if (inputExitCode != 0)
			{
				printArrayInputProgress(arr, size, i, cType);
				cout << IMP_STYLE << "������ �����:" << D_STYLE;
				if (cType == 'i') cout << " ������� ������� ������ ���� ����� ������. ��������� ����.\n";
				else if (cType == 'f')  cout << " ������� ������� ������ ���� ������ � ��������� ������ ���� float. ��������: 3.14f. �� �������� ��� ������� f � �����! ��������� ����.\n";
				else cout << " ������� ������� ������ ���� ������ � ��������� ������. ��������� ����.\n";
			}
			else break;
		}

		arr[i] = elementEntered;
		printArrayInputProgress(arr, size, i + 1, cType);
	}

	return arr;
}