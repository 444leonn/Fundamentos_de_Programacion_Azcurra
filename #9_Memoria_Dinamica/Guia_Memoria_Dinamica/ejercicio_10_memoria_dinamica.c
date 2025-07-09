/*
* Utilizar memoria dinámica para almacenar una cierta cantidad de n palabras ingresadas por el usuario.
* Crear una estructura de datos dinámica de dos dimensiones que permita almacenar esta información.
* Mostrar toda la información de la estructura luego de haber sido cargada.
* Liberar toda la memoria al finalizar el programa.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

typedef char T_String[MAX];

void ingresar_n(int *numero) {
    printf("Ingrese la cantidad de palabras:  ");
    scanf("%d", numero);
}

void ingresar_palabras(char **palabras, int cantidad) {
    int i;
    char buffer[MAX];
    
    printf("Ingrese las palabras:\n");
    for (i = 0; i < cantidad; i++) {
        printf("Palabra %d: ", i + 1);
        scanf("%s", buffer);
        
        // Reservar memoria para cada palabra
        palabras[i] = malloc((strlen(buffer) + 1) * sizeof(char));
        if (palabras[i] != NULL) {
            strcpy(palabras[i], buffer);
        } else {
            printf("Error: No se pudo reservar memoria para la palabra %d\n", i + 1);
        }
    }
}

void mostrar_palabras(char **palabras, int cantidad) {
    int i;
    printf("\nPalabras ingresadas:\n");
    for (i = 0; i < cantidad; i++) {
        if (palabras[i] != NULL) {
            printf("Palabra %d: %s\n", i + 1, palabras[i]);
        }
    }
}

void liberar_memoria(char **palabras, int cantidad) {
    int i;
    for (i = 0; i < cantidad; i++) {
        if (palabras[i] != NULL) {
            free(palabras[i]);
        }
    }
    free(palabras);
}

int main() {
    int num_n;
    char **palabras = NULL;

    ingresar_n(&num_n);

    palabras = malloc(num_n * sizeof(char*));   
    if (palabras != NULL) {
        ingresar_palabras(palabras, num_n);

        mostrar_palabras(palabras, num_n);

        liberar_memoria(palabras, num_n);
    } 
    else {
        printf("Error, no se pudo reservar memoria para el array de palabras.\n");
    }
    
    return 0;
}