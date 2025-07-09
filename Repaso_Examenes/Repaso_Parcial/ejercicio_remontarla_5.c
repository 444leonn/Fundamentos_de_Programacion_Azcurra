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
#include <stdbool.h>

#define MAX 5

typedef int T_Mat[MAX][MAX];

void cargar_matriz(T_Mat matriz) {
    int i, j;

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("Posicion [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\n");
}

void mostrar_matriz(T_Mat matriz) {
    int i, j;

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int sumatoria_elementos(T_Mat matriz) {
    int i, j, sumatoria = 0;

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            sumatoria += matriz[i][j];
        }
    }

    return sumatoria;
}

int sumatoria_diag_princ(T_Mat matriz) {
    int i, sumatoria = 0;

    for (i = 0; i < MAX; i++) {
        sumatoria += matriz[i][i];
    }

    return sumatoria;
}

int sumatoria_diag_sec(T_Mat matriz) {
    int i, sumatoria = 0, ult_pos = MAX - 1;

    for (i = 0; i < MAX; i++) {
        sumatoria += matriz[ult_pos - i][i];
    }

    return sumatoria;
}

int sumatoria_triangulo_sup(T_Mat matriz) {
    int i, j, sumatoria = 0;

    for (i = 0; i < MAX - 1; i++) {
        for (j = i + 1; j < MAX; j++) {
            sumatoria += matriz[i][j];
        }
    }
    
    return sumatoria;
}

int sumatoria_triangulo_inf(T_Mat matriz) {
    int i, j, sumatoria = 0;

    for (i = 1; i < MAX; i++) {
        for (j = 0; j < i; j++) {
            sumatoria += matriz[i][j];
        }
    }
    
    return sumatoria;
}

bool det_diagonal(T_Mat matriz) {
    bool es_diagonal = true;

    int i, j, sumatoria = 0;

    i = 0;
    while (i < MAX - 1 && es_diagonal) {
        j = i + 1;
        while (j < MAX && es_diagonal) {
            if (matriz[i][j] != 0) {
                es_diagonal = false;
            }
            j++;
        }
        i++;
    } 

    i = 1;
    while (i < MAX && es_diagonal) {
        j = 0;
        while(j < i && es_diagonal) {
            if (matriz[i][j] != 0) {
                es_diagonal = false;
            }
            j++;
        }
        i++;
    }

    
    return es_diagonal;
}

void informe_diagonal(T_Mat matriz) {
    if (det_diagonal(matriz)) {
        printf("La matriz es diagonal.\n");
    }
    else {
        printf("La matriz no es diagonal.\n");
    }
}


int main() {
    T_Mat matriz_cuadrada;

    printf("Cargue la matriz.\n");
    cargar_matriz(matriz_cuadrada);

    mostrar_matriz(matriz_cuadrada);
    
    //printf("La sumatoria de los elementos de la matriz da: %d.\n", sumatoria_elementos(matriz_cuadrada));

    //printf("La sumatoria de los elementos de la diagonal principal da: %d.\n", sumatoria_diag_princ(matriz_cuadrada));

    printf("La sumatoria de los elementos de la diagonal secundaria da: %d.\n", sumatoria_diag_sec(matriz_cuadrada));

    //printf("La sumatoria de los elementos del triangulo superior da: %d.\n", sumatoria_triangulo_sup(matriz_cuadrada));

    //printf("La sumatoria de los elementos del triangulo inferior da: %d.\n", sumatoria_triangulo_inf(matriz_cuadrada));

    //informe_diagonal(matriz_cuadrada);

    return 0;
}