#include "Libraries.h"

int inputArraySize(char cType)
{
	int* inputInfo = NULL;
	int inputExitCode = 0;
	int size = 0;

	printFirstProblemSpecialInfo(false);

	while (true)
	{
		cout << IN_STYLE << "������� ������ �������: " << D_STYLE;

		inputInfo = inputInteger();
		inputExitCode = inputInfo[0];
		size = inputInfo[1];
		delete[] inputInfo;

		system("cls");
		printDataType(cType);
		printFirstProblemSpecialInfo(false);

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

