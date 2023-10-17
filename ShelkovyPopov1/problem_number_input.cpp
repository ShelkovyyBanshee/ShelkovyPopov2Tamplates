#include "Libraries.h"

// ���������� ����� ������ �� ��������� [1, problemsAmount].
// -1, ���� ������������ ������ � �����
int inputProblemNumber(int problemsAmount, bool subProblem)
{
	cout << IN_STYLE << "������� ����� " << (subProblem ? "���" : "") << "������: " << D_STYLE;
	int* inputInfo = inputInteger();
	int inputExitCode = inputInfo[0];
	int problemNumber = inputInfo[1];

	if (inputExitCode != 0 || problemNumber < 0 || problemNumber > problemsAmount) problemNumber = -1;

	delete[] inputInfo;
	return problemNumber;
}