#pragma once

// ��������� 

const char FILE_NAME[] = "user_file.txt"; // ��� ����������������� ����� �� ������ 3

const char D_STYLE[] = "\033[0;37;40m"; // ������� ����� - ������ ���, ����� �����
const char IMP_STYLE[] = "\033[4;31;40m"; // ����� ��� ������ ����� - ������� ������������
const char IN_STYLE[] = "\033[0;36;40m"; // ����� ��� ���� �����
const char H_STYLE[] = "\033[1;33;40m"; // ������ ��������� ��� ����������
const char SP[] = "\033[1;36;40m"; // ������� ���������
const char SCS_STYLE[] = "\033[0;32;40m"; // ������ ����� ��� ���������� �� �������� �����

// ����
// ���������� ���������� �� �������
void printProblemsMenu();
void printFirstProblemSpecialInfo();
void printSecondProblemSpecialInfo();

// ������������ ����� ������� � �������
void printArrayInputProgress(int* arr, int size, int elementsEntered);
void printArray(int* arr, int size);
void printMatrixInputProgress(int** matrix, int Rows, int Cols, int elementsEntered);

// ������� �����
char* inputString(int symCount);
int* inputInteger();

int inputProblemNumber(int problemsAmount, bool subProblem = false);

int* inputArray(int size);
int inputArraySize();

int** inputMatrix(int Rows, int Cols);
int inputMatrixSize(bool inputFirstSize);

// ������ 1
void arrayProblemMenuOption();

int* getIndexesOfZsPair(int* elements, int size);
int zerosProblemCheck(int* elements, int size);

// ������ 2
void matrixProblemMenuOption();
void kRowsSubOption(int** matrix, int M, int N);
void rowsWithNegativeSubProblem(int** matrix, int Rows, int Cols);

int* findMatrixKRows(int** matrix, int N);
void printKRowsInfo(int** matrix, int N, int* kRows);
void printRowsWithNegativeInfo(int* iOfCorrectRows, int* sums, int amountOfCorrect);
int countOfNegative(int** matrix, int Rows, int Cols);
int* indexesOfNegative(int** matrix, int Rows, int Cols);
int* sumWithNegative(int** matrix, int Rows, int Cols);

// ������ 3
void fileProblemMenuOption();

// ������

// ����������� �����
int strToInt(char* str);
int charToInt(char c);

// �������� �����
bool isInteger(char* str);

// �������������� ����������
int intPow(int n, int degree);

// ������������ ������
void deleteMatrix(int** matrix, int rows);

