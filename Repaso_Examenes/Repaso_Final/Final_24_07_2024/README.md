# Examen Integrador Final - Fundamentos de Programación / Algoritmos y Programacion I (Fecha: 24/07/2024)\

## Ejercicio 1

1. Una libreria posee un archivo denominado `Stock.dat`, cuyos registros contienen el `codigo del libro` (entero), el `titulo` (30 caracteres), el `stock actual` de dicho libro (entero), el `stock minimo` de dicho libro (entero) y el `precio unitario` (real). Dicho archivo **no esta ordenado** y **"NO ENTRA" en memoria en su totalidad**.
Se pide desarrollar un programa modular en lenguaje C que procese este archivo y que permita:

- Generar una tabla llamada `Ofertas` que contenga solo los libros cuyo stock actual esta por encima del doble del stock minimo. Incluir en la tabla los siguientes campos:

  - El `codigo` del libro (entero)
  - El `titulo` del libro (30 caracteres).
  - La `cantidad` de libros a ofertar (entero, a lo sumo se pueden ofertar la mitad de los libros que estan por sobre el stock minimo).
  - El `precio` unitario de oferta (real, el descuento de la oferta es del 30%).
Asumir que esta tabla tendra como maximo 100 registros y que **cabe en memoria**.

- Ordenar la tabla Ofertas ascendentemenete por titulo del libro.

## Ejercicio 2

- Escribir una funcion llamada `crear_estructura_dinamica` que reciba un arreglo unidimensional de elementos enteros ya cargado, y su respectivo maximo logico. La funcion debe devolver un puntero a una estructura dinamica que contenga los elementos del arreglo recibido y utilice solo el espacio de memoria necesario.
Escribir un main que:

  - Invoque a la funcion utilizando como arreglo la siguiente declaracion: `int vector[100] = {48, 23, 2, 5, 18};`
  - Haga una llamada a la funcion `mostrar_estructura_dinamica` a la que se le debe pasar la estructura y la correspondiente cantidad de elemenetos a mostrar. No tenes que desarrollar esta funcion, solo utilizarla adecuadamente. Solo se puede invocar esta funcion si el puntero no es nulo.

## Ejercicio 3

- Desarrollar una funcion recursiva en lenguaje C que reciba un arreglo y su maximo logico, y devuelva la suma de los elementos que estan en las posiciones pares del arreglo.

## IMPORTANTE

1. Realizar los puntos en forma independiente, evitando el uso de variables globales.
2. Desarrollar la evaluacion con escritura prolija y entendible.
3. Los archivos se podran recorrer secuencialmente en su totalidad, en una sola oportunidad por cada punto.
4. Completar y codificar todo y solo lo necesario para la resolucion del presente problema, en especial, lo que se refiera a definiciones de tipos, variables, funciones y programa principal.
