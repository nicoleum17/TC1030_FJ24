/*
 * Proyecto Tienda de Videojuegos
 * Joanna Nicole Uriostegui Magaña
 * A01711853
 * 03/06/2024
 * 
 * El proyecto consiste en el modelado de una tienda de videojuegos,
 * la cual tiene varios tipos de productos, desde juegos, consolas y 
 * accesorios en el inventario, en el que se agregarán o eliminarán 
 * los productos para poder ofrecerlos en la tienda. Los usuarios 
 * pueden comprar con base en el inventario, pueden agregar o eliminar 
 * productos a la clase carrito, así como obtener el costo de sus 
 * productos y checar si hay descuentos disposibles.
 * 
 */
#include <iostream>
#include <string>
using namespace std;

//Bibliotecas de clases del proyecto
#include "Producto.h"
#include "Juego.h"
#include "Consola.h"
#include "Accesorio.h"
#include "Carrito.h" 
#include "Inventario.h"


int main() {
    //Variables
    char respuesta;
    int n, indice;
    string tipo;

    //Instanciamos nuestro objeto y lo inicializamos
    Inventario inventarioNicole;
    inventarioNicole.inicialInv();

    //Bienvenida al programa y mostramos el inventario
    cout << " \n\n------ Bienvenido a GamesOn ------"; 
    cout << "\nA continuacion observaras todos los productos existentes\n";
    cout << "en el inventario.";

    cout << "\nEste es el inventario actual";
    inventarioNicole.mostrarInventario();

    //Pregunta para añadir productos
    cout << "\nDeseas agregar mas productos al inventario? (S/N): ";
    cin >> respuesta; cin.ignore();

    // R = 'S' para agregar la cantidad de productos indicados
    if(respuesta == 'S'){
        cout << "\nIngresa la cantidad de productos a agregar al inventario: "; cin >> n;
        cin.ignore(); inventarioNicole.agregarProd(n);
        inventarioNicole.mostrarInventario();
    }

    //Pregunta para eliminar algún producto
    cout << "\nDeseas eliminar algun producto del inventario? (S/N): ";
    cin >> respuesta; cin.ignore();

    //Eliminamos la cantidad de productos indicados
    if(respuesta == 'S'){
        cout << "\nIngresa la cantidad de productos a eliminar del inventario: "; cin >> n;
        cin.ignore(); 
        for(int i = 0; i < n; i++){
            inventarioNicole.mostrarInventario();

            cout << "Indica el indice del producto a eliminar: ";
            cin >> indice;
            cin.ignore();          
            inventarioNicole.eliminarProd(indice - 1);
        }
        inventarioNicole.mostrarInventario();
    }
    
    //Instanciamos el carrito para el usuario
    Carrito carritoCompra;

    //Variables
    string nombre;

    //Le otrogamos nombre al carrito
    cout << "\n\n---------------------------------";
    cout << "\n\nUsuario, bienvenido a GamesOn.";
    cout << "\nIngresa tu nombre: "; cin >> nombre;
    cin.ignore();  
    carritoCompra.setUsuario(nombre);

    //ciclo para agregar los productos que usuario desee a su carrito de compras
    cout << "\nDeseas comprar algun producto? (S/N): "; 
    cin >> respuesta; cin.ignore();

    while(respuesta == 'S'){
        //Mostramos el inventario al usuario por tipo de producto
        do{
            cout<< "\nEn GamesOn tenemos distintos tipos de productos, a continuacion\n";
            cout << "elige el tipo de producto que desees comprar, Juego / Consola / Accesorio: ";
            cin >> tipo; cin.ignore();
        }while(tipo != "Juego" && tipo != "Consola" && tipo != "Accesorio");

        cout << "\nEste es el inventario de "<< tipo << "s: \n";
        inventarioNicole.buscarInventario(tipo);

        // Creamos un arreglo para verificar los indices de cada categoria
        int cant = inventarioNicole.getNumProductos();
        int indicesValidos[cant], indices = 0;
        for (int i = 0; i < cant; i++) {
            if (inventarioNicole.getProducto(i)->getTipo() == tipo) {
                indicesValidos[indices] = i;
                indices++;
            }
        }

        bool indiceValido = false;

        //Solicitamos el indice para agregarlo al carrito de compras
        do {
            cout << "\nIndica el indice del producto que deseas agregar: "; 
            cin >> indice;
            cin.ignore();

            //verificamos si el indice es valido de la categoría
            for (int i = 0; i < indices; i++) {
                if (indicesValidos[i] == indice - 1) {
                    indiceValido = true;
                }
            }

            if (!indiceValido) {
                cout << "Indice invalido. Por favor ingrese un indice valido.\n";
            }
        } while (!indiceValido);

        carritoCompra.agregarProd(inventarioNicole.getProducto(indice-1));

        cout << "\nDeseas agregar mas productos? (S/N): "; 
        cin >> respuesta; cin.ignore();
    }
    
    // Checamos si hay descuentos aplicables: 
    carritoCompra.aplicarDesc();
    cout << "\nSali de aplicar el descuento";
    carritoCompra.mostrarCarrito();
    cout << "\nDescuento: " << carritoCompra.getCupon();
    cout << "\nTotal: " << carritoCompra.calcularTotal();
    //segmentation for
    return 0;
}