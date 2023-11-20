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
		if (inputFirstSize) cout << "Введите кол-во строк " << SP << "M" << D_STYLE; 
		else cout << "Введите кол-во столбов " << SP << "N" << D_STYLE;

		cout << " <= 8 для матрицы " << SP << "M" << D_STYLE << "x" << SP << "N" << D_STYLE << ": ";
		

		inputInfo = inputInteger();
		inputExitCode = inputInfo[0];
		N = inputInfo[1];
		delete[] inputInfo;

		system("cls");
		printDataType(cType);
		printSecondProblemSpecialInfo(false);

		if (inputExitCode == -1) 
		{
			cout << IMP_STYLE << "Ошибка ввода:" << D_STYLE;
			cout << " число " << SP << var << D_STYLE << " должно быть целым положительным числом. Повторите ввод.\n";
		} 
		else if (N == 0) 
		{
			cout << IMP_STYLE << "Ошибка ввода:" << D_STYLE;
			cout << " матрица нулевой размерности не имеет смысла ни в одной из задача. Повторите ввод.\n";
		} 
		else if (N < 0) 
		{
			cout << IMP_STYLE << "Ошибка ввода:" << D_STYLE;
			cout << " число " << SP << var << D_STYLE << " должно быть положительным числом.\n";
		} 
		else if (N > 8) 
		{
			cout << IMP_STYLE << "Ошибка ввода:" << D_STYLE;
			cout << " число " << SP << var << D_STYLE << " не должно превышать 8. Повторите ввод.\n";
		} 
		else break;
	}
	
	return N;
}