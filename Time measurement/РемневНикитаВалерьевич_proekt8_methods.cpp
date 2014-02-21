/*
���: ������ ������ ����������
������: 271(2)��
����: 2.11.2013
������: ��������� �������
����� ����������: Microsoft Visual Studio 2010
*/

#include "����������������������_proekt8_methods.h" //����������� ������������� �����

//������������� clock
void test_clock() {
	double timestart, timefinish; 
	for (int i = 0; i < 10; i++) {
		timestart = clock(); 
		while (clock() == timestart); 
		timefinish = clock(); 
		cout << timestart << "ms " << timefinish << "ms " 
				<< (timefinish - timestart) << "ms" << endl; 
	}
}

//������������� time
void test_time() {
	double timestart, timefinish;
	for (int i = 0; i < 10; i++) {
		timestart = time(NULL); 
		while (time(NULL) == timestart); 
		timefinish = time(NULL); 
		cout << timestart << "ms " << timefinish << "ms " 
				<< (timefinish - timestart) << "ms" << endl; 
	}
}

//������������� timeGetTime
void test_timeGetTime() {
	DWORD timestart, timefinish; 
	for (int i = 0; i < 10; i++) {
		timestart = timeGetTime(); 
		while (timeGetTime() == timestart); 
		timefinish =  timeGetTime(); 
		cout << timestart << "ms " << timefinish << "ms " 
				<< (timefinish - timestart) << "ms" << endl; 
	}
}

//������������� GetTickCount
void test_GetTickCount() {
	DWORD timestart, timefinish; 
	for (int i = 0; i < 10; i++) {
		timestart = GetTickCount(); 
		while (GetTickCount() == timestart); 
		timefinish =  GetTickCount(); 
		cout << timestart << "ms " << timefinish << "ms " 
				<< (timefinish - timestart) << "ms" << endl;
	}
} 

//������������� GetTickCount64
void test_GetTickCount64() {
	ULONGLONG timestart, timefinish; 
	for (int i = 0; i < 10; i++) {
		timestart = GetTickCount64(); 
		while (GetTickCount64() == timestart); 
		timefinish =  GetTickCount64(); 
		cout << timestart << "ms " << timefinish << "ms " 
				<< (timefinish - timestart) << "ms" << endl;
	}
} 

//������������� QueryPerformanceCount � QueryPerformanceFrequency
void test_QueryPerformance() {
	LARGE_INTEGER Fr;
	LARGE_INTEGER timestart, timefinish; 
	LARGE_INTEGER check;
	QueryPerformanceFrequency(&Fr); 
	QueryPerformanceCounter(&timestart); 
	QueryPerformanceCounter(&timefinish); 
	for (int i = 0; i < 10; i++) {
		QueryPerformanceCounter(&timestart); 
		QueryPerformanceCounter(&check); 
		while (timestart.QuadPart * 1000000 / Fr.QuadPart == check.QuadPart * 1000000 / Fr.QuadPart) QueryPerformanceCounter(&check); 
		QueryPerformanceCounter(&timefinish); 
		cout << timestart.QuadPart * 1000000 / Fr.QuadPart << "mks " << timefinish.QuadPart * 1000000 / Fr.QuadPart << "mks " 
			<< (timefinish.QuadPart - timestart.QuadPart) * 1000000 / Fr.QuadPart   << "mks" << endl;
	}
}

//������������� ���������� 32 ����
void test_Assembler32() {
	DWORD StartTime3, ElapsedTime3; 
	for (int i = 0; i < 10; i++) {  
		_asm 
		{ 
			RDTSC 
			mov StartTime3, eax 
		} 
	 
		_asm 
		{ 
			RDTSC 
			sub eax, StartTime3 
			mov ElapsedTime3, eax 
		} 
		cout<<"32-CPU "<<StartTime3<<" "<<ElapsedTime3<<" Tick"<<endl;
	 } 
}

//������������� ���������� 64 ����
void test_Assembler64() {
	_int64 StartTime4, EndTime4; 
	for(int i = 0; i < 10; i++) { 
		 _asm 
		 { 
			 RDTSC 
			 mov DWORD PTR StartTime4, eax 
			 mov DWORD PTR StartTime4+4, edx 
		 } 
		 _asm 
		 {
			 RDTSC 
			 mov DWORD PTR EndTime4, eax 
			 mov DWORD PTR EndTime4+4, edx 
		 } 
		cout<<"CPU-64 "<<StartTime4<<" "<<EndTime4<<" "<<EndTime4 - StartTime4<<" Tick"<<endl; 
	 } 
}

//������������� omp_get_wtime(), �������������� �������, ������� �� ���� � ��������
void test_OPENMP() {
	double timestart, timefinish;
	for (int i = 0; i < 10; i++) {
		timestart = omp_get_wtime(); 
		while (omp_get_wtime() == timestart); 
		timefinish = omp_get_wtime(); 
		cout << timestart<< "ms " << timefinish<< "ms " 
				<< (timefinish - timestart) << "ms" << endl; 
	}
}