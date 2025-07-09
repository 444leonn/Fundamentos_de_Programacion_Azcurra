/*
* Implementar una función que retorna un puntero a un vector de n valores de tipo int, todos inicializados en cero,
* el cual apunta a un bloque de memoria dinámica, respetando la siguiente declaración.
* En caso de no poder reservar la memoria, retornar NULL.
*/

#include <stdio.h>
#include <stdlib.h>

void ingresar_n(int *numero_n) {
    printf("Ingrese la cantidad N de enteros a reservar:  ");
    scanf("%d", numero_n);
}

int *crear_vector_inicializado(int n) {
    int *vector, i;
    vector = malloc(n * sizeof(int));

    if (vector != NULL) {
        for (i = 0; i < n; i++) {
            vector[i] = 0;
        }
    }

    return vector;
}

int main() {
    int num_n, *vec_enteros;
    ingresar_n(&num_n);
    
    vec_enteros = crear_vector_inicializado(num_n);

    free(vec_enteros);
    
    return 0;
}