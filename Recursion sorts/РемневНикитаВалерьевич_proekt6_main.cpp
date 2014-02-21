/*
ФИО: Ремнев Никита Валерьевич
Группа: 271(2)ПИ
Дата: 16.10.2013
Задача: Рекурсивные сортировки
Среда разработки: Microsoft Visual Studio 2010
*/

#include "РемневНикитаВалерьевич_proekt6_methods.h" //подключение заголовочного файла

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
						
					    ofstream out("output_proekt6.txt"); //открытие файла для записи
						srand(time(0)); //для генерации массива
						
						for (int i = 0; i < NL; i++)
						{
							array_generation(ar, N, min, max); //генерация массива
							my_copy(ar, ar1, N); //копирование ar в ar1
							
							out<<"Тест №"<<i + 1<<"\n"; //вывод результатов для каждой сортировки
							out<<endl;
							out<<"Cортировка слиянием"<<"\n";
							merge_sort(ar1, 0, N - 1);
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
							
							out<<"Пирамидальная сортировка"<<"\n";
							heap_sort(ar1, N);
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
							
							out<<"Сортировка Хоара (средний элемент)"<<"\n";
							quick_sort_middle(ar1, 0, N - 1);
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
							
							out<<"Сортировка Хоара (второй слева элемент)"<<"\n";
							quick_sort_left(ar1, 0, N - 1);
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

							out<<"Сортировка Хоара (произвольный элемент)"<<"\n";
							quick_sort_random(ar1, 0, N - 1);
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
						cout<<"Результаты были выведены в файл output_proekt6.txt"<<endl;
						cout<<endl;
						out.close();

						break;
					}
					case 2:
					{
						ifstream in("input_proekt6.txt"); //для входного файла
						ofstream out("output_proekt6.txt"); //для выходного файла
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
								out<<"Cортировка слиянием"<<"\n";
								merge_sort(ar1, 0, N - 1);
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
							
								out<<"Пирамидальная сортировка"<<"\n";
								heap_sort(ar1, N);
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

								out<<"Сортировка Хоара (средний элемент)"<<"\n";
								quick_sort_middle(ar1, 0, N - 1);
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

								out<<"Сортировка Хоара (второй слева элемент)"<<"\n";
								quick_sort_left(ar1, 0, N - 1);
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

								out<<"Сортировка Хоара (произвольный элемент)"<<"\n";
								quick_sort_random(ar1, 0, N - 1);
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

						cout<<"Результаты были выведены в файл output_proekt6.txt"<<endl;
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
