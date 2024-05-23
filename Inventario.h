#include <iostream>
using namespace std;

#include "Producto.h"
#include "Juego.h"
#include "Consola.h"

#ifndef INVENTARIO
#define INVENTARIO

//Clase Inventario
//Se compone de objetos de tipo Producto
class Inventario {
    private: 
        //Atributos
        Producto productos[30];
        int numProductos;
    public:
        //Constructor
        //Solo inicializamos el valor de la cantidad de productos
        Inventario():numProductos(0) {}
    
        //Getter
        int getNumProductos(){ return numProductos; }

        //Métodos
        void inicialInv();
        void agregarProd(int);
        void eliminarProd(int);
        void mostrarInventario();
};

//Implementación

//Inicializamos el inventario con una composición de productos
void Inventario::inicialInv(){
    //Instanciamos el objeto
    productos[numProductos] = Consola("Sony", "5", 825, "PlayStation 5", 499.99, "PlayStation", "Consola");
    numProductos++; //Incrementamos el contador
    productos[numProductos] = Consola("Microsoft", "Series X", 1000, "Xbox Series X", 499.99, "Xbox", "Consola");
    numProductos++;
    productos[numProductos] = Consola("Nintendo", "Switch", 32, "Nintendo Switch", 299.99, "Nintendo", "Consola");
    numProductos++;
    productos[numProductos] = Juego("Aventura", "Nintendo", 12, 1, "The Legend of Zelda: Breath of the Wild", 60.00, "Nintendo Switch", "Juego");
    numProductos++;
    productos[numProductos] = Juego("Shooter", "Blizzard", 12, 12, "Overwatch", 40.00, "PC", "Juego");
    numProductos++;
    productos[numProductos] = Juego("Sandbox", "Mojang", 7, 8, "Minecraft", 30.00, "Multiplataforma", "Juego");
    numProductos++;
    productos[numProductos] = Accesorio("Recargable", "Bluetooth", "Mando Inalámbrico Xbox", 59.99, "Xbox", "Accesorio");
    numProductos++;
    productos[numProductos] = Accesorio("N/A", "Cable 3.5mm", "Auriculares para Gaming Logitech G432", 79.99, "Multiplataforma", "Accesorio");
    numProductos++;
    productos[numProductos] = Accesorio("N/A", "Cable USB", "Volante de Carreras Logitech G29", 299.99, "PlayStation/PC", "Accesorio");
    numProductos++;
}

// Preguntamos al usuario los atributos de la clase para instanciar el objeto agregándolo al arreglo
void Inventario::agregarProd(int n) {
    string nombre, plataforma, tipo;
    float precio;
    //iteramos segun la cantidad de productos a agregar
    for(int i = 0; i < n; i++){
        //solicitamos los datos al usuario
        cout << "Ingresa el nombre del producto: "; cin >> nombre;
        cout << "Ingresa el precio: "; cin >> precio; 
        cout << "Ingresa el tipo de plataforma: "; cin >> plataforma;
        cout << "Ingresa el tipo de producto: "; cin >> tipo;
        //verificamos disponibilidad en el inventario
        if(numProductos < 30){
            //instanciamos el objeto
            productos[numProductos] = Producto(nombre, precio, plataforma, tipo);
            numProductos++; //incrementamos el contador
        } else {
            cout << "El inventario esta lleno.\n";
        }
    }
}

//Eliminamos el producto según el indice indicado
void Inventario::eliminarProd(int indice) {
    //Validamos que el pindice sea válido
    if (indice < 0 || indice >= numProductos) {
        cout << "Índice inválido." << endl;
        return;
    }
    //modificamos el arreglo recorriendo los productos
    for (int i = indice; i < numProductos - 1; i++) {
        productos[i] = productos[i + 1];
    }
    numProductos--; //disminuimos el contador
}

// Mostramos los atributos de cada objeto, 
// de momento solo muestra los atributos de tipo Producto
void Inventario::mostrarInventario() {
    cout << "\nInventario: \n"; 
    for (int i = 0; i < numProductos; i++) {
        cout << "\nProducto " << i + 1 << ":" << endl;
        productos[i].mostrarProducto();
    }
}

#endif


