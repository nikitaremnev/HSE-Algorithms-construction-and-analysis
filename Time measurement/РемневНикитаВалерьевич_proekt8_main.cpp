/*
���: ������ ������ ����������
������: 271(2)��
����: 2.11.2013
������: ��������� �������
����� ����������: Microsoft Visual Studio 2010
*/

#include "����������������������_proekt8_methods.h" //����������� ������������� �����

void main() 
{         
	setlocale(LC_ALL,"Russian"); //����������� ������ (������� ����)
	//����� �� ���� ��������
	
	cout<<"������� clock()"<<endl;
	test_clock(); 
	cout<<"������� time()"<<endl;
	test_time();
	cout<<"������� timeGetTime()"<<endl;
	test_timeGetTime();
	cout<<"������� GetTickCount()"<<endl;
	test_GetTickCount();
	cout<<"������� GetTickCount64()"<<endl;
	test_GetTickCount64();
	cout<<"������� QueryPerformanceCount()"<<endl;
	test_QueryPerformance();
	cout<<"������������� Assembler 32 ����"<<endl;
	test_Assembler32();
	cout<<"������������� Assembler 64 ����"<<endl;
	test_Assembler64();
	cout<<"������������� OPENMP"<<endl;
	test_OPENMP();
	system("pause");
}