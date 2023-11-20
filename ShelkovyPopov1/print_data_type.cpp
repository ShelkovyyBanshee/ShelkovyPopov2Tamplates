#include "Libraries.h"

void printDataType(char type)
{
	cout << ">>юйрхбмши рхо дюммшу: ";
	cout << SP;

	if (type == 'i')
		cout << "INT\n\n";
	else if (type == 'f')
		cout << "FLOAT\n\n";
	else if (type == 'd')
		cout << "DOUBLE\n\n";

	cout << D_STYLE;
}