/*
* Solicitar al usuario una palabra, reservar memoria dinámica justa, copiar la palabra, mostrarla y liberar la memoria.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR 200

void ingresar_palabra(char palabra[MAX_STR]) {
    printf("Ingrese una palabra: ");
    fgets(palabra, MAX_STR, stdin);
    palabra[strcspn(palabra, "\n")] = '\0';
}

char *reservar_memoria(char palabra[MAX_STR]) {
    return malloc((strlen(palabra) + 1) * sizeof(char));
}

int main() {
    char palabra_ingresada[MAX_STR];
    char *palabra_dinamica;

    ingresar_palabra(palabra_ingresada);

    palabra_dinamica = reservar_memoria(palabra_ingresada);
    if (palabra_dinamica == NULL) {
        printf("Error, no se ha podido reservar la memoria.\n");
    }
    else {
        strcpy(palabra_dinamica, palabra_ingresada);
        printf("Palabra reservada en memoria dinamica: %s\n\n", palabra_dinamica);

        free(palabra_dinamica);
    }

    return 0;
}