/*
* - Escribir una funcion llamada `crear_estructura_dinamica` que reciba un arreglo unidimensional de elementos enteros ya cargado, y su respectivo maximo logico.
* La funcion debe devolver un puntero a una estructura dinamica que contenga los elementos del arreglo recibido y utilice solo el espacio de memoria necesario.
* Escribir un main que:
*   - Invoque a la funcion utilizando como arreglo la siguiente declaracion: `int vector[100] = {48, 23, 2, 5, 18};`
*   - Haga una llamada a la funcion `mostrar_estructura_dinamica` a la que se le debe pasar la estructura y la correspondiente cantidad de elementos a mostrar. 
* No tenes que desarrollar esta funcion, solo utilizarla adecuadamente.
* Solo se puede invocar esta funcion si el puntero no es nulo.
*/

#include <stdio.h>
#include <stdlib.h>

int *crear_estructura_dinamica(int vector[], int ML) {
    int i;
    int *vector_dinamico;

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
}

int main() {
    int vector[100] = {48, 23, 2, 5, 18};
    int ml = 5;
    int *vec_dinamico = crear_estructura_dinamica(vector, ml);

    if (vec_dinamico == NULL) {
        printf("Error, no se ha podido reservar la memoria.\n");
    }
    else {
        mostrar_estructura_dinamica(vec_dinamico, ml);

        free(vec_dinamico);
    }
    
    return 0;
}