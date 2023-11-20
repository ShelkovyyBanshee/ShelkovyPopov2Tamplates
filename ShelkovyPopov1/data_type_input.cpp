#include "Libraries.h"

char inputIFDChar()
{
	char* input = inputString(2);
	int len = (int)strlen(input);
	char sym = input[0];
	delete[] input;

	if (len == 1 && (sym == 'f' || sym == 'i' || sym == 'd')) return sym;
	else return '\0';
}

char inputDataType(int problemNumber)
{
	char result = '-';
	while(true)
	{
		cout << H_STYLE << "�� ������� ������ <" << problemNumber << ">\n\n" << D_STYLE;
		if (problemNumber == 1)
			printFirstProblemSpecialInfo(false);
		else
			printSecondProblemSpecialInfo(false);
		
		cout << H_STYLE << "�������� ��� ������ � ";
		cout << ((problemNumber == 1) ? "�������" : "�������");
		cout << ":\n" << D_STYLE;
		cout << "\n>> i - ����� ��� int\n";
		cout << "\n>> f - ����� � ��������� ������ float\n";
		cout << "\n>> d - ����� � ��������� ������ double\n";

		if (result == '\0') cout << IMP_STYLE << "������ �����:" << D_STYLE << "������� �� ��������. �� ������ ������ ���� �� ��� ��������: i, f, d\n";

		cout << SP << "������� ������ ����: " << D_STYLE;
		
		result = inputIFDChar();

		if (result != '\0')
			break;

		system("cls");
	}
	
	return result;
}

