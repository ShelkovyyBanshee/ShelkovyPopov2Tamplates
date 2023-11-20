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

// Функции вывода
void printProblemsMenu();
void printDataType(char type);
void printFirstProblemSpecialInfo(bool printZero = true);
void printSecondProblemSpecialInfo(bool printZero = true);

// Элементарный ввод
char* inputString(int symCount);
int* inputInteger();

// Ввод в меню
int inputProblemNumber(int problemsAmount, bool subProblem = false);
char inputDataType(int problemNumber);

// Ввод размерностей
int inputArraySize(char cType);
int inputMatrixSize(bool inputFirstSize, char cType);

// ожидание ввода
void waitForInput();

// РАБОТА С ФАЙЛОМ
char* getFileName();
int fileSize();
char* readFile(int size);

// ЗАДАЧА 1
void printZerosWrongInputInfo(int* indexesOfPair);
bool checkZerosPair(int* indexesOfPair);

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
double doublePow(double d, int degree);


