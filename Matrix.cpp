#include "Matrix.h"

Matrix::Matrix(int n) {
    this->n = n;
    data = new int*[n]; 
    for (int i = 0; i < n; i++) {
        data[i] = new int[n]; 
    }
}

Matrix::Matrix(const Matrix &d) {
    this->n = d.n;
    this->data = new int*[d.n];
    for (int i = 0; i < d.n; i++) {
        this->data[i] = new int[d.n]; 
        for (int j = 0; j < d.n; j++) {
            this->data[i][j] = d.data[i][j]; 
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < n; i++) {
        delete[] data[i]; 
    }
    delete[] data; 
}

Matrix Matrix::operator+(const Matrix &d) {
    if (this->n != d.n) {
        cout << "Hai ma trận không cùng kích thước.\n";
        return *this;
    }
    Matrix res(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res.data[i][j] = this->data[i][j] + d.data[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator-(const Matrix &d) {
    if (this->n != d.n) {
        cout << "Hai ma trận không cùng kích thước.\n";
        return *this;
    }
    Matrix res(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res.data[i][j] = this->data[i][j] - d.data[i][j];
        }
    }
    return res;
}

istream &operator>>(istream &in, Matrix &d) {
    d.data = new int*[d.n]; 
    for (int i = 0; i < d.n; i++) {
        d.data[i] = new int[d.n]; 
    }
    cout << "Nhap vao ma tran: \n";
    for (int i = 0; i < d.n; i++) {
        for (int j = 0; j < d.n; j++) {
            in >> d.data[i][j];
        }
    }
    return in;
}

ostream &operator<<(ostream &out, const Matrix &d) {
    out << "Ma tran la: \n";
    for (int i = 0; i < d.n; i++) {
        for (int j = 0; j < d.n; j++) {
            out << d.data[i][j] << " "; 
        }
        out << endl; 
    }
    return out;
}

int Matrix::operator()(int hang, int cot) {
    return data[hang][cot];
}

Matrix &Matrix::operator=(const Matrix &d) {
    if (this == &d) {
        return *this; 
    }

    for (int i = 0; i < n; i++) {
        delete[] data[i];
    }
    delete[] data;

    this->n = d.n;
    data = new int*[n];
    for (int i = 0; i < n; i++) {
        data[i] = new int[n];
        for (int j = 0; j < n; j++) {
            data[i][j] = d.data[i][j]; 
        }
    }

    return *this; 
}

Matrix Matrix::operator*(const Matrix &d) {
    if (this->n != d.n) {
        cout << "Hai ma trận không cùng kích thước.\n";
        return *this;
    }

    Matrix res(this->n); 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res.data[i][j] = 0;
            for (int k = 0; k < n; k++) {
                res.data[i][j] += this->data[i][k] * d.data[k][j];
            }
        }
    }
    return res;
}
