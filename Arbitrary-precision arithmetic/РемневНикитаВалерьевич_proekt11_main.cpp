/*
ФИО: Ремнев Никита Валерьевич
Группа: 271(2)ПИ
Дата: 5.12.2013
Задача: Длинные целые
Среда разработки: Microsoft Visual Studio 2010
*/

#include <iostream> //подключение необходимых библиотек
#include <Windows.h>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std; //стандартное пространство имен

class LargeNumbers {

	public:	
		//конструктор с параметрами
		LargeNumbers(string num, int rad) {
			number = num;
			radix = rad;
			N = getN();
			a = new int[N];
			input();
		}

		//конструктор без параметров
		LargeNumbers() {
			number = "0";
			radix = 10;
			N = 0;
			a = new int[2];
			a[0] = 1;
			a[1] = 0;
		}
		
		//считает размер массива
		int getN() {
			int rad = radix;
			N = 0; 
			while (rad > 9) {
				rad = rad / 10;
				N ++;
			}
			int N1 = N;
			N = number.size() / N;
			if (N == 0) { 
				N ++;
			} else {
				if (number.size() % N1 > 0) {
					N ++;
				}
			}
			N ++;
			return N;
		}

		//возвращает число-массив
		int* getNumber() {
			return a;
		}

		//возвращает основание системы счисления
		int getRadix() {
			return radix;
		}

		//задает число через массив
		void setNumber(string num) {
			number = num;
			input();
		}

		//задает число через массив
		void setNumber(int* c) {
			a = c;
		}

		//возвращает основание системы счисления числа
		void setRadix(int rad) {
			radix = rad;
		}

		//ввод из консоли
		void consoleInput() {
			cout<<"Введите число:"<<endl;
			cin>>number;
			cout<<"Введите  основание системы счисления:"<<endl;
			cin>>radix;
			int rad = radix;
			N = getN();
			a = new int[N];
			input();
		}

		//ввод из файла
		void fileInput(string fileName) {
			fstream file;
			file.open (fileName, fstream::in);
			file>>number;
			file>>radix;
			int rad = radix;
			N = getN();
			a = new int[N];
			file.close();
			input();
		}

		//вывод в консоль
		void consoleOutput() {
			int temp;
			int kol1 = 0;
			temp = radix - 1;
			while (temp > 9) {
				temp = temp / 10;
				kol1 ++;
			}
			kol1 ++;
			if (a[0] == 0) {
				cout<<0;
			}
			for (int i = a[0]; i >= 1; i --) {
				if (i != a[0]) {
					int kol = 0;
					temp = a[i];
					while (temp > 9) {
						temp = temp / 10;
						kol ++;
					}
					kol ++;
					if (kol < kol1) {
						for (int j = 0; j < (kol1 - kol); j ++) {
							cout<<"0";
						}
					}
					cout<<a[i];
				} else {
					cout<<a[i];
				}
			}
		}

		//вывод в файл
		void fileOutput(string fileName) {
			fstream file;
			file.open (fileName, fstream::out);
			int temp;
			int kol1 = 0;
			temp = radix - 1;
			while (temp > 9) {
				temp = temp / 10;
				kol1 ++;
			}
			kol1 ++;
			if (a[0] == 0) {
				file<<0;
			}
			for (int i = a[0]; i >= 1; i --) {
				if (i != a[0]) {
					int kol = 0;
					temp = a[i];
					while (temp > 9) {
						temp = temp / 10;
						kol ++;
					}
					kol ++;
					if (kol < kol1) {
						for (int j = 0; j < (kol1 - kol); j ++) {
							file<<"0";
						}
					}
					file<<a[i];
				} else {
					file<<a[i];
				}
			}
			file<<endl;
			file.close();
		}

		//формирование из строки - числа-массива
		void input() {
			for (int i = 0; i < N; i ++) {
				a[i] = 0;
			}
			int j = 0;
			while (j < number.size()) { 
				char ch = number[j];
				j ++;
				if ((ch >= '0') && (ch <= '9')) {
					for (int i = a[0]; i > 0; i --) {
						a[i + 1] = a[i + 1] + a[i] * 10 / radix;
						a[i] = a[i] * 10 % radix;
					}
					a[1] = a[1] + (ch -'0');
					if (a[a[0] + 1] > 0) {
						a[0] = a[0] + 1;
					}
				} 
			}
		}

		//обнуляет число
		void nullNumber() {
			number = "0";
			radix = 10;
			N = 0;
			delete [] a;
			a = new int[2];
			a[0] = 1;
			a[1] = 0;
		}
		
		//this + b : возвращает объект класса
		LargeNumbers plusNumber(LargeNumbers object) {
			int* b = object.getNumber();
			int k = max(a[0], b[0]);
			int* c = new int[k + 2];
			c[k + 1] = 0;
			if (a[0] > b[0]) {
				for (int i = 1; i <= k; i ++) {
					c[i] = a[i];
				}
				for (int i = 1; i <= b[0]; i ++) { 
					c[i + 1] = c[i + 1] + (c[i] + b[i]) / radix; // перенос в старший «разряд»
					c[i] = (c[i] + b[i]) % radix; // текущий «разряд»
				} 
			} else {
				for (int i = 1; i <= k; i ++) {
					c[i] = b[i];
				}
				for (int i = 1; i <= a[0]; i ++) { 
					c[i + 1] = c[i + 1] + (c[i] + a[i]) / radix; // перенос в старший «разряд»
					c[i] = (c[i] + a[i]) % radix; // текущий «разряд»
				} 
			}			
			if (c[k + 1] == 0) {
				c[0] = k; 
			} else { // k - кол-во ячеек массива С с учетом переноса в старший разряд
				c[0] = k + 1;
			}
			LargeNumbers obj = LargeNumbers();
			obj.setNumber(c);
			obj.setRadix(radix);
			return obj;
		}

		//this - b : возвращает объект класса
		LargeNumbers minusNumber(LargeNumbers object) {
			int* b = object.getNumber();
			int i, temp, carry = 0;
			if (lessThan(object)) {
				cout<<"Программа работает только на множестве положительных чисел, поменяйте вычитаемое и уменьшаемое для получения результата"<<endl;
				return LargeNumbers("0", radix);
			} else {
				int* c = new int[max(a[0], b[0]) + 1];
				for (i = 1; i <= b[0]; i ++) {
					temp = a[i] - b[i] + carry;
					if (temp < 0) {
						c[i] = temp + radix;
						carry = -1; 
					} else {
						c[i] = temp;
						carry = 0;
					}
				}
				for (; i <= a[0]; i ++) { 
					temp = a[i] + carry; 
					if (temp < 0) {
						c[i] = temp + radix;
						carry = -1; 
					} 
					else { 
						c[i] = temp;
						carry = 0;
					}
				}
				// Размер результата - по первому 
				// положительному разряду массива с
				i = a[0];
				while ( (i > 0) && (c[i] == 0)) {
					i --; 
				}
				c[0] = i;
				LargeNumbers obj = LargeNumbers();
				obj.setNumber(c);
				obj.setRadix(radix);
				return obj;
			}
		}

		// this == b
		bool equals(LargeNumbers object) {
			bool Eq = false; 
			int* b = object.getNumber();
			if (a[0] != b[0]) {
				return Eq;
			} else { 
				int i = 1;
				while ((i <= a[0]) && (a[i] == b[i])) {
					i ++;
				}
				Eq = (i == (a[0] + 1));
			}
			return Eq;
		}
		
		// (this > b)
		bool moreThan(LargeNumbers object) {
			int* b = object.getNumber();
			bool More = false; // More = (a > b)
			if (a[0] < b[0]) {
				return More;
			} else if (a[0] > b[0]) {
				More = true; 
				return More;
			} else { 
				int i = a[0];
				while ((i > 0) && (a[i] == b[i])) {
					i --;
				}
				if (i == 0) {
					More = false;
				} else if (a[i]>b[i]) {
					More=true;
				} else {
					More=false;
				}
			}
			return More;
		}

		// (this >= b)
		bool moreOrEqual(LargeNumbers object) {
			return moreThan(object) || equals(object);
		}

		// (this != b)
		bool notEquals(LargeNumbers object) {
			return !equals(object);
		}

		// (this < b)
		bool lessThan(LargeNumbers object) {
			return (! moreThan(object)) && (! equals(object));
		}

		//вычисление n-ого числа Фибоначчи
		static LargeNumbers fibonacci(int N) { 
			if (N == 0) {
				return LargeNumbers("0", 1000);
			}
			LargeNumbers* mas = new LargeNumbers[N + 1];
			mas[0] = LargeNumbers("0", 1000);
			mas[1] = LargeNumbers("1", 1000);
			for (int i = 2; i < N + 1; i ++) {
				mas[i] = mas[i - 1].plusNumber(mas[i - 2]);
			}
			LargeNumbers object = mas[N];
			for (int i = 0; i < N; i ++) {
				delete [] mas[i].getNumber();
			}
			delete [] mas;
			return object;
		}

	private:  
		string number; //строковое представление числа (используется для методов ввода числа)
		int radix; //основание системы счисления
		int* a; //массив для хранения числа
		int N; //для вычисления размера массива 
};

void main() {         
	setlocale(LC_ALL,"Russian"); //переключаем локаль (русский язык)
	ifstream in("input11.txt"); 
	int NT; //количество тестов
	in>>NT;
	int radix; //ввод основания системы счисления
	in>>radix;
	cout<<"Задание №2: сравнение чисел из файла."<<endl;
	for (int i = 0; i < NT; i ++) {	
		cout<<"Тест №"<<i + 1<<endl;
		string one;
		string two;
		in>>one;
		in>>two;
		LargeNumbers oneNumber = LargeNumbers(one, radix);
		LargeNumbers twoNumber = LargeNumbers(two, radix);
		oneNumber.consoleOutput();
		if (oneNumber.notEquals(twoNumber)) {
			if (oneNumber.moreThan(twoNumber)) {
				cout<<" больше ";
			} else {
				cout<<" меньше ";
			}
		} else {
			cout<<" равно ";
		}
		twoNumber.consoleOutput();
		cout<<endl;
		delete [] oneNumber.getNumber();
		delete [] twoNumber.getNumber();
	}
	in.close();
	cout<<endl;
	cout<<"Задание №3: N-ое число Фибоначчи."<<endl;
	cout<<"Введите число N (50 < N < 101):"<<endl;
	int N; //номер искомого числа Фибоначчи
	cin>>N;
	cout<<"N - ое число Фибоначчи:"<<endl;
	LargeNumbers result = LargeNumbers();
	result = result.fibonacci(N);
	result.consoleOutput(); //вывод числа
	delete [] result.getNumber();
	cout<<endl;
	system("pause");
}