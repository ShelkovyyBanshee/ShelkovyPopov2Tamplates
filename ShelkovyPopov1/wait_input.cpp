#include "Libraries.h"

void waitForInput()
{
	cout << IN_STYLE << "������� ���-������, ����� ��������� � ����: " << D_STYLE;
	char* a = inputString(1);
	delete[] a;
}