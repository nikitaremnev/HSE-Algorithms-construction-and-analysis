/*
ФИО: Ремнев Никита Валерьевич
Группа: 271(2)ПИ
Дата: 16.10.2013
Задача: Рекурсивные сортировки
Среда разработки: Microsoft Visual Studio 2010
*/

#include "РемневНикитаВалерьевич_proekt6_methods.h" //подключение заголовочного файла

void merge_sort(int a[], int in, int ik) //сортировка слиянием
{
	if (in < ik)
	{               
		merge_sort(a, in, (in + ik) / 2);     
		merge_sort(a, (in + ik) / 2 + 1, ik); 
		merge(a, in, ik);    
	}
}

void merge(int a[], int in, int ik) //слияние двух массивов
{
  int p1 = in;
  int p2 = (in + ik) / 2 + 1;
  int p3 = 0;  
  int *temp = new int[ik - in + 1];
  while (p1 <= ((in + ik) / 2) && p2 <= ik) 
  {
    if (a[p1] < a[p2])
	{
      temp[p3] = a[p1];
	  p3++; p1++;
	}
    else
	{
      temp[p3] = a[p2];
	  p3++; p2++;
	}
  }
  while (p2 <= ik) 
  {
    temp[p3] = a[p2];
	p3++; p2++;
  }
  while (p1 <= ((in + ik) / 2))
  {
    temp[p3] = a[p1];
	p3++; p1++;
  }
  for (p3 = 0; p3 < ik-in+1; p3++)
    a[in+p3] = temp[p3];
  delete [] temp;
}

void heap_sort(int a[], int n) //пирамидальная сортировка
{
	build_heap(a, n);
	for (int i = 0; i < n - 1; i++) 
	{
		int t = a[n - 1 - i];
		a[n - 1 - i] = a[0];
		a[0] = t;
		heapify(a, n - 1 - i, 0);
	}
}

void build_heap(int a[], int n) //построение кучи
{
	for (int i = (n - 2) / 2; i >= 0; i--) 
		heapify(a, n, i); 
}

void heapify(int a[], int n, int i) //поддерживает основное свойство кучи
{
	int temp = i;
	if ((i * 2 + 1 < n) && (a[temp] < a[i * 2 + 1])) temp = i * 2 + 1;
	if ((i * 2 + 2 < n) && (a[temp] < a[i * 2 + 2])) temp = i * 2 + 2;
	if (temp != i) 
	{
		int t = a[i];
		a[i] = a[temp];
		a[temp] = t;
		heapify(a, n, temp);
	}
}

void quick_sort_middle(int a[], int in, int ik) // сортировка Хоара, разделительный элемент – средний в подмассиве
{
	int i;
	int j;
	i = in;
	j = ik;
	int k = (i + j) / 2;
	int x = a[k];
	do
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++; j--;
		}
	} while (i <= j);
	if (in < j)
		quick_sort_middle(a, in, j);
	if (ik > i)
		quick_sort_middle(a, i, ik);
}

void quick_sort_left(int a[], int in, int ik) // сортировка Хоара, разделительный элемент – второй слева в подмассиве
{
	int i;
	int j;
	i = in;
	j = ik;
	int k = i + 1;
	int x = a[k];
	do
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++; j--;
		}
	} while (i <= j);
	if (in < j)
		quick_sort_left(a, in, j);
	if (ik > i)
		quick_sort_left(a, i, ik);
}

void quick_sort_random(int a[], int in, int ik) // сортировка Хоара, разделительный элемент – произвольный
{
	int i;
	int j;
	i = in;
	j = ik;
	int k = in + rand()%(ik + 1 - in);
	int x = a[k];
	do
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++; j--;
		}
	} while (i <= j);
	if (in < j)
		quick_sort_random(a, in, j);
	if (ik > i)
		quick_sort_random(a, i, ik);
}

void array_generation(int a[], int n, int min, int max) //генерируем массив
{
	for (int i = 0; i < n; i++)
		a[i] = min + rand()%(max - min + 1);
}

bool sort(int a[], int n) //проверка отсортированности массива
{
	for (int i = 0; i < n-1; i++)
		if (a[i] > a[i + 1]) 
			return false;
	return true;
}

void my_copy(int a[], int a1[], int n) //метод для копирования элементов одного массива в другой
{
	for (int i = 0; i < n; i++)
		a1[i] = a[i];
}
