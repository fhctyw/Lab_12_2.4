#pragma once
#include <iostream>
using namespace std;

class Matrix
{
	int** mat;
	int row, col;
public:
	Matrix();
	Matrix(int row, int col);
	Matrix(const Matrix& m);
	~Matrix();
	Matrix& operator=(const Matrix& m);

	int getRow() const { return row; }
	void setRow(int r){ row = r >= 0 ? r : 0; };
	int getCol() const { return col; }
	void setCol(int c){ col = c >= 0 ? c : 0; };
	void rnd();

	operator string() const;
	friend ostream& operator<<(ostream& out, const Matrix& m);
	friend istream& operator>>(istream& in, Matrix& m);
	friend Matrix operator+(const Matrix&, const Matrix&);
	unsigned int Norm() const;

	friend bool operator==(const Matrix& m1, const Matrix& m2);
	int* operator[](int i) { return mat[i]; }
	const int* operator[](int i) const { return mat[i]; }
private:
	Matrix(int** mat, int row, int col);
};

