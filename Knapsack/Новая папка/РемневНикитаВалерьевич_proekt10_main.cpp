/*
ФИО: Ремнев Никита Валерьевич
Группа: 271(2)ПИ
Дата: 28.11.2013
Задача: Упаковка рюкзака
Среда разработки: Microsoft Visual Studio 2010
*/

#include "РемневНикитаВалерьевич_proekt10_methods.h" //подключение заголовочного файла

void main() 
{         
	setlocale(LC_ALL,"Russian"); //переключаем локаль (русский язык)

	ifstream in("input_knap.txt"); //для входного файла
	ofstream out("output_knap.txt"); //для выходного файла
	out.close(); //создание - закрытие, для гарантии существования файла

	int NT; //количество тестов
	in>>NT; //считываем количество тестов
	int* weight; //массив весов предметов
	int* cost; //массив цен предметов

	for (int i = 0; i < NT; i ++) { //проходим по тестам

		int W; //максимальный вес
		in>>W; //считываем максимальный вес
		int N; //количество предметов в рюкзаке
		in>>N; //считываем количество предметов в рюкзаке
		weight = new int[N]; //массив весов
		cost = new int[N]; //массив цен
		for (int j = 0; j < N; j ++) {
			in>>weight[j]; //считываем массив весов
		}
		for (int j = 0; j < N; j ++) {
			in>>cost[j]; //считываем массив цен
		}

		out.open("output_knap.txt", std::ios_base::app); //вывод в файл и в консоль
		cout<<"Тест №"<<i + 1<<":"<<endl;
		out<<"Тест №"<<i + 1<<":"<<endl;

		cout<<"Рекурсивный алгоритм с возвратом:"<<endl;
		out<<"Рекурсивный алгоритм с возвратом:"<<endl;
		out.close();
		knapsack_comeback(weight, cost, W, N);

		out.open("output_knap.txt", std::ios_base::app);
		cout<<"Рекурсивный алгоритм (динамическое программирование):"<<endl;
		out<<"Рекурсивный алгоритм (динамическое программирование):"<<endl;
		out.close();
		knapsack_dynamic_recursion(weight, cost, W, N);

		out.open("output_knap.txt", std::ios_base::app);
		cout<<"Динамическое программирование (без рекурсии):"<<endl;
		out<<"Динамическое программирование (без рекурсии):"<<endl;
		out.close();
		knapsack_dynamic(weight, cost, W, N);

		out.open("output_knap.txt", std::ios_base::app);
		cout<<"Простой жадный алгоритм:"<<endl;
		out<<"Простой жадный алгоритм:"<<endl;
		out.close();
		knapsack_greedy(weight, cost, W, N);

		delete [] weight;
		delete [] cost;
	}
	system("pause");
}