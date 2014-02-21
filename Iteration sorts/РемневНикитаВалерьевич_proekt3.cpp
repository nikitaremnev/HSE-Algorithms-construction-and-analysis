/*���: ������ ������ ����������
������: 271(2)��
����: 1.10.2013
������: ������������ ����������
����� ����������: Microsoft Visual Studio 2010
*/

#include <iostream> //����������� ����������� ���������
#include <ctime>
#include <Windows.h>
#include <fstream>

void insertion_sort(int a[], int n);// ��������� ���� �������
void counting_sort(int a[], int n);
void radix_sort10(int a[], int n);
void radix_sort256(int a[], int n);
void binary_sort(int a[], int n);
void array_generation(int a[], int n, int min, int max);
bool sort(int a[], int n);
void my_copy(int a[], int a1[], int n);

using namespace std; //����������� ������������ ����

void main() 
{                                  
	setlocale(LC_ALL,"Russian"); //����������� ������ (������� ����)

	int *ar, *ar1; //������������ �������, ���� ��� �������� ������������� �������, ������ ��� ����������������
	int command = 0;

	do //���� ������� 
	{ 
		cout<<"��� ���������� �������� � ���������, �������:"<<endl; //�������� ������ ������������
		cout<<"1 - ��� ������ ������������ ����������;"<<endl;
		cout<<"0 - ��� ������ �� ���������."<<endl;
		cout<<"������� �������:"<<endl;
		cin>>command; //���� �������
		cout<<endl;

		switch (command) //�������� �������� � ����������� �� �������
		{
		    case 1:
			{
				cout<<"�� ������� ������������ ����������, �������:"<<endl; //�������� ������ ������������
				cout<<"1 - ��� ������� ��������� ������� � �������;"<<endl;
				cout<<"2 - ��� ������� ��������� ������� �� �����;"<<endl;
				cout<<"0 - ��� ������ � ������� ����."<<endl;
				cout<<"������� �������:"<<endl;
				int commandtest = 0;
				cin>>commandtest; //���� �������

				switch (commandtest)
				{ //���������� ������
					case 1:
					{
						cout<<endl;
						cout<<"������� ���������� ������:"<<endl; //���� ����������� ������
						int NL = 0;
						cin>>NL;
						cout<<"������� ������ ��������:"<<endl;
						int N = 0;
						cin>>N;
						cout<<"������� ����������� ������� ��������� ������� (����� ����� >=0):"<<endl;
						int min = 0;
						cin>>min;
						cout<<"������� ������������ ������� ��������� ������� (����� ����� ������� ����������� �������):"<<endl;
						int max = 0;
						cin>>max;

						ar = new int[N];
						ar1 = new int[N];
						
					    ofstream out("output_proekt3.txt"); //�������� ����� ��� ������
						srand(time(0)); //��� ��������� �������
						
						for (int i = 0; i < NL; i++)
						{
							array_generation(ar, N, min, max); //��������� �������
							my_copy(ar, ar1, N); //����������� ar � ar1
							
							out<<"���� �"<<i + 1<<"\n"; //����� ����������� ��� ������ ����������
							out<<endl;
							out<<"C��������� �������� ���������"<<"\n";
							insertion_sort(ar1, N);
							out<<"������ �� ����������:"<<"\n";
							for (int i = 0; i < N; i++)
								out<<ar[i]<<" ";
							out<<"\n";
							out<<"������ ����� ����������:"<<"\n";
							for (int i = 0; i < N; i++)
								out<<ar1[i]<<" ";
							out<<"\n";
							if (sort(ar1, N)) out<<"������ ������������ �����!"<<"\n";
							else out<<"������ ������������ �������!"<<"\n";
							my_copy(ar, ar1, N);
							out<<endl;
							
							out<<"C��������� ��������� ���������"<<"\n";
							binary_sort(ar1, N);
							out<<"������ �� ����������:"<<"\n";
							for (int i = 0; i < N; i++)
								out<<ar[i]<<" ";
							out<<"\n";
							out<<"������ ����� ����������:"<<"\n";
							for (int i = 0; i < N; i++)
								out<<ar1[i]<<" ";
							out<<"\n";
							if (sort(ar1, N)) out<<"������ ������������ �����!"<<"\n";
							else out<<"������ ������������ �������!"<<"\n";
							my_copy(ar, ar1, N);
							out<<endl;

							out<<"C��������� ���������"<<"\n";
							counting_sort(ar1, N);
							out<<"������ �� ����������:"<<"\n";
							for (int i = 0; i < N; i++)
								out<<ar[i]<<" ";
							out<<"\n";
							out<<"������ ����� ����������:"<<"\n";
							for (int i = 0; i < N; i++)
								out<<ar1[i]<<" ";
							out<<"\n";
							if (sort(ar1, N)) out<<"������ ������������ �����!"<<"\n";
							else out<<"������ ������������ �������!"<<"\n";
							my_copy(ar, ar1, N);
							out<<endl;

							out<<"�������� ���������� �� ��������� 10"<<"\n";
							radix_sort10(ar1, N);
							out<<"������ �� ����������:"<<"\n";
							for (int i = 0; i < N; i++)
								out<<ar[i]<<" ";
							out<<"\n";
							out<<"������ ����� ����������:"<<"\n";
							for (int i = 0; i < N; i++)
								out<<ar1[i]<<" ";
							out<<"\n";
							if (sort(ar1, N)) out<<"������ ������������ �����!"<<"\n";
							else out<<"������ ������������ �������!"<<"\n";
							my_copy(ar, ar1, N);
							out<<endl;

							out<<"�������� ���������� �� ��������� 256"<<"\n";
							radix_sort256(ar1, N);
							out<<"������ �� ����������:"<<"\n";
							for (int i = 0; i < N; i++)
								out<<ar[i]<<" ";
							out<<"\n";
							out<<"������ ����� ����������:"<<"\n";
							for (int i = 0; i < N; i++)
								out<<ar1[i]<<" ";
							out<<"\n";
							if (sort(ar1, N)) out<<"������ ������������ �����!"<<"\n";
							else out<<"������ ������������ �������!"<<"\n";
							out<<endl; 

						}
						
						delete [] ar; //����������� ������ �� ��� ��������
						delete [] ar1;
						cout<<"���������� ���� �������� � ���� output_proekt3.txt"<<endl;
						cout<<endl;
						out.close();

						break;
					}
					case 2:
					{
						ifstream in("input_proekt3.txt"); //��� �������� �����
						ofstream out("output_proekt3.txt"); //��� ��������� �����
						if (in.good()) //�������� ������ �� ����
						{
							int NL; //��������� ���������� ������
							in>>NL;
							
							for (int i = 0; i < NL; i++)
							{
								int N; //��������� ������ �������
								in>>N;
								ar = new int[N];
								ar1 = new int[N];

								for (int j = 0; j < N; j++)
								{
									in>>ar[j]; //��������� ������
									ar1[j] = ar[j];
								}

								out<<"���� �"<<i + 1<<"\n"; //����� ����������� ��� ������ ����������
								out<<endl;
								out<<"C��������� �������� ���������"<<"\n";
								insertion_sort(ar1, N);
								out<<"������ �� ����������:"<<"\n";
								for (int i = 0; i < N; i++)
									out<<ar[i]<<" ";
								out<<"\n";
								out<<"������ ����� ����������:"<<"\n";
								for (int i = 0; i < N; i++)
									out<<ar1[i]<<" ";
								out<<"\n";
								if (sort(ar1, N)) out<<"������ ������������ �����!"<<"\n";
								else out<<"������ ������������ �������!"<<"\n";
								my_copy(ar, ar1, N);
								out<<endl;
							
								out<<"C��������� ��������� ���������"<<"\n";
								binary_sort(ar1, N);
								out<<"������ �� ����������:"<<"\n";
								for (int i = 0; i < N; i++)
									out<<ar[i]<<" ";
								out<<"\n";
								out<<"������ ����� ����������:"<<"\n";
								for (int i = 0; i < N; i++)
									out<<ar1[i]<<" ";
								out<<"\n";
								if (sort(ar1, N)) out<<"������ ������������ �����!"<<"\n";
								else out<<"������ ������������ �������!"<<"\n";
								my_copy(ar, ar1, N);
								out<<endl;

								out<<"C��������� ���������"<<"\n";
								counting_sort(ar1, N);
								out<<"������ �� ����������:"<<"\n";
								for (int i = 0; i < N; i++)
									out<<ar[i]<<" ";
								out<<"\n";
								out<<"������ ����� ����������:"<<"\n";
								for (int i = 0; i < N; i++)
									out<<ar1[i]<<" ";
								out<<"\n";
								if (sort(ar1, N)) out<<"������ ������������ �����!"<<"\n";
								else out<<"������ ������������ �������!"<<"\n";
								my_copy(ar, ar1, N);
								out<<endl;

								out<<"�������� ���������� �� ��������� 10"<<"\n";
								radix_sort10(ar1, N);
								out<<"������ �� ����������:"<<"\n";
								for (int i = 0; i < N; i++)
									out<<ar[i]<<" ";
								out<<"\n";
								out<<"������ ����� ����������:"<<"\n";
								for (int i = 0; i < N; i++)
									out<<ar1[i]<<" ";
								out<<"\n";
								if (sort(ar1, N)) out<<"������ ������������ �����!"<<"\n";
								else out<<"������ ������������ �������!"<<"\n";
								my_copy(ar, ar1, N);
								out<<endl;

								out<<"�������� ���������� �� ��������� 256"<<"\n";
								radix_sort256(ar1, N);
								out<<"������ �� ����������:"<<"\n";
								for (int i = 0; i < N; i++)
									out<<ar[i]<<" ";
								out<<"\n";
								out<<"������ ����� ����������:"<<"\n";
								for (int i = 0; i < N; i++)
									out<<ar1[i]<<" ";
								out<<"\n";
								if (sort(ar1, N)) out<<"������ ������������ �����!"<<"\n";
								else out<<"������ ������������ �������!"<<"\n";
								out<<endl; 

								delete [] ar;
								delete [] ar1;
							}
						}
						else
						{ //���� ���� �� ��� ������
							cout<<"���� �� ��� ������"<<endl;
							cout<<endl;
							break;
						}
				        in.close(); //�������� ������
						out.close();

						cout<<"���������� ���� �������� � ���� output_proekt3.txt"<<endl;
						cout<<endl;

						break;
					}
					case 0: //������� � ������� ����
					{
						cout<<endl;
						break;
					}
				}
					
			}
			case 0: break; //������� �� ���������
		}

	}
	while (command != 0);
}

void insertion_sort(int a[], int n) //���������� �������� ���������
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

void counting_sort(int a[], int n) //���������� ���������
{
	int k = 0;
	for (int i = 0; i < n; i++) //�������� ������� ������������ � ����������
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

void radix_sort10(int a[], int n) //�������� ���������� �� ��������� 10
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

void radix_sort256(int a[], int n) //�������� ���������� �� ��������� 256
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

void binary_sort(int a[], int n) //���������� ��������� ���������
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

void array_generation(int a[], int n, int min, int max) //���������� ������
{
	for (int i = 0; i < n; i++)
		a[i] = min + rand()%(max - min + 1);
}

bool sort(int a[], int n) //�������� ����������������� �������
{
	for (int i = 0; i < n-1; i++)
		if (a[i] > a[i + 1]) 
			return false;
	return true;
}

void my_copy(int a[], int a1[], int n) //����� ��� ����������� ��������� ������ ������� � ������
{
	for (int i = 0; i < n; i++)
	{
		a1[i] = a[i];
	}
}