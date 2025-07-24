/*
* Desarrollar una funcion recursiva en C que reciba un array de numeros enteros, su tamaño y un valor
* la cual debe retornar la cantidad de elementos dentro del array cuyo valor es mayor al pasado por parametro.
* Ejemplo:
*     - Invocacion con:
*     `vector[5] = {3, 1, 4, 5, 2}`, `valor = 2` y `tamaño = 5`. Debe devolver 3.
*/

#include <stdio.h>

int valores(int vector[], int tamanio, int valor) {
    if (tamanio <= 0) {
        return 0;
    }
    else {
        if (vector[tamanio - 1] > valor) {
            return 1 + valores(vector, tamanio - 1, valor);
        }
        else {
            return valores(vector, tamanio - 1, valor);
        }
    }
}

int main() {
    int vector[5] = {3, 1, 4, 5, 2};
    int valor = 2;
    int max = 5;
    int cant_valores;

    cant_valores = valores(vector, max, valor);

    printf("Cantidad de elementos mayor a %d en el vector: %d\n\n", valor, cant_valores);
    
    return 0;
}