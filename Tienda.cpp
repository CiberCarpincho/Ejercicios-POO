#include "Tienda.h"
#include <string>
#include <iostream>


using namespace std;

// Función auxiliar para leer una entrada del usuario
string leer(string mensaje)
{
    cout << mensaje << endl;
    string aux = "";
    getline(cin, aux);
    return aux;
}

// Función para convertir una cadena a minúsculas
string minusculiar(string cadena)
{
    for (int i = 0; i < cadena.length(); i++) {
        cadena[i] = tolower(cadena[i]);
    }
    return cadena;
}

// Constructor de Tienda
Tienda::Tienda()
{
    cantidad_productos = 0;
    total_unidades =0;
}

// Destructor de Tienda
Tienda::~Tienda()
{
    // destructor
}
// Método para ingresar un producto
void Tienda::ingresar_producto()
{
    cout << "Has elegido la opción de ingresar un producto." << endl;

    // Leer datos del producto
    string _nombre = leer("Digite el nombre del producto");
    double _valor = stod(leer("Digite el valor del producto"));
    int _cantidad = stoi(leer("Digite la cantidad del producto"));

    // Variable para determinar si el producto es nuevo
    bool es_nuevo = true;

    // Verificar el valor de cantidad_productos antes de proceder
    cout << "Actualmente hay " << cantidad_productos << " productos en el catálogo." << endl;

    // Verificar si el catálogo está lleno
    if (cantidad_productos >= 10)
    {
        cout << "No se pueden ingresar más productos, el catálogo está lleno." << endl;
        return;
    }

    // Buscar si el producto ya existe
    for (int i = 0; i < cantidad_productos; i++)
    {
        if (minusculiar(_nombre) == minusculiar(catalogo[i].get_nombre()))  // Comparar nombres en minúsculas
        {
            // Si el producto ya existe, actualizar la cantidad
            cout << "El producto ya está registrado, actualizando cantidad..." << endl;
            catalogo[i].set_cantidad(_cantidad);  // Se actualiza la cantidad
            es_nuevo = false;  // No es un producto nuevo
            break;
        }
    }

    // Si el producto es nuevo, agregarlo al catálogo
    if (es_nuevo)
    {
        catalogo[cantidad_productos] = Producto(_nombre, _valor, _cantidad);
        cantidad_productos++;  // Incrementar la cantidad de productos solo si es nuevo
        cout << "El producto se ha ingresado con éxito. Ahora hay " << cantidad_productos << " productos." << endl;
    }
}

// Método para mostrar productos
void Tienda::mostrar_productos()
{
    if (cantidad_productos!=0)
    {
        for (int i = 0; i < cantidad_productos; i++)
        {
            cout<<"---------------------------------------------------------------"<<endl;
            cout << "Producto: " << catalogo[i].get_nombre()
                << ", Precio: " << catalogo[i].get_precio()
                << ", Stock: " << catalogo[i].get_cantidad() << endl;
        }
    }
    else
        cout<<"todavia no hay productos por mostrar"<<endl;
}
void Tienda::buscar_producto()
{
    bool si_esta = false;
    cout << "Has elegido la opción de buscar un producto por nombre." << endl;
    string buscado = leer("¿Qué producto desea buscar?");

    for (int a = 0; a < cantidad_productos; a++)
    {
        // Convertimos ambos nombres a minúsculas para una comparación insensible a mayúsculas
        string nombre_producto = minusculiar(catalogo[a].get_nombre());
        string nombre_buscado = minusculiar(buscado);

        // Si encontramos el nombre exacto
        if (nombre_buscado == nombre_producto)
        {
            cout << "---------------------------------------------------------------" << endl;
            cout << "Producto: " << catalogo[a].get_nombre() << endl;
            cout << "Precio: " << catalogo[a].get_precio() << endl;
            cout << "Stock: " << catalogo[a].get_cantidad() << endl;
            si_esta = true;
        }
        // Si el nombre buscado está contenido dentro del nombre del producto
        else if (nombre_producto.find(nombre_buscado) != string::npos)
        {
            cout << "---------------------------------------------------------------" << endl;
            cout << "El producto " << catalogo[a].get_nombre() << " contiene la palabra buscada." << endl;
            cout << "Precio: " << catalogo[a].get_precio() << endl;
            cout << "Stock: " << catalogo[a].get_cantidad() << endl;
            si_esta = true;
        }
    }

    // Si no se encontró ningún producto
    if (si_esta==false)
    {
        cout << "No se encontró ningún producto similar a: " << buscado << "." << endl;
    }
}

void Tienda::calcular_porcentaje()
{

    double porcentaje = 0.0;

    for (int o = 0; o < cantidad_productos; o++)
    {
        total_unidades += catalogo[o].get_cantidad();
    }

    cout << "La cantidad total de unidades de todos los productos es: " << total_unidades << endl;
    cout << "---------------------------------------------------------------" << endl;

    // Si no hay productos o total_unidades es 0, no se puede calcular el porcentaje
    if (total_unidades == 0) {
        cout << "No hay productos o no hay unidades en stock para calcular porcentajes." << endl;
        return;
    }

    // Calculamos y mostramos el porcentaje de cada producto
    for (int u = 0; u < cantidad_productos; u++)
    {
        // Cast a double para asegurarnos de obtener un valor decimal
        porcentaje = (static_cast<double>(catalogo[u].get_cantidad()) / total_unidades) * 100;

        cout << "El porcentaje del producto: " << catalogo[u].get_nombre()
             << " es " << to_string(porcentaje) << "%, ya que tiene "
             << catalogo[u].get_cantidad() << " unidades en stock." << endl;
    }
}
void Tienda::buscar_rango_precio()
{
    cout<<"ha saleccionado la opcion de buscar por rango de precio"<<endl;
    double rangoi = stod(leer("Digite el rango inicial:"));
    double rangof = stod(leer("Digite el rango final:"));
    double aus = 0.0;
    bool sihay = false;

    // Intercambiar valores si el rango inicial es mayor que el final
    if (rangoi > rangof)
    {
        cout << "El rango inicial es mayor que el rango final, intercambiando los valores..." << endl;
        aus = rangoi;
        rangoi = rangof;
        rangof = aus;
        cout << "Ahora el rango final es " << rangof << " y el rango inicial es " << rangoi << endl;
    }

    for (int z = 0; z < cantidad_productos; z++)
    {

        if ((catalogo[z].get_precio() <= rangof) && (catalogo[z].get_precio() >= rangoi))
        {
            cout << "El producto " << catalogo[z].get_nombre()
                 << " se encuentra dentro del rango ya que su precio es "
                 << catalogo[z].get_precio() << "." << endl;
            sihay = true;
        }
    }

    // Si no hay productos dentro del rango
    if (sihay == false)
    {
        cout << "No hay productos en este rango de precios." << endl;
    }
}

void Tienda::modificar_precio()
{
    cout << "Ha seleccionado la opción de modificar el precio de un producto." << endl;
    string nombrem = leer("Digite el nombre del producto para modificar su valor:");
    bool sifue = false;
    double valorm = 0.0;

    for (int k = 0; k < cantidad_productos; k++)
    {
        if (minusculiar(nombrem) == minusculiar(catalogo[k].get_nombre()))
        {
            cout << "Se ha encontrado el producto " << catalogo[k].get_nombre()
                 << " que actualmente tiene el precio de " << catalogo[k].get_precio() << "." << endl;

            // Solicitar el nuevo precio
            valorm = stod(leer("Digite el nuevo precio para este producto:"));

            // Modificar el precio del producto
            catalogo[k].set_precio(valorm);

            cout << "El precio ha sido modificado exitosamente." << endl;
            sifue = true;
            break;  // Salir del bucle una vez que se encuentra y modifica el producto
        }
    }


    if (sifue == false)
    {
        cout << "No se encontraron productos con ese nombre." << endl;
    }
}
