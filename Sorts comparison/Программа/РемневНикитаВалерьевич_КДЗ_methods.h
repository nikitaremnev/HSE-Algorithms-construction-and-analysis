/*
ФИО: Ремнев Никита Валерьевич
Группа: 271(2)ПИ
Дата: 1/12/2013
Задача: КДЗ
Среда разработки: Microsoft Visual Studio 2010
*/

#include <iostream> //подключение необходимых библиотек
#include <ctime>
#include <fstream>
#include <omp.h>

void bubble_sort(int a[], int n); // сортировки пузырьком
void bubble_iverson_1(int a[], int n);
void bubble_iverson_2(int a[], int n);

void insertion_sort(int a[], int n); // итерационные сортировки
void counting_sort(int a[], int n);
void radix_sort16(int a[], int n);
void binary_sort(int a[], int n);

void merge_sort(int a[], int in, int ik); //рекурсивные сортировки
void merge(int a[], int in, int ik);
void heap_sort(int a[], int n);
void heapify(int a[], int n, int i);
void build_heap(int a[], int n);
void quick_sort_middle(int a[], int in, int ik);
void quick_sort_left(int a[], int in, int ik);
void quick_sort_random(int a[], int in, int ik);

void array_generation(int a[], int n, int min, int max); //вспомогательные методы
void results(int a[], int n, int a1[], int n1);
void my_copy(int a[], int a1[], int n);
void array_reverse(int a[], int n);
void array_almost_sort(int a[], int n);

using namespace std; //стандартное пространство имен
