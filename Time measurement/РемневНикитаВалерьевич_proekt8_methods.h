/*
ФИО: Ремнев Никита Валерьевич
Группа: 271(2)ПИ
Дата: 2.11.2013
Задача: Измерение времени
Среда разработки: Microsoft Visual Studio 2010
*/

#include <iostream> //подключение необходимых библиотек
#include <Windows.h>
#include <time.h>
#include <Mmsystem.h>
#include <conio.h>
#include <WinBase.h>
#pragma comment(lib, "Kernel32.lib")
#pragma comment(lib, "winmm.lib")
#include <omp.h>

using namespace std; //стандартное пространство имен

void test_clock(); //прототипы всех методов
void test_time();
void test_timeGetTime();
void test_GetTickCount();
void test_GetTickCount64();
void test_QueryPerformance();
void test_Assembler32();
void test_Assembler64();
void test_OPENMP();