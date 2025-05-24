/*
* Escribir una función en C, que reciba una cadena que representa una palabra o una frase y devuelva si la misma es o no un palíndromo.
* Un palíndromo, es una palabra o frase que se lee igual en ambos sentidos.
* Probar la función con los siguientes casos de prueba:
*     - anilina (Es palíndromo)
*     - ojo (Es palíndromo)
*     - radar (Es palíndromo)
*     - reconocer (Es palíndromo)
*     - amar a roma (Es palíndromo)
*     - ana lava lana (Es palíndromo)
*     - a ti no, bonita (Es palíndromo)
*     - algoritmos y programas (No es palíndromo)
*     - lenguaje C (No es palíndromo)
* Evitar realizar ciclos innecesarios.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 35
#define NUMEROS "0123456789"

typedef char T_Cadena[MAX];

void ingresar_cadena(T_Cadena cadena) {
    printf("Ingrese una cadena: ");
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] =  '\0';
}

void invertir_cadena(T_Cadena cadena, T_Cadena cadena_aux) {
    int i, j = 0;

    for (i = strlen(cadena) - 1; i >= 0; i--) {
        if (cadena[i] != ' ') {
            cadena_aux[j] = cadena[i];
            j++;
        }
    }
    cadena_aux[j] = '\0';
}

bool es_alfabetico(char caracter) {
    return ((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z'));
}

bool es_numerico(char digito) {
    char strchar[] = {digito, '\0'};
    return strstr(NUMEROS, strchar) != NULL;
}

bool det_palindromo(const T_Cadena cadena, const T_Cadena cadena_aux) {
    bool es_palindromo = true;
    int i = 0, j = 0;

    while (cadena[i] != '\0' && es_palindromo) {
        if ((! es_alfabetico(cadena[i])) && (! es_numerico(cadena[i]))) {
            i++;
        }
        else if (cadena[i] != cadena_aux[j]) {
            es_palindromo = false;
        }
        i++;
        j++;
    }
    
    return es_palindromo;
}

int main() {
    T_Cadena cadena, cadena_invertida;

    ingresar_cadena(cadena);

    invertir_cadena(cadena, cadena_invertida);

    if (det_palindromo(cadena, cadena_invertida)) {
        printf("La frase es palindromo.\n");
    }
    else {
        printf("La frase no es palindromo.\n");
    }

    return 0;
}