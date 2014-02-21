/*
���: ������ ������ ����������
������: 271(2)��
����: 5.12.2013
������: ������� �����
����� ����������: Microsoft Visual Studio 2010
*/

#include <iostream> //����������� ����������� ���������
#include <Windows.h>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std; //����������� ������������ ����

class LargeNumbers {

	public:	
		//����������� � �����������
		LargeNumbers(string num, int rad) {
			number = num;
			radix = rad;
			N = getN();
			a = new int[N];
			input();
		}

		//����������� ��� ����������
		LargeNumbers() {
			number = "0";
			radix = 10;
			N = 0;
			a = new int[2];
			a[0] = 1;
			a[1] = 0;
		}
		
		//������� ������ �������
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

		//���������� �����-������
		int* getNumber() {
			return a;
		}

		//���������� ��������� ������� ���������
		int getRadix() {
			return radix;
		}

		//������ ����� ����� ������
		void setNumber(string num) {
			number = num;
			input();
		}

		//������ ����� ����� ������
		void setNumber(int* c) {
			a = c;
		}

		//���������� ��������� ������� ��������� �����
		void setRadix(int rad) {
			radix = rad;
		}

		//���� �� �������
		void consoleInput() {
			cout<<"������� �����:"<<endl;
			cin>>number;
			cout<<"�������  ��������� ������� ���������:"<<endl;
			cin>>radix;
			int rad = radix;
			N = getN();
			a = new int[N];
			input();
		}

		//���� �� �����
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

		//����� � �������
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

		//����� � ����
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

		//������������ �� ������ - �����-�������
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

		//�������� �����
		void nullNumber() {
			number = "0";
			radix = 10;
			N = 0;
			delete [] a;
			a = new int[2];
			a[0] = 1;
			a[1] = 0;
		}
		
		//this + b : ���������� ������ ������
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
					c[i + 1] = c[i + 1] + (c[i] + b[i]) / radix; // ������� � ������� �������
					c[i] = (c[i] + b[i]) % radix; // ������� �������
				} 
			} else {
				for (int i = 1; i <= k; i ++) {
					c[i] = b[i];
				}
				for (int i = 1; i <= a[0]; i ++) { 
					c[i + 1] = c[i + 1] + (c[i] + a[i]) / radix; // ������� � ������� �������
					c[i] = (c[i] + a[i]) % radix; // ������� �������
				} 
			}			
			if (c[k + 1] == 0) {
				c[0] = k; 
			} else { // k - ���-�� ����� ������� � � ������ �������� � ������� ������
				c[0] = k + 1;
			}
			LargeNumbers obj = LargeNumbers();
			obj.setNumber(c);
			obj.setRadix(radix);
			return obj;
		}

		//this - b : ���������� ������ ������
		LargeNumbers minusNumber(LargeNumbers object) {
			int* b = object.getNumber();
			int i, temp, carry = 0;
			if (lessThan(object)) {
				cout<<"��������� �������� ������ �� ��������� ������������� �����, ��������� ���������� � ����������� ��� ��������� ����������"<<endl;
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
				// ������ ���������� - �� ������� 
				// �������������� ������� ������� �
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

		//���������� n-��� ����� ���������
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
		string number; //��������� ������������� ����� (������������ ��� ������� ����� �����)
		int radix; //��������� ������� ���������
		int* a; //������ ��� �������� �����
		int N; //��� ���������� ������� ������� 
};

void main() {         
	setlocale(LC_ALL,"Russian"); //����������� ������ (������� ����)
	ifstream in("input11.txt"); 
	int NT; //���������� ������
	in>>NT;
	int radix; //���� ��������� ������� ���������
	in>>radix;
	cout<<"������� �2: ��������� ����� �� �����."<<endl;
	for (int i = 0; i < NT; i ++) {	
		cout<<"���� �"<<i + 1<<endl;
		string one;
		string two;
		in>>one;
		in>>two;
		LargeNumbers oneNumber = LargeNumbers(one, radix);
		LargeNumbers twoNumber = LargeNumbers(two, radix);
		oneNumber.consoleOutput();
		if (oneNumber.notEquals(twoNumber)) {
			if (oneNumber.moreThan(twoNumber)) {
				cout<<" ������ ";
			} else {
				cout<<" ������ ";
			}
		} else {
			cout<<" ����� ";
		}
		twoNumber.consoleOutput();
		cout<<endl;
		delete [] oneNumber.getNumber();
		delete [] twoNumber.getNumber();
	}
	in.close();
	cout<<endl;
	cout<<"������� �3: N-�� ����� ���������."<<endl;
	cout<<"������� ����� N (50 < N < 101):"<<endl;
	int N; //����� �������� ����� ���������
	cin>>N;
	cout<<"N - �� ����� ���������:"<<endl;
	LargeNumbers result = LargeNumbers();
	result = result.fibonacci(N);
	result.consoleOutput(); //����� �����
	delete [] result.getNumber();
	cout<<endl;
	system("pause");
}