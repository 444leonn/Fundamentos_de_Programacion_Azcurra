/*
* Desarrollar una función recursiva que invierta una cadena de caracteres (string).
*/

#include <stdio.h>

void invertir_recursivo(char cadena[], int inicio, int fin) {
    if (inicio >= fin)
        return;

    char temp = cadena[inicio];
    cadena[inicio] = cadena[fin];
    cadena[fin] = temp;

    invertir_recursivo(cadena, inicio + 1, fin - 1);
}

int main() {
    char hola_mundo[11] = "hola mundo";
    int ini = 0;
    int fin = 9;  // El último índice real es el largo - 1 (10 - 1 = 9)

    invertir_recursivo(hola_mundo, ini, fin);

    printf("\nCadena Invertida:  %s\n\n", hola_mundo);
    
    return 0;
}