#include "DATHUC.h"

int main() {
    DATHUC p1, p2;

    cin >> p1;
    cin >> p2;

    DATHUC p3 = p1 + p2;
    cout << p3 << endl;

    float x = 2;
    cout << "Gia tri da thuc p1 tai x = " << x << " la: " << p1(x) << endl;

    return 0;
}
