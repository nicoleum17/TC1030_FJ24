#include <iostream>
using namespace std;

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

    //Instanciamos nuestro objeto y lo inicializamos
    Inventario inventarioNicole;
    inventarioNicole.inicialInv();

    //Bienvenida al programa y mostramos el inventario
    cout << " --- Bienvenido a GamesOn ---"; 
    cout << "\nEste es el inventario actual: \n";
    inventarioNicole.mostrarInventario();

    //Pregunta para añadir productos
    cout << "\nDeseas agregar mas productos al inventario? (S/N): ";
    cin >> respuesta;

    // R = 'S' para agregar la cantidad de productos indicados
    if(respuesta == 'S'){
        cout << "Ingresa la cantidad de productos a agregar al inventario: "; cin >> n;
        inventarioNicole.agregarProd(n);
        inventarioNicole.mostrarInventario();
    }

    //Pregunta para eliminar algún producto
    cout << "\nDeseas eliminar algun producto del inventario? (S/N): ";
    cin >> respuesta;

    //Eliminamos la cantidad de productos indicados
    if(respuesta == 'S'){
        cout << "Ingresa la cantidad de productos a eliminar del inventario: "; cin >> n;
        for(int i = 0; i < n; i++){
            inventarioNicole.mostrarInventario();

            cout << "Indica el indice del producto a eliminar: ";
            cin >> indice;
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
    cout << "\nAhora actuaras como el usuario";
    cout << "\nIngresa tu nombre: "; cin >> nombre;
    carritoCompra.setUsuario(nombre);

    //Mostramos el inventario al usuario
    inventarioNicole.mostrarInventario();

    //ciclo para agregar los productos que usuario desee a su carrito de compras
    cout << "Deseas comprar algun producto? (S/N): "; cin >> respuesta;

    while(respuesta == 'S'){
        cout << "\nIndica el indice del producto que deseas agregar: "; cin >> indice;
        //cout << inventarioNicole.getProducto(indice);
        carritoCompra.agregarProd(inventarioNicole.getProducto(indice-1));

        cout << "\nDeseas agregar mas productos? (S/N): "; cin >> respuesta;
    }
    
    // Checamos si hay descuentos aplicables: 
    carritoCompra.aplicarDesc();
    carritoCompra.mostrarCarrito();
    cout << "\nDescuento: " << carritoCompra.getCupon();
    cout << "\nTotal: " << carritoCompra.calcularTotal();

    return 0;
}