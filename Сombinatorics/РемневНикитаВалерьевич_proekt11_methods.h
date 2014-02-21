/*
ФИО: Ремнев Никита Валерьевич
Группа: 271(2)ПИ
Дата: 5.12.2013
Задача: Генерация комбинаторных объектов
Среда разработки: Microsoft Visual Studio 2010
*/

#include <iostream> //подключение необходимых библиотек
#include <Windows.h>
#include <algorithm>
#include <fstream>

using namespace std; //стандартное пространство имен

_int64 F(int N); //прототипы всех методов
_int64 A(int N, int M);
_int64 C(int N, int M);
void recursionF(int* mas, int N); 
void iterationF(int N);
void generationA(int N, int M);
void swap(int* mas, int i, int j);
void getNext(int mas[], int N);
bool eq(int mas[], int mas1[], int N);
void solve(int mas[], int mas1[], int t, int N, int M);
void generationC(int N, int M);
void sumGenerationHelp(int S, int N, int mas[], int t);
void sumGeneration(int N);