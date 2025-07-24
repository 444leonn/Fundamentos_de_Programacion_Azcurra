# Examen Integrador Final - Fundamentos de Programación / Algoritmos y Programacion I (Catedra: Azcurra) | Fecha (16/07/2025)

## Ejercicio 1

1. Una libreria posee un archivo denominado `Stock.dat`, cuyos registros contienen el `codigo del libro` (entero), el `titulo` (30 caracteres), el `stock actual` de dicho libro (entero), el `stock minimo` de dicho libro (entero) y el `precio unitario` (real). Dicho archivo **no esta ordenado** y **"NO ENTRA" en memoria en su totalidad**.
Se pide desarrollar un programa modular en lenguaje C que procese este archivo y que permita:

- Generar una tabla llamada `Ofertas` que contenga solo los libros cuyo stock actual esta por encima del doble del stock minimo. Incluir en la tabla los siguientes campos:

  - El `codigo` del libro (entero)
  - El `titulo` del libro (30 caracteres).
  - La `cantidad` de libros a ofertar (entero, a lo sumo se pueden ofertar la mitad de los libros que estan por sobre el stock minimo).
  - El `precio` unitario de oferta (real, el descuento de la oferta es del 25%).
Asumir que esta tabla tendra como maximo 100 registros y que **cabe en memoria**.

- Ordenar la tabla Ofertas ascendentemenete por titulo del libro.

## Ejercicio 2

2. Escribir una funcion llamada `crear_estructura_dinamica` que reciba una cadena de caracteres `nombre` y un entero correspondiente a un `legajo`, la misma debe reservar memoria, para almacenar los dos valores en un registro t_alumno. La funcion debe devolver un puntero a una estructura dinamica `t_alumno` que contenga los elementos pasados por parametros y utilice solo el espacio de memoria necesario.
Escribir un main que:

- Invoque a la funcion utilizando como arreglo la siguiente declaracion:
    `nombre = Pepe`
    `legajo = 111111`
- Haga una llamada a la funcion `mostrar_estructura_dinamica` a la que se le debe pasar la estructura y la correspondiente cantidad de elementos a mostrar. No tenes que desarrollar esta funcion, solo utilizarla adecuadamente. Solo se puede invocar esta funcion si el puntero no es nulo.

## Ejercicio 3

3. Desarrollar una funcion recursiva en C que reciba un array de numeros enteros, su tamaño y un valor, la cual debe retornar la cantidad de elementos dentro del array cuyo valor es mayor al pasado por parametro.
Ejemplo:
    - Invocacion con:
    `vector[5] = {3, 1, 4, 5, 2}`, `valor = 2` y `tamaño = 5`. Debe devolver 3.
