#include <iostream>
#include <string>
using namespace std;

#ifndef PRODUCTO
#define PRODUCTO

//Clase Padre: Producto
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
        void mostrarProducto();
};

///Implementación

//Constructores
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

//Setters
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

//Métodos

//Se redefine el valor del precio del producto
void Producto::actualizarPrecio(float nuevo){
    precio = nuevo;
}

//Mostramos en pantalla los atributos del producto
void Producto::mostrarProducto(){
    cout << "Nombre: " << nombre << endl;
    cout << "Precio: " << precio << endl;
    cout << "Plataforma: " << plataforma << endl;
}


#endif