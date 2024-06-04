/*
 * Proyecto Tienda de Videojuegos : Clase Accesorio
 * Joanna Nicole Uriostegui Magaña
 * A01711853
 * 03/06/2024 
 * 
 * La clase Accesorio hereda los atributos de la clase Producto.
 * Permite al usuario rmostrar la bateria del accesorio, así como
 * mostrar y solicitar atributos.
 * 
 */

#include <iostream>
#include <string>
#include <time.h>
#include <limits> // Necesario para numeric_limits


#include "Producto.h"
using namespace std;

#ifndef ACCESORIO
#define ACCESORIO

/* * * * * * * * * * * * Clase Accesorio * * * * * * * * * * * * */
// Clase Hija de Producto

class Accesorio:public Producto{
    private:
        //Atributos
        string bateria;
        string conexion;
    public:
        //Constructor
        Accesorio():Producto(){
            bateria = " ";
            conexion = " ";
        }

        //Sobrecarga de contructor
        Accesorio(string bat, string con, string nom, float price, string plat, string type) : Producto(nom, price, plat, type){
            bateria = bat;
            conexion = con;
        }

        //Getters y Setters
        string getBateria(){ return bateria; }
        void setBateria(string);
        string getConexion(){ return conexion;}
        void setConexion(string);

        //Métodos
        void cantBateria();
        void mostrarProducto(); //Sobreescritura
        void solicitarAtributos();

};

/* * * * * * * * * * * * Implementación * * * * * * * * * * * * */

//* * * * * * * Setters
void Accesorio::setBateria(string bat){
    bateria = bat;
}

void Accesorio::setConexion(string con){
    conexion = con;
}

//* * * * * * * Métodos 

/*
 * * * * * * * * * * * * * Iniciar Inventario * * * * * * * * * * * * *
 * 
 * Con base en un numero aleatorio, mostramos la bateria del accesorio
 * 
 * Param: -
 * Return: -
 */

void Accesorio::cantBateria(){
    srand(time(NULL));
    cout<< "Cantidad de Bateria: " << rand() % 101 << endl;
}

/*
 * * * * * * * * * * * * * Mostrar Producto * * * * * * * * * * * * *
 * 
 * Mostramos en pantalla los atributos del producto mediante cout
 * 
 * Param: -
 * Return: -
 */

void Accesorio::mostrarProducto(){
    cout << "Nombre: " << nombre << endl;
    cout << "Precio: " << precio << endl;
    cout << "Plataforma: " << plataforma << endl;
    cout << "Bateria: " << bateria << endl;
    cout << "Conexion: " << conexion << endl;
}

/*
 * * * * * * * * * * * * * Solicitar Atributos * * * * * * * * * * * * *
 * 
 * Solicitamos al usuario cada atributo de la clase
 * 
 * Param: -
 * Return: -
 */

void Accesorio::solicitarAtributos() {
    cout << "Ingrese el nombre del producto: "; getline(cin, nombre);
    cout << "Ingrese el precio: "; cin >> precio; cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ingrese la plataforma: "; getline(cin, plataforma);
    tipo = "Accesorio"; 
    cout << "Ingresa el tipo de batería del accesorio: "; getline(cin, bateria);
    cout << "Ingresa el tipo de conexión del accesorio: "; getline(cin, conexion);
}

#endif