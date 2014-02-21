/*
���: ������ ������ ����������
������: 271(2)��
����: 28.11.2013
������: �������� �������
����� ����������: Microsoft Visual Studio 2010
*/

#include <iostream> //����������� ����������� ���������
#include <Windows.h>
#include <algorithm>
#include <fstream>
#include <math.h>
#include <omp.h>

using namespace std; //����������� ������������ ����

void knapsack_greedy(int weight[], int cost[], int W, int N); //������ ��������
void knapsack_comeback(int weight[], int cost[], int W, int N); //��� ������ �������� � ���������
void knapsack_dynamic(int weight[], int cost[], int W, int N); //������������ ���������������� (��� ��������)
void backtracking(int i, int C_search, int W_search); //������� � ���������
void knapsack_dynamic_recursion(int weight[], int cost[], int W, int N); //��� ������ ����������� ������� (������������ ����������������)
void dynamic_recursion(int i, int j); //������������ ���������������� � ���������
void output_console(int W, int C, int variants[], int size, double time); //����� � �������
void output_file(int W, int C, int variants[], int size, double time); //����� � ����