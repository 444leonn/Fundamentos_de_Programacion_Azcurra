#include <stdio.h>
#define MAX 15

int main() {
    char cadena[MAX] = "Hola Mundo";
    int i;

    printf("Cadena: %s\n", cadena); // Muestro la Cadena


    // Muestro TODOS los caracteres
    for (i = 0; i < MAX; i++) {
        printf("Caracter en la posicion %d: %c\n", i, cadena[i]);
    }

    printf("\n");
    
    // Muestro SOLO los caracteres almacenados
    i = 0;
    while (cadena[i] != '\0') {
        printf("Caracter en la posicion %d: %c\n", i, cadena[i]);
        i++;
    }

    printf("\n");    

    printf("Espacio total de la cadena: %ld\n", sizeof(cadena));

    // Modifico Valores de la cadena.
    cadena[0] = 'X';
    cadena[5] = 'X';
    cadena[8] = 'X';

    printf("Cadena Modificada: %s\n", cadena);
    
    return 0;
}