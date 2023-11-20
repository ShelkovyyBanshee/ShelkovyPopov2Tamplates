#include "Libraries.h"

int inputMatrixSize(bool inputFirstSize, char cType)
{
	int* inputInfo = NULL;
	int inputExitCode = 0;
	int N = 0;

	char var = inputFirstSize ? 'M' : 'N';

	printSecondProblemSpecialInfo(false);

	while(true)
	{
		if (inputFirstSize) cout << "������� ���-�� ����� " << SP << "M" << D_STYLE; 
		else cout << "������� ���-�� ������� " << SP << "N" << D_STYLE;

		cout << " <= 8 ��� ������� " << SP << "M" << D_STYLE << "x" << SP << "N" << D_STYLE << ": ";
		

		inputInfo = inputInteger();
		inputExitCode = inputInfo[0];
		N = inputInfo[1];
		delete[] inputInfo;

		system("cls");
		printDataType(cType);
		printSecondProblemSpecialInfo(false);

		if (inputExitCode == -1) 
		{
			cout << IMP_STYLE << "������ �����:" << D_STYLE;
			cout << " ����� " << SP << var << D_STYLE << " ������ ���� ����� ������������� ������. ��������� ����.\n";
		} 
		else if (N == 0) 
		{
			cout << IMP_STYLE << "������ �����:" << D_STYLE;
			cout << " ������� ������� ����������� �� ����� ������ �� � ����� �� ������. ��������� ����.\n";
		} 
		else if (N < 0) 
		{
			cout << IMP_STYLE << "������ �����:" << D_STYLE;
			cout << " ����� " << SP << var << D_STYLE << " ������ ���� ������������� ������.\n";
		} 
		else if (N > 8) 
		{
			cout << IMP_STYLE << "������ �����:" << D_STYLE;
			cout << " ����� " << SP << var << D_STYLE << " �� ������ ��������� 8. ��������� ����.\n";
		} 
		else break;
	}
	
	return N;
}