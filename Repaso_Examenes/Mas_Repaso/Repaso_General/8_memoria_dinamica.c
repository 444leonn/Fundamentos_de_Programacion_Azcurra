/*
* Solicitar al usuario la cantidad N de enteros a cargar.
* Reservar memoria dinámica, cargar los valores y mostrarlos.
* Liberar la memoria al finalizar.
*/

#include <stdio.h>
#include <stdlib.h>

void ingresar_n(int *numero) {
    printf("Ingrese la cantidad de neteros que desea cargar: ");
    scanf("%d", numero);
}

int *reservar_memoria(int cantidad) {
    return malloc(cantidad * sizeof(int));
}

void cargar_valores(int vector[], int ML) {
    int i;
    for (i = 0; i < ML; i++) {
        printf("Valor %d: ", i);
        scanf("%d", &vector[i]);
    }
}

void mostrar(int vector[], int ML) {
    int i;
    for (i = 0; i < ML; i++) {
        printf("%d ", vector[i]);
    }
}

int main() {
    int num_n;
    int *vec_dinamico;

    ingresar_n(&num_n);

    vec_dinamico = reservar_memoria(num_n);
    if (vec_dinamico == NULL) {
        printf("Error, no se ha podido reservar la memoria.\n");
    }
    else {
        cargar_valores(vec_dinamico, num_n);

        printf("Vector almacenado en memoria dinamica: ");
        mostrar(vec_dinamico, num_n);
        printf("\n");
        
        free(vec_dinamico);
    }
    
    return 0;
}