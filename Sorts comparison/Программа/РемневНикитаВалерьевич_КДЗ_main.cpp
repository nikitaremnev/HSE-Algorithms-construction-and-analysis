/*
ФИО: Ремнев Никита Валерьевич
Группа: 271(2)ПИ
Дата: 1/12/2013
Задача: КДЗ
Среда разработки: Microsoft Visual Studio 2010
*/

#include "РемневНикитаВалерьевич_КДЗ_methods.h";

typedef void (*function)(int[], int);
typedef void (*function_two)(int[], int, int);

ofstream out("output.txt");

void method_case(function f, int minimum, int maximum, int variant);
void method_case_second(function_two f, int minimum, int maximum, int variant);
void method_case_third(function f);
void method_case_fourth(function_two f);

_int64 timestart, timefinish;
double start, finish;

void main() {

	setlocale(LC_ALL,"Russian"); //переключаем локаль (русский язык)
	
	start = omp_get_wtime();
	
	for (int i = 0; i < 12; i ++) {
		switch (i) {
			case 0:
				out<<"Сортировка пузырьком:"<<endl;
				out<<endl;
				method_case_third(bubble_sort);
				break;
			case 1:
				out<<"___________________________________________"<<endl;
				out<<endl;
				out<<"Сортировка пузырьком с условием Айверсона I:"<<endl;
				out<<endl;
				method_case_third(bubble_iverson_1);
				break;
			case 2:
				out<<"___________________________________________"<<endl;
				out<<endl;
				out<<"Сортировка пузырьком с условием Айверсона II:"<<endl;
				out<<endl;
				method_case_third(bubble_iverson_2);
				break;
			case 3:
				out<<"___________________________________________"<<endl;
				out<<endl;
				out<<"Сортировка простыми вставками:"<<endl;
				out<<endl;
				method_case_third(insertion_sort);
				break;
			case 4:
				out<<"___________________________________________"<<endl;
				out<<endl;
				out<<"Сортировка бинарными вставками:"<<endl;
				out<<endl;
				method_case_third(binary_sort);
				break;
			case 5:
				out<<"___________________________________________"<<endl;
				out<<endl;
				out<<"Сортировка подсчетом:"<<endl;
				out<<endl;
				for (int j = 0; j < 5; j ++) {
					switch (j) {
						case 0:
							out<<"Массив заполнен случайными элементами от 0 до 4:"<<endl;
							out<<endl;
							method_case(counting_sort, 0, 4, j);
							break;	
						case 1:
							out<<"Массив заполнен случайными элементами от 0 до максимального целого:"<<endl;
							out<<endl;
							method_case(counting_sort, 0, INT_MAX, j);
							break;
						case 2:
							out<<"Массив заполнен случайными элементами и отсортирован:"<<endl;
							out<<endl;
							method_case(counting_sort, 0, 100, j);
							break;
						case 3:
							out<<"Массив заполнен случайными элементами и почти отсортирован:"<<endl;
							out<<endl;
							method_case(counting_sort, 0, 100, j);
							break;
						case 4:
							out<<"Массив заполнен случайными элементами и отсортирован в обратном порядке:"<<endl;
							out<<endl;
							method_case(counting_sort, 0, 100, j);
							break;
					}
				}
				break;
			case 6:
				out<<"___________________________________________"<<endl;
				out<<endl;
				out<<"Цифровая сортировка (по основанию 16):"<<endl;
				out<<endl;
				for (int j = 0; j < 5; j ++) {
					switch (j) {
						case 0:
							out<<"Массив заполнен случайными элементами от 0 до 4:"<<endl;
							out<<endl;
							method_case(counting_sort, 0, 4, j);
							break;	
						case 1:
							out<<"Массив заполнен случайными элементами от 0 до максимального целого:"<<endl;
							out<<endl;
							method_case(counting_sort, 0, INT_MAX, j);
							break;
						case 2:
							out<<"Массив заполнен случайными элементами и отсортирован:"<<endl;
							out<<endl;
							method_case(counting_sort, 0, 100, j);
							break;
						case 3:
							out<<"Массив заполнен случайными элементами и почти отсортирован:"<<endl;
							out<<endl;
							method_case(counting_sort, 0, 100, j);
							break;
						case 4:
							out<<"Массив заполнен случайными элементами и отсортирован в обратном порядке:"<<endl;
							out<<endl;
							method_case(counting_sort, 0, 100, j);
							break;
					}
				}
				break;
			case 7:
				out<<"___________________________________________"<<endl;
				out<<endl;
				out<<"Сортировка слиянием:"<<endl;
				out<<endl;
				method_case_fourth(merge_sort);
				break;
			case 8:
				out<<"___________________________________________"<<endl;
				out<<endl;
				out<<"Пирамидальная сортировка:"<<endl;
				out<<endl;
				method_case_third(heap_sort);
				break;
			case 9:
				out<<"___________________________________________"<<endl;
				out<<endl;
				out<<"Быстрая сортировка (Хоара), разделительный элемент - средний:"<<endl;
				out<<endl;
				method_case_fourth(quick_sort_middle);
				break;
			case 10:
				out<<"___________________________________________"<<endl;
				out<<endl;
				out<<"Быстрая сортировка (Хоара), разделительный элемент - произвольный:"<<endl;
				out<<endl;
				method_case_fourth(quick_sort_random);
				break;
			case 11:
				out<<"___________________________________________"<<endl;
				out<<endl;
				out<<"Быстрая сортировка (Хоара), разделительный элемент - второй слева:"<<endl;
				out<<endl;
				method_case_fourth(quick_sort_left);
				break;
		}
	}

	finish = omp_get_wtime();
	
	cout<<"Программа выполнена за "<<(int)((finish - start) / 60) <<" минут"<<endl;
	cout<<"Программа выполнена за "<<(finish - start) <<" секунд"<<endl;
	cout<<"Программа выполнена за "<<(int)((finish - start) / 60) <<" минут "<<(int)(finish - start) % 60 <<" секунд"<<endl;
	cout<<"Результат выведен в файл output.txt"<<endl;
	out.close();

	system("pause");
}

void method_case(function f, int minimum, int maximum, int variant) {
	for (int l = 1000; l <= 8000; l = l + 1000) {
		out<<"Размер массива: "<<l<<endl;

		int* etalon = new int[l];
		int* sorting = new int[l];

		_int64 min = INT_MAX;
		_int64 max = -2;
		_int64 sum = 0;
		int kol = 0;

		switch (variant) {
			case 0:
				array_generation(etalon, l, minimum, maximum);
				break;
			case 1:
				array_generation(etalon, l, minimum, maximum);
				break;
			case 2:
				array_generation(etalon, l, minimum, maximum);
				bubble_sort(etalon, l);
				break;
			case 3:
				array_generation(etalon, l, minimum, maximum);
				array_almost_sort(etalon, l);
				break;
			case 4:
				array_generation(etalon, l, minimum, maximum);
				array_reverse(etalon, l);
				break;
		}

		for (int k = 0; k < 20; k ++) { 
			my_copy(etalon, sorting, l);

			_asm { 
				 RDTSC 
				 mov DWORD PTR timestart, eax 
				 mov DWORD PTR timestart+4, edx 
			} 
		 
			f(sorting, l); 
			
			_asm {
				 RDTSC 
				 mov DWORD PTR timefinish, eax 
				 mov DWORD PTR timefinish+4, edx 
			} 

			if ((timefinish - timestart) > max) { 
				max = (timefinish - timestart);
			}
			if ((timefinish - timestart) < min) { 
				min = (timefinish - timestart);
			}
			sum = sum + (timefinish - timestart); 
			kol ++;
		}

		out<<"Минимальное время: "<<min<<" Ticks"<<endl;
		out<<"Среднее время время: "<<sum / kol<<" Ticks"<<endl;
		out<<"Максимальное время: "<<max<<" Ticks"<<endl;

		delete [] etalon;
		delete [] sorting;	
	};
	out<<endl;
}

void method_case_second(function_two f, int minimum, int maximum, int variant) {
	for (int l = 1000; l <= 8000; l = l + 1000) {
		out<<"Размер массива: "<<l<<endl;

		int* etalon = new int[l];
		int* sorting = new int[l];

		_int64 min = INT_MAX;
		_int64 max = -2;
		_int64 sum = 0;
		int kol = 0;

		switch (variant) {
		case 0:
			array_generation(etalon, l, minimum, maximum);
			break;
		case 1:
			array_generation(etalon, l, minimum, maximum);
			break;
		case 2:
			array_generation(etalon, l, minimum, maximum);
			bubble_sort(etalon, l);
			break;
		case 3:
			array_generation(etalon, l, minimum, maximum);
			array_almost_sort(etalon, l);
			break;
		case 4:
			array_generation(etalon, l, minimum, maximum);
			array_reverse(etalon, l);
			break;
		}

		for (int k = 0; k < 20; k ++) { 
			my_copy(etalon, sorting, l);

			_asm { 
				 RDTSC 
				 mov DWORD PTR timestart, eax 
				 mov DWORD PTR timestart+4, edx 
			} 
		 
			f(sorting, 0, l - 1); 
			
			_asm {
				 RDTSC 
				 mov DWORD PTR timefinish, eax 
				 mov DWORD PTR timefinish+4, edx 
			}

			if ((timefinish - timestart) > max) { 
				max = (timefinish - timestart);
			}
			if ((timefinish - timestart) < min) { 
				min = (timefinish - timestart);
			}
			sum = sum + (timefinish - timestart); 
			kol ++;
		}

		out<<"Минимальное время: "<<min<<" Ticks"<<endl;
		out<<"Среднее время время: "<<sum / kol<<" Ticks"<<endl;
		out<<"Максимальное время: "<<max<<" Ticks"<<endl;

		delete [] etalon;
		delete [] sorting;	
	};
	out<<endl;
}

void method_case_third(function f) {
	for (int j = 0; j < 5; j ++) {
		switch (j) {
			case 0:
				out<<"Массив заполнен случайными элементами от -2 до 2:"<<endl;
				out<<endl;
				method_case(f, -2, 2, j);
				break;	
			case 1:
				out<<"Массив заполнен случайными элементами от 0 до максимального целого:"<<endl;
				out<<endl;
				method_case(f, 0, INT_MAX, j);
				break;
			case 2:
				out<<"Массив заполнен случайными элементами и отсортирован:"<<endl;
				out<<endl;
				method_case(f, 0, 100, j);
				break;
			case 3:
				out<<"Массив заполнен случайными элементами и почти отсортирован:"<<endl;
				out<<endl;
				method_case(f, 0, 100, j);
				break;
			case 4:
				out<<"Массив заполнен случайными элементами и отсортирован в обратном порядке:"<<endl;
				out<<endl;
				method_case(f, 0, 100, j);
				break;
		}
	}
}

void method_case_fourth(function_two f) {
	for (int j = 0; j < 5; j ++) {
		switch (j) {
			case 0:
				out<<"Массив заполнен случайными элементами от -2 до 2:"<<endl;
				out<<endl;
				method_case_second(f, -2, 2, j);
				break;	
			case 1:
				out<<"Массив заполнен случайными элементами от 0 до максимального целого:"<<endl;
				out<<endl;
				method_case_second(f, 0, INT_MAX, j);
				break;
			case 2:
				out<<"Массив заполнен случайными элементами и отсортирован:"<<endl;
				out<<endl;
				method_case_second(f, 0, 100, j);
				break;
			case 3:
				out<<"Массив заполнен случайными элементами и почти отсортирован:"<<endl;
				out<<endl;
				method_case_second(f, 0, 100, j);
				break;
			case 4:
				out<<"Массив заполнен случайными элементами и отсортирован в обратном порядке:"<<endl;
				out<<endl;
				method_case_second(f, 0, 100, j);
				break;
		}
	}
}