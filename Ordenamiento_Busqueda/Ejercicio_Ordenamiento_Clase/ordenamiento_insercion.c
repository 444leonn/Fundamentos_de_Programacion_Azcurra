#include <stdio.h>

#define MAX 20

typedef int T_Vec[MAX];

void ordenar_por_insercion (T_Vec vector, int ML) {
    int i, j, aux;

    for (i = 1; i < ML; i++) {
        aux = vector[i];

        j = i - 1;
        while ((j >= 0) && (vector[j] > aux)) {
            vector[j + 1] = vector[j];
            j = j - 1;
        }

        vector[j + 1] = aux;
    }
}

void mostrar_vector (T_Vec vector, int ML) {
    int i;

    for (i = 0; i < ML; i++) {
        printf("%d ", vector[i]);
    }    
    printf("\n");
}

int main() {
    T_Vec vec = {3, 1, 2, 5};
    int ml = 4;

    mostrar_vector(vec, ml);

    ordenar_por_insercion(vec, ml);

    mostrar_vector(vec, ml);
    
    return 0;
}