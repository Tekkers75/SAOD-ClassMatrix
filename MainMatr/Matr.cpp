///Подключаем заголовочный файл 
#include "Matr.h"
/// Библиотека для ввода и вывода
#include <iostream>
/// Библиотека для форматирования строк
#include <iomanip>
#include <string>


using namespace std;

Matrix::Matrix()
{
	size = 0;
	matr = nullptr;
}

Matrix::Matrix(int size1)
{
	size = size1;
	matr = new int[size];
}

Matrix::~Matrix() 
{
	for (int i = 0; i < size; i++)
	{
		delete[] matr;
	}
}

void Matrix::set_size(int size1)
{
	if (size1 == 0) throw std::invalid_argument("Error size = 0");
	size = size1;
}

int Matrix::get_size() { return size; }

int** Matrix::create_matrix(int size1)
{
	int** matr = new int* [size1];
	for (int i = 0; i < size1; i++)
	{
		matr[i] = new int[size1];
	}
	return matr;
}

void Matrix::set_matr(int** matr1, int size1)
{
	
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size1; j++)
		{
			
			cout << "[" << i << "]" << "[" << j << "] = ";
			cin >> matr1[i][j];
		}
	}
}


void Matrix::print_matrix(int** matr1, int size1)
{
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size1; j++)
		{
			cout << matr1[i][j] << " ";
		}
		cout << endl;
	}
}

int Matrix::sled_matr(int **matr1, int size1)
{
	int sum = 0;
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size1; j++)
		{
			if (i == j)
				sum += matr1[i][j];
		}
	}
	return sum;
}


void Matrix::transpose_matr1(int** matr1,/*int **Transpose,*/ int size1)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) 
		{
			//matr1[j][i];
			cout << matr1[j][i] << " ";
		}
		cout << endl;
	}
}


/// Todo Сделать как то через свой класс?

//Matrix Matrix::transpose_matr(int **matr1,int size1)
//{
//	Matrix trans;
//	trans.create_matrix(size1);
//	//trans.set_matr(Matrix1, Msize);
//	for (int i = 0; i < size1; i++) {
//		for (int j = 0; j < size1; j++) {
//			trans.create_matrix(size1)[j][i] = trans.create_matrix(size1)[i][j];
//			//trans.matr[j * trans.size + i] = matr[i * size+ j];
//			cout << trans.create_matrix(size1)[j][i] << " ";
//		}
//		cout << endl;
//	}
//	return trans;
//}