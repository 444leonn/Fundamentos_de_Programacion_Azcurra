#include <stdio.h>

#define MAX 20

typedef int T_Vec[MAX];

void ordenar_por_seleccion(T_Vec vector, int ML) {
    int i, j, aux, posMinimo;

    for (i = 0; i < ML - 1; i++) {
        posMinimo = i;

        for (j = i + 1; j < ML; j++) {
            if (vector[j] < vector[posMinimo]) {
                posMinimo = j;
            }
        }

        aux = vector[i];
        vector[i] = vector[posMinimo];
        vector[posMinimo] = aux;
    }
}