/*
Một công ty Bất động sản cần quản lý các mảnh đất có hình dạng: Hình tròn, Hình vuông, Hình tam giác đều với thông tin kích thước mảnh đất và địa chỉ mảnh đất.
Viết chương trình tổ chức theo hướng đối tượng để tính và in ra chu vi, diện tích của các mảnh đất và tổng diện tích các mảnh đất của công ty quản lý.
*/

#include "DAHINH.h"

void Shape::Nhap()
{
    cin.ignore();
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);
}

void Shape::Xuat()
{
    cout << "Chu vi: " << chuVi() << endl;
    cout << "Dien tich: " << dienTich() << endl;
    cout << "Dia chi: " << diaChi << endl;
}

void Circle::Nhap()
{
    cout << "Nhap ban kinh: ";
    cin >> kichThuoc;
    Shape::Nhap();
}

void Circle::Xuat()
{
    Shape::Xuat();
}

int Circle::chuVi()
{
    return 2 * pi * kichThuoc;
}

float Circle::dienTich()
{
    return pi*kichThuoc*kichThuoc;
}

void square::Nhap()
{
    cout << "Nhap canh cua hinh vuong: ";
    cin >> kichThuoc;
    Shape::Nhap();
}

void square::Xuat()
{
    Shape::Xuat();
}

int square::chuVi()
{
    return kichThuoc*4;
}

float square::dienTich()
{
    return kichThuoc * kichThuoc;
}

void tamGiacDeu::Nhap()
{
    cout << "Nhap canh cua tam giac deu: ";
    cin >> kichThuoc;
    Shape::Nhap();
}

void tamGiacDeu::Xuat()
{
    Shape::Xuat();
}

int tamGiacDeu::chuVi()
{
    return kichThuoc * 3;
}

float tamGiacDeu::dienTich()
{
    return kichThuoc * kichThuoc * (sqrt(3) / 4);
}
