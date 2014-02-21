/*
ФИО: Ремнев Никита Валерьевич
Группа: 271(2)ПИ
Дата: 28.11.2013
Задача: Упаковка рюкзака
Среда разработки: Microsoft Visual Studio 2010
Примечания:
В каждом методе, решающем задачу рюкзака, запуск таймера начинается
там, где непосредственно выполняются действия необходимые для решения
тем или иным способом. То есть копирование переданных локальных переменных
в глобальные - входить не будет, так как этого можно избежать (добавляя больше параметров
в функции - что не очень удобно). А создание массива, использующегося в решении - войдет.
Для измерения времени используется функция omp_get_wtime() из библиотеки omp.h. Очень удобна в данном случае,
так как для измерения времени необходимо минимум строк кода, и минимальный интервал измерения ниже чем во многих
других способах измерения времени. Время в наносекундах.
Также, в программе есть 4-ый способ решения задачи рюкзака - динамическое программирование 
без рекурсии. Когда выяснилось, что нужно решение с рекурсией, уже было поздно, поэтому убирать его 
не стал.
*/

#include "РемневНикитаВалерьевич_proekt10_methods.h" //подключение заголовочного файла

double timestart, timefinish; //для вычисления времени

void knapsack_greedy(int weight[], int cost[], int W, int N) { //жадный алгоритм (не гарантирует оптимальность!)

	timestart = omp_get_wtime(); //запускаем таймер 

	double* ud_cost = new double[N]; //массив удельных весов
	for (int i = 0; i < N; i ++) {
		ud_cost[i] = (double)cost[i] / (double)weight[i]; //заполняем массив удельных весов
	} 

	int* numbers = new int[N]; //массив для хранения номеров элементов
	for (int i = 0; i < N; i ++) {
		numbers[i] = i;
	}

	int C_search=0, W_search=0; //для вывода результата
	int* mas = new int[N];

	for (int i = N - 1; i > 0; i --) // сортировка массивов (ключ сортировки - массив удельных весов)
	    for (int j = 0; j < i; j ++) //сортируем пузырьком
		    if (ud_cost[j] < ud_cost[j + 1]) {
				double temp = ud_cost[j]; 
				ud_cost[j] = ud_cost[j + 1];
				ud_cost[j + 1] = temp;
				
				int temp1 = weight[j]; 
				weight[j] = weight[j + 1];
				weight[j + 1] = temp1;
				
				int temp2 = cost[j]; 
				cost[j] = cost[j + 1];
				cost[j + 1] = temp2;

				int temp3 = numbers[j]; 
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp3;
			}

    for (int i = 0; i < N; i ++) { //заполнение рюкзака - ищем максимальную стоимость и вес
		mas[numbers[i]] = 0;
		if ((W_search + weight[i]) <= W) {
          W_search = W_search + weight[i];
          C_search = C_search + cost[i];
		  mas[numbers[i]] = 1;
		}
	}	

	timefinish = omp_get_wtime(); //фиксируем конец выполнения 

	output_console(W_search, C_search, mas, N, timefinish - timestart); //вывод ответов
	output_file(W_search, C_search, mas, N, timefinish - timestart); //вывод ответов

	delete [] ud_cost; //очищаем память
	delete [] numbers;
	delete [] mas;
} 

//глобальные переменные для перебора с возвратом
//для того чтобы передавать одно значение - номер элемента, а не тащить в функцию все параметры
int* weight1; //массив весов
int* cost1;  //массив цен
int W1; //храним максимальный вес рюкзака
int N1; //размер рюкзака
int C_max; //максимальная цена
int W_max; //максимальный вес
int *mas; //массив для хранения состояния взятых предметов
int *mas_max; //массив для хранения состояния взятых предметов при максимальной цене
 
void knapsack_comeback(int weight[], int cost[], int W, int N) {//функция задает глобальные переменные
	//и вызывает рекурсивный перебор с возвратом
	weight1 = weight; //копируем глобальные переменные
	cost1 = cost;
	W1 = W;
	N1 = N;

	timestart = omp_get_wtime();

	W_max = 0; //формируем переменные необходимые в решении
	C_max = 0;
	mas = new int[N1];
	mas_max = new int[N1];

	backtracking(0, 0, 0); //вызов перебора

	timefinish = omp_get_wtime();

	output_console(W_max, C_max, mas_max, N1, timefinish - timestart); //вывод ответов
	output_file(W_max, C_max, mas_max, N1, timefinish - timestart); //вывод ответов

	delete [] mas_max; //очищаем память
	delete [] mas;
}

void backtracking(int i, int C_search, int W_search) { //рекурсивный перебор с возвратом
	for (int j = i; j < N1; j ++) { //проходим по всем предметам, начиная с переданного номера
		mas[j] = 0; //не берем элемент изначально
		if (W1 >= W_search + weight1[j]) { //если вес предмета не превышает максимальный
			if (C_search + cost1[j] >= C_max) { //если стоимость превышаем максимальную
				C_max = C_search + cost1[j]; //сохраняем предметы
				W_max = W_search + weight1[j];
				mas[j] = 1; //берем предмет
				for (int k = 0; k < N1; k ++) {
					mas_max[k] = mas[k];
				}
			}
			mas[j] = 1; //берем предмет
			backtracking(j + 1,  C_search + cost1[j], W_search + weight1[j]); //запускаем рекурсию дальше
        } 
		mas[j] = 0; //вытаскиваем предмет
    }
}

void knapsack_dynamic(int weight[], int cost[], int W, int N) { //динамическое программирование (без рекурсии)
	
	timestart = omp_get_wtime();
	
	int** dp = new int*[N + 1]; //создаем матрицу

	for (int i = 0; i < N + 1; i ++) { //создаем матрицу и заполняем нулевую строку нулями
		dp[i] = new int[W + 1];
	}

	for (int i = 0; i < W + 1; i ++) 
		dp[0][i] = 0;

	for (int i = 1; i <= N; ++ i) { //динамическое заполнение таблицы
		for (int j = 0; j <= W; ++ j) {
			dp[i][j] = dp[i - 1][j];
			if (j >= weight[i - 1]) {
				dp[i][j] = max(dp[i - 1][j - weight[i - 1]] + cost[i - 1], dp[i - 1][j]);
			} 
		}
	}

	int s = N;
	int n = W;
	int W_search=0;
	mas = new int[N];
	for (int i = 0; i < N; i ++) {
		mas[i] = 0;
	}
	while (dp[s][n]!=0) { //получаем вес рюкзака
		if (dp[s - 1][n] == dp[s][n]) {
			s = s - 1;
		}
		else {
			s = s - 1;
			n = n - weight[s];
			W_search = W_search + weight[s];
			mas[s] = 1;
		}
	}
	
	timefinish = omp_get_wtime(); 

	output_console(W_search, dp[N][W], mas, N, timefinish - timestart); //вывод ответов
	output_file(W_search, dp[N][W], mas, N, timefinish - timestart); //вывод ответов

	for (int i = 0; i < N + 1; i ++) { //очищаем память
		delete [] dp[i];
	}

	delete [] dp;
	delete [] mas;
}

int **dp1; //глобальная переменная для хранения матрицы (для вызова рекурсивной функции (дин. программирование))
void knapsack_dynamic_recursion(int weight[], int cost[], int W, int N) {
	weight1 = weight; //копируем глобальные переменные
	cost1 = cost;

	timestart = omp_get_wtime(); 
	
	dp1 = new int*[N + 1]; //создаем матрицу
	for (int i = 0; i < N + 1; i ++) { //создаем матрицу и заполняем нулевую строку нулями
		dp1[i] = new int[W + 1];
	}
	for (int i = 0; i < W + 1; i ++) 
		dp1[0][i] = 0;

	dynamic_recursion(N, W); //заполняем рекурсивно таблицу (некоторые элементы, не все)

	int s = N;
	int n = W;
	int W_search=0;
	mas = new int[N];
	for (int i = 0; i < N; i ++) {
		mas[i] = 0;
	}
	while (dp1[s][n]!=0) { //получаем вес рюкзака
		if (dp1[s - 1][n] == dp1[s][n]) {
			s = s - 1;
		}
		else {
			s = s - 1;
			n = n - weight[s];
			W_search = W_search + weight[s];
			mas[s] = 1;
		}
	}

	timefinish = omp_get_wtime();

	output_console(W_search, dp1[N][W], mas, N, timefinish - timestart); //вывод ответов
	output_file(W_search, dp1[N][W], mas, N, timefinish - timestart); //вывод ответов
	
	for (int i = 0; i < N + 1; i ++) { //очищаем память
		delete [] dp1[i];
	}
	delete [] dp1;
	delete [] mas;
}

void dynamic_recursion(int i, int j) {
	if ((i == 0) || (j < 0)) { //выход из рекурсии
		return;
	}
	dynamic_recursion(i - 1, j); //получаем предыдущий элемент
	dp1[i][j] = dp1[i - 1][j];
	if (j >= weight1[i - 1]) {
		dynamic_recursion(i - 1, j - weight1[i - 1]); //получаем предыдущий элемент
		dp1[i][j] = max(dp1[i - 1][j - weight1[i - 1]] + cost1[i - 1], dp1[i - 1][j]);
	} 
}

void output_console(int W, int C, int variants[], int size, double time) { //вывод в консоль
	cout<<"Время выполнения: "<<time * 1000000<<" mks (микросекунд)"<<endl;
	cout<<"Вес рюкзака: "<<W<<endl; 
	cout<<"Стоимость рюкзака: "<<C<<endl;
	cout<<"Номера предметов в рюкзаке: ";
	for (int i = 0; i < size; i ++) {
		if (variants[i]==1) 
			cout<<i + 1<<" ";
	}
	cout<<endl;
	cout<<endl;
}

void output_file(int W, int C, int variants[], int size, double time) { //вывод в файл
	ofstream out;
	out.open("output_knap.txt", std::ios_base::app);
	out<<"Время выполнения: "<<time * 1000000<<" mks (микросекунд)"<<endl;
	out<<"Вес рюкзака: "<<W<<endl; 
	out<<"Стоимость рюкзака: "<<C<<endl;
	out<<"Номера предметов в рюкзаке: ";
	for (int i = 0; i < size; i ++) {
		if (variants[i]==1) 
			out<<i + 1<<" ";
	}
	out<<endl;
	out<<endl;
	out.close();
}