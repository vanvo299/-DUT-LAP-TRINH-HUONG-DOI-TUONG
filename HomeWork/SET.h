#ifndef SET_H
#define SET_H

#include <iostream>
using namespace std;

const int max_size = 100;

class set {
    private:    
        int n;
        int *data;
        int size;
    public:
        set(int n = 10);
        ~set();
        set(const set &);
        set(int soNguyen[], int size);
        set operator + (int x);
        set operator - (int x);
        set operator + (set &other);
        set operator - (set &other);
        set operator * (set &other);
        bool operator () (int x);
        int operator [] (unsigned int x);
        set &operator = (const set &s);
        friend ostream &operator << (ostream &out, const set &s);
};
#endif