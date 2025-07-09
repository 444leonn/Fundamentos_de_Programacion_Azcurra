/*
* Reservar memoria para almacenar una palabra ingresada por el usuario, es leída en una cadena auxiliar,
* luego copiada a memoria dinámica, recordando que se requiere adicionar un carácter de fin de cadena '\n'.
* Ejemplo:
*     "hola mundo" + '\0' -> requiere espacio para 11 caracteres.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

typedef char T_String[MAX];

void ingresar_cadena(T_String cadena) {
    printf("Ingrese una cadena: ");
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
}

void copiar_cadena(T_String cadena_ingresada, char cadena_copiada[]) {
    int i = 0;

    while (cadena_ingresada[i] != '\0') {
        cadena_copiada[i] = cadena_ingresada[i];

        i++;
    }

    cadena_copiada[i] = cadena_ingresada[i];
}

int main() {
    T_String str_ingresado;
    char *str_dinamico = NULL;
    int tamanio;

    ingresar_cadena(str_ingresado);

    tamanio = strlen(str_ingresado) + 1;

    str_dinamico = malloc(tamanio * sizeof(char));
    if (str_dinamico != NULL) {
        copiar_cadena(str_ingresado, str_dinamico);

        printf("\nCadena original ingresada:  \"%s\"\n", str_ingresado);
        printf("\nCadena copiada en memoria dinamica: \"%s\"\n", str_dinamico);
        
        free(str_dinamico);
    }
    else {
        printf("Error, no se ha podido reservar la memoria.\n");
    }

    return 0;
}