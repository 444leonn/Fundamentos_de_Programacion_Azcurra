/*
* Escribir un programa modular que solicite el ingreso de dos palabras y luego muestre las mismas según la longitud de cada una de ellas,
* mostrando primero la de menor longitud.
* A igualdad de longitud, mostrar primero la menor de las dos, en términos de orden alfabético.
* Las palabras tienen una longitud máxima de 15 caracteres.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 25

typedef char T_Str[MAX];

void ingresar_palabra(T_Str palabra) {
    fgets(palabra, MAX, stdin);
    palabra[strcspn(palabra, "\n")] = '\0';
}

bool primera_mas_larga(T_Str prim_palabra, T_Str seg_palabra) {
    int long_prim = strlen(prim_palabra);
    int long_seg = strlen(seg_palabra);

    return long_prim > long_seg;
}

bool longitudes_iguales(T_Str prim_palabra, T_Str seg_palabra) {
    int long_prim = strlen(prim_palabra);
    int long_seg = strlen(seg_palabra);

    return long_prim == long_seg;
}

void mostrar_palabra(T_Str prim_palabra, T_Str seg_palabra) {
    if (primera_mas_larga(prim_palabra, seg_palabra)) {
        printf("%s\n", seg_palabra);
        printf("%s\n", prim_palabra);
    }
    else if (longitudes_iguales(prim_palabra, seg_palabra)) {
        if (strcmp(prim_palabra, seg_palabra) < 0) {
            printf("%s\n", prim_palabra);
            printf("%s\n", seg_palabra);
        }
        else {
            printf("%s\n", seg_palabra);
            printf("%s\n", prim_palabra);
        }
    }
    else {
        printf("%s\n", prim_palabra);
        printf("%s\n", seg_palabra);
    }
}

int main() {
    T_Str palabra_1, palabra_2;

    printf("Ingrese una palabra: ");
    ingresar_palabra(palabra_1);

    printf("Ingrese otra palabra: ");
    ingresar_palabra(palabra_2);

    mostrar_palabra(palabra_1, palabra_2);
    
    return 0;
}