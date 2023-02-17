#include <iostream>
#include "Matr.h"
#include <fstream>


using namespace std;


void printInFile(string file_name, int** matr1, int size1, int sled)
{
	ofstream f(file_name);
	if (file_name == "")  throw std::invalid_argument("File's name error"); /// Если файл без имени
	if (!f.is_open()) throw std::invalid_argument("File isn't open!"); /// Если файл не открыт
	f << "Изначальная матрица: " << endl;
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size1; j++)
		{
			f << matr1[i][j] << " ";
		}
		f << endl;
	}
	f << "След матрицы = " << sled;
	f << endl;
	f << "Транспонированная матрица: " << endl;
	
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size1; j++)
		{
			f << matr1[j][i] << " ";
		}
		f << endl;
	}
	f.close();
}


int main()
{	
	setlocale(LC_ALL, "Russian");
	try {
		Matrix m1;
		Matrix m2;
		
		int Msize = 0; /// Объявлять переменную?
		cout << "Введите размер матрицы = ";
		cin >> Msize;
		m1.set_size(Msize);
		int** Matrix1 = m1.create_matrix(Msize);
		cout << "Введите элементы матрицы: " << endl;
		m1.set_matr(Matrix1, Msize);
		m1.print_matrix(Matrix1, Msize);
		int sled = m1.sled_matr(Matrix1, Msize);
		cout << "След матрицы = " << sled << endl;
		cout << "Транспонированная матрицы: " << endl;
		m1.transpose_matr1(Matrix1,Msize);
		cout << endl;
		printInFile("test1.txt", Matrix1, Msize, m1.sled_matr(Matrix1,Msize));
		m1.~Matrix();
		delete[] Matrix1;
		
		/// todo Идея создать трансп. матрицу что бы можно было с ней работать.
		//int** TransMatr = m1.create_matrix(Msize);
		
	}
	catch (invalid_argument e)
	{
		cout << e.what();
	}
}

