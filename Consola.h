/*
 * Proyecto Tienda de Videojuegos : Clase Consola
 * Joanna Nicole Uriostegui Magaña
 * A01711853
 * 03/06/2024 
 * 
 * La clase Consola hereda los atributos de la clase Producto.
 * Permite al usuario ejecutar juegos, así como configurar la
 * consola según sus preferencias y mostrar y solicitar sus 
 * atributos.
 * 
 */

#include <iostream>
#include <string>
#include <limits> // Necesario para numeric_limits


#include "Producto.h"
using namespace std;

#ifndef CONSOLA
#define CONSOLA

/* * * * * * * * * * * * Clase Consola * * * * * * * * * * * * */
//Clase Hija de Producto

class Consola:public Producto{
    private:
        //Atributos
        string fabricante;
        string modelo;
        int almacenamiento;
    public:
        //Contructor vacío
        Consola():Producto(){
            fabricante = " ";
            modelo = " ";
            almacenamiento = 0;
        }

        //Constructos sobrecargado
        Consola(string fab, string mod, int alm, string nom, float price, string plat, string type) : Producto(nom, price, plat, type){
            fabricante = fab;
            modelo = mod;
            almacenamiento = alm;
        }

        //Getters y Setters
        string getFabricante(){ return fabricante; }
        void setFabricante(string);
        string getModelo(){ return modelo; }
        void setModelo(string);
        int getAlmacenamiento(){ return almacenamiento; }
        void setAlmacenamiento(int);

        //Métodos
        void ejecutarJuego();
        void configuracion();

        void mostrarProducto(); //Sobreescritura
        void solicitarAtributos();

};

/* * * * * * * * * * * * Implementación * * * * * * * * * * * * */

//* * * * * * * Setters
void Consola::setFabricante(string fab){
    fabricante = fab;
}

void Consola::setModelo(string mod){
    modelo = mod;
}

void Consola::setAlmacenamiento(int alm){
    almacenamiento = alm;
}

void Consola::ejecutarJuego(){
    cout << "Ejecutando Juego ...\n.\n.\n.\n";
}

//* * * * * * * Métodos 

/*
 * * * * * * * * * * * * * Configuración * * * * * * * * * * * * *
 * 
 * Realizamos preguntas al usuario para configurar su consola
 * 
 * Param: 
 * Return: 
 */

void Consola::configuracion(){
    string respuestas;

    cout << "Iniciar Sesion: "; cin >> respuestas; cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "¿Conectar cable HDMI?: "; cin >> respuestas; cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Selecciona la entrada: "; cin >> respuestas; cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Conexión Wi-Fi o cable Ethernet: "; cin >> respuestas; cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ajuste de audio: "; cin >> respuestas; cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/*
 * * * * * * * * * * * * * Mostrar Producto * * * * * * * * * * * * *
 * 
 * Mostramos en pantalla los atributos del producto mediante cout
 * 
 * Param: -
 * Return: -
 */

void Consola::mostrarProducto(){
    cout << "Nombre: " << nombre << endl;
    cout << "Precio: " << precio << endl;
    cout << "Plataforma: " << plataforma << endl;
    cout << "Fabricante: " << fabricante << endl;
    cout << "Modelo: " << modelo << endl;
    cout << "Almacenamiento: " << almacenamiento << endl;
}

/*
 * * * * * * * * * * * * * Solicitar Atributos * * * * * * * * * * * * *
 * 
 * Solicitamos al usuario cada atributo de la clase
 * 
 * Param: -
 * Return: -
 */

void Consola::solicitarAtributos() {
    cout << "Ingrese el nombre del producto: "; getline(cin, nombre);
    cout << "Ingrese el precio: "; cin >> precio; cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ingrese la plataforma: "; getline(cin, plataforma);
    tipo = "Consola"; 
    cout << "Ingresa el fabricante de la consola: "; getline(cin, fabricante);
    cout << "Ingresa el modelo de la consola: "; getline(cin, modelo); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ingresa el almacenamiento de la consola: "; cin >> almacenamiento;
}

#endif