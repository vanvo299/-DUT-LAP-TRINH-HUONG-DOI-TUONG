#include "Vector.h"
#include <iostream>
#include <cmath>
using namespace std;

int Vector::count = 0;

Vector::Vector(float x, float y, float z) : x(x), y(y), z(z) {
    count++;
};

void Vector::Nhap()
{
    cout << "Nhap x, y, z: ";
    cin >> x >> y >> z; 
}

void Vector::Xuat()
{
    cout << "x, y, z lan luot la: ";
    cout << x << ' ' << y << ' ' << z << endl;
}

float Vector::distance() const
{
    return (float)sqrt(x*x + y*y + z*z);
}

void Vector::countObject()
{
    cout << "So doi tuong thuoc lop Vector3D la: " << count << endl;
}