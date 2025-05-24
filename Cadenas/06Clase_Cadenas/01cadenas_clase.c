/*
* Escribir un programa en C, que:
* - declare una cadena para almacenar como máximo 40 caracteres y como valor inicial le asigne tu nombre y apellido
* - recorra la cadena e imprima sólo las consonantes, una debajo de la otra
* - indique cuantas consonantes hay en tu nombre y apellido
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 40

bool det_caracteres(char caracter) {
    bool es_letra = false;

    if ((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <='z')) {
        es_letra = true;
    }

    return es_letra;
}

bool evalua_vocales(char caracter) {
    bool no_es_vocal = false;

    if (caracter != 'A' && caracter != 'E' && caracter != 'I' && caracter != 'O' && caracter != 'U' && caracter != 'a' && caracter != 'e' && caracter != 'i' && caracter != 'o' && caracter != 'u') {
       no_es_vocal = true;
    }

    return no_es_vocal;
}

int main() {
    char cadena[MAX] = "Leon Acosta", caracter;
    int i = 0, consonantes = 0;

    caracter = cadena[i];
    while (caracter != '\0') {
        caracter = cadena[i];
        if (det_caracteres(caracter) && evalua_vocales(caracter)) {
            printf("Consonante %d: %c\n", i, caracter);
            consonantes++;
        
        }
        i++;
    }

    printf("Tu nombre y apellido tiene %d consonantes.\n", consonantes);
    
    return 0;
}