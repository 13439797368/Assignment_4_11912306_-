#include<iostream>
#include"Matrix.h"
using namespace std;

int main() {
	//--------------------test the construction Matrix(int row, int column, float f[]), operator = , operator << , operator + -----------------
	//int r, c;
	//r = 2;
	//c = 3;
	//float f[] = { 1,2,3,1,2,3 };
	//Matrix m(r, c, f);
	//cout << "Getcount_matrix() of m: "<<m.Getcount_matrix() << endl;
	//Matrix t(r, c, f);
	//cout << "Getcount_matrix() of f: " << m.Getcount_matrix() << endl;
	//cout << "m and t is: "<<endl;
	//cout << m << t;
	//Matrix p;
	//cout << "p = m + t , p is " << endl;
	//p = m + t;
	//cout << p;
	//--------------------------------------------------------------------------------------

	//----------------------test the construction Matrix(int row, int column, istream in) operatior *-----------------------------------
	//int r, c;
	//cout << "please enter the row and column of the first matrix" << endl;
	//cin >> r;
	//cin >> c;
	//cout << "please enter the first matrix"<<endl;
	//Matrix m(r, c, cin);
	//cout << "please enter the row and column of the second matrix" << endl;
	//cin >> r;
	//cin >> c;
	//cout << "please enter the second matrix" << endl;
	//Matrix t(r, c, cin);
	//cout << "m and t is: "<<endl;
	//cout << m << t;
	//Matrix p;
	//cout << "p = m * t ,p is: " << endl;
	//p = m * t;
	//cout << p;
	//----------------------------------------------------------------------------------------------------------------------------------

	//-----------------------test the operator - , operator [] (use [][] to get the element in a certain position of a matrix) , operator == --------------------------------------------------------------------------
	/*int r, c;
	r = 2;
	c = 3;
	float f1[] = { 1,2,3,1,2,3 };
	float f2[] = { 5,5,5,6,6,6 };
	float f3[] = { -4,-3,-2,-5,-4,-3 };
	Matrix m(r, c, f1);
	Matrix t(r, c, f2);
	cout << "m and t is: " << endl;
	cout << m << t;
	Matrix p;
	p = m - t;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "the element in the " << i << "th row and " << j << "th column is:  " << p[i][j] << endl;
		}
	}
	cout << p << endl;
	Matrix q = m - t;
	cout << "p = m - t\nq = m - t\np is equal to q: " << (p == q) << endl;
	q = p;
	cout << "p = m - t\nq = p\np is equal to q: " << (p == q) << endl;
	q = m + p;
	cout << "p = m - t\nq = m + t\np is equal to q: " << (p == q) << endl;
	q = Matrix(r, c, f3);
	cout << "p = m - t\nq = { -4,-3,-2;-5,-4,-3 }\np is equal to q: " << (p == q) << endl;*/
	//-------------------------------------------------------------------------------------------------------

	//---------------------test operator >> and operator <<----------------------------
	//Matrix a,b;
	//cin >> a >>b;
	//cout << a << b;
	//-------------------------------------

	//----------------test operator * ------------------------
	int r, c;
	cout << "please enter the row and column of the first matrix" << endl;
	cin >> r;
	cin >> c;
	cout << "please enter the first matrix"<<endl;
	Matrix m(r, c, cin);
	cout << "please enter the row and column of the second matrix" << endl;
	cin >> r;
	cin >> c;
	cout << "please enter the second matrix" << endl;
	Matrix t(r, c, cin);
	cout << "m and t is: "<<endl;
	cout << m << t << endl;
	Matrix p;
	cout << "p = m * t ,p is: " << endl;
	p = m * t;
	cout << p << endl;
	cout << "please enter a constent a" << endl;
	int a;
	cin >> a;
	cout << "p = a * m ,p is: " << endl;
	cout << (p * a) << endl;
	cout << "p = m * a ,p is: " << endl;
	cout << (a * p) << endl;
	return 0;
}