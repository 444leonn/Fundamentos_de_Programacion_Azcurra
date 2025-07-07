/*
* Asumiendo que ya existe un puntero que apuntan a un bloque de memoria previamente reservada con malloc de tamaño (n * int), 
* redimensionar dicha memoria a un tamaño de (2 * n *int).
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_n = 4, *vec_enteros = NULL, *aux = NULL;

    vec_enteros = malloc(num_n * sizeof(int));
    if (vec_enteros == NULL) {
        printf("Error, no se ha podido reservar la memoria.\n");
    }
    else {
        aux = realloc(vec_enteros, 2 * num_n * sizeof(int));

        if (aux == NULL) {
            printf("Error, no se ha podido reasignar la memoria.\n");
            free(vec_enteros);
        }
        else {
            printf("Se ha redimensionado la memoria.\n");
            vec_enteros = aux;

            free(vec_enteros);
        }
    }
    
    return 0;
}