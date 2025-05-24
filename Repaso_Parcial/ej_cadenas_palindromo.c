/*
* Escribir una función en C, que reciba una cadena que representa una palabra y devuelva si la misma es o no un palíndromo.
* Una palabra es un palíndromo, si se lee igual en ambos sentidos.
* Probar la función con los siguientes casos de prueba:
*   - anilina (Es palíndromo)
*   - ojo (Es palíndromo)
*   - radar (Es palíndromo)
*   - reconocer (Es palíndromo)
*   - algoritmos (No es palíndromo)
*   - programas (No es palíndromo)
* Evitar realizar ciclos innecesarios.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 25

typedef char T_Str[MAX];

void ingresar_palabra(T_Str cadena) {
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
}

bool det_palindromo(T_Str cadena) {
    T_Str cadena_invertida; 
    int i, long_cadena = strlen(cadena);

    cadena_invertida[long_cadena] = '\0';

    for (i = 0; i < long_cadena; i++) {
        cadena_invertida[i] = cadena[long_cadena - i - 1];
    }

    return strcmp(cadena, cadena_invertida) == 0;
}

void informe(T_Str cadena) {
    if (det_palindromo(cadena))
        printf("La palabra: \"%s\" es palindromo.\n", cadena);
    else
        printf("La palabra: \"%s\" NO es palindromo.\n", cadena);
} 

int main() {
    T_Str palabra;

    printf("Ingrese una palabra: ");
    ingresar_palabra(palabra);

    informe(palabra);

    return 0;
}