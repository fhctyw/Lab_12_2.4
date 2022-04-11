#include <iostream>
#include <Windows.h>
#include "Matrix.h"
using namespace std;

int main()
{
	srand(time(0));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	Matrix m1(2, 2), m2;
	m1.rnd();
	cin >> m2;
	cout << m1 << endl << m2 << endl;

	cout << m1 + m2 << endl;

	m1 = m2;
	cout << (m1 == m2) << endl;

	cout << m1.Norm() << endl;
	
	return 0;
}