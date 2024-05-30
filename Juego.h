#include <iostream>
#include <string>

#include "Producto.h"
using namespace std;

#ifndef JUEGO
#define JUEGO

//Clase Hija: Juego
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

///Implementación

//Getters
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

//Métodos

//Mostramos en pantalla que se reproduce el trailer del juego
void Juego::reproducirTrailer(){
    cout << "Reproduciendo Trailer . . .";
    cout << ".\n.\n.\n";
}

//Mostramos la cantidad de jugadores máximos para el juego
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

//Mostramos en pantalla los atributos del Juego
void Juego::mostrarProducto(){
    cout << "Nombre: " << nombre << endl;
    cout << "Precio: " << precio << endl;
    cout << "Plataforma: " << plataforma << endl;
    cout << "Genero: " << genero << endl;
    cout << "Desarrollador: " << desarrollador << endl;
    cout << "Clasificacion: " << clasificacion << endl;
    cout << "Cantidad Maxima de Juegadores: " << jugadoresMax << endl;
}

void Juego::solicitarAtributos() {
    cout << "Ingrese el nombre del producto: "; getline(cin, nombre);
    cout << "Ingrese el precio: "; cin >> precio;
    cout << "Ingrese la plataforma: "; getline(cin, plataforma);
    cout << "Ingrese el tipo de producto: "; cin >> tipo;
    cout << "Ingresa el género del juego: "; getline(cin, genero);
    cout << "Ingresa el desarrollador del juego: "; getline(cin, desarrollador);
    cout << "Ingresa la clasificación del juego: "; cin >> clasificacion;
    cout << "Ingresa el número máximo de jugadores: "; cin >> jugadoresMax;
}


#endif
