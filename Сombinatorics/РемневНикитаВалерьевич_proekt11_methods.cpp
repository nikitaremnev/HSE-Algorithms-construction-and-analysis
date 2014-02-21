/*
���: ������ ������ ����������
������: 271(2)��
����: 5.12.2013
������: ��������� ������������� ��������
����� ����������: Microsoft Visual Studio 2010
*/

#include "����������������������_proekt11_methods.h" //����������� ������������� �����

int N1, M1; //���������� ���������� ��� �������

_int64 F(int N) { //��������� ����� N
	return N > 0 ? N * F(N - 1) : 1;
}

_int64 A(int N, int M) { //����� ���������� ��� ���������� �� N �� M
	return F(N) / F(N - M);
}

_int64 C(int N, int M) { //����� ��������� �� N �� M
	N1 = N;
	M1 = M;
	return A(N, M) / F(M);
}

void swap(int mas[], int i, int j) { //����� ������� ���� ��������� �������
	int temp = mas[i];
	mas[i] = mas[j];
	mas[j] = temp;
 }
 
void recursionF(int mas[], int N) { //����������� �������� ��������� ���� ������������
	if (N == 1) {
		for (int i = 0; i < N1; i ++) { //����� �������
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

void iterationF(int N) { //������������ �������� ��������� ���� ������������
	int* perestanovka = new int[N];
	for (int i = 0; i < N; i ++) { //������� ������ ������������
		perestanovka[i] = i + 1;
	}
	for (int i = 0; i < N; i ++) { //����� ������ ������������
		if (i == N - 1) {
			cout<<perestanovka[i];
		} else {
			cout<<perestanovka[i]<<"|";
		}
	}
	cout<<endl;

	int* last = new int[N];
	for (int i = N; i > 0; i --) { //�������� ��������� ������������
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

void getNext(int mas[], int N) { //����� ��� ��������� ��������� ������������
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

bool eq(int mas[], int mas1[], int N) { //�������� ��������� ���� ������������
	bool f = true;
	for (int i = 0; i < N; i ++) {
		if (mas[i] != mas1[i]) {
			f = false;
		}
	}
	return f;
}

void generationA(int N, int M) { //������������� ���� ����������
	int* numbers = new int[N + 1];
	for (int i = 1; i < N + 1; i ++) {
		numbers[i] = 0;
	}
	int* A = new int[M + 1];
	solve(numbers, A, 1, N, M);

	delete [] A;
	delete [] numbers;
}

void solve(int numbers[], int A[], int t, int N, int M) { //���������������� ��������� ����������
	for (int i = 1; i <= N; i ++) {
		if (numbers[i] == 0) {
			numbers[i] = 1; //����� �����
			A[t] = i;
			if (t + 1 < M + 1) {
				solve(numbers, A, t + 1, N, M);
			} else {
				for (int j = 1; j < M + 1; j ++) { //����� �������
					if (j == M) {
						cout<<A[j];
					} else {
						cout<<A[j]<<"|";
					}
				}
				cout<<endl;
			}
			numbers[i] = 0; //�������
		}
	}
}

void generationC(int N, int M) { //������������� ���� ���������
	int* C = new int[M + 1];
	C[0] = -1;
	for (int i = 1; i < M + 1; i ++) {
		C[i] = i; //������ ���������
	}
	int j = 1;
	while (j != 0) {
		for (int k = 1; k < M + 1; k ++) { //����� ���������
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
		C[j] = C[j] + 1; //���������� ��������� �����
		for (int i = j + 1; i < M + 1; i ++) {
			C[i] = C[i - 1] + 1;
		}
	}
	delete [] C;
}

void sumGeneration(int N) { //������������� ���� ����� ������������������ �������������� ����� ������������� ���������
	int* mas = new int[N + 1];
	for (int i = 1; i < N + 1; i ++) { //�������� �� ���� ��������� ��������� 1..N
		mas[1] = i;
		sumGenerationHelp(i, N, mas, 1);
	}

	delete [] mas;
}

void sumGenerationHelp(int S, int N, int mas[], int temp) { //��������������� ����� ��� ��������� ����
	if (S == N) {
		for (int i = 1; i < temp + 1; i ++) {
			if ( i == temp) { //����� �����
				cout<<mas[i];
			} else {
				cout<<mas[i]<<"+"; 
			}
		}
		cout<<endl;
	} else {
		for (int i = 1; i <= min(mas[temp], N - S); i ++) {
			mas[++ temp] = i; 
			S = S + i; //��������� �������
			sumGenerationHelp(S, N, mas, temp);
			S = S - i; //�������
			temp --;
		}
	}
}