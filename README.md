# TC1030_FJ24
Repositorio para la materia de Programación Orientada a Objetos TC1030 donde se actualizarán los avances del proyecto.

# Tienda de Videojuegos.
El proyecto consiste en el modelado de una tienda de videojuegos, la cual tiene varios tipos de productos, desde juegos, consolas y accesorios en el inventario, en el que se agregarán o eliminarán los productos para poder ofrecerlos en la tienda. Los usuarios pueden comprar con base en el inventario, pueden agregar o eliminar productos a la clase carrito, así como obtener el costo de sus productos y checar si hay descuentos disposibles.

Para cada tipo de producto puedes visualizar distintas caracteristicas de cada uno, el trailer del juego, la bateria de los accesorios, ejecutar el juego en la consola, checar la posibilidad de multijugador en los juegos y establecer la configuración de las consolas.

## Clases.
- Producto (Clase Padre)

  (Clases Hijas)
  - Juego
  - Consola
  - Accesorio
- Inventario (Composición de Productos)
- Carrito (Agregación de Productos)

## Funcionalidad.
El programa servirá para la tienda de videojugos como un punto de venta en línea mediante el cual pueden ofrecer a sus clientes sus productos así como una descripción de ellos.

## Consideraciones.

Se deben de descargagr todos los archivos, cada clase y el main. 
Todo el código esta realizado con C++
Compilar con "g++ main.cpp -o main"
Correr en windows con: "a.exe"
El descuento de la compra de dos productos iguales, solo aplica el primer para un par de productos
Cuando se solicita una decisión ingresar la información tal como se pide, sean mayúsculas o minúsculas
Si se solicita una cantidad ingresar un número, si no texto o cadena de texto de ser posible.

## Documentación

RAND, TIME, SRAND.
    https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/?ref=header_search
    
## Diagrama UML
![TiendaVideojuegos drawio (1)](https://github.com/nicoleum17/TC1030_FJ24/assets/142357118/3995c193-04e6-42c8-925f-9c5880fe8386)



