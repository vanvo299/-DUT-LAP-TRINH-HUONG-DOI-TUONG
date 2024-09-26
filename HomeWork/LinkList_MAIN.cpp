#include "LinkList.h"

int main()
{
    LinkList p1;
    p1.addEnd(1);
    p1.addEnd(2);
    p1.addEnd(3);
    p1.addEnd(17);
    p1.addEnd(12);
    p1.addEnd(21);
    
    cout << "Danh sach sau khi them cac phan tu vao cuoi danh sach:: ";
    cout << p1;

    p1.addBegin(10);
    p1.addBegin(14);
    p1.addBegin(32);
    p1.addBegin(29);
    cout << "Danh sach sau khi them phan tu vao dau danh sach: ";
    cout << p1;

    p1.addLaterOneElement(1, 9);
    p1.addLaterOneElement(3, 7);
    cout << "Danh sach sau khi them phan tu 9 va 7 lan luot vao sau gia tri 1 va 3: ";
    cout << p1;


    p1.deleteEnd();
    cout << "Danh sach sau khi xoa phan tu cuoi: ";
    cout << p1;
    p1.deleteBegin();
    cout << "Danh sach sau khi xoa phan tu dau: ";
    cout << p1;
    p1.deleteLaterOneElement(9);
    cout << "Danh sach sau khi xoa phan tu sau phan tu co gia tri 9: ";
    cout << p1;

    p1.sortAscending();
    cout << "Danh sach sau khi sap xep tang dan: ";
    cout << p1;
    p1.sortDescending();
    cout << "Danh sach sau khi sap xep giam dan: ";
    cout << p1;
    
    p1.addElementX(14);
    cout << "Danh sach sau khi them phan tu co gia tri x trong DLSK: ";
    cout << p1;

    p1.deleteElementX(9);
    cout << "Danh sach sau khi xoa phan tu co gia tri x trong DSLK: ";
    cout << p1;
    return 0;
}