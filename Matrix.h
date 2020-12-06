#pragma once
#define MATRIX_H
#include <iostream>
using namespace std;


class Matrix {
private:
	float* matrix = NULL;
	int* count_matrix = NULL;
	float* matrix_c = NULL;//this is no use here. it is used to speed up SSE, however, i don't realize it this time.
	int* count_matrix_c = NULL;//this is the same with above
	int column = 0;
	int row = 0;
public:
	Matrix* Build_Matrix(int row, int col, std::istream& in);
	Matrix Matrix_Multiplication(const Matrix& a, const Matrix& b);
	Matrix clone(Matrix m);
	void Build_Matrix_c(Matrix* A);
	void Print_Matrix(Matrix* a);
	inline int Getrow() const;
	inline int Getcolumn() const;
	inline float* Getmatrix() const;
	int Getcount_matrix();
	Matrix operator=(const Matrix& m);
	Matrix operator+(const Matrix& m);
	Matrix operator-(const Matrix& m);
	Matrix operator*(const Matrix& m);
	bool operator==(const Matrix& m);
	float* operator[](int i);
	friend std::ostream& operator<<(std::ostream& os,const Matrix& a);
	friend Matrix operator-(const Matrix& a);
	friend Matrix operator*(const Matrix& m, float a);
	friend Matrix operator*(float a, const Matrix& m);
	friend istream& operator>>(istream& in, Matrix& a);

	Matrix();
	Matrix(const Matrix& m);
	Matrix(int r, int col); 
	Matrix(int r, int col, float f[]);
	Matrix(int r, int col, std::istream& in);

	~Matrix();
};

