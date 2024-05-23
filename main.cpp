#include <iostream>
using namespace std;

#include "Producto.h"
#include "Juego.h"
#include "Consola.h"
#include "Accesorio.h"
//#include "Carrito.h" Después usare esta clase
#include "Inventario.h"


int main() {
    //Variables
    char respuesta;
    int n, indice;

    //Instanciamos nuestro objeto y lo inicializamos
    Inventario inventarioNicole;
    inventarioNicole.inicialInv();

    //Bienvenida al programay mostramos el inventario
    cout << " --- Bienvenido a GamesOn ---";
    cout << " Este es el inventario actual: \n";
    inventarioNicole.mostrarInventario();

    //Pregunta para añadir productos
    cout << "¿Deseas agregar mas productos al inventario? (S/N): ";
    cin >> respuesta;

    // R = 'S' para agregar la cantidad de productos indicados
    if(respuesta == 'S'){
        cout << "Ingresa la cantidad de productos a agregar al inventario: "; cin >> n;
        for(int i = 0; i < n; i++){
            inventarioNicole.agregarProd(n);
        }
        inventarioNicole.mostrarInventario();
    }

    //Pregunta para eliminar algún producto
    cout << "¿Deseas eliminar algun producto del inventario? (S/N): ";
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
    
    return 0;
}