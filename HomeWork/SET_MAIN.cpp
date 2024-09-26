#include "SET.h"

int main()
{
    cout << endl;
    // Tạo mảng s1 và thêm các phần tử
    int a[] = {2, 3, 5, 1, 8, 10};
    set s1(a, 6);
    
    set ss(6);
    ss = s1;
    cout << "SET sau khi duoc gan cho SET khac: ";
    cout << ss; 

    s1 = s1 + 14;
    s1 = s1 + 15;
    s1 = s1 + 16;
    cout << "SET sau khi them phan tu vao: ";
    cout << s1;

    // Xóa các phần tử khỏi s1
    s1 = s1 - 10;
    s1 = s1 - 14;
    s1 = s1 - 15;
    cout << "SET sau khi xoa di phan tu: ";
    cout << s1;
    
    cout << endl;

    cout << "Phep hop cua 2 tap s2 va s3: \n";
    int b[] = {1, 2, 3};
    int c[] = {3, 4, 5};
    set s2(b, 3), s3(c, 3); 
    cout << s2 << s3;
    cout << "s2 + s3: " << s2 + s3 << endl;

    cout << "Phep hieu cua 2 tap s4 va s5: \n";
    int d[] = {1, 2, 3, 4, 5};
    int e[] = {3, 4, 6};
    set s4(d, 5), s5(e, 3); 
    cout << s4 << s5;
    cout << "s4 - s5: " << s4 - s5 << endl;

    cout << "Phep giao cua 2 tap s6 va s7: \n";
    int f[] = {1, 2, 3, 4};
    int g[] = {3, 4, 5, 6};
    set s6(f, 4), s7(g, 4); 
    cout << s6 << s7;
    cout << "s6 * s7: " << s6 * s7 << endl;



    // Sử dụng toán tử []
    cout << "Phan tu nam o vi tri thu 2 trong set s1 la: " << s1[1] << endl;
    cout << "Phan tu nam o vi tri thu 4 trong set s1 la: " << s1[3] << endl;
    cout << endl;

    // Sử dụng toán tử ()
    bool check = s1(3);
    bool check2 = s1(10);
    cout << endl;
    return 0;
}
