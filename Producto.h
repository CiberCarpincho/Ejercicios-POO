#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
#include<iostream>
using namespace std;


class Producto
{
    public:
        Producto();
        ~Producto();
        Producto(string, double, int);
        string get_nombre();
        double get_precio();
        int get_cantidad();
        void set_cantidad(int);
        void set_precio(double);


    protected:

    private:
        string nombre;
        double precio;
        int cantidad;
};

#endif // PRODUCTO_H
