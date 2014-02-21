/*ФИО: Ремнев Никита Валерьевич
Группа: 271(2)ПИ
Дата: 1.10.2013
Задача: Итерационные сортировки
Среда разработки: Microsoft Visual Studio 2010
*/

#include <iostream> //подключение необходимых библиотек
#include <ctime>
#include <Windows.h>
#include <fstream>

void insertion_sort(int a[], int n);// прототипы всех методов
void counting_sort(int a[], int n);
void radix_sort10(int a[], int n);
void radix_sort256(int a[], int n);
void binary_sort(int a[], int n);
void array_generation(int a[], int n, int min, int max);
bool sort(int a[], int n);
void my_copy(int a[], int a1[], int n);

using namespace std; //стандартное пространство имен

void main() 
{                                  
	setlocale(LC_ALL,"Russian"); //переключаем локаль (русский язык)

	int *ar, *ar1; //используемые массивы, один для хранения оригинального массива, другой для отсортированного
	int command = 0;

	do //цикл повтора 
	{ 
		cout<<"Для выполнения действий в программе, введите:"<<endl; //описание команд пользователя
		cout<<"1 - для нового тестирования сортировок;"<<endl;
		cout<<"0 - для выхода из программы."<<endl;
		cout<<"Введите команду:"<<endl;
		cin>>command; //ввод команды
		cout<<endl;

		switch (command) //выбираем действия в зависимости от команды
		{
		    case 1:
			{
				cout<<"Вы выбрали тестирование сортировок, введите:"<<endl; //описание команд пользователя
				cout<<"1 - для задания исходного массива в консоли;"<<endl;
				cout<<"2 - для задания исходного массива из файла;"<<endl;
				cout<<"0 - для выхода в главное меню."<<endl;
				cout<<"Введите команду:"<<endl;
				int commandtest = 0;
				cin>>commandtest; //ввод команды

				switch (commandtest)
				{ //выполнение команд
					case 1:
					{
						cout<<endl;
						cout<<"Введите количество тестов:"<<endl; //ввод необходимых данных
						int NL = 0;
						cin>>NL;
						cout<<"Введите размер массивов:"<<endl;
						int N = 0;
						cin>>N;
						cout<<"Введите минимальную границу элементов массива (целое число >=0):"<<endl;
						int min = 0;
						cin>>min;
						cout<<"Введите максимальную границу элементов массива (целое число большее минимальной границы):"<<endl;
						int max = 0;
						cin>>max;

						ar = new int[N];
						ar1 = new int[N];
						
					    ofstream out("output_proekt3.txt"); //открытие файла для записи
						srand(time(0)); //для генерации массива
						
						for (int i = 0; i < NL; i++)
						{
							array_generation(ar, N, min, max); //генерация массива
							my_copy(ar, ar1, N); //копирование ar в ar1
							
							out<<"Тест №"<<i + 1<<"\n"; //вывод результатов для каждой сортировки
							out<<endl;
							out<<"Cортировка простыми вставками"<<"\n";
							insertion_sort(ar1, N);
							out<<"Массив до сортировки:"<<"\n";
							for (int i = 0; i < N; i++)
								out<<ar[i]<<" ";
							out<<"\n";
							out<<"Массив после сортировки:"<<"\n";
							for (int i = 0; i < N; i++)
								out<<ar1[i]<<" ";
							out<<"\n";
							if (sort(ar1, N)) out<<"Массив отсортирован верно!"<<"\n";
							else out<<"Массив отсортирован неверно!"<<"\n";
							my_copy(ar, ar1, N);
							out<<endl;
							
							out<<"Cортировка бинарными вставками"<<"\n";
							binary_sort(ar1, N);
							out<<"Массив до сортировки:"<<"\n";
							for (int i = 0; i < N; i++)
								out<<ar[i]<<" ";
							out<<"\n";
							out<<"Массив после сортировки:"<<"\n";
							for (int i = 0; i < N; i++)
								out<<ar1[i]<<" ";
							out<<"\n";
							if (sort(ar1, N)) out<<"Массив отсортирован верно!"<<"\n";
							else out<<"Массив отсортирован неверно!"<<"\n";
							my_copy(ar, ar1, N);
							out<<endl;

							out<<"Cортировка подсчетом"<<"\n";
							counting_sort(ar1, N);
							out<<"Массив до сортировки:"<<"\n";
							for (int i = 0; i < N; i++)
								out<<ar[i]<<" ";
							out<<"\n";
							out<<"Массив после сортировки:"<<"\n";
							for (int i = 0; i < N; i++)
								out<<ar1[i]<<" ";
							out<<"\n";
							if (sort(ar1, N)) out<<"Массив отсортирован верно!"<<"\n";
							else out<<"Массив отсортирован неверно!"<<"\n";
							my_copy(ar, ar1, N);
							out<<endl;

							out<<"Цифровая сортировка по основанию 10"<<"\n";
							radix_sort10(ar1, N);
							out<<"Массив до сортировки:"<<"\n";
							for (int i = 0; i < N; i++)
								out<<ar[i]<<" ";
							out<<"\n";
							out<<"Массив после сортировки:"<<"\n";
							for (int i = 0; i < N; i++)
								out<<ar1[i]<<" ";
							out<<"\n";
							if (sort(ar1, N)) out<<"Массив отсортирован верно!"<<"\n";
							else out<<"Массив отсортирован неверно!"<<"\n";
							my_copy(ar, ar1, N);
							out<<endl;

							out<<"Цифровая сортировка по основанию 256"<<"\n";
							radix_sort256(ar1, N);
							out<<"Массив до сортировки:"<<"\n";
							for (int i = 0; i < N; i++)
								out<<ar[i]<<" ";
							out<<"\n";
							out<<"Массив после сортировки:"<<"\n";
							for (int i = 0; i < N; i++)
								out<<ar1[i]<<" ";
							out<<"\n";
							if (sort(ar1, N)) out<<"Массив отсортирован верно!"<<"\n";
							else out<<"Массив отсортирован неверно!"<<"\n";
							out<<endl; 

						}
						
						delete [] ar; //освобождаем память из под массивов
						delete [] ar1;
						cout<<"Результаты были выведены в файл output_proekt3.txt"<<endl;
						cout<<endl;
						out.close();

						break;
					}
					case 2:
					{
						ifstream in("input_proekt3.txt"); //для входного файла
						ofstream out("output_proekt3.txt"); //для выходного файла
						if (in.good()) //проверка открыт ли файл
						{
							int NL; //считываем количество тестов
							in>>NL;
							
							for (int i = 0; i < NL; i++)
							{
								int N; //считываем размер массива
								in>>N;
								ar = new int[N];
								ar1 = new int[N];

								for (int j = 0; j < N; j++)
								{
									in>>ar[j]; //считываем массив
									ar1[j] = ar[j];
								}

								out<<"Тест №"<<i + 1<<"\n"; //вывод результатов для каждой сортировки
								out<<endl;
								out<<"Cортировка простыми вставками"<<"\n";
								insertion_sort(ar1, N);
								out<<"Массив до сортировки:"<<"\n";
								for (int i = 0; i < N; i++)
									out<<ar[i]<<" ";
								out<<"\n";
								out<<"Массив после сортировки:"<<"\n";
								for (int i = 0; i < N; i++)
									out<<ar1[i]<<" ";
								out<<"\n";
								if (sort(ar1, N)) out<<"Массив отсортирован верно!"<<"\n";
								else out<<"Массив отсортирован неверно!"<<"\n";
								my_copy(ar, ar1, N);
								out<<endl;
							
								out<<"Cортировка бинарными вставками"<<"\n";
								binary_sort(ar1, N);
								out<<"Массив до сортировки:"<<"\n";
								for (int i = 0; i < N; i++)
									out<<ar[i]<<" ";
								out<<"\n";
								out<<"Массив после сортировки:"<<"\n";
								for (int i = 0; i < N; i++)
									out<<ar1[i]<<" ";
								out<<"\n";
								if (sort(ar1, N)) out<<"Массив отсортирован верно!"<<"\n";
								else out<<"Массив отсортирован неверно!"<<"\n";
								my_copy(ar, ar1, N);
								out<<endl;

								out<<"Cортировка подсчетом"<<"\n";
								counting_sort(ar1, N);
								out<<"Массив до сортировки:"<<"\n";
								for (int i = 0; i < N; i++)
									out<<ar[i]<<" ";
								out<<"\n";
								out<<"Массив после сортировки:"<<"\n";
								for (int i = 0; i < N; i++)
									out<<ar1[i]<<" ";
								out<<"\n";
								if (sort(ar1, N)) out<<"Массив отсортирован верно!"<<"\n";
								else out<<"Массив отсортирован неверно!"<<"\n";
								my_copy(ar, ar1, N);
								out<<endl;

								out<<"Цифровая сортировка по основанию 10"<<"\n";
								radix_sort10(ar1, N);
								out<<"Массив до сортировки:"<<"\n";
								for (int i = 0; i < N; i++)
									out<<ar[i]<<" ";
								out<<"\n";
								out<<"Массив после сортировки:"<<"\n";
								for (int i = 0; i < N; i++)
									out<<ar1[i]<<" ";
								out<<"\n";
								if (sort(ar1, N)) out<<"Массив отсортирован верно!"<<"\n";
								else out<<"Массив отсортирован неверно!"<<"\n";
								my_copy(ar, ar1, N);
								out<<endl;

								out<<"Цифровая сортировка по основанию 256"<<"\n";
								radix_sort256(ar1, N);
								out<<"Массив до сортировки:"<<"\n";
								for (int i = 0; i < N; i++)
									out<<ar[i]<<" ";
								out<<"\n";
								out<<"Массив после сортировки:"<<"\n";
								for (int i = 0; i < N; i++)
									out<<ar1[i]<<" ";
								out<<"\n";
								if (sort(ar1, N)) out<<"Массив отсортирован верно!"<<"\n";
								else out<<"Массив отсортирован неверно!"<<"\n";
								out<<endl; 

								delete [] ar;
								delete [] ar1;
							}
						}
						else
						{ //если файл не был открыт
							cout<<"Файл не был открыт"<<endl;
							cout<<endl;
							break;
						}
				        in.close(); //закрытие файлов
						out.close();

						cout<<"Результаты были выведены в файл output_proekt3.txt"<<endl;
						cout<<endl;

						break;
					}
					case 0: //выходим в главное меню
					{
						cout<<endl;
						break;
					}
				}
					
			}
			case 0: break; //выходим из программы
		}

	}
	while (command != 0);
}

void insertion_sort(int a[], int n) //сортировка простыми вставками
{
	for (int i = 1; i < n; i++)
		{
			int j = i;
			while ((j > 0) && (a[j] < a[j - 1]))
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				j = j - 1;
			}
		}
}

void counting_sort(int a[], int n) //сортировка подсчетом
{
	int k = 0;
	for (int i = 0; i < n; i++) //максимум массива используемый в сортировке
		if (k < a[i]) k = a[i];
	int *c = new int[k + 1];
	int *b = new int[n];
	for (int i = 0; i < k + 1; i++)
		c[i] = 0;
	for (int i = 0; i < n; i++)
		c[a[i]]++;
	for (int j = 1; j < k + 1; j++)
		c[j] = c[j] + c[j-1];
	for (int i = n - 1; i >= 0; i--)
	{
		c[a[i]]--;
		b[c[a[i]]] = a[i];
	}
	for (int i = 0; i < n; i++)
		a[i] = b[i];
	delete [] c;
	delete [] b;
}

void radix_sort10(int a[], int n) //цифровая сортировка по основанию 10
{
	int i, max = 0, exp = 1;
	int *b = new int[n];
	for (i = 0; i < n; i++)
		if (a[i] > max)
			max = a[i];
	while (max / exp > 0)
	{
		int ar[10] = {0};
		for (i = 0; i < n; i++)
			ar[a[i] / exp % 10]++;
		for (i = 1; i < 10; i++)
			ar[i] += ar[i - 1];
		for (i = n - 1; i >= 0; i--)
			b[--ar[a[i] / exp % 10]] = a[i];
		for (i = 0; i < n; i++)
			a[i] = b[i];
		exp *= 10;
	}
	delete [] b;
}

void radix_sort256(int a[], int n) //цифровая сортировка по основанию 256
{
	int i, max = 0, exp = 1;
	int *b = new int[n];
	for (i = 0; i < n; i++)
		if (a[i] > max)
			max = a[i];
	while (max / exp > 0)
	{
		int ar[256] = {0};
		for (i = 0; i < n; i++)
			ar[a[i] / exp % 256]++;
		for (i = 1; i < 256; i++)
			ar[i] += ar[i - 1];
		for (i = n - 1; i >= 0; i--)
			b[--ar[a[i] / exp % 256]] = a[i];
		for (i = 0; i < n; i++)
			a[i] = b[i];
		exp *= 256;
	}	

	delete [] b;
}

void binary_sort(int a[], int n) //сортировка бинарными вставками
{
	for (int i = 1; i < n; i++)
	if (a[i-1] > a[i])
	{
		int x = a[i];
		int first = 0;
		int last = i - 1;
		while (first <= last) 
		{
			int middle = (first + last) / 2;
			if (a[middle] < x) 
				first = middle + 1;
			else
				last = middle - 1;
		}
		for (int j = i - 1; j > first - 1; j--)
			a[j + 1] = a[j];
		a[first] = x;
	}
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
	{
		a1[i] = a[i];
	}
}