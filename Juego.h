/*
 * Proyecto Tienda de Videojuegos : Clase Juego
 * Joanna Nicole Uriostegui Magaña
 * A01711853
 * 03/06/2024 
 * 
 * La clase Juego hereda los atributos de la clase Producto.
 * Permite al usuario reproducir el trailer del juego, así como
 * checar el multijugador del juego y mostrar y solicitar atributos.
 * 
 */

#include <iostream>
#include <string>

#include "Producto.h"
using namespace std;

#ifndef JUEGO
#define JUEGO

/* * * * * * * * * * * * Clase Juego * * * * * * * * * * * * */
//Clase Hija de Clase Producto
class Juego:public Producto{
    private:
        //Atributos
        string genero;
        string desarrollador;
        int clasificacion;
        int jugadoresMax;

    public:
        //Constructor vacío
        Juego():Producto(){
            genero = " ";
            desarrollador = " ";
            clasificacion = 0;
            jugadoresMax = 0;
        }
        
        //Constructor con parámetros, con base en clase padre - sobrecarga
        Juego(string gen, string des, int clas, int max, string nom, float price, string plat, string type) : Producto(nom, price, plat, type){
            genero = gen;
            desarrollador = des;
            clasificacion = clas; 
            jugadoresMax = max;
        }

        //Getters y Setters
        string getGenero(){ return genero; }
        void setGenero(string);
        string getDesarrollador(){ return desarrollador; }
        void setDesarrollador(string);
        int getClasificacion(){ return clasificacion; }
        void setClasificacion(int);
        int getJugMax(){ return jugadoresMax; }
        void setJugMax(int);

        //Métodos
        void reproducirTrailer();
        void verificarMultiJugador();
        void mostrarProducto(); //Sobreescritura
        void solicitarAtributos();

};

/* * * * * * * * * * * * Implementación * * * * * * * * * * * * */

//* * * * * * * Setters
void Juego::setGenero(string gen){
    genero = gen;
}

void Juego::setDesarrollador(string des){
    desarrollador = des;
}

void Juego::setClasificacion(int clas){
    clasificacion = clas;
}

void Juego::setJugMax(int max){
    jugadoresMax = max;
}

//* * * * * * * Métodos 

/*
 * * * * * * * * * * * * * Reproducir Trailer * * * * * * * * * * * * *
 * 
 * Mostramos en pantalla que se reproduce el trailer del juego
 * Param: -
 * Return: -
 */

void Juego::reproducirTrailer(){
    cout << "Reproduciendo Trailer . . .";
    cout << ".\n.\n.\n";
}

/*
 * * * * * * * * * * * * * Verificar Multijugador * * * * * * * * * * * * *
 * 
 * Mostramos la cantidad de jugadores máximos para el juego.
 * Con el condicional if evaluamos la cantidad de jugadores máximos posibles
 * en el juego y lo mostramos en pantalla.
 * 
 * Param: -
 * Return: -
 */

void Juego::verificarMultiJugador()
{
    //Condicional respecto a la cantidad de jugadores máximos
    if(jugadoresMax == 4){ 
        cout << "Multijugador de 4 personas\n";
    } else if(jugadoresMax == 2){
        cout << "Multijugador de 2 personas\n";
    } else {
        cout << "Juego para un solo jugador\n";
    }
}

/*
 * * * * * * * * * * * * * Mostrar Producto * * * * * * * * * * * * *
 * 
 * Mostramos en pantalla los atributos del producto mediante cout
 * 
 * Param: -
 * Return: -
 */

void Juego::mostrarProducto(){
    cout << "Nombre: " << nombre << endl;
    cout << "Precio: " << precio << endl;
    cout << "Plataforma: " << plataforma << endl;
    cout << "Genero: " << genero << endl;
    cout << "Desarrollador: " << desarrollador << endl;
    cout << "Clasificacion: " << clasificacion << endl;
    cout << "Cantidad Maxima de Jugadores: " << jugadoresMax << endl;
}

/*
 * * * * * * * * * * * * * Solicitar Atributos * * * * * * * * * * * * *
 * 
 * Solicitamos al usuario cada atributo de la clase
 * 
 * Param: -
 * Return: -
 */

void Juego::solicitarAtributos() {
    cout << "Ingrese el nombre del producto: "; getline(cin, nombre);
    cout << "Ingrese el precio: "; cin >> precio; cin.ignore();
    cout << "Ingrese la plataforma: "; getline(cin, plataforma);
    tipo = "Juego";    
    cout << "Ingresa el genero del juego: "; getline(cin, genero);
    cout << "Ingresa el desarrollador del juego: "; getline(cin, desarrollador);
    cout << "Ingresa la clasificación del juego: +"; cin >> clasificacion; cin.ignore();
    cout << "Ingresa el numero maximo de jugadores: "; cin >> jugadoresMax; cin.ignore();
}


#endif
