#include <iostream>
#include <time.h>
using namespace std;

#include "Producto.h"
#include "Juego.h"
#include "Consola.h"
#include "Inventario.h"

#ifndef CARRITO
#define CARRITO

//Clase Carrito
class Carrito {
    private: 
        //Atributos
        int numCompras;
        int cupon;
        string usuario;
        Producto* compras[100]; //Array de productos
    public:
        //Constructor vacío
        Carrito():numCompras(0) {}
        //Sobrecarga de constructor
        Carrito(string);

        //Getters y Setters
        int getNumCompras(){ return numCompras; }
        string getUsuario(){ return usuario; }
        void setUsuario(string);
        int getCupon(){ return cupon; }
        void setCupon(int);

        //Métodos
        void agregarProd(Producto*);
        void quitarProd(int);
        void mostrarCarrito();
        float calcularTotal();
        void aplicarDesc(); //falta de implementar
};

///Implementación

//Constructor sobrecargado
Carrito::Carrito(string name){
    usuario = name;
    numCompras = 0;
}

//Setter

void Carrito::setUsuario(string name){
    usuario = name;
}

//Recibimos un objeto de tipo producto y lo agregamos al array
void Carrito::agregarProd(Producto* prod) {
    compras[numCompras] = prod;
    numCompras++;
}

//Eliminamos el producto del carrito según el indice indicado
void Carrito::quitarProd(int indice) {
    if (indice < 0 || indice >= numCompras) {
        cout << "Indice invalido." << endl;
        return;
    }
    for (int i = indice; i < numCompras - 1; i++) {
        compras[i] = compras[i + 1];
    }
    numCompras--;
}

//Mostramos en pantalla los objetos que componen al array de compras
void Carrito::mostrarCarrito() {
    cout << "\nCarrito: \n"; 
    for (int i = 0; i < numCompras; i++) {
        cout << "\nProducto " << i + 1 << ":" << endl;
        compras[i] -> mostrarProducto();
    }
}

//Calculamos el total de la compra
float Carrito::calcularTotal(){
    float total = 0;
    for(int i = 0; i < numCompras; i++){
        total += compras[i] -> getPrecio();
    }
    return total;
}

void Carrito::aplicarDesc(){
    srand(time(NULL));
    int indice;
    float cupon;

    //Identificamos el tipo de descuento aplicable

    //20% para 2 compras del mismo producto
    for(int i = 0; i < numCompras; i++){
        for(int j = i + 1; j < numCompras; j++){
            if(compras[i]->getNombre() == compras[j]->getNombre()){
                indice = i;
                cupon = 0.2;
                break;
            }
        }
        if(indice != -1) break;
    }

    //Realizamos el descuento
    if(indice != -1) {
        float precio = compras[indice] -> getPrecio();
        float precioDescuento = precio * (1 - cupon);
        compras[indice] -> setPrecio(precioDescuento);
        cout << "Producto con descuento aplicado. Nuevo precio: " << precioDescuento << endl;
    } else {
        cout << "No fue posible aplicar ningun descuento." << endl;
    }
}

#endif