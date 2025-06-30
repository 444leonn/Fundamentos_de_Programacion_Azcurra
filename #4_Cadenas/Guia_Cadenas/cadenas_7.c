/*
* Escribir una función en C, que reciba una cadena que representa una palabra y  devuelva si la misma es o no un palíndromo.
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

#define MAX 15

typedef char T_Cadena[MAX];

void ingresar_cadena(T_Cadena cadena) {
    printf("Ingrese una cadena: ");
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] =  '\0';
}

void invertir_cadena(T_Cadena cadena, T_Cadena cadena_aux) {
    int i, j = 0;

    for (i = strlen(cadena) - 1; i >= 0; i--) {
        cadena_aux[j] = cadena[i];
        j++;
    }
    cadena_aux[j] = '\0';
}

bool det_palindromo(const T_Cadena cadena, const T_Cadena cadena_aux) {
    bool es_palindromo = true;
    int i = 0;

    while ((cadena[i] != '\0' && cadena_aux[i] != '\0') && es_palindromo) {
        if (cadena[i] != cadena_aux[i]) {
            es_palindromo = false;
        }
        i++;
    }

    return es_palindromo;
}

int main() {
    T_Cadena cadena_palindromo;
    T_Cadena cadena_invertida;

    ingresar_cadena(cadena_palindromo);

    invertir_cadena(cadena_palindromo, cadena_invertida);

    if (det_palindromo(cadena_palindromo, cadena_invertida)) {
        printf("La palabra es palindromo.\n");
    }
    else {
        printf("La palabra NO es palindromo.\n");
    }

    return 0;
}