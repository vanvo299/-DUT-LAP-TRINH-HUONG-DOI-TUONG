/*
Một công ty Bất động sản cần quản lý các mảnh đất có hình dạng: Hình tròn, Hình vuông, Hình tam giác đều với thông tin kích thước mảnh đất và địa chỉ mảnh đất.
Viết chương trình tổ chức theo hướng đối tượng để tính và in ra chu vi, diện tích của các mảnh đất và tổng diện tích các mảnh đất của công ty quản lý.
*/
#ifndef SHAPE_H
#define SHAPE_H

#include <bits/stdc++.h>
using namespace std;

const float pi = 3.14159265359;

class Shape {
    protected:
        int kichThuoc;
        string diaChi;
    public:
        virtual void Nhap();
        virtual void Xuat();
        virtual int chuVi() = 0;
        virtual float dienTich() = 0;
};

class Circle : public Shape {
    public:
        void Nhap();
        void Xuat();
        int chuVi();
        float dienTich();
};

class square : public Shape {
    public:
        void Nhap();
        void Xuat();
        int chuVi();
        float dienTich();
};

class tamGiacDeu : public Shape {
    public:
        void Nhap();
        void Xuat();
        int chuVi();
        float dienTich();
};

#endif

