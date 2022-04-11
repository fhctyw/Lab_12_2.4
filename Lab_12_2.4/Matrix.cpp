#include "Matrix.h"
#include <sstream>

Matrix::Matrix()
{
    row = 0;
    col = 0;
    mat = nullptr;
}

Matrix::Matrix(int row, int col)
{
    setRow(row);
    setCol(col);

    if (row == 0 || col == 0)
        mat = nullptr;
    else 
    {
        mat = new int* [row];
        for (size_t i = 0; i < row; i++) {
            mat[i] = new int[col];
            for (size_t j = 0; j < col; j++)
                mat[i][j] = 0;
        }
    }
}

Matrix::Matrix(int** mat, int row, int col)
{
    this->row = row;
    this->col = col;
    
    this->mat = new int* [row];
    for (size_t i = 0; i < row; i++) {
        this->mat[i] = new int[col];
        for (size_t j = 0; j < col; j++)
            this->mat[i][j] = mat[i][j];
    }
}

Matrix::Matrix(const Matrix& m)
{
    *this = m;
}

Matrix::~Matrix()
{
    if (mat)
    {
        for (size_t i = 0; i < row; i++)
            delete[] mat[i];
        delete[] mat;
    }
}

Matrix& Matrix::operator=(const Matrix& m)
{
    if (&m == this) return *this;
    if (mat)
    {
        for (size_t i = 0; i < row; i++)
            delete[] mat[i];
        delete[] mat;
    }

    if (!(m.row == 0 || m.col == 0))
    {
        row = m.row;
        col = m.col;

        mat = new int* [row];
        for (size_t i = 0; i < row; i++) {
            mat[i] = new int[col];
            for (size_t j = 0; j < col; j++)
                mat[i][j] = m.mat[i][j];
        }
    }
    else
    {
        row = 0;
        col = 0;
        mat = nullptr;
    }
    return *this;
}

void Matrix::rnd()
{
    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < col; j++)
            mat[i][j] = 1 + rand() % 9;
}

Matrix::operator string() const
{
    stringstream ss;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
            ss << mat[i][j] << (j == col - 1 ? "" : " ");
        ss << endl;
    }
    return ss.str();
}

unsigned int Matrix::Norm() const
{
    int max = mat[0][0], min = mat[0][0];
    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < col; j++)
        {
            if (mat[i][j] > max)
                max = mat[i][j];

            if (mat[i][j] < min)
                min = mat[i][j];
        }

    return abs(max - min);
}

ostream& operator<<(ostream& out, const Matrix& m)
{
    out << (string)m;
    return out;
}

istream& operator>>(istream& in, Matrix& m)
{
    if (m.mat)
    {
        for (size_t i = 0; i < m.row; i++)
            delete[] m.mat[i];
        delete[] m.mat;
    }
    cout << "¬вед≥ть к≥льк≥сть колонк≥в: "; cin >> m.col;
    cout << "¬вед≥ть к≥льк≥сть р€дк≥в: "; cin >> m.row;

    if (!(m.row == 0 || m.col == 0))
    {
        m.mat = new int* [m.row];
        for (size_t i = 0; i < m.row; i++) {
            m.mat[i] = new int[m.col];
            for (size_t j = 0; j < m.col; j++)
            {
                cout << '[' << i << "][" << j << "] = "; cin >> m.mat[i][j];
            }
        }
    }
    else
    {
        m.row = 0;
        m.col = 0;
        m.mat = nullptr;
    }

    return in;
}


Matrix operator+(const Matrix& m1, const Matrix& m2)
{
    if (m1.col == m2.col && m1.row == m2.row)
    {
        Matrix m = m1;
        for (size_t i = 0; i < m1.row; i++)
            for (size_t j = 0; j < m1.col; j++)
                m[i][j] += m2[i][j];
        return Matrix(m.mat, m.row, m.col);
    }
    else
        return Matrix(m1);
}

bool operator==(const Matrix& m1, const Matrix& m2)
{
    if (m1.col == m2.col && m1.row == m2.row)
    {
        for (size_t i = 0; i < m1.row; i++)
            for (size_t j = 0; j < m1.col; j++)
                if (m1[i][j] != m2[i][j])
                    return false;
        return true;
    }
    else
        return false;
}

