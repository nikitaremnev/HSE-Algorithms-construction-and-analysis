/*
ФИО: Ремнев Никита Валерьевич
Группа: 271(2)ПИ
Дата: 2.11.2013
Задача: Измерение времени
Среда разработки: Microsoft Visual Studio 2010
*/

#include "РемневНикитаВалерьевич_proekt8_methods.h" //подключение заголовочного файла

//использование clock
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

//использование time
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

//использование timeGetTime
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

//использование GetTickCount
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

//использование GetTickCount64
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

//использование QueryPerformanceCount и QueryPerformanceFrequency
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

//использование ассемблера 32 бита
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

//использование ассемблера 64 бита
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

//использование omp_get_wtime(), дополнительная функция, которой не было в семинаре
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