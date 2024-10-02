#ifndef TIENDA_H
#define TIENDA_H
#include<string>
#include "Producto.h"
using namespace std;




class Tienda
{
    public:
        Tienda();
        virtual ~Tienda();
        void ingresar_producto();
        void mostrar_productos();
        void buscar_producto();
        void calcular_porcentaje();
        void buscar_rango_precio();
        void modificar_precio();


    private:
        Producto catalogo[10];
        int cantidad_productos;
        int total_unidades;
};
#else
class Tienda;

#endif // TIENDA_H


