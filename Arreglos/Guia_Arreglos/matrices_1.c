/*
* Dada una matriz de 3x4, escribir un programa que permita cargar sus datos y luego mostrarlos.
*/

#include <stdio.h>
#define FILAS 3
#define COLUMNAS 4
typedef int T_Mat[FILAS][COLUMNAS];

void cargar_matriz(T_Mat matriz) {
    int i, j;

    printf("Ingrese los valores a almacenar en la matriz.\n");
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            printf("Posicion[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrar_matriz(T_Mat matriz) {
    int i, j;

    printf("Matriz: \n");
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    T_Mat matriz_3x4_enteros;
    int i, j;

    cargar_matriz(matriz_3x4_enteros);
    mostrar_matriz(matriz_3x4_enteros);

    return 0;
}