#pragma once

// КОНСТАНТЫ 

const char FILE_NAME[] = "user_file.txt"; // Имя пользовательского файла из задачи 3

const char D_STYLE[] = "\033[0;37;40m"; // Базовый стиль - чёрный фон, белый текст
const char IMP_STYLE[] = "\033[4;31;40m"; // Стиль для ошибок ввода - красный подчёркнутый
const char IN_STYLE[] = "\033[0;36;40m"; // Стиль для поля ввода
const char H_STYLE[] = "\033[1;33;40m"; // Слабое выделение для заголовков
const char SP[] = "\033[1;36;40m"; // Сильное выделение
const char SCS_STYLE[] = "\033[0;32;40m"; // Зелёный стиль для соообщений об успешном вводе

// МЕНЮ

void runGlobalMenu();

// Справочная информация по задачам
void printProblemsMenu();
void printFirstProblemSpecialInfo(bool printZero=true);
void printSecondProblemSpecialInfo(bool printZero=true);

// Визуализация ввода массива и матрицы
void printArrayInputProgress(int* arr, int size, int elementsEntered);
void printArray(int* arr, int size);
void printMatrixInputProgress(int** matrix, int Rows, int Cols, int elementsEntered);

// Функции ввода
char* inputString(int symCount);
int* inputInteger();

int inputProblemNumber(int problemsAmount, bool subProblem = false);

int* inputArray(int size);
int inputArraySize();

int** inputMatrix(int Rows, int Cols);
int inputMatrixSize(bool inputFirstSize);

void waitForInput();

// РАБОТА С ФАЙЛОМ
char* getFileName();
int fileSize();
char* readFile(int size);

// ЗАДАЧА 1
void arrayProblemMenuOption();

void printMaxesInfo(int* info);
void printZerosWrongInputInfo(int* indexesOfPair);

int* getIndexesOfZsPair(int* elements, int size);
int* multiplyZero(int* pArray, const int size);
int* oddEvenITransformArray(int* pArray, int size);
int findMaxElInArray(int* pArray, int size);
int* maxOfElements(int* pArray, int size);
bool checkZerosPair(int* indexesOfPair);

// ЗАДАЧА 2
void matrixProblemMenuOption();
void kRowsSubOption(int** matrix, int M, int N);
void rowsWithNegativeSubProblem(int** matrix, int Rows, int Cols);

int* findMatrixKRows(int** matrix, int N);
void printKRowsInfo(int** matrix, int N, int* kRows);
void printRowsWithNegativeInfo(int* iOfCorrectRows, int* sums, int amountOfCorrect);
int countOfNegative(int** matrix, int Rows, int Cols);
int* indexesOfNegative(int** matrix, int Rows, int Cols);
int* sumWithNegative(int** matrix, int Rows, int Cols);

// ЗАДАЧА 3
void fileProblemMenuOption();
void printWords(int* startIndexes, char* text, int textSize);
int* getStartIOfCorrectWords(char* file, int fileSize, int maxSize);
int countWordsByLen(char* file, int fileSize, int maxSize);

// ПРОЧЕЕ

// Конвертация строк
int strToInt(char* str);
int charToInt(char c);

// Проверки строк
bool isInteger(char* str);
bool isDigit(char c);
bool isLetter(char c);

// Математические дополнения
int intPow(int n, int degree);

// Освобождение памяти
void deleteMatrix(int** matrix, int rows);

