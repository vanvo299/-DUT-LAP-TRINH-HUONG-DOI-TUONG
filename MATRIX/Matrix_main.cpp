#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    int size;

    cout << "Nhap cap ma tran thu nhat: ";
    cin >> size;
    Matrix A(size);
    cout << "Nhap ma tran A:" << endl;
    cin >> A;

    cout << "Nhap cap cua ma tran thu hai: ";
    cin >> size;
    Matrix B(size);
    cout << "Nhap ma tran B:" << endl;
    cin >> B;

    // Phép cộng
    Matrix C = A + B;
    cout << "Ma tran A + B:" << endl;
    cout << C;

    // Phép trừ
    Matrix D = A - B;
    cout << "Ma tran A - B:" << endl;
    cout << D;

    // Phép nhân
    Matrix E = A * B;
    cout << "Ma tran A * B:" << endl;
    cout << E;

    int pos = A(0, 2);
    cout << pos << endl;
    return 0;
}
