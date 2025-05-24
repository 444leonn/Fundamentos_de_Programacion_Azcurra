/*
* Escribir una función que reciba como parámetro una cadena de caracteres y devuelva la cantidad de dígitos numéricos que hay en la cadena
*/

#include <stdio.h>
#include <string.h>
#define MAX 30
typedef char T_Cadena[MAX];

int contar_digitos(T_Cadena cadena) {
    int cant_digitos = 0;
    int i = 0;
    char caracter = cadena[i];

    while (caracter != '\0') {
        if (caracter >= '0' && caracter <= '9') {
            cant_digitos++;
        }
        i++;
        caracter = cadena[i];
    }

    return cant_digitos;
}

int main() {
    T_Cadena cadena_con_digitos;

    printf("Ingrese una cadena: ");
    fgets(cadena_con_digitos, MAX, stdin);
    cadena_con_digitos[strcspn(cadena_con_digitos, "\n")] = '\0';

    printf("La cantidad de digitos en la cadena \"%s\" es: %d\n", cadena_con_digitos, contar_digitos(cadena_con_digitos));
    
    return 0;
}
