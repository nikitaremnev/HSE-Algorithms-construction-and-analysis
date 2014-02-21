/*
���: ������ ������ ����������
������: 271(2)��
����: 28.11.2013
������: �������� �������
����� ����������: Microsoft Visual Studio 2010
����������:
� ������ ������, �������� ������ �������, ������ ������� ����������
���, ��� ��������������� ����������� �������� ����������� ��� �������
��� ��� ���� ��������. �� ���� ����������� ���������� ��������� ����������
� ���������� - ������� �� �����, ��� ��� ����� ����� �������� (�������� ������ ����������
� ������� - ��� �� ����� ������). � �������� �������, ��������������� � ������� - ������.
��� ��������� ������� ������������ ������� omp_get_wtime() �� ���������� omp.h. ����� ������ � ������ ������,
��� ��� ��� ��������� ������� ���������� ������� ����� ����, � ����������� �������� ��������� ���� ��� �� ������
������ �������� ��������� �������. ����� � ������������.
�����, � ��������� ���� 4-�� ������ ������� ������ ������� - ������������ ���������������� 
��� ��������. ����� ����������, ��� ����� ������� � ���������, ��� ���� ������, ������� ������� ��� 
�� ����.
*/

#include "����������������������_proekt10_methods.h" //����������� ������������� �����

double timestart, timefinish; //��� ���������� �������

void knapsack_greedy(int weight[], int cost[], int W, int N) { //������ �������� (�� ����������� �������������!)

	timestart = omp_get_wtime(); //��������� ������ 

	double* ud_cost = new double[N]; //������ �������� �����
	for (int i = 0; i < N; i ++) {
		ud_cost[i] = (double)cost[i] / (double)weight[i]; //��������� ������ �������� �����
	} 

	int* numbers = new int[N]; //������ ��� �������� ������� ���������
	for (int i = 0; i < N; i ++) {
		numbers[i] = i;
	}

	int C_search=0, W_search=0; //��� ������ ����������
	int* mas = new int[N];

	for (int i = N - 1; i > 0; i --) // ���������� �������� (���� ���������� - ������ �������� �����)
	    for (int j = 0; j < i; j ++) //��������� ���������
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

    for (int i = 0; i < N; i ++) { //���������� ������� - ���� ������������ ��������� � ���
		mas[numbers[i]] = 0;
		if ((W_search + weight[i]) <= W) {
          W_search = W_search + weight[i];
          C_search = C_search + cost[i];
		  mas[numbers[i]] = 1;
		}
	}	

	timefinish = omp_get_wtime(); //��������� ����� ���������� 

	output_console(W_search, C_search, mas, N, timefinish - timestart); //����� �������
	output_file(W_search, C_search, mas, N, timefinish - timestart); //����� �������

	delete [] ud_cost; //������� ������
	delete [] numbers;
	delete [] mas;
} 

//���������� ���������� ��� �������� � ���������
//��� ���� ����� ���������� ���� �������� - ����� ��������, � �� ������ � ������� ��� ���������
int* weight1; //������ �����
int* cost1;  //������ ���
int W1; //������ ������������ ��� �������
int N1; //������ �������
int C_max; //������������ ����
int W_max; //������������ ���
int *mas; //������ ��� �������� ��������� ������ ���������
int *mas_max; //������ ��� �������� ��������� ������ ��������� ��� ������������ ����
 
void knapsack_comeback(int weight[], int cost[], int W, int N) {//������� ������ ���������� ����������
	//� �������� ����������� ������� � ���������
	weight1 = weight; //�������� ���������� ����������
	cost1 = cost;
	W1 = W;
	N1 = N;

	timestart = omp_get_wtime();

	W_max = 0; //��������� ���������� ����������� � �������
	C_max = 0;
	mas = new int[N1];
	mas_max = new int[N1];

	backtracking(0, 0, 0); //����� ��������

	timefinish = omp_get_wtime();

	output_console(W_max, C_max, mas_max, N1, timefinish - timestart); //����� �������
	output_file(W_max, C_max, mas_max, N1, timefinish - timestart); //����� �������

	delete [] mas_max; //������� ������
	delete [] mas;
}

void backtracking(int i, int C_search, int W_search) { //����������� ������� � ���������
	for (int j = i; j < N1; j ++) { //�������� �� ���� ���������, ������� � ����������� ������
		mas[j] = 0; //�� ����� ������� ����������
		if (W1 >= W_search + weight1[j]) { //���� ��� �������� �� ��������� ������������
			if (C_search + cost1[j] >= C_max) { //���� ��������� ��������� ������������
				C_max = C_search + cost1[j]; //��������� ��������
				W_max = W_search + weight1[j];
				mas[j] = 1; //����� �������
				for (int k = 0; k < N1; k ++) {
					mas_max[k] = mas[k];
				}
			}
			mas[j] = 1; //����� �������
			backtracking(j + 1,  C_search + cost1[j], W_search + weight1[j]); //��������� �������� ������
        } 
		mas[j] = 0; //����������� �������
    }
}

void knapsack_dynamic(int weight[], int cost[], int W, int N) { //������������ ���������������� (��� ��������)
	
	timestart = omp_get_wtime();
	
	int** dp = new int*[N + 1]; //������� �������

	for (int i = 0; i < N + 1; i ++) { //������� ������� � ��������� ������� ������ ������
		dp[i] = new int[W + 1];
	}

	for (int i = 0; i < W + 1; i ++) 
		dp[0][i] = 0;

	for (int i = 1; i <= N; ++ i) { //������������ ���������� �������
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
	while (dp[s][n]!=0) { //�������� ��� �������
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

	output_console(W_search, dp[N][W], mas, N, timefinish - timestart); //����� �������
	output_file(W_search, dp[N][W], mas, N, timefinish - timestart); //����� �������

	for (int i = 0; i < N + 1; i ++) { //������� ������
		delete [] dp[i];
	}

	delete [] dp;
	delete [] mas;
}

int **dp1; //���������� ���������� ��� �������� ������� (��� ������ ����������� ������� (���. ����������������))
void knapsack_dynamic_recursion(int weight[], int cost[], int W, int N) {
	weight1 = weight; //�������� ���������� ����������
	cost1 = cost;

	timestart = omp_get_wtime(); 
	
	dp1 = new int*[N + 1]; //������� �������
	for (int i = 0; i < N + 1; i ++) { //������� ������� � ��������� ������� ������ ������
		dp1[i] = new int[W + 1];
	}
	for (int i = 0; i < W + 1; i ++) 
		dp1[0][i] = 0;

	dynamic_recursion(N, W); //��������� ���������� ������� (��������� ��������, �� ���)

	int s = N;
	int n = W;
	int W_search=0;
	mas = new int[N];
	for (int i = 0; i < N; i ++) {
		mas[i] = 0;
	}
	while (dp1[s][n]!=0) { //�������� ��� �������
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

	output_console(W_search, dp1[N][W], mas, N, timefinish - timestart); //����� �������
	output_file(W_search, dp1[N][W], mas, N, timefinish - timestart); //����� �������
	
	for (int i = 0; i < N + 1; i ++) { //������� ������
		delete [] dp1[i];
	}
	delete [] dp1;
	delete [] mas;
}

void dynamic_recursion(int i, int j) {
	if ((i == 0) || (j < 0)) { //����� �� ��������
		return;
	}
	dynamic_recursion(i - 1, j); //�������� ���������� �������
	dp1[i][j] = dp1[i - 1][j];
	if (j >= weight1[i - 1]) {
		dynamic_recursion(i - 1, j - weight1[i - 1]); //�������� ���������� �������
		dp1[i][j] = max(dp1[i - 1][j - weight1[i - 1]] + cost1[i - 1], dp1[i - 1][j]);
	} 
}

void output_console(int W, int C, int variants[], int size, double time) { //����� � �������
	cout<<"����� ����������: "<<time * 1000000<<" mks (�����������)"<<endl;
	cout<<"��� �������: "<<W<<endl; 
	cout<<"��������� �������: "<<C<<endl;
	cout<<"������ ��������� � �������: ";
	for (int i = 0; i < size; i ++) {
		if (variants[i]==1) 
			cout<<i + 1<<" ";
	}
	cout<<endl;
	cout<<endl;
}

void output_file(int W, int C, int variants[], int size, double time) { //����� � ����
	ofstream out;
	out.open("output_knap.txt", std::ios_base::app);
	out<<"����� ����������: "<<time * 1000000<<" mks (�����������)"<<endl;
	out<<"��� �������: "<<W<<endl; 
	out<<"��������� �������: "<<C<<endl;
	out<<"������ ��������� � �������: ";
	for (int i = 0; i < size; i ++) {
		if (variants[i]==1) 
			out<<i + 1<<" ";
	}
	out<<endl;
	out<<endl;
	out.close();
}