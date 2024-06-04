/*
 * Proyecto Tienda de Videojuegos : Clase Inventario
 * Joanna Nicole Uriostegui Magaña
 * A01711853
 * 03/06/2024 
 * 
 * La clase Inventario es una composición de Productos, 
 * permite al usuario agregar, eliminar y mostrar los 
 * productos que lo componen.
 * 
 */

#include <iostream>
using namespace std;

#include "Producto.h"
#include "Juego.h"
#include "Consola.h"
#include "Accesorio.h"

#ifndef INVENTARIO
#define INVENTARIO

/* * * * * * * * * * * * Clase Inventario * * * * * * * * * * * * */

//Se compone de objetos de tipo Producto
class Inventario {
    private: 
        //Atributos
        Producto* productos[30];
        int numProductos;
    public:
        //Constructor
        //Solo inicializamos el valor de la cantidad de productos
        Inventario():numProductos(0) {}
        ~Inventario() {
            for (int i = 0; i < numProductos; i++) {
                delete productos[i];
            }
        }

        //Getter
        int getNumProductos(){ return numProductos; }

        //Métodos
        void inicialInv();
        void agregarProd(int);
        void eliminarProd(int);
        Producto* getProducto(int);
        void mostrarInventario();
};

/* * * * * * * * * * * * Implementación * * * * * * * * * * * * */

//* * * * * * * Métodos 

/*
 * * * * * * * * * * * * * Iniciar Inventario * * * * * * * * * * * * *
 * 
 * Inicializamos el inventario con una composición de productos
 * Mediante polimorfismo en un array de punteros de tipo Producto, 
 * instanciamos con new cada constructor del tipo de clase  que 
 * corresponde aumentando el contador.
 * 
 * Param: -
 * Return: -
 */

void Inventario::inicialInv(){
    //Instanciamos el objeto
    productos[numProductos] = new Consola("Sony", "5", 825, "PlayStation 5", 499.99, "PlayStation", "Consola");
    numProductos++; //Incrementamos el contador
    productos[numProductos] = new Consola("Microsoft", "Series X", 1000, "Xbox Series X", 499.99, "Xbox", "Consola");
    numProductos++;
    productos[numProductos] = new Consola("Nintendo", "Switch", 32, "Nintendo Switch", 299.99, "Nintendo", "Consola");
    numProductos++;
    productos[numProductos] = new Juego("Aventura", "Nintendo", 12, 1, "The Legend of Zelda: Breath of the Wild", 60.00, "Nintendo Switch", "Juego");
    numProductos++;
    productos[numProductos] = new Juego("Shooter", "Blizzard", 12, 12, "Overwatch", 40.00, "PC", "Juego");
    numProductos++;
    productos[numProductos] = new Juego("Sandbox", "Mojang", 7, 8, "Minecraft", 30.00, "Multiplataforma", "Juego");
    numProductos++;
    productos[numProductos] = new Accesorio("Recargable", "Bluetooth", "Mando Inalambrico Xbox", 59.99, "Xbox", "Accesorio");
    numProductos++;
    productos[numProductos] = new Accesorio("N/A", "Cable 3.5mm", "Auriculares para Gaming Logitech G432", 79.99, "Multiplataforma", "Accesorio");
    numProductos++;
    productos[numProductos] = new Accesorio("N/A", "Cable USB", "Volante de Carreras Logitech G29", 299.99, "PlayStation/PC", "Accesorio");
    numProductos++;
}

/*
 * * * * * * * * * * * * * Agregar Producto * * * * * * * * * * * * *
 * 
 * Solicitamos los atributos para crear el objeto de cada tipo.
 * Mediante un ciclo for iteramos la cantidad de veces indicadas por el 
 * usuario y de acuerdo al tipo de producto a ingresar manda llamar el 
 * método correspondiente para solicitar los atributos necesario.
 * 
 * Param: Int que indica la cantidad de productos a agregar
 * Return: -
 */

void Inventario::agregarProd(int n) {
    string tipo;

    for (int i = 0; i < n; i++) {
        // Solicitamos el tipo de producto
        cout << "Ingresa el tipo de producto (Juego/Consola/Accesorio): "; cin >> tipo; 
        cin.ignore();

        if (numProductos < 30) {
            if (tipo == "Juego") {
                Juego* juego = new Juego();
                // Solicitamos los atributos de Juego
                juego->solicitarAtributos();
                productos[numProductos] = juego;
            } else if (tipo == "Consola") {
                Consola* consola = new Consola();
                // Solicitamos los atributos de Consola
                consola->solicitarAtributos();
                productos[numProductos] = consola;
            } else if (tipo == "Accesorio") {
                Accesorio* accesorio = new Accesorio();
                // Solicitamos los atributos de Accesorio
                accesorio->solicitarAtributos();
                productos[numProductos] = accesorio;
            } else {
                cout << "Tipo de producto invalido. Intente de nuevo." << endl;
                i--; // Para repetir la iteración actual
                continue;
            }
            numProductos++; // Incrementamos el contador
        } else {
            cout << "El inventario está lleno.\n";
            break;
        }
    }
}

/*
 * * * * * * * * * * * * * Eliminar Producto * * * * * * * * * * * * *
 * 
 * Eliminamos el producto según el indice indicado
 * Se checa la validéz del índice para recorrer el arreglo cambiando
 * cada producto posterir al indice anterior.
 * 
 * Param: Int que indica el índice del producto a eliminar
 * Return: -
 */

void Inventario::eliminarProd(int indice) {
    //Validamos que el índice sea válido
    if (indice < 0 || indice >= numProductos) {
        cout << "Indice invalido." << endl;
        return;
    }
    //modificamos el arreglo recorriendo los productos
    for (int i = indice; i < numProductos - 1; i++) {
        productos[i] = productos[i + 1];
    }
    numProductos--; //disminuimos el contador
}

/*
 * * * * * * * * * * * * * Get Producto * * * * * * * * * * * * *
 * 
 * Devolvemos el producto que compone el inventario según el indice
 * indicado.
 * 
 * Param: Int que indica el indice del producto a devolver
 * Return: Un apuntador de tipo Producto
 */

Producto* Inventario::getProducto(int indice){
    return productos[indice];
}

/*
 * * * * * * * * * * * * * Mostrar Inventario * * * * * * * * * * * *
 * 
 * Mostramos los atributos de cada objeto.
 * Recorremos el array del inventario y mandamos a llamar el método 
 * que corresponde a cada tipo de Producto para mostrar sus atributos.
 * 
 * Param: -
 * Return: -
 */

void Inventario::mostrarInventario() {
    cout << "\nInventario: \n"; 
    for (int i = 0; i < numProductos; i++) {
        cout << "\nProducto " << i + 1 << ":" << endl;
        productos[i] -> mostrarProducto();
    }
}

#endif