#include "DATHUC.h"
#include <cmath>

using namespace std;

DATHUC::DATHUC(int bac) {
    this->bac = bac;
    this->data = new float[bac + 1];
}

DATHUC::~DATHUC() {
    delete[] data;
}

DATHUC::DATHUC(const float heso[], int size) {
    this->bac = size - 1;
    this->data = new float[size];
    for (int i = 0; i < size; i++) {
        this->data[i] = heso[i];
    }
}

DATHUC::DATHUC(const DATHUC &d) {
    this->bac = d.bac;
    this->data = new float[bac + 1];
    for (int i = 0; i <= bac; i++) {
        this->data[i] = d.data[i];
    }
}

// Toán tử cộng
DATHUC DATHUC::operator + (const DATHUC &d) {
    int max_bac = max(this->bac, d.bac);
    DATHUC t(max_bac);
    for (int i = 0; i <= max_bac; i++) {
        float a = (i <= this->bac) ? this->data[i] : 0;
        float b = (i <= d.bac) ? d.data[i] : 0;
        t.data[i] = a + b;
    }
    return t;
}

// Toán tử trừ
DATHUC DATHUC::operator - (const DATHUC &d) {
    int max_bac = max(this->bac, d.bac);
    DATHUC t(max_bac);
    for (int i = 0; i <= max_bac; i++) {
        float a = (i <= this->bac) ? this->data[i] : 0;
        float b = (i <= d.bac) ? d.data[i] : 0;
        t.data[i] = a - b;
    }
    return t;
}

// Toán tử nhập >>
istream &operator >> (istream &in, DATHUC &d) {
    cout << "Nhap vao bac cua da thuc: ";
    in >> d.bac;
    delete[] d.data; // Giải phóng bộ nhớ trước khi cấp phát lại
    d.data = new float[d.bac + 1];
    cout << "Nhap vao he so cua da thuc: ";
    for (int i = 0; i <= d.bac; i++) {
        in >> d.data[i];
    }
    return in;
}

// Toán tử xuất <<
ostream &operator << (ostream &out, const DATHUC &d) {
    out << "Da thuc la: ";
    for (int i = d.bac; i >= 0; i--) {
        out << d.data[i] << "x^" << i;
        if (i > 0) {
            out << " + ";
        }
    }
    return out;
}

// Toán tử () tính giá trị tại điểm x
float DATHUC::operator () (float x) {
    float result = 0;
    for (int i = 0; i <= bac; i++) {
        result += data[i] * pow(x, i);
    }
    return result;
}

// Toán tử [] truy cập hệ số tại bậc index
float &DATHUC::operator [] (unsigned int index) {
    if (index > bac) {
        throw out_of_range("Index out of range");
    }
    return data[index];
}
