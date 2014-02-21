/*
ФИО: Ремнев Никита Валерьевич
Группа: 271(2)ПИ
Дата: 1/12/2013
Задача: КДЗ
Среда разработки: Microsoft Visual Studio 2010
*/

#include "РемневНикитаВалерьевич_КДЗ_methods.h";

void bubble_sort(int a[], int n) { //сортировка обычным пузырьком
    for (int i = n - 1; i > 0; i --) { 
	    for (int j = 0; j < i; j ++) {
		    if (a[j] > a[j + 1]) {
				int P = a[j]; 
				a[j] = a[j + 1];
				a[j + 1] = P;
			}
		}
	}
}

void bubble_iverson_1(int a[], int n) { //сортировка пузырьком с условием Айверсона 1
	bool T = true;
	for (int i = n - 1; (i > 0) && (T); i --) {
		T = false;
		for (int j = 0; j < i; j ++) {
		    if (a[j] > a[j + 1]) {
				int P = a[j]; 
				a[j] = a[j + 1];
				a[j + 1] = P;
				T = true;
			}
		}
	}
}

void bubble_iverson_2(int a[], int n) { //сортировка пузырьком с условием Айверсона 2
	int bound = n - 1;
	for (int i = n - 1; (i > 0) && (bound != 0); i --) {
		int t = 0;
		for (int j = 0; j < bound; j ++) {
		    if (a[j] > a[j+1]) {
				int P = a[j]; 
				a[j] = a[j + 1];
				a[j + 1] = P;
				t = j;
			}
		}
		bound = t;
	}
}

void insertion_sort(int a[], int n) { //сортировка простыми вставками
	for (int i = 1; i < n; i ++) {
		int j = i;
		while ((j > 0) && (a[j] < a[j - 1])) {
			int temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
			j = j - 1;
		}
	}
}

void counting_sort(int a[], int n) { //сортировка подсчетом
	int k = 0;
	for (int i = 0; i < n; i ++) { //максимум массива используемый в сортировке
		if (k < a[i]) {
			k = a[i];
		}
	}
	int *c = new int[k + 1];
	int *b = new int[n];
	for (int i = 0; i < k + 1; i ++) {
		c[i] = 0;
	}
	for (int i = 0; i < n; i ++) {
		c[a[i]] ++;
	}
	for (int j = 1; j < k + 1; j ++) {
		c[j] = c[j] + c[j-1];
	}
	for (int i = n - 1; i >= 0; i --) {
		c[a[i]] --;
		b[c[a[i]]] = a[i];
	}
	for (int i = 0; i < n; i ++) {
		a[i] = b[i];
	}
	delete [] c;
	delete [] b;
}

void radix_sort16(int a[], int n) { //цифровая сортировка по основанию 16
	int max = 0, exp = 1;
	int *b = new int[n];
	for (int i = 0; i < n; i ++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	while (max / exp > 0) {
		int ar[16] = {0};
		for (int i = 0; i < n; i ++) {
			ar[a[i] / exp % 16] ++;
		}
		for (int i = 1; i < 16; i ++) {
			ar[i] += ar[i - 1];
		}
		for (int i = n - 1; i >= 0; i --) {
			b[-- ar[a[i] / exp % 16]] = a[i];
		}
		for (int i = 0; i < n; i ++) {
			a[i] = b[i];
		}
		exp *= 16;
	}
	delete [] b;
}

void binary_sort(int a[], int n) { //сортировка бинарными вставками
	for (int i = 1; i < n; i ++) {
		if (a[i-1] > a[i]) {
			int x = a[i];
			int first = 0;
			int last = i - 1;
			while (first <= last) {
				int middle = (first + last) / 2;
				if (a[middle] < x) {
					first = middle + 1;
				} else {
					last = middle - 1;
				}
			}
			for (int j = i - 1; j > first - 1; j --) {
				a[j + 1] = a[j];
			}
			a[first] = x;
		}
	}
}

void merge_sort(int a[], int in, int ik) { //сортировка слиянием
	if (in < ik) {               
		merge_sort(a, in, (in + ik) / 2);     
		merge_sort(a, (in + ik) / 2 + 1, ik); 
		merge(a, in, ik);    
	}
}

void merge(int a[], int in, int ik) { //слияние двух массивов
	int p1 = in;
	int p2 = (in + ik) / 2 + 1;
	int p3 = 0;  
	int *temp = new int[ik - in + 1];
	while (p1 <= ((in + ik) / 2) && p2 <= ik) {
		if (a[p1] < a[p2]) {
			temp[p3] = a[p1];
			p3 ++; p1 ++;
		} else {
			temp[p3] = a[p2];
			p3 ++; 
			p2 ++;
		}
	}
	while (p2 <= ik) {
		temp[p3] = a[p2];
		p3 ++; 
		p2 ++;
	}
	while (p1 <= ((in + ik) / 2)) {
		temp[p3] = a[p1];
		p3 ++; 
		p1 ++;
	}
	for (p3 = 0; p3 < ik - in + 1; p3 ++) {
		a[in+p3] = temp[p3];
	}
	delete [] temp;
}

void heap_sort(int a[], int n) { //пирамидальная сортировка
	build_heap(a, n);
	for (int i = 0; i < n - 1; i ++) {
		int t = a[n - 1 - i];
		a[n - 1 - i] = a[0];
		a[0] = t;
		heapify(a, n - 1 - i, 0);
	}
}

void build_heap(int a[], int n) { //построение кучи
	for (int i = (n - 2) / 2; i >= 0; i --) {
		heapify(a, n, i); 
	}
}

void heapify(int a[], int n, int i) { //поддерживает основное свойство кучи
	int temp = i;
	if ((i * 2 + 1 < n) && (a[temp] < a[i * 2 + 1])) temp = i * 2 + 1;
	if ((i * 2 + 2 < n) && (a[temp] < a[i * 2 + 2])) temp = i * 2 + 2;
	if (temp != i) {
		int t = a[i];
		a[i] = a[temp];
		a[temp] = t;
		heapify(a, n, temp);
	}
}

void quick_sort_middle(int a[], int in, int ik) { // сортировка Хоара, разделительный элемент – средний в подмассиве
	int i = in;
	int j = ik;
	int k = (i + j) / 2;
	int x = a[k];
	do {
		while (a[i] < x) {
			i ++;
		}
		while (a[j] > x) {
			j --;
		}
		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i ++; j --;
		}
	} while (i <= j);
	if (in < j) {
		quick_sort_middle(a, in, j);
	}
	if (ik > i) {
		quick_sort_middle(a, i, ik);
	}
}

void quick_sort_left(int a[], int in, int ik) { // сортировка Хоара, разделительный элемент – второй слева в подмассиве
	int i = in;
	int j = ik;
	int k;
	if ((j - i) > 0) {
		k = i + 1;
	} else {
		k = i;
	}
	int x = a[k];
	do {
		while (a[i] < x) {
			i ++;
		}
		while (a[j] > x) {
			j --;
		}
		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i ++; j --;
		}
	} while (i <= j);
	if (in < j) {
		quick_sort_left(a, in, j);
	}
	if (ik > i) {
		quick_sort_left(a, i, ik);
	}
}

void quick_sort_random(int a[], int in, int ik) { // сортировка Хоара, разделительный элемент – произвольный
	int i = in;
	int j = ik;
	int k = in + rand()%(ik + 1 - in);
	int x = a[k];
	do {
		while (a[i] < x) {
			i ++;
		}
		while (a[j] > x) {
			j --;
		}
		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i ++; j --;
		}
	} while (i <= j);
	if (in < j) {
		quick_sort_random(a, in, j);
	}
	if (ik > i) {
		quick_sort_random(a, i, ik);
	}
}

void array_generation(int a[], int n, int min, int max) { //генерируем массив
	srand(time(0));
	for (int i = 0; i < n; i ++) {
		a[i] = min + rand()%(max - min + 1);
	}
}

void array_reverse(int a[], int n) { //сортировка в обратном порядке (используется сортировка пузырьком)
    for (int i = n - 1; i > 0; i --) { 
	    for (int j = 0; j < i; j ++) {
		    if (a[j] < a[j + 1]) {
				int P = a[j]; 
				a[j] = a[j + 1];
				a[j + 1] = P;
			}
		}
	}
}

void array_almost_sort(int a[], int n) { //формирование "почти" сортированного массива
	quick_sort_middle(a, 0, n - 1);
	int kol = 0;
	do { //меняем местами несколько элементов
		int first = 0 + rand()%(n);
		int second = 0 + rand()%(n);
		if (first != second) {
			int P = a[first]; 
			a[first] = a[second];
			a[second] = P;
			kol ++;
		}
	} while (kol != 5);
}

void results(int a[], int n, int a1[], int n1) { //вывод результата
	cout<<"Массив до сортировки:"<<endl;
	for (int i = 0; i < n; i ++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"Массив после сортировки:"<<endl;
	for (int i = 0; i < n1; i ++) {
		cout<<a1[i]<<" ";
	}
	cout<<endl;
}

void my_copy(int a[], int a1[], int n) { //метод для копирования элементов одного массива в другой
	for (int i = 0; i < n; i ++) {
		a1[i] = a[i];
	}
}