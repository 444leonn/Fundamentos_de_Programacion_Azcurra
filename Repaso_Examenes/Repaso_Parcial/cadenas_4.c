/*
* Escribir una función en C que reciba como primer parámetro, una cadena de tipot_cadena, y devuelva como segundo parámetro,
* la misma cadena pero invertida, sin considerar los blancos.
* Sólo se deben invertir las posiciones con caracteres ciertos, y no aquellas posiciones potenciales a ser utilizadas pero que podrían contener caracteres inciertos.
* Recorrer la cadena a lo sumo una vez.
* Declare un tipo t_cadena acorde.
*/

#include <stdio.h>
#include <string.h>

#define MAX 25

typedef char T_Str[MAX];

void ingresar_cadena(T_Str cadena) {
    fgets(cadena, MAX, stdin);

    cadena[strcspn(cadena, "\n")] = '\0';
}

void invertir_cadena(T_Str cadena, T_Str cadena_invertida) {
    int long_cadena = strlen(cadena), i, j = 0;

    for (i = long_cadena - 1; i >= 0; i--) {
        if (cadena[i] != ' ') {
            cadena_invertida[j] = cadena[i];
            j++;
        }
    }
    cadena_invertida[j] = '\0';
}

int main() {
    T_Str cadena, cadena_invertida;

    printf("Ingrese una cadena: ");
    ingresar_cadena(cadena);

    invertir_cadena(cadena, cadena_invertida);

    printf("%s\n", cadena_invertida);

    return 0;
}