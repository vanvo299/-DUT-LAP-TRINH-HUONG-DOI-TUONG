// #include "VectoNC.h"
#include "BT_VECTO_CHUONG4.h"

Vecto_NC::Vecto_NC(unsigned int chieu) 
{
    this->chieu = chieu;
    this->data = new float[chieu];
}

Vecto_NC::Vecto_NC(const Vecto_NC &vecto)
{
    this->chieu = vecto.chieu;

    this->data = new float[chieu];
    for (int i = 0; i < chieu; i++) {
        data[i] = vecto.data[i];
    }
}

Vecto_NC::~Vecto_NC()
{
    delete [] data;
}

Vecto_NC &Vecto_NC::operator+(Vecto_NC &v)
{
    if (this->chieu != v.chieu) {
        cout << "Hai vecto khong cung chieu !\n";
        return *this;
    }
   
    Vecto_NC *t = new Vecto_NC(this->chieu);
    for (int i = 0; i < chieu; i++) {
        t->data[i] = this->data[i] + v.data[i];
    }
    return *t;
    
}

Vecto_NC &Vecto_NC::operator-(Vecto_NC &v)
{
    if (this->chieu != v.chieu) {
        cout << "Hai vecto khong cung chieu\n";
        return *this;
    }
    Vecto_NC *t = new Vecto_NC(this->chieu);
    for (int i = 0; i < chieu; i++) {
        t->data[i] = this->data[i] - v.data[i];
    }
    return *t;
}

float &Vecto_NC::operator*(Vecto_NC &v)
{
    static float res = 0;
    for (int i = 0; i < chieu; i++) {
        res += this->data[i] * v.data[i];
    }
    return res;
}

istream &operator >> (istream &in, Vecto_NC &v)
{
    cout << "Nhap vao chieu cua vecto: ";
    in >> v.chieu;

    v.data = new float[v.chieu];
    cout << "Nhap vao toa do x, y, z: ";
    for (int i = 0; i < v.chieu; i++) {
        in >> v.data[i];
    }
}

ostream &operator << (ostream &out, const Vecto_NC &v)
{
    cout << "Toa do cua vecto la: ";
    for (int i = 0; i < v.chieu; i++) {
        out << v.data[i] << ' ';
    }
    cout << endl;
}

float &Vecto_NC::operator[](unsigned int index)
{
    return data[index];
}

const Vecto_NC &Vecto_NC::operator=(const Vecto_NC &v)
{
    this->chieu = v.chieu;
    data = new float[chieu];
    for (int i = 0; i < chieu; i++) {
        data[i] = v.data[i];
    }
    return *this;
}

