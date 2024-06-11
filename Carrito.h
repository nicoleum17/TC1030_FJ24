/*
 * Proyecto Tienda de Videojuegos: Clase Carrito
 * Joanna Nicole Uriostegui Magaña
 * A01711853
 * 03/06/2024
 * 
 * Clase Carrito que es una agregación de los productos
 * instanciados en la clase inventario. 
 * Permite al usuario elegir productos para comprarlos.
 * 
 */

#include <iostream>
#include <string>
using namespace std;

#include "Producto.h"
#include "Juego.h"
#include "Consola.h"
#include "Inventario.h"

#ifndef CARRITO
#define CARRITO

/* * * * * * * * * * * * Clase Carrito * * * * * * * * * * * * */
class Carrito {
    private: 
        //Atributos
        int numCompras;
        int cupon;
        string usuario;
        Producto* compras[100]; //Array de productos
    public:
        //Constructor vacío
        Carrito():numCompras(0), cupon(0) {}
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
        void aplicarDesc(); 
};

/* * * * * * * * * * * * Implementación * * * * * * * * * * * * */

//* * * * * * * Constructor sobrecargado
Carrito::Carrito(string name){
    usuario = name;
    numCompras = 0;
}
 
// * * * * * * * Setter

void Carrito::setUsuario(string name){
    usuario = name;
}

//* * * * * * * Métodos 

/*
 * * * * * * * * * * * * * Agregar Producto * * * * * * * * * * * * *
 * 
 * Recibimos un objeto de tipo producto y lo agregamos 
 * al array de punteros de tipo Producto "compras".
 * 
 * Param: Puntero de tipo Juego, Consola o Accesorio
 * Return: -
 */

void Carrito::agregarProd(Producto* prod) {
    compras[numCompras] = prod;
    numCompras++;
}

/*
 * * * * * * * * * * * * * Quitar Producto * * * * * * * * * * * * *
 * 
 * Eliminamos el producto del carrito según el indice indicado.
 * Se verifica la validez del índice y luego se recorre cada 
 * producto posterior al indicado.
 * 
 * Param: Int que representa el indice
 * Return: -
 */

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

/*
 * * * * * * * * * * * * * Mostrar Carrito * * * * * * * * * * * * *
 * 
 * Mostramos en pantalla los objetos que componen al array de compras
 * Recorre todo el array de 'compras' imprimiendo de acuerdo a cada
 * tipo de producto sus respectivos atributos.
 * 
 * Param: -
 * Return: -
 */

void Carrito::mostrarCarrito() {
    cout << "\nCarrito: \n"; 
    for (int i = 0; i < numCompras; i++) {
        cout << "\nProducto " << i + 1 << ":" << endl;
        compras[i] -> mostrarProducto();
    }
}

/*
 * * * * * * * * * * * * * * Calcular Total * * * * * * * * * * * * *
 * 
 * Calculamos el total de la compra
 * Recorre el array de compras y obtiene el precio de cada tipo
 * mientras lo suma los suma al float total.
 * 
 * Param: -
 * Return: Float de la suma de los precios de artículos en el carrito
 */

float Carrito::calcularTotal(){
    float total = 0;
    for(int i = 0; i < numCompras; i++){
        total += compras[i] -> getPrecio();
    }
    return total;
}

/*
 * * * * * * * * * * * * Aplicar Descuento * * * * * * * * * * * *
 * 
 * Aplica un descuento del 20% cuando hay dos productos iguales.
 * Recorre el array para identificar si hay algún producto repetido
 * para guardar el índice y el cupon con un 20%. Para luego obtener
 * el precio del artículo y modificarlo en el array de compras.
 * 
 * Param: -
 * Return: -
 */

void Carrito::aplicarDesc(){

    //Identificamos el tipo de descuento aplicable

    //20% para 2 compras del mismo producto
    int i = 0, j = numCompras - 1;
    float precio;
    string ini = compras[i] -> getNombre();
    string fin = compras[j] -> getNombre();

    while(i <= j){
        if(ini == fin){
            precio = compras[i] -> getPrecio();
            precio *=.8;
            compras[i] -> actualizarPrecio(precio);
            cupon = 20;
        }
        i++;
        j--;
        ini = compras[i] -> getNombre();
        fin = compras[j] -> getNombre();
    }
}

#endif