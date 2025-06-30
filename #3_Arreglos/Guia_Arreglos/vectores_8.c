/*
* Dadas las siguientes declaraciones de constantes y tipos:
*     #define MAX 1000​
*     typedef int vector_t[MAX]
* 
* Desarrollar una función en lenguaje C que reciba como parámetros un vector de tipo vector_t ya cargado y su máximo lógico, que devuelva:
*     -​ un valor de verdad que informe si el vector está ordenado ascendentemente
*     -​ la menor diferencia entre elementos contiguos.
* Se solicita resolver lo pedido recorriendo una sola vez al vector.
*     Ejemplo:
*     Dado el siguiente vector cuyo máximo lógico es 7, la función debe devolver true y 1 (la menor diferencia entre 27 y 28).
*     0   1   2   3   4   5   6   7   8
*     15 18  20  27  28  46  70   -   -
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 1000
typedef int vector_t[MAX];

bool analizar_vector(vector_t vector, int max_logico, int *menor_diferencia) {
    int i, diferencia;
    bool ordenado = true;
    *menor_diferencia = __INT_MAX__;
    
    for (i = 0; i < max_logico - 1; i++) {
        diferencia = vector[i + 1] - vector[i];
        if (diferencia < 0) {
            ordenado = false;
        }
        else if (diferencia < *menor_diferencia) {
            *menor_diferencia = diferencia;
        }
    }

    return ordenado;
}

int main() {
    vector_t vector_enteros = {15, 18, 20, 27, 28, 46, 70};
    int ML = 7, diferencia;
    bool esta_ordenado;

    esta_ordenado = analizar_vector(vector_enteros, ML, &diferencia);

    if (esta_ordenado) {
        printf("El vector esta ordenado.\n");
        printf("La menor diferencia es: %d", diferencia);
    }
    else {
        printf("El vector no esta ordenado.\n");
    }

    return 0;
}