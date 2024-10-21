#include "LinkList.h"
int main()
{
    cout << endl;
    LinkList p1;
    // Thêm phần tử vào cuối danh sách
    p1.addEnd(1);
    p1.addEnd(2);
    p1.addEnd(3);
    p1.addEnd(17);
    p1.addEnd(12);
    p1.addEnd(21);
    
    cout << "Danh sach sau khi them cac phan tu vao cuoi danh sach: ";
    cout << p1;

    // Thêm phần tử vào đầu danh sách
    p1.addBegin(10);
    p1.addBegin(14);
    p1.addBegin(32);
    p1.addBegin(29);
    cout << "Danh sach sau khi them phan tu vao dau danh sach: ";
    cout << p1;

    // Phần tử sau vào sau 1 phần tử
    p1.addLaterOneElement(1, 9);
    p1.addLaterOneElement(3, 7);
    cout << "Danh sach sau khi them phan tu 9 va 7 lan luot vao sau gia tri 1 va 3: ";
    cout << p1;

    // Xóa 1 phần tử ở cuối danh sách
    p1.deleteEnd();
    cout << "Danh sach sau khi xoa phan tu cuoi: ";
    cout << p1;
    // Xóa 1 phần tử ở đầu danh sách
    p1.deleteBegin();
    cout << "Danh sach sau khi xoa phan tu dau: ";
    cout << p1;
    // Xóa 1 phần tử sau 1 phần tử
    p1.deleteLaterOneElement(9);
    cout << "Danh sach sau khi xoa phan tu sau phan tu co gia tri 9: ";
    cout << p1;

    // Sắp xếp danh sách theo chiều tăng dân
    p1.sortAscending();
    cout << "Danh sach sau khi sap xep tang dan: ";
    cout << p1;
    // Sắp xếp danh sách theo chiều giảm dần
    p1.sortDescending();
    cout << "Danh sach sau khi sap xep giam dan: ";
    cout << p1;
    
    // Thêm 1 phần tử có giá trị x trong DSLK
    p1.addElementX(14);
    cout << "Danh sach sau khi them phan tu co gia tri 14 trong DLSK: ";
    cout << p1;

    // Thêm 1 phần tử có giá trị x trong DSLK
    p1.deleteElementX(9);
    cout << "Danh sach sau khi xoa phan tu co gia tri 9 trong DSLK: ";
    cout << p1;

    cout << endl;
    return 0;
}