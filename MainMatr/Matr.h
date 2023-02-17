#pragma once
class Matrix
{
private:
	int size;
	int* matr;

public: 
	Matrix();
	Matrix(int size);
	~Matrix();
	void set_size(int size1);
	int get_size();
	void set_matr(int** matr1, int size1);
	int** create_matrix(int size1);
	void print_matrix(int** matr1, int size1);
	int sled_matr(int** matr1, int size1);
	void transpose_matr1(int** matr1,/* int** Transpose,*/ int size1);



	/*Matrix transpose_matr(int** matr1, int size1);*/
};

