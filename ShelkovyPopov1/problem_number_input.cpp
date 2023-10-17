#include "Libraries.h"

// возвращает номер задачи из диапозона [1, problemsAmount].
// -1, если пользователь ошибс€ в вводе
int inputProblemNumber(int problemsAmount, bool subProblem)
{
	cout << IN_STYLE << "¬ведите номер " << (subProblem ? "под" : "") << "задачи: " << D_STYLE;
	int* inputInfo = inputInteger();
	int inputExitCode = inputInfo[0];
	int problemNumber = inputInfo[1];

	if (inputExitCode != 0 || problemNumber < 0 || problemNumber > problemsAmount) problemNumber = -1;

	delete[] inputInfo;
	return problemNumber;
}