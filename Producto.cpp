#include "Producto.h"
using namespace std;


Producto::Producto()
{
    nombre="";
    precio=0;
    cantidad=0;
}

Producto::~Producto()
{
    //dtor
}

Producto::Producto(string _nombre, double _precio, int _cantidad)
{
    nombre=_nombre;
    precio=_precio;
    cantidad=_cantidad;

}
string Producto::get_nombre()
{
    return nombre;
}

void Producto::set_cantidad(int _cantidad)
{
    cantidad= _cantidad;
    cout<<"la cantidad del producto se ha modificado"<<endl;
}

double Producto::get_precio()
{
    return precio;
}
int Producto::get_cantidad()
{
    return cantidad;
}
void Producto::set_precio(double nuevop)
{
    precio=nuevop;
    cout<<"el precio del producto se ha modificado a"<<precio<<"."<<endl;
}
