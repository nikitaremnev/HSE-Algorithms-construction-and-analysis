/*
���: ������ ������ ����������
������: 271(2)��
����: 16.10.2013
������: ����������� ����������
����� ����������: Microsoft Visual Studio 2010
*/

#include "����������������������_proekt6_methods.h" //����������� ������������� �����

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
						
					    ofstream out("output_proekt6.txt"); //�������� ����� ��� ������
						srand(time(0)); //��� ��������� �������
						
						for (int i = 0; i < NL; i++)
						{
							array_generation(ar, N, min, max); //��������� �������
							my_copy(ar, ar1, N); //����������� ar � ar1
							
							out<<"���� �"<<i + 1<<"\n"; //����� ����������� ��� ������ ����������
							out<<endl;
							out<<"C��������� ��������"<<"\n";
							merge_sort(ar1, 0, N - 1);
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
							
							out<<"������������� ����������"<<"\n";
							heap_sort(ar1, N);
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
							
							out<<"���������� ����� (������� �������)"<<"\n";
							quick_sort_middle(ar1, 0, N - 1);
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
							
							out<<"���������� ����� (������ ����� �������)"<<"\n";
							quick_sort_left(ar1, 0, N - 1);
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

							out<<"���������� ����� (������������ �������)"<<"\n";
							quick_sort_random(ar1, 0, N - 1);
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
						cout<<"���������� ���� �������� � ���� output_proekt6.txt"<<endl;
						cout<<endl;
						out.close();

						break;
					}
					case 2:
					{
						ifstream in("input_proekt6.txt"); //��� �������� �����
						ofstream out("output_proekt6.txt"); //��� ��������� �����
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
								out<<"C��������� ��������"<<"\n";
								merge_sort(ar1, 0, N - 1);
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
							
								out<<"������������� ����������"<<"\n";
								heap_sort(ar1, N);
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

								out<<"���������� ����� (������� �������)"<<"\n";
								quick_sort_middle(ar1, 0, N - 1);
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

								out<<"���������� ����� (������ ����� �������)"<<"\n";
								quick_sort_left(ar1, 0, N - 1);
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

								out<<"���������� ����� (������������ �������)"<<"\n";
								quick_sort_random(ar1, 0, N - 1);
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

						cout<<"���������� ���� �������� � ���� output_proekt6.txt"<<endl;
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
