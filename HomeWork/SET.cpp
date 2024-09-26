#include "SET.h"


set::set(int n)
{
    this->n = 0;
    this->size = max_size;
    this->data = new int[size];
}

set::~set()
{
    delete [] data;
}

set::set(const set &s)
{
    this->n = s.n;
    this->size = s.size;
    this->data = new int[s.size];
    for (int i = 0; i < s.n; i++) {
        this->data[i] = s.data[i];
    }
}

set::set(int soNguyen[], int size)
{
    this->n = size;
    this->size = max_size;
    this->data = new int[this->size];
    for (int i = 0; i < this->size; i++) {
        this->data[i] = soNguyen[i];
    }
}

// set set::operator+(int x)
// {
//     if (this->n == this->size) {
//         cout << "Mang da het cho. \n";
//         return *this; 
//     }
//     set res(*this);
//     res.data[res.n++] = x;
//     return res;
// }

set set::operator+(int x) {
    if (this->n == this->size) {
        cout << "Mang da het cho. \n";
        return *this; 
    }

    // Tạo đối tượng mới để lưu kết quả sau khi thêm phần tử x vào
    set res; 
    res.n = this->n;
    res.size = this->size;
    res.data = new int[res.size];

    for (int i = 0; i < this->n; i++) {
        res.data[i] = this->data[i];
    }

    res.data[res.n++] = x;
    return res; 
}

set set::operator-(int x)
{
    int pos = -1;
    for (int i = 0; i < this->n; i++) {
        if (this->data[i] == x) {
            pos = i; 
            break; 
        }
    }
    if (pos == -1) {
        cout << "Khong tim thay " << x << " trong mang. \n";
        return *this;
    } else {
        for (int i = pos; i < n - 1; i++) {
            this->data[i] = this->data[i + 1]; 
        }
        n--; 
    }
    return *this; 
}
ostream &operator << (ostream &out, const set &s)
{
    for (int i = 0; i < s.n; i++) {
        out << s.data[i] << ' ';
    }
    out << endl;
    return out;
}

set &set::operator = (const set &s)
{
    if (this == &s) {
        return *this;
    }

    delete [] this->data;

    this->n = s.n;
    this->size = s.size;
    this->data = new int[s.n];

    for (int i = 0; i < s.n; i++) {
        this->data[i] = s.data[i];
    }
    return *this;
}

// Hợp của 2 tập
/*
- Hợp của hai tập (còn gọi là phép hợp) là một khái niệm trong lý thuyết tập hợp, 
thể hiện tập hợp tất cả các phần tử thuộc ít nhất một trong hai tập.

Ví dụ:
Nếu A={1,2,3} và B={3,4,5},  thì hợp của A và 𝐵 sẽ là: A∪B={1,2,3,4,5}

*/

set set::operator+(set &other)
{
    int danhDau[1005] = {0};
    set res; // Đối tượng set kết quả

    for (int i = 0; i < this->n; i++) {
        res.data[res.n++] = this->data[i]; // Thêm phần tử của mảng hiện tại vào kết quả
        danhDau[this->data[i]] = 1; // Đánh dấu các phần tử đã xuất hiện trong kết quả
    }

    for (int i = 0; i < other.n; i++) {
        if (danhDau[other.data[i]] == 0) {
            // Kiểm tra phần tử đã có trong mảng đánh dấu chưa
            res.data[res.n++] = other.data[i]; // chưa có thì thêm vào
            danhDau[other.data[i]] = 1; // Đánh dấu đã xuất hiện
        } 
    }
    return res;
}

/*
- Hiệu của hai tập hợp là tập hợp chứa các phần tử chỉ có trong tập hợp đầu tiên nhưng không
có trong tập hợp thứ hai. Ký hiệu của hiệu hai tập hợp A và B thường là A−B hoặc A∖B.

- Ví dụ: 
Tập hợp A = {1, 2, 3, 4, 5}
Tập hợp B = {3, 4, 6}
=> Hiệu của A và B là: A - B = {1, 2, 5}
*/
set set::operator-(set &other)
{
    int danhDau[1005] = {0};
    set res; 

    for (int i = 0; i < other.n; i++) {
        danhDau[other.data[i]] = 1;
    }

    for (int i = 0; i < this->n; i++) {
        if (danhDau[this->data[i]] == 0) {
            res.data[res.n++] = this->data[i];
        }
    }
    return res;
}

// Giao của 2 tập hợp
set set::operator*(set &other)
{
    int danhDau[1005] = {0};
    set res;

    for (int i = 0; i < this->n; i++) {
        danhDau[this->data[i]] = 1; 
    }

    for (int i = 0; i < other.n; i++) {
        if (danhDau[other.data[i]]) {
            // Kiểm tra trong mảng A có phần tử đang xét hay chưa.
            res.data[res.n++] = other.data[i]; // Nếu có thì thêm vào mảng kết quả
        }
    }
    return res;
}

// Toan tu []
int set::operator[] (unsigned int x)
{
    if (this->n == 0) {
        cout << "Array empty. \n";
    }
    return this->data[x];
}

// Toan tu ()
bool set::operator() (int x)
{
    for (int i = 0; i < this->n; i++){
        if (this->data[i] == x) {
            cout << x << " nam o vi tri thu " << i + 1 << " trong mang. \n";
            return true;
        }
    }
    cout << x << " khong nam trong mang. \n";
    return false;
}