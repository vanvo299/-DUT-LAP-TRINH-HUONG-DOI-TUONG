#ifndef DATHUC_H
#define DATHUC_H

#include <iostream>
using namespace std;

class DATHUC {
    private:
        int bac;
        float *data;
    public:
        DATHUC(int bac = 1);
        ~DATHUC();
        DATHUC(const DATHUC &);
        DATHUC(const float heso[], int size);
        DATHUC operator + (const DATHUC &d);
        DATHUC operator - (const DATHUC &d);
        float operator () (float x);
        float &operator [] (unsigned int index);
        friend istream &operator >> (istream &in, DATHUC &d);
        friend ostream &operator << (ostream &out, const DATHUC &d);

};
#endif