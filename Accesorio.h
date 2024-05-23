#include <iostream>
#include <string>
#include <time.h>

#include "Producto.h"
using namespace std;

#ifndef ACCESORIO
#define ACCESORIO

// Clase Hija: Accesorio
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
};

///Implementación

//Setters
void Accesorio::setBateria(string bat){
    bateria = bat;
}

void Accesorio::setConexion(string con){
    conexion = con;
}

//Métodos

//Con base en un numero aleatorio, mostramos la bateria del accesorio
void Accesorio::cantBateria(){
    srand(time(NULL));
    cout<< "Cantidad de Bateria: " << rand() % 101 << endl;
}

//Mostramos en pantalla los atributos del Accesorio
void Accesorio::mostrarProducto(){
    cout << "Nombre: " << nombre << endl;
    cout << "Precio: " << precio << endl;
    cout << "Plataforma: " << plataforma << endl;
    cout << "Bateria: " << bateria << endl;
    cout << "Conexion: " << conexion << endl;
}

#endif