/* 
* 10
*   Dado un vector a de longitud n y un elemento p del mismo tipo que los elementos del vector,
*   buscar p en el vector a y devolver la posición que ocupa en caso de encontrarlo o una señal en caso contrario. 
*   Suponer que no hay repeticiones.
* 11
*   Idem problema anterior, pero el vector está ordenado ascendente.
*/

#include <stdio.h>
#include <stdbool.h>

bool buscar_posicion(int vector[7], int elemento) {
    int i = 0;
    bool no_encontrado = true;

    while (vector[i] != elemento && i < 7){
        i++;
    }
    if (vector[i] == elemento) {
        printf("El elemento %d se encuentra en la posicion: %d\n", elemento, i);
        no_encontrado = false;
    }

    return no_encontrado;
}

int main() {
    int vector[] = {4, 1, 5, 8, 9, 2, 10};
    int vector_ascendente[] = {1, 2, 3, 4, 5, 6, 10};

    int elemento_p = 4;

    if (buscar_posicion(vector, elemento_p)) {
        printf("No se ha encontrado el elemento en el vector.\n");
    }
    if (buscar_posicion(vector_ascendente, elemento_p)) {
        printf("No se ha encontrado el elemento en el vector.\n");
    }

    return 0;
}