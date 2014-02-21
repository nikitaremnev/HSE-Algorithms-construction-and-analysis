/*
���: ������ ������ ����������
������: 271(2)��
����: 28.11.2013
������: �������� �������
����� ����������: Microsoft Visual Studio 2010
*/

#include "����������������������_proekt10_methods.h" //����������� ������������� �����

void main() 
{         
	setlocale(LC_ALL,"Russian"); //����������� ������ (������� ����)

	ifstream in("input_knap.txt"); //��� �������� �����
	ofstream out("output_knap.txt"); //��� ��������� �����
	out.close(); //�������� - ��������, ��� �������� ������������� �����

	int NT; //���������� ������
	in>>NT; //��������� ���������� ������
	int* weight; //������ ����� ���������
	int* cost; //������ ��� ���������

	for (int i = 0; i < NT; i ++) { //�������� �� ������

		int W; //������������ ���
		in>>W; //��������� ������������ ���
		int N; //���������� ��������� � �������
		in>>N; //��������� ���������� ��������� � �������
		weight = new int[N]; //������ �����
		cost = new int[N]; //������ ���
		for (int j = 0; j < N; j ++) {
			in>>weight[j]; //��������� ������ �����
		}
		for (int j = 0; j < N; j ++) {
			in>>cost[j]; //��������� ������ ���
		}

		out.open("output_knap.txt", std::ios_base::app); //����� � ���� � � �������
		cout<<"���� �"<<i + 1<<":"<<endl;
		out<<"���� �"<<i + 1<<":"<<endl;

		cout<<"����������� �������� � ���������:"<<endl;
		out<<"����������� �������� � ���������:"<<endl;
		out.close();
		knapsack_comeback(weight, cost, W, N);

		out.open("output_knap.txt", std::ios_base::app);
		cout<<"����������� �������� (������������ ����������������):"<<endl;
		out<<"����������� �������� (������������ ����������������):"<<endl;
		out.close();
		knapsack_dynamic_recursion(weight, cost, W, N);

		out.open("output_knap.txt", std::ios_base::app);
		cout<<"������������ ���������������� (��� ��������):"<<endl;
		out<<"������������ ���������������� (��� ��������):"<<endl;
		out.close();
		knapsack_dynamic(weight, cost, W, N);

		out.open("output_knap.txt", std::ios_base::app);
		cout<<"������� ������ ��������:"<<endl;
		out<<"������� ������ ��������:"<<endl;
		out.close();
		knapsack_greedy(weight, cost, W, N);

		delete [] weight;
		delete [] cost;
	}
	system("pause");
}