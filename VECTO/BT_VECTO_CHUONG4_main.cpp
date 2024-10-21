// #include "VectoNC.h"
#include "BT_VECTO_CHUONG4.h"

int main()
{
    // Khởi tạo vector động
    Vecto_NC *vt1 = new Vecto_NC;
    cin >> *vt1;

    Vecto_NC *vt2 = new Vecto_NC;
    cin >> *vt2;

    // Cộng hai vector
    cout << *vt1 + *vt2; // Cộng
    cout << *vt1 - *vt2; // Trừ
    cout << "Tich cua hai vecto 1 va vecto 2 la: " << *vt1 * *vt2 << endl; // Tích vô hướng
     
    Vecto_NC *tmp = new Vecto_NC;
    tmp = vt1; // Gán
    cout << *tmp; 
    // Giải phóng bộ nhớ
    delete vt1;
    delete vt2;
    delete tmp;

    return 0;
}
