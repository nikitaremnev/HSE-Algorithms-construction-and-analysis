/*
ФИО: Ремнев Никита Валерьевич
Группа: 271(2)ПИ
Дата: 22.09.2013
Задача: Функции сортировки пузырьком
Среда разработки: Microsoft Visual Studio 2010
*/

#include <iostream> //подключение необходимых библиотек
#include <ctime>
#include <Windows.h>

void bubble_sort(int a[], int n);// прототипы всех методов
void bubble_iverson_1(int a[], int n);
void bubble_iverson_2(int a[], int n);
void array_generation(int a[], int n, int min, int max);
void results(int a[], int n, int a1[], int n1);

using namespace std; //стандартное пространство имен

void main() 
{                                  
	setlocale(LC_ALL,"Russian"); //переключаем локаль (русский язык)

	int *ar, *ar1; //массивы, ar - не будет сортироваться для сохранения начального массива, ar1 - сортируемый массив
	int command=0, n, min, max; //command - для ввода команды пользователя, n - количество элементов массива, min, max - границы массива
	bool f=false; //флаг для определения существования массива 

	do //цикл повтора 
	{ 
		cout<<"Для выполнения действий в программе, введите:"<<endl; //описание команд пользователя
		cout<<"1 - для генерации массива;"<<endl;
		cout<<"2 - для сортировки алгоритма пузырьком;"<<endl;
		cout<<"3 - для сортировки алгоритма пузырьком с условием Айверсона I;"<<endl;
		cout<<"4 - для сортировки алгоритма пузырьком с условием Айверсона II;"<<endl;
		cout<<"0 - для выхода из программы."<<endl;
		cout<<"Введите команду:"<<endl;
		cin>>command; //ввод команды

		switch (command) //выбираем действия в зависимости от команды
		{
		    case 1:
			{
				cout<<"Введите количество элементов в массиве (целое число, большее 0):"<<endl;
		      	cin>>n; //вводим количество элементов массива

				if (f)
				{ //освобождаем память
					delete [] ar;
					delete [] ar1;
				}

	    		ar1=new int[n]; //инициализируем массивы
				ar=new int[n];

				cout<<"Введите минимальную границу элементов массива (целое число):"<<endl; //вводим границы массива
				cin>>min;
			    cout<<"Введите максимальную границу элементов массива (целое число большее минимальной границы):"<<endl;
			    cin>>max;
			
		     	array_generation(ar, n, min, max); //генерируем массив

				cout<<"Получившийся массив:"<<endl; //вывод получившегося массива
	            for (int i=0;i<n;i++)
					cout<<ar[i]<<" ";
				cout<<endl;

			    for (int i=0;i<n;i++) //поверхностное копирование массива
					ar1[i]=ar[i];

				f=true; //флажок - массив создан
				break;
			}
			case 2:
			{
				if (f) //проверка, что массив уже создан
				{
			        for (int i=0;i<n;i++) //поверхностное копирование массива, на случай если уже ar1 уже отсортирован
						ar1[i]=ar[i]; 

					bubble_sort(ar1,n); //сортируем
					results(ar, n, ar1, n); //вывод результата
				}
				else
				{
					cout<<"Массив не был сгенерирован, сортировать нечего!"<<endl; 
				}
				break;
			}
			case 3:
			{
				if (f) //проверка, что массив уже создан
				{
			        for (int i=0;i<n;i++) //поверхностное копирование массива, на случай если уже ar1 уже отсортирован
						ar1[i]=ar[i]; 

					bubble_iverson_1(ar1,n); //сортируем массив
					results(ar, n, ar1, n); //выводим результат
				}
				else
				{
					cout<<"Массив не был сгенерирован, сортировать нечего!"<<endl;
				}
				break;
			}
			case 4:
			{
				if (f) //проверка, что массив уже создан
				{
			        for (int i=0;i<n;i++)//поверхностное копирование массива, на случай если уже ar1 уже отсортирован
						ar1[i]=ar[i]; 

					bubble_iverson_2(ar1,n); //сортируем массив
					results(ar, n, ar1, n); //выводим результат
				}
				else
				{
					cout<<"Массив не был сгенерирован, сортировать нечего!"<<endl;
				}
				break;
			}
			default: break;
		}
	}
	while(command!=0);
	if (f)
	{
		delete [] ar; //освобождаем память
		delete [] ar1;
	}
}

void bubble_sort(int a[], int n) //сортировка обычным пузырьком
{
    for (int i=n-1;i>0;i--) 
	    for (int j=0;j<i;j++)
		    if (a[j]>a[j+1])
			{
				int P=a[j]; 
				a[j]=a[j+1];
				a[j+1]=P;
			}
}

void bubble_iverson_1(int a[], int n) //сортировка пузырьком с условием Айверсона 1
{
	bool T=true;
	for (int i=n-1;(i>0)&&(T);i--) 
	{
		T=false;
		for (int j=0;j<i;j++)
		    if (a[j]>a[j+1])
			{
				int P=a[j]; 
				a[j]=a[j+1];
				a[j+1]=P;
				T=true;
			}
	}
}

void bubble_iverson_2(int a[], int n) //сортировка пузырьком с условием Айверсона 2
{
	int bound=n-1;
	for (int i=n-1;(i>0)&&(bound!=0);i--) 
	{
		int t=0;
		for (int j=0;j<bound;j++)
		    if (a[j]>a[j+1])
			{
				int P=a[j]; 
				a[j]=a[j+1];
				a[j+1]=P;
				t=j;
			}
		bound=t;
	}
}

void array_generation(int a[], int n, int min, int max) //генерируем массив
{
	srand(time(0));
	for (int i=0;i<n;i++)
		a[i]=min+rand()%(max-min+1);
}

void results(int a[], int n, int a1[], int n1) //вывод результата
{
	cout<<"Массив до сортировки:"<<endl;
	for (int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<"Массив после сортировки:"<<endl;
	for (int i=0;i<n1;i++)
		cout<<a1[i]<<" ";
	cout<<endl;
}