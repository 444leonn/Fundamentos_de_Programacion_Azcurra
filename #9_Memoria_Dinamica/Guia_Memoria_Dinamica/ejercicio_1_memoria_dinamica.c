/*
* Escribir un programa el cual reserve memoria dinámica para almacenar un número entero (int), 
* le solicite al usuario el ingreso de un número y se asigna dicho valor en la memoria reservada, 
* luego mostrar dicho valor por pantalla. Liberar la memoria reservada al finalizar el programa.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *entero_dinamico;

    entero_dinamico = malloc(sizeof(int));

    if (entero_dinamico != NULL) {
        printf("Ingrese un entero para guardar en la memoria dinamica.\n");
        printf("Valor:  ");
        scanf("%d", entero_dinamico);

        printf("Entero: %d\n", *entero_dinamico);

        free(entero_dinamico);
    }
    else {
        printf("Error, no se ha podido reservar la memoria.\n");
    }     
    
    return 0;    
}