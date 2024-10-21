#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

class Matrix {
    private:
        int n;
        int **data;
    public:
        Matrix(int n);
        Matrix(const Matrix &);
        ~Matrix();
        Matrix operator+(const Matrix &d);
        Matrix operator-(const Matrix &d);
        Matrix operator*(const Matrix &d);
        friend istream &operator >> (istream &in, Matrix &d);
        friend ostream &operator << (ostream &out, const Matrix &d);
        int operator () (int hang, int cot);
        Matrix &operator = (const Matrix &d);

};
#endif