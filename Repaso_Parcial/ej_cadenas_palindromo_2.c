/*
* Escribir una función en C, que reciba una cadena que representa una palabra o una frase y devuelva si la misma es o no un palíndromo.
* Un palíndromo, es una palabra o frase que se lee igual en ambos sentidos.
* Probar la función con los siguientes casos de prueba:
* - anilina (Es palíndromo)
* - ojo (Es palíndromo)
* - radar (Es palíndromo)
* - reconocer (Es palíndromo)
* - amar a roma (Es palíndromo)
* - ana lava lana (Es palíndromo)
* - a ti no, bonita (Es palíndromo)
* - algoritmos y programas (No es palíndromo)
* - lenguaje C (No es palíndromo)
* Evitar realizar ciclos innecesarios.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 50

typedef char T_Str[MAX];

void ingresar_frase(T_Str cadena){
    fgets(cadena, MAX, stdin);

    cadena[strcspn(cadena, "\n")] = '\0';
}

bool es_caracter(char caracter) {
    return (caracter >= 'a' && caracter <= 'z');
}

bool det_palindromo(T_Str cadena) {
    T_Str cadena_invertida, cadena_limpia;
    int i, j, k, long_cadena = strlen(cadena);

    j = 0;
    for (i = 0; i < long_cadena; i++) {
        if (es_caracter(cadena[i])) {
            cadena_limpia[j] = cadena[i];
            j++;
        }
    }
    cadena_limpia[j] = '\0';

    for (k = 0; k < j; k++) {
        cadena_invertida[k] = cadena_limpia[j - k - 1];
    }
    cadena_invertida[k] = '\0';

    return strcmp(cadena_limpia, cadena_invertida) == 0;
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
    ingresar_frase(palabra);

    informe(palabra);

    return 0;
}