/*
* Dada una matriz cuadrada de 5x5 cargada por el usuario con números enteros, escribir un programa modular que muestre:
*     a)​ Todos los elementos de la matriz.
*     b)​ La suma de todos los elementos de la matriz.
*     c)​ La suma de la diagonal principal.
*     d)​ La suma de la diagonal secundaria.
*     e)​ La suma de los elementos del triángulo superior.
*     f)​ La suma de los elementos del triángulo inferior.
*     g)​ Si es una matriz diagonal (todos los elementos por fuera de la diagonal principal son igual a cero)
* Cada módulo debe optimizar la cantidad de iteraciones a realizar.
*/

#include <stdio.h>
#define FILAS 5
#define COLUMNAS 5
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

int sumar_elementos_matriz(T_Mat matriz) {
    int i, j;
    int sumatoria = 0;

    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            sumatoria += matriz[i][j];
        }
    }

    return sumatoria;
}

int suma_diagonal_princ(T_Mat matriz) {
    int i;
    int sumatoria = 0;

    for (i = 0; i < FILAS; i++) {
        sumatoria += matriz[i][i];
    }
    
    return sumatoria;
}

int suma_diagonal_sec(T_Mat matriz) {
    int i;
    int sumatoria = 0, colum = 4;

    for (i = 0; i < FILAS; i++) {
        sumatoria += matriz[i][colum - i];
    }

    return sumatoria;
}

int suma_triangulo_sup(T_Mat matriz) {
    int i, j;
    int sumatoria = 0; 

    for (i = 0; i < FILAS; i++) {
        for (j = i + 1; j < COLUMNAS; j++) {
            sumatoria += matriz[i][j];
        }
    }

    return sumatoria;
}

int suma_triangulo_inf(T_Mat matriz) {
    int i, j;
    int sumatoria = 0; 

    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < i; j++) {
            sumatoria += matriz[i][j];
        }
    }

    return sumatoria;
}

int main() {
    T_Mat matriz_5x5;

    cargar_matriz(matriz_5x5);
    mostrar_matriz(matriz_5x5);

    printf("La suma de todos los elementos de la matriz da: %d\n", sumar_elementos_matriz(matriz_5x5));
    printf("La suma de los elementos de la diagonal principal da: %d\n", suma_diagonal_princ(matriz_5x5));
    printf("La suma de los elementos de la diagonal secundaria da: %d\n", suma_diagonal_sec(matriz_5x5));
    printf("La suma de los elementos del triangulo superior da: %d\n", suma_triangulo_sup(matriz_5x5));
    printf("La suma de los elementos del triangulo inferior da: %d\n", suma_triangulo_inf(matriz_5x5));
 
    return 0;
}