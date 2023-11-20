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

void runGlobalMenu();

// ������� ������
void printProblemsMenu();
void printDataType(char type);
void printFirstProblemSpecialInfo(bool printZero = true);
void printSecondProblemSpecialInfo(bool printZero = true);

// ������������ ����
char* inputString(int symCount);
int* inputInteger();

// ���� � ����
int inputProblemNumber(int problemsAmount, bool subProblem = false);
char inputDataType(int problemNumber);

// ���� ������������
int inputArraySize(char cType);
int inputMatrixSize(bool inputFirstSize, char cType);

// �������� �����
void waitForInput();

// ������ � ������
char* getFileName();
int fileSize();
char* readFile(int size);

// ������ 1
void printZerosWrongInputInfo(int* indexesOfPair);
bool checkZerosPair(int* indexesOfPair);

// ������ 3
void fileProblemMenuOption();
void printWords(int* startIndexes, char* text, int textSize);
int* getStartIOfCorrectWords(char* file, int fileSize, int maxSize);
int countWordsByLen(char* file, int fileSize, int maxSize);

// ������

// ����������� �����
int strToInt(char* str);
int charToInt(char c);

// �������� �����
bool isInteger(char* str);
bool isDigit(char c);
bool isLetter(char c);

// �������������� ����������
int intPow(int n, int degree);
double doublePow(double d, int degree);


