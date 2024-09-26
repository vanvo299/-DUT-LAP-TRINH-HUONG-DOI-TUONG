#include <iostream>
using namespace std;

class nganXep {
private:
    unsigned int maxSize;
    int top;
    int *data;

public: 
    nganXep(int);
    nganXep(const nganXep &);
    ~nganXep();
    void Push(int);
    void Pop();
    int Top();
    int isEmpty();
    int isFull();
};

// hàm dựng
nganXep::nganXep(int maxSize)
{
    this->maxSize = maxSize;
    this->top = -1;
    this->data = new int[maxSize];
}

// hàm dựng sao chép
nganXep::nganXep(const nganXep &p)
{
    this->maxSize = p.maxSize;
    this->top = p.top;
    this->data = new int[p.maxSize];

    for (int i = 0; i < p.top; i++) {
        this->data[i] = p.data[i];
    }
}

// hàm hủy
nganXep::~nganXep()
{
    delete [] data;
}

// Kiểm tra ngăn xếp rỗng
int nganXep::isEmpty()
{
    return this->top == -1;
}

// Kiểm tra ngăn xếp đầy
int nganXep::isFull()
{
    return this->top == this->maxSize - 1;
}

// Đẩy phần tử vào ngăn xếp
void nganXep::Push(int x)
{
    if (isFull()) {
        cout << "The stack is full\n";
    }
    else this->data[++this->top] = x;
}

// Lấy phần tử ra khỏi ngăn xếp
void nganXep::Pop()
{
    if (isEmpty()) {
        cout << "The stack is empty\n";
    }
    else --this->top;
}

// Truy xuất phần tử trên cùng của ngăn xếp
int nganXep::Top()
{
    if (isEmpty()) {
        cout << "The stack is empty\n";
        return -1;
    }
    return this->data[this->top];
}

void chuyenCoSo(nganXep *S, long long soCanChuyen)
{
    int soDu = 0;

    while(soCanChuyen != 0) {
        soDu = soCanChuyen % 16;
        S->Push(soDu);
        soCanChuyen /= 16;
    }
}

void printResult(nganXep *S)
{
    cout << "So sau khi chuyen sang co so 10: ";
    char ds[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while(!S->isEmpty()) {
        int topElement = S->Top();
        cout << ds[topElement];
        S->Pop();
    }
    cout << endl;
}
int main()
{
    nganXep *S = new nganXep(100);
    long long soCanChuyen; 
    cout << "Nhap so can chuyen: ";
    cin >> soCanChuyen;
    chuyenCoSo(S, soCanChuyen);
    printResult(S);
    delete S;
    return 0;
}
