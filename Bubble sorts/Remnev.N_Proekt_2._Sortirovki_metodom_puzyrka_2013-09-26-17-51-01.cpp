/*
���: ������ ������ ����������
������: 271(2)��
����: 22.09.2013
������: ������� ���������� ���������
����� ����������: Microsoft Visual Studio 2010
*/

#include <iostream> //����������� ����������� ���������
#include <ctime>
#include <Windows.h>

void bubble_sort(int a[], int n);// ��������� ���� �������
void bubble_iverson_1(int a[], int n);
void bubble_iverson_2(int a[], int n);
void array_generation(int a[], int n, int min, int max);
void results(int a[], int n, int a1[], int n1);

using namespace std; //����������� ������������ ����

void main() 
{                                  
	setlocale(LC_ALL,"Russian"); //����������� ������ (������� ����)

	int *ar, *ar1; //�������, ar - �� ����� ������������� ��� ���������� ���������� �������, ar1 - ����������� ������
	int command=0, n, min, max; //command - ��� ����� ������� ������������, n - ���������� ��������� �������, min, max - ������� �������
	bool f=false; //���� ��� ����������� ������������� ������� 

	do //���� ������� 
	{ 
		cout<<"��� ���������� �������� � ���������, �������:"<<endl; //�������� ������ ������������
		cout<<"1 - ��� ��������� �������;"<<endl;
		cout<<"2 - ��� ���������� ��������� ���������;"<<endl;
		cout<<"3 - ��� ���������� ��������� ��������� � �������� ��������� I;"<<endl;
		cout<<"4 - ��� ���������� ��������� ��������� � �������� ��������� II;"<<endl;
		cout<<"0 - ��� ������ �� ���������."<<endl;
		cout<<"������� �������:"<<endl;
		cin>>command; //���� �������

		switch (command) //�������� �������� � ����������� �� �������
		{
		    case 1:
			{
				cout<<"������� ���������� ��������� � ������� (����� �����, ������� 0):"<<endl;
		      	cin>>n; //������ ���������� ��������� �������

				if (f)
				{ //����������� ������
					delete [] ar;
					delete [] ar1;
				}

	    		ar1=new int[n]; //�������������� �������
				ar=new int[n];

				cout<<"������� ����������� ������� ��������� ������� (����� �����):"<<endl; //������ ������� �������
				cin>>min;
			    cout<<"������� ������������ ������� ��������� ������� (����� ����� ������� ����������� �������):"<<endl;
			    cin>>max;
			
		     	array_generation(ar, n, min, max); //���������� ������

				cout<<"������������ ������:"<<endl; //����� ������������� �������
	            for (int i=0;i<n;i++)
					cout<<ar[i]<<" ";
				cout<<endl;

			    for (int i=0;i<n;i++) //������������� ����������� �������
					ar1[i]=ar[i];

				f=true; //������ - ������ ������
				break;
			}
			case 2:
			{
				if (f) //��������, ��� ������ ��� ������
				{
			        for (int i=0;i<n;i++) //������������� ����������� �������, �� ������ ���� ��� ar1 ��� ������������
						ar1[i]=ar[i]; 

					bubble_sort(ar1,n); //���������
					results(ar, n, ar1, n); //����� ����������
				}
				else
				{
					cout<<"������ �� ��� ������������, ����������� ������!"<<endl; 
				}
				break;
			}
			case 3:
			{
				if (f) //��������, ��� ������ ��� ������
				{
			        for (int i=0;i<n;i++) //������������� ����������� �������, �� ������ ���� ��� ar1 ��� ������������
						ar1[i]=ar[i]; 

					bubble_iverson_1(ar1,n); //��������� ������
					results(ar, n, ar1, n); //������� ���������
				}
				else
				{
					cout<<"������ �� ��� ������������, ����������� ������!"<<endl;
				}
				break;
			}
			case 4:
			{
				if (f) //��������, ��� ������ ��� ������
				{
			        for (int i=0;i<n;i++)//������������� ����������� �������, �� ������ ���� ��� ar1 ��� ������������
						ar1[i]=ar[i]; 

					bubble_iverson_2(ar1,n); //��������� ������
					results(ar, n, ar1, n); //������� ���������
				}
				else
				{
					cout<<"������ �� ��� ������������, ����������� ������!"<<endl;
				}
				break;
			}
			default: break;
		}
	}
	while(command!=0);
	if (f)
	{
		delete [] ar; //����������� ������
		delete [] ar1;
	}
}

void bubble_sort(int a[], int n) //���������� ������� ���������
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

void bubble_iverson_1(int a[], int n) //���������� ��������� � �������� ��������� 1
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

void bubble_iverson_2(int a[], int n) //���������� ��������� � �������� ��������� 2
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

void array_generation(int a[], int n, int min, int max) //���������� ������
{
	srand(time(0));
	for (int i=0;i<n;i++)
		a[i]=min+rand()%(max-min+1);
}

void results(int a[], int n, int a1[], int n1) //����� ����������
{
	cout<<"������ �� ����������:"<<endl;
	for (int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<"������ ����� ����������:"<<endl;
	for (int i=0;i<n1;i++)
		cout<<a1[i]<<" ";
	cout<<endl;
}