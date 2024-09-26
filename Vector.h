#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector {
    private:
        float x, y, z;
        static int count;
    public:
        Vector(float = 0, float = 0, float = 0);
        void Nhap();
        void Xuat();
        float distance() const;
        void countObject();
};

#endif