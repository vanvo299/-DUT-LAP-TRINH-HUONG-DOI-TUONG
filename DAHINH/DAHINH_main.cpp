#include "DAHINH.h"

int main()
{
    Shape *shape[100];
    int n = 0;
    double tongDienTich = 0.0;
    do {
        char choice;
        cout << "Dua ra lua chon cua ban (S/C/T): ";
        cin >> choice;
        choice = toupper(choice);

        if (choice == 'S') {
            // hinh vuong
            shape[n] = new square;
        }
        else if (choice == 'C') {
            // hinh tron
            shape[n] = new Circle;
        }
        else if (choice == 'T') {
            // hinh tam giac deu
            shape[n] = new tamGiacDeu;
        } else break;
        shape[n++]->Nhap();
    } while (n < 100);

    for (int i = 0; i < n; i++) {
        shape[i]->Xuat();
        tongDienTich += shape[i]->dienTich();
    }
    cout << "Tong dien tich cua cac manh dat la: " << tongDienTich << endl;
    return 0;
}