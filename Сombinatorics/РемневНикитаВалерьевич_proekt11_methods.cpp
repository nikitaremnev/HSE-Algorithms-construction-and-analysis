/*
ФИО: Ремнев Никита Валерьевич
Группа: 271(2)ПИ
Дата: 5.12.2013
Задача: Генерация комбинаторных объектов
Среда разработки: Microsoft Visual Studio 2010
*/

#include "РемневНикитаВалерьевич_proekt11_methods.h" //подключение заголовочного файла

int N1, M1; //глобальные переменные для методов

_int64 F(int N) { //факториал числа N
	return N > 0 ? N * F(N - 1) : 1;
}

_int64 A(int N, int M) { //число размещений без повторений из N по M
	return F(N) / F(N - M);
}

_int64 C(int N, int M) { //число сочетаний из N по M
	N1 = N;
	M1 = M;
	return A(N, M) / F(M);
}

void swap(int mas[], int i, int j) { //обмен местами двух элементов массива
	int temp = mas[i];
	mas[i] = mas[j];
	mas[j] = temp;
 }
 
void recursionF(int mas[], int N) { //рекурсивный алгоритм получения всех перестановок
	if (N == 1) {
		for (int i = 0; i < N1; i ++) { //вывод массива
			if (i == N1 - 1) {
				cout<<mas[i];
			} else {
				cout<<mas[i]<<"|";
			}
		}
		cout<<endl;
	} else {
		for (int i = 0; i < N; i ++) { 
			recursionF(mas, N - 1);
			if (N % 2 == 1) {
				swap(mas, 0, N - 1);
			} else {
				swap(mas, i, N - 1);
			}
		}
	}
}

void iterationF(int N) { //итерационный алгоритм получения всех перестановок
	int* perestanovka = new int[N];
	for (int i = 0; i < N; i ++) { //задание первой перестановки
		perestanovka[i] = i + 1;
	}
	for (int i = 0; i < N; i ++) { //вывод первой перестановки
		if (i == N - 1) {
			cout<<perestanovka[i];
		} else {
			cout<<perestanovka[i]<<"|";
		}
	}
	cout<<endl;

	int* last = new int[N];
	for (int i = N; i > 0; i --) { //получаем последнюю перестановку
		last[N - i] = perestanovka[i - 1];
	}

	while (!eq(perestanovka, last, N)) {
		getNext(perestanovka, N - 1);
		for (int i = 0; i < N; i ++) {
			if (i == N - 1) {
				cout<<perestanovka[i];
			} else {
				cout<<perestanovka[i]<<"|";
			}
		}
		cout<<endl;
	}

	delete [] perestanovka;
	delete [] last;

}

void getNext(int mas[], int N) { //метод для получения следующей перестановки
	int i = N;
	while ((i > 0) && (mas[i] < mas[i - 1])) {
		i --;
	}
	int j = N;
	while (mas[j] < mas[i - 1]) {
		j --;
	}
	swap(mas, i - 1, j);	
	for (int j = 0; j < ((N - i + 1) / 2); j ++) {
		swap(mas, i + j, N - j);
	}
}

bool eq(int mas[], int mas1[], int N) { //проверка равенства двух перестановок
	bool f = true;
	for (int i = 0; i < N; i ++) {
		if (mas[i] != mas1[i]) {
			f = false;
		}
	}
	return f;
}

void generationA(int N, int M) { //генерирование всех размещений
	int* numbers = new int[N + 1];
	for (int i = 1; i < N + 1; i ++) {
		numbers[i] = 0;
	}
	int* A = new int[M + 1];
	solve(numbers, A, 1, N, M);

	delete [] A;
	delete [] numbers;
}

void solve(int numbers[], int A[], int t, int N, int M) { //непосредственное получение размещений
	for (int i = 1; i <= N; i ++) {
		if (numbers[i] == 0) {
			numbers[i] = 1; //берем число
			A[t] = i;
			if (t + 1 < M + 1) {
				solve(numbers, A, t + 1, N, M);
			} else {
				for (int j = 1; j < M + 1; j ++) { //вывод массива
					if (j == M) {
						cout<<A[j];
					} else {
						cout<<A[j]<<"|";
					}
				}
				cout<<endl;
			}
			numbers[i] = 0; //убираем
		}
	}
}

void generationC(int N, int M) { //генерирование всех сочетаний
	int* C = new int[M + 1];
	C[0] = -1;
	for (int i = 1; i < M + 1; i ++) {
		C[i] = i; //первое сочетание
	}
	int j = 1;
	while (j != 0) {
		for (int k = 1; k < M + 1; k ++) { //вывод сочетания
			if (k == M) {
				cout<<C[k]; 
			} else {
				cout<<C[k]<<"|"; 
			}
		}
		cout<<endl;
		j = M;
		while (C[j] >= N - M + j) {
			j --;
		}
		C[j] = C[j] + 1; //наращиваем найденное число
		for (int i = j + 1; i < M + 1; i ++) {
			C[i] = C[i - 1] + 1;
		}
	}
	delete [] C;
}

void sumGeneration(int N) { //генерирование всех суммы последовательности невозрастающих целых положительных слагаемых
	int* mas = new int[N + 1];
	for (int i = 1; i < N + 1; i ++) { //проходим по всем элементам множества 1..N
		mas[1] = i;
		sumGenerationHelp(i, N, mas, 1);
	}

	delete [] mas;
}

void sumGenerationHelp(int S, int N, int mas[], int temp) { //вспомогательный метод для генерации сумм
	if (S == N) {
		for (int i = 1; i < temp + 1; i ++) {
			if ( i == temp) { //вывод суммы
				cout<<mas[i];
			} else {
				cout<<mas[i]<<"+"; 
			}
		}
		cout<<endl;
	} else {
		for (int i = 1; i <= min(mas[temp], N - S); i ++) {
			mas[++ temp] = i; 
			S = S + i; //добавляем элемент
			sumGenerationHelp(S, N, mas, temp);
			S = S - i; //убираем
			temp --;
		}
	}
}