/*
 * Proyecto Tienda de Videojuegos : Clase Producto
 * Joanna Nicole Uriostegui Magaña
 * A01711853
 * 03/06/2024 
 * 
 * La clase Producto se establece como clase padre
 * la cual posee atributos generales de cada tipo
 * de producto, permite al usuario modificar el
 * precio ya establecido, mostrar los atributos
 * y solicitar los atributos necesario para crear
 * otro objeto.
 * 
 */
#include <iostream>
#include <string>
using namespace std;

#ifndef PRODUCTO
#define PRODUCTO

/* * * * * * * * * * * * Clase Producto * * * * * * * * * * * * */
// Clase Padre
class Producto{
    protected:
        //Atributos de la clase padre
        string nombre;
        float precio;
        string plataforma;
        string tipo;
    
    public:
      
        //Constructores
        Producto();
        Producto(string, float, string, string); //Sobrecarga de constructores

        //Getters y Setters
        string getNombre(){ return nombre; }
        void setNombre(string);
        float getPrecio(){ return precio; }
        void setPrecio(float);
        string getPlataforma(){ return plataforma; }
        void setPlataforma(string);
        string getTipo(){ return tipo; }
        void setTipo(string);

        //Métodos
        void actualizarPrecio(float);
        virtual void mostrarProducto() = 0; //abstracta
        virtual void solicitarAtributos() = 0;

};

/* * * * * * * * * * * * Implementación * * * * * * * * * * * * */

//* * * * * * * Constructores
Producto::Producto(){
    nombre = " ";
    precio = 0;
    plataforma = " ";
    tipo = " ";
}

//Constructor sobrecargado
Producto::Producto(string nom, float price, string plat, string type){
    nombre = nom;
    precio = price;
    plataforma = plat;
    tipo = type;
}

//* * * * * * *Setters
void Producto::setNombre(string nom){
    nombre = nom;
}

void Producto::setPrecio(float price){
    precio = price;
}

void Producto::setPlataforma(string plat){
    plataforma = plat;
}

void Producto::setTipo(string type){
    tipo = type;
}

//* * * * * * * Métodos 

/*
 * * * * * * * * * * * * * Actualizar Precio * * * * * * * * * * * * *
 * 
 * Se redefine el valor del precio del producto
 * 
 * Param: -
 * Return: -
 */

void Producto::actualizarPrecio(float nuevo){
    precio = nuevo;
}

/*
 * * * * * * * * * * * * * Mostrar Producto * * * * * * * * * * * * *
 * 
 * Mostramos en pantalla los atributos del producto mediante cout
 * 
 * Param: -
 * Return: -
 */

void Producto::mostrarProducto(){
    cout << "Nombre: " << nombre << endl;
    cout << "Precio: " << precio << endl;
    cout << "Plataforma: " << plataforma << endl;
}

/*
 * * * * * * * * * * * * * Solicitar Atributos * * * * * * * * * * * * *
 * 
 * Solicitamos al usuario cada atributo de la clase
 * 
 * Param: -
 * Return: -
 */

void Producto::solicitarAtributos() {
    cout << "Ingrese el nombre del producto: "; getline(cin, nombre);
    cout << "Ingrese el precio: "; cin >> precio;
    cout << "Ingrese la plataforma: "; getline(cin, plataforma);
    cout << "Ingrese el tipo de producto: "; cin >> tipo;
}

#endif