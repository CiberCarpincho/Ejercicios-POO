#include <iostream>
#include "Tienda.h"
#include "Producto.h"


using namespace std;

int main()
{
    int opc = 0;
    string aux="";
    Tienda mitienda;

    do
    {
        cout << "1. Ingresar producto a la tienda" << endl;
        cout << "2. Mostrar los productos de la tienda" << endl;
        cout << "3. Buscar producto por nombre" << endl;
        cout << "4. Calcular porcentajes de stock " << endl;
        cout << "5. Buscar los productos de un rango de precios" << endl;
        cout << "6. Modificar el precio de un producto" << endl;
        cout << "7. Salir" << endl;
        cout<<"---------------------------------------------------------------"<<endl;

        cout<<"digite una opcion"<<endl;
        getline(cin,aux);
        opc=stoi(aux);
        switch(opc)
        {
            case 1:
                mitienda.ingresar_producto();
                break;
            case 2:
                mitienda.mostrar_productos();
                break;
            case 3:
                mitienda.buscar_producto();
                break;
            case 4:
                mitienda.calcular_porcentaje();
                break;
            case 5:
                mitienda.buscar_rango_precio();
                break;
            case 6:
                mitienda.modificar_precio();
                break;
            case 7:
                cout << "Hasta luego, pirinola" << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
        cout<<"---------------------------------------------------------------"<<endl;
    } while(opc != 7);

    return 0;
}
