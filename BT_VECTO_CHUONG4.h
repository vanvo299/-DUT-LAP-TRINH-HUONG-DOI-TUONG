#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>
using namespace std;

class Vecto_NC {
    private:
        unsigned int chieu;
        float *data;
    public:
        Vecto_NC(unsigned int chieu = 1);
        Vecto_NC(const Vecto_NC &);
        ~Vecto_NC();
        Vecto_NC &operator + (Vecto_NC &);
        Vecto_NC &operator - (Vecto_NC &);
        float &operator * (Vecto_NC &);
        const Vecto_NC &operator = (const Vecto_NC &);
        float &operator [] (unsigned int index);
        friend istream &operator >> (istream &in, Vecto_NC &v);
        friend ostream &operator << (ostream &out, const Vecto_NC &v);
};

#endif