#include "Libraries.h"

void waitForInput()
{
	cout << IN_STYLE << "¬ведите что-нибудь, чтобы вернутьс€ в меню: " << D_STYLE;
	char* a = inputString(1);
	delete[] a;
}