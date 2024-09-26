#include "Vector.h"
#include <iostream>
using namespace std;

int main()
{
    Vector *vt1 = new Vector();
    vt1->Nhap();
    vt1->Xuat();
    cout << "Distance is: " << vt1->distance() << endl;
    vt1->countObject();
    return 0;
}