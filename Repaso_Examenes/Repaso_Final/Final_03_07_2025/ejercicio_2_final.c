/*
* Escribir una función en lenguaje C llamada "crear_estructura_dinamica"
* que reciba un arreglo unidimensional de enteros ya cargado y su máximo lógico.
* La función debe devolver un puntero a una estructura dinámica que contenga los elementos del arreglo recibido
* y utilice solo el espacio de memoria necesario.
* 
* Escribir un programa "main" que:
*     1. Invoque la función `crear_estructura_dinamica` con:
*         int vec[100] = {4, 8, 23, 25, 18};
* 2. Invocar la función "mostrar_estructura_dinamica", pasándole la estructura y la cantidad de elementos.
* Esta función no debe desarrollarse, solo invocarse correctamente si el puntero no es NULL.
*/

#include <stdio.h>
#include <stdlib.h>

int *crear_estructura_dinamica(int vector[], int ML) {
    int *vector_dinamico, i;

    vector_dinamico = malloc(ML * sizeof(int));

    if (vector_dinamico != NULL) {
        for (i = 0; i < ML; i++) {
            vector_dinamico[i] = vector[i];
        }
    }

    return vector_dinamico;
}

void mostrar_estructura_dinamica(int vector_dinamico[], int ML) {
    int i;
    for (i = 0; i < ML; i++) {
        printf("%d ", vector_dinamico[i]);
    }
    printf("\n");
}

int main() {
    int vec[100] = {4, 8, 23, 25, 18};
    int ml = 5;
    int *vec_dinamico;

    vec_dinamico = crear_estructura_dinamica(vec, ml);
    if (vec_dinamico == NULL) {
        printf("Error, no se ha podido reservar la memoria.\n");
    }
    else {
        mostrar_estructura_dinamica(vec_dinamico, ml);

        free(vec_dinamico);
    }
    
    return 0;
}