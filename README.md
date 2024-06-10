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

- Para compilar

Se deben de descargagr todos los archivos, cada clase y el main. 
Todo el código esta realizado con C++
Compilar con "g++ main.cpp"
Correr en windows con: "a.exe"

- Al usarse
  
El descuento de la compra de dos productos iguales, solo aplica el primer para un par de productos.

Cuando se solicita una decisión ingresar la información tal como se pide, sean mayúsculas o minúsculas.

Si se solicita una cantidad ingresar un número, si no texto o cadena de texto de ser posible.

Debes de ser muy cuidadoso ingresando indices válidos al carrito de compras.

## Documentación

- RAND, TIME, SRAND.

Obtenemos números aleatorios con base en un valor semilla.

    - GeeksforGeeks. (2023, May 7). rand() and srand() in C. GeeksforGeeks. 
  
           https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/?ref=header_search
    

- GETLINE
  
Permite leer toda la cadena de texto de una misma linea sin importar la existencia de espacios.

     - GeeksforGeeks. (2024, January 30). getline (string) in C. GeeksforGeeks. 
    
            https://www.geeksforgeeks.org/getline-string-c/?ref=header_search

-CIN.IGNORE

Ayuda a limpiar el buffer para que los getline no lean el salto de línea.

     - GeeksforGeeks. (2022, October 30). Clearing the input buffer in CC. GeeksforGeeks. 
     
            https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/?ref=header_search
            
## Diagrama UML
![TiendaVideojuegos drawio (2)](https://github.com/nicoleum17/TC1030_FJ24/assets/142357118/a8d3ed39-f8f0-406c-a901-461385a836aa)




