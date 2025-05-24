/*
* Ejercicios Propuestos
* Modificar el programa del ejemplo para: 
*   a) Permitir al usuario el ingreso de valores en la matriz.
*   b) Calcule la suma de los valores de la diagonal principal.
*   c) Calcule los valores de la suma de la diagonal secundaria.
*   d) Declarar un vector auxiliar y guardar en el la suma de los elementos de cada fila de la matriz
*/

#include <stdio.h>

void imprimir_matriz(int matriz[3][3], int filas, int columnas) {
    int i, j;
    for (i = 0; i < filas;  i++) {
        for (j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void imprimir_vector(int vector[3], int elementos_vector) {
    int i; 
    for (i = 0; i < elementos_vector; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void ingreso_valores_matriz(int matriz[3][3], int filas, int columnas) {
    int i, j;

    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            printf("Ingrese el valor de a guardar en el indice [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

int suma_diagonal_principal(int matriz[3][3], int dimension) {
    int i, resultado = 0;

    for (i = 0; i < dimension; i++) {
        resultado += matriz[i][i];
    }

    return resultado;
}

int suma_diagonal_secundaria(int matriz[3][3], int dimension) {
    int i, j, resultado = 0;

    for (i = 0; i < dimension; i++) {
        resultado += matriz[i][dimension - i - 1];
        }

    return resultado;
}

int suma_elementos_fila(int matriz[3][3], int filas, int columnas, int vector[3]) {
    int i, j, resultado ;

    for (i = 0; i < filas; i++) {
        resultado = 0;
        for (j = 0; j < columnas; j++) {
            resultado += matriz[i][j];
        }
        vector[i] = resultado;
    }
}

int main() {
    int matriz_main[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int resultado_diagonal_princ, resultado_diagonal_sec;
    int vector_auxiliar[3];

    printf("Matriz: \n");
    imprimir_matriz(matriz_main, 3, 3);

    ingreso_valores_matriz(matriz_main, 3, 3);
    printf("Matriz Modificada. \n");
    imprimir_matriz(matriz_main, 3, 3);

    resultado_diagonal_princ = suma_diagonal_principal(matriz_main, 3);
    printf("El resultado de la suma de los valores de la diagonal principal de la matriz es: %d.\n", resultado_diagonal_princ);

    resultado_diagonal_sec = suma_diagonal_secundaria(matriz_main, 3);
    printf("El resultado de la suma de la diagonal secundaria: %d.\n", resultado_diagonal_sec);

    suma_elementos_fila(matriz_main, 3, 3, vector_auxiliar);
    printf("El vector con la suma de los elementos es: ");
    imprimir_vector(vector_auxiliar, 3);
    
    return 0;
}