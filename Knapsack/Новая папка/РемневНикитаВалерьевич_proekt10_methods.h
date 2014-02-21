/*
ФИО: Ремнев Никита Валерьевич
Группа: 271(2)ПИ
Дата: 28.11.2013
Задача: Упаковка рюкзака
Среда разработки: Microsoft Visual Studio 2010
*/

#include <iostream> //подключение необходимых библиотек
#include <Windows.h>
#include <algorithm>
#include <fstream>
#include <math.h>
#include <omp.h>

using namespace std; //стандартное пространство имен

void knapsack_greedy(int weight[], int cost[], int W, int N); //жадный алгоритм
void knapsack_comeback(int weight[], int cost[], int W, int N); //для вызова перебора с возвратом
void knapsack_dynamic(int weight[], int cost[], int W, int N); //динамическое программирование (без рекурсии)
void backtracking(int i, int C_search, int W_search); //перебор с возвратом
void knapsack_dynamic_recursion(int weight[], int cost[], int W, int N); //для вызова рекурсивной функции (динамическое программирование)
void dynamic_recursion(int i, int j); //динамическое программирование с рекурсией
void output_console(int W, int C, int variants[], int size, double time); //вывод в консоль
void output_file(int W, int C, int variants[], int size, double time); //вывод в файл