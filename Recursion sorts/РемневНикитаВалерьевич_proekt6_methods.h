/*
ФИО: Ремнев Никита Валерьевич
Группа: 271(2)ПИ
Дата: 16.10.2013
Задача: Рекурсивные сортировки
Среда разработки: Microsoft Visual Studio 2010
*/

#include <iostream> //подключение необходимых библиотек
#include <ctime>
#include <Windows.h>
#include <fstream>

void merge_sort(int a[], int in, int ik); //прототипы всех методов
void merge(int a[], int in, int ik);
void heap_sort(int a[], int n);
void heapify(int a[], int n, int i);
void build_heap(int a[], int n);
void quick_sort_middle(int a[], int in, int ik);
void quick_sort_left(int a[], int in, int ik);
void quick_sort_random(int a[], int in, int ik);
void array_generation(int a[], int n, int min, int max);
bool sort(int a[], int n);
void my_copy(int a[], int a1[], int n);
