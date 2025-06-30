/*
* Escribir una función que reciba como parámetro una cadena de caracteres y devuelva la cantidad de caracteres no alfabéticos que hay en la cadena.
* No tener en cuenta la ñ, ni las vocales acentuadas.
*/

#include <stdio.h>
#include <string.h>
#define MAX 30
typedef char T_String[MAX];

void ingresar_cadena(T_String cadena) {
    printf("Ingrese una cadena: ");
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
}

int contar_no_alfabeticos(T_String cadena) {
    int i = 0, cant = 0;
    char caracter;

    caracter = cadena[i];
    while (caracter != '\0') {
        if (! ((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z')))
            cant++;
        i++;
        caracter = cadena[i];
    }

    return cant;
}

int main() {
    T_String cadena_caracteres;

    ingresar_cadena(cadena_caracteres);

    printf("Cantidad de Caracteres no alfabeticos: %d", contar_no_alfabeticos(cadena_caracteres));

    return 0;
}