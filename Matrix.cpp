#include"Matrix.h"
#include <iostream>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;

int check_int(string s) {
	int ans = 0;
	if (s[0] == '-' || s[0] == '0') {
		cout << "your input is illegal or nonpositive" << endl;
		exit(0);
	}
	for (int i = 0; i < s.length(); i++) {
		if (isdigit(s[i])) {
			ans = ans * 10 + s[i] - '0';
		}
		else {
			cout << "your input is illegal, this must be integer" << endl;
			exit(0);
		}
	}
	return ans;
}

float check_float(string s) {
	float ans = 0;
	int i = 0;
	int neg = 1;
	if (s[i] == '-') {
		neg = -1;
		i++;
	}
	if (s[i] == '0' && s[i + 1] != '.') {
		cout << "0 can not be initial number like you've printed" << endl;
		exit(0);
	}
	for (; i < s.length(); i++) {
		if (isdigit(s[i])) {
			ans = ans * 10 + s[i] - '0';
		}
		else if (s[i] == '.') {
			if (i == s.length() - 1) {
				cout << "numbers are missing after '.'" << endl;
				exit(0);
			}
			else {
				i++;
				break;
			}
		}
		else {
			cout << "this is not a float" << endl;
			exit(0);
		}
	}
	int j = i - 1;
	for (; i < s.length(); i++) {
		if (isdigit(s[i])) {
			ans += (s[i] - '0') / (float)pow(10, j);
			j++;
		}
		else {
			cout << "this is not a float" << endl;
			exit(0);
		}
	}
	return neg * ans;
}

Matrix* Matrix::Build_Matrix(int row, int col, istream& in)
{
	Matrix* temp = new Matrix;
	temp->column = col;
	temp->row = row;
	temp->matrix = new float[col * row];
	this->count_matrix = (int*)malloc(sizeof(int));
	(*this->count_matrix) = 1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			string s;
			in >> s;
			temp->matrix[i * col + j] = check_float(s);
		}
	}
	return temp;
}

void Matrix::Build_Matrix_c(Matrix* A)
{
	A->matrix_c = new float[A->column * A->row];
	for (int i = 0; i < A->column * A->row; i++) {
		A->matrix_c[i / A->row + i % A->row * A->column] = A->matrix[i];
	}
}

void Matrix::Print_Matrix(Matrix* a)
{
	for (int i = 0; i < a->row; i++) {
		for (int j = 0; j < a->column; j++) {
			cout << a->matrix[i * a->column + j] << " ";
		}
		cout << endl;
	}
	return;
}

Matrix Matrix::Matrix_Multiplication(const Matrix& a, const Matrix& b)
{
	if (a.column != b.row) {
		cout << "Their column and row do not match." << endl;
		exit(0);
	}
	Matrix temp(a.row, b.column);
	memset(temp.matrix, 0, temp.column * temp.row * sizeof(float));
	for (int i = 0; i < temp.row; i++) {
		for (int j = 0; j < temp.column; j++) {
			int flag = 0;
			while (flag < a.column) {
				temp.matrix[i * temp.column + j] += a.matrix[i * a.column + flag] * b.matrix[j + flag * b.column];
				flag++;
			}
		}
	}
	return temp;
}

Matrix Matrix::clone(Matrix m)
{
	Matrix temp(m.row, m.column);
	cout << "adress: " << &temp << " is a clone of adress" << &m << endl;
	for (int i = 0; i < m.row * m.column; i++) {
		temp.matrix[i] = m.matrix[i];
	}
	return temp;
}

int Matrix::Getrow() const
{
	return this->row;
}

int Matrix::Getcolumn() const
{
	return this->column;
}

float* Matrix::Getmatrix() const
{
	return this->matrix;
}

int Matrix::Getcount_matrix()
{
	return 1;
}

Matrix Matrix::operator=(const Matrix& m)
{
	cout << "operation = is been used" << endl;
	this->row = m.row;
	this->column = m.column;
	this->matrix = m.matrix;
	this->count_matrix = m.count_matrix;
	(*this->count_matrix)++;
	return *this;
}

//Matrix Matrix::operator=(const Matrix& m)
//{
//	cout << "operation = is been used" << endl;
//	Matrix temp(m.row, m.column);
//	//cout << "temp for operator = adress" << &temp << " is built without default" << endl;
//	temp.matrix = m.matrix;
//	temp.count_matrix = m.count_matrix;
//	(*temp.count_matrix)++;
//	return temp;
//}

Matrix Matrix::operator+(const Matrix& m)
{
	if (m.column != this->column || m.row!=this->row) {
		cout << "these two matrix can not be added together: size error" << endl;
		exit(1);
	}
	Matrix temp(m.row, m.column);
	for (int i = 0; i < m.column * m.row; i++) {
		temp.matrix[i] = m.matrix[i] + this->matrix[i];
	}
	return temp;
}

Matrix Matrix::operator-(const Matrix& m)
{
	return *this + (-m);
}

Matrix Matrix::operator*(const Matrix& m)
{
	return Matrix_Multiplication(*this,m);
}

bool Matrix::operator==(const Matrix& m)
{
	if (this->column != m.column || this->row != m.row)return false;
	if (&this->matrix == &m.matrix)return true;
	for (int i = 0; i < m.column * m.row; i++) {
		if (this->matrix[i] != m.matrix[i])return false;
	}
	return true;
}

float* Matrix::operator[](int i)
{
	return &(this->matrix[column * i]);
}

Matrix::Matrix()
{
	cout << "adress: " << this << "  is built\nthere is nothing!" << endl;

}

Matrix::Matrix(const Matrix& m)
{
	cout << "adress" << this << " is built with default matrix " << &m << endl;
	this->column = m.column;
	this->row = m.row;
	this->matrix = m.matrix;
	this->count_matrix = m.count_matrix;
	(*this->count_matrix)++;
}

Matrix::Matrix(int r, int col) {
	cout << "adress: " << this << "  is built" << endl;
	this->column = col;
	this->row = r;
	this->matrix = new float[r * col];
	this->count_matrix = (int*)malloc(sizeof(int));
	(*this->count_matrix) = 1;
	//memset(matrix, 0, (r * col + 1) * sizeof(float));
}

Matrix::Matrix(int r, int col, float f[])
{
	cout << "adress: " << this << "  is built" << endl;
	this->column = col;
	this->row = r;
	this->matrix = new float[r * col];
	this->count_matrix = (int*)malloc(sizeof(int));
	(*this->count_matrix) = 1;
	//cout << "sizeof(f)"<<sizeof(f) << endl;
	for (int i = 0; i < r * col; i++) {
		this->matrix[i] = f[i];
	}
}

Matrix::Matrix(int r, int col, istream& in)
{
	this->column = col;
	this->row = r;
	this->matrix = new float[col * r];
	this->count_matrix = (int*)malloc(sizeof(int));
	(*this->count_matrix) = 1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			string s;
			in >> s;
			this->matrix[i * col + j] = check_float(s);
		}
	}
}

Matrix::~Matrix()
{
	cout << "adress: " << this << "  ";
	cout << "matrix destroy   ";
	cout << "count_matrix: " << *count_matrix << endl;
	if (matrix != NULL) {
		if (*count_matrix == 1) {
			delete[] matrix;
			delete count_matrix;
		}
		else if (*count_matrix > 1) {
			(*count_matrix)--;
		}
	}
	//these following code are usless because i didn't use matrix_c
	if (matrix_c != NULL) {
		if (*count_matrix_c == 1) {
			delete[] matrix_c;
			delete count_matrix_c;
		}
		else if (*count_matrix_c > 1) {
			(*count_matrix_c)--;
		}
	}
}

ostream& operator<<(ostream& os,const Matrix& a)
{
	cout << "put matrix adress: " << &a << " into ostream" << endl;
	int r = a.Getrow();
	int c = a.Getcolumn();
	float* m = a.Getmatrix();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			os << m[i * c + j] << " ";
		}
		os << endl;
	}
	return os;
}

Matrix operator-(const Matrix& a)
{
	int r = a.Getrow();
	Matrix temp(a.row, a.column);
	for (int i = 0; i < a.column * a.row; i++) {
		temp.matrix[i] = -a.matrix[i];
	}
	return temp;
}

Matrix operator*(const Matrix& m, float a)
{
	Matrix temp(m.row, m.column);
	for (int i = 0; i < m.row * m.column; i++) {
		temp.matrix[i] = m.matrix[i] * a;
	}
	return temp;
}

Matrix operator*(float a, const Matrix& m)
{
	Matrix temp(m.row, m.column);
	for (int i = 0; i < m.row * m.column; i++) {
		temp.matrix[i] = m.matrix[i] * a;
	}
	return temp;
}

istream& operator>>(istream& in, Matrix& a)
{
	cout << "please enter the row and column of the matrix" << endl;
	int r, c;
	cin >> r;
	cin >> c;
	a = Matrix(r, c);
	float* matrix = a.Getmatrix();
	cout << "please enter the element of the matrix" << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			string s;
			in >> s;
			matrix[i * c + j] = check_float(s);
		}
	}
	return in;
}
