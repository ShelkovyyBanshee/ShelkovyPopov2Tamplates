#include "Libraries.h"

void printCheckResultZsProblem(int resultOfCheck)
{
	switch(resultOfCheck)
	{
	case(1):
		cout << "�� �� ����� �� ������ �������� ��������. ������ ���� 2 ������� ��������. ��������� ����.";
		break;
	case(2):
		cout << "�� ����� ������ ���� ������� �������. ������ ���� 2 ������� ��������. ��������� ����.";
		break;
	case(3):
		cout << "��� ������� ������������ ���������� ���� �� 2 �������� ����� ������. ��������� ����.";
	}
}