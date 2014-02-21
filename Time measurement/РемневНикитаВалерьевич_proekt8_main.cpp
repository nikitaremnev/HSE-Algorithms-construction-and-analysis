/*
ФИО: Ремнев Никита Валерьевич
Группа: 271(2)ПИ
Дата: 2.11.2013
Задача: Измерение времени
Среда разработки: Microsoft Visual Studio 2010
*/

#include "РемневНикитаВалерьевич_proekt8_methods.h" //подключение заголовочного файла

void main() 
{         
	setlocale(LC_ALL,"Russian"); //переключаем локаль (русский язык)
	//вывод по всем функциям
	
	cout<<"Функция clock()"<<endl;
	test_clock(); 
	cout<<"Функция time()"<<endl;
	test_time();
	cout<<"Функция timeGetTime()"<<endl;
	test_timeGetTime();
	cout<<"Функция GetTickCount()"<<endl;
	test_GetTickCount();
	cout<<"Функция GetTickCount64()"<<endl;
	test_GetTickCount64();
	cout<<"Функция QueryPerformanceCount()"<<endl;
	test_QueryPerformance();
	cout<<"Использование Assembler 32 бита"<<endl;
	test_Assembler32();
	cout<<"Использование Assembler 64 бита"<<endl;
	test_Assembler64();
	cout<<"Использование OPENMP"<<endl;
	test_OPENMP();
	system("pause");
}