/*
* Escribir un programa modular en C, que solicite el ingreso de no más de 20 palabras. Cada palabra no tendrá más de 20 caracteres.
* Informar:
*   1. Mostrar las palabras ingresadas.
*   2. Cuál es la palabra más larga.
*   3. Solictar el ingreso de una palabra, e indicar si la misma se encuentra entre las ingresadas.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define LARGO_CADENA 21
#define CANTIDAD_CADENAS 20
typedef char T_Palabra[LARGO_CADENA];
typedef T_Palabra T_Cadenas[CANTIDAD_CADENAS];

void ingresar_palabras(T_Cadenas vector) {
    int i;

    for (i = 0; i < CANTIDAD_CADENAS; i++) {
        printf("Ingrese la palabra %d: ", i + 1);
        fgets(vector[i], LARGO_CADENA, stdin);
        vector[i][strcspn(vector[i], "\n")] = '\0';
    }
}

void mostrar_palabras(T_Cadenas vector) {
    int i;

    for (i = 0; i < CANTIDAD_CADENAS; i++) {
        printf("%s", vector[i]);
    }
}

int main() {
    T_Cadenas vector_palabras;

    ingresar_palabras(vector_palabras);
    mostrar_palabras(vector_palabras);

    return 0;
}