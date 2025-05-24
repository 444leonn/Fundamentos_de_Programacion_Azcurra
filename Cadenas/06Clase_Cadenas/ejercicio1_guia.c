/*
* Escribir una función que reciba como parámetro una cadena de caracteres y devuelva la cantidad de dígitos numéricos que hay en la cadena.
*/

#include <stdio.h>
#include <string.h>
#define MAX 20

void solicitar_cadena(char *cadena) {
    fgets(cadena, MAX, stdin);
}

int contar_digitos(char cadena[MAX]) {
    int i = 0, cant = 0;
    while (cadena[i] != '\0') {
        if (cadena[i] >= '0' && cadena[i] <= '9') {
            cant++;
        }
        i++;
    }

    return cant;
}

int main() {
    char cadena_con_digitos[MAX];

    printf("Ingrese una cadena de maximo %d caracteres: ", MAX);
    solicitar_cadena(cadena_con_digitos);

    printf("Cantidad de digitos numericos: %d\n", contar_digitos(cadena_con_digitos));

    return 0;
}