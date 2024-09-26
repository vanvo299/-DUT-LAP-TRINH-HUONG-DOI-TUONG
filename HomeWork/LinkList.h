/*
Bài 2. Cài đặt lớp LinkList là 01 danh sách liên kết (DSLK) gồm con trỏ đầu và cuối danh sách liên kết các số nguyên.
Định nghĩa hàm dựng tạo DSLK rỗng; hàm hủy; hàm dựng sao chếp; hàm thêm 01 phần tử x vào đầu/cuối/sau 01 phần từ; hàm 
xóa 01 phần tử đầu/cuối/sau 01 phần tử; hàm thêm/xóa 01 phần tử có giá trị x trong DSLK; hàm toán tử << để hiển thị DSLK; 
hàm sắp xếp các phần tử trong DSLK theo thứ tự tăng/giảm dần.

*/

#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
using namespace std;

class node {
    public:
        int value;
        node *next;
};

class LinkList {
    private:
        node *begin;
        node *end;
    public:
        LinkList();
        ~LinkList();
        LinkList(const LinkList &);
        
        void addEnd(int x); // Thêm phần tử x vào cuối danh sách
        void addBegin(int x); // Thêm phần tử x vào đầu danh sách
        void addLaterOneElement(int element, int x); // Thêm phần tử x vào sau 1 phần tử

        void deleteEnd(); // Xóa 1 phần tử ở cuối danh sách
        void deleteBegin(); // Xóa phần tử ở đầu danh sách
        void deleteLaterOneElement(int element); // Xóa phần tử sau 1 phần tử 

        void addElementX(int element); // Thêm 1 phần tử có giá trị x trong DSLK
        void deleteElementX(int element); // Xóa 1 phần tử có giá trị x trong DSLK
        
        void sortAscending(); // sắp xếp danh sách tăng dần
        void sortDescending(); // sắp xếp danh sách giảm dần
        
        friend ostream &operator << (ostream &out, const LinkList &);
};
#endif