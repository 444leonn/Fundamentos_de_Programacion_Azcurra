/*
* Escribir un programa el cual reserve memoria dinámica para almacenar una cierta cantidad de números enteros (n * int),
* este valor n debe ser ingresado por el usuario. 
* Luego solicitarle que ingresé n valores enteros ingresados de a uno y almacenarlos en la memoria previamente reservada. 
* Mostrar luego todos los valores ingresados.
* Liberar la memoria reservada al finalizar el programa.
*/

#include <stdio.h>
#include <stdlib.h>

void ingresar_n(int *numero_n) {
    printf("Ingrese la cantidad N de enteros a reservar:  ");
    scanf("%d", numero_n);
}

void ingresar_valores(int vector[], int MAX) {
    int i;
    for (i = 0; i < MAX; i++) {
        printf("Ingrese el valor %d:   ", i);
        scanf("%d", &vector[i]);
    }
}

void mostrar_valores(int vector[], int MAX) {
    int i;
    for (i = 0; i < MAX; i++) {
        printf("Vector[%d]:  %d.\n", i, vector[i]);
    }
}

int main() {
    int num_n, *vec_enteros = NULL;

    ingresar_n(&num_n);

    vec_enteros = malloc(num_n * sizeof(int));
    if (vec_enteros != NULL ) {
        ingresar_valores(vec_enteros, num_n);

        mostrar_valores(vec_enteros, num_n);

        free(vec_enteros);
    }
    else {
        printf("Error no se ha podido reservar la memoria.\n");
    }
    
    return 0;
}
