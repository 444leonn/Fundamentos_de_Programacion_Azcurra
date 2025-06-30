/*
* a) Escribir un programa modular (compuesto por funciones) en donde el usuario deba cargar una matriz de números reales, de n x m.
* Las dimensiones se le solicitarán al usuario al inicio, validar que estén dentro del rango [1-10].
* Luego de la carga de la matriz el programa debe completar un vector de dimensión n para que en cada posición i del mismo se almacene el elemento mínimo de cada fila i de la matriz.
* Por ultimo se debe mostrar el promedio de los elementos de dicho vector.
* Considerar un máximo físico de 10, por lo que n y m deben ser menores o igual a dicho número.
* Ejemplo:
*     n = 3
*     m = 4
*     matriz = [
*         [23.5, 45.7, 2.34, 50.3],
*         [32.1, 6.78, 10.11, 42.1],
*         [45.6, 4.6, 34.21, 76.4],
*     ]
*     vector = [2.34, 6.78, 4.6] (contiene los menores elementos de cada fila)
*     promedio de los elementos del vector = 4.57
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 10
#define MIN 1
typedef float T_Mat[MAX][MAX];
typedef float T_Vec[MAX];

void ingreso_dimension_valida(int *numero) {
    printf("Ingrese un valor entero positivo entre 1-10: ");
    scanf("%d", numero);
    while (*numero > MAX || *numero < MIN) {
        printf("Numero fuera de rango.\n");
        printf("Ingrese un valor entero positivo entre 1-10: ");
        scanf("%d", numero);
    }
}

void carga_matriz(T_Mat matriz, int filas, int columnas) {
    int i, j;

    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            printf("Ingrese el valor de matriz[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        }
    }
}

void completa_vector(T_Mat matriz, T_Vec vector, int filas, int columnas) {
    int i, j;
    float valor_min;

    for (i = 0; i < filas; i++) {
        valor_min = matriz[i][0];

        for (j = 1; j < columnas; j++) {
            if (matriz[i][j] < valor_min) {
                valor_min = matriz[i][j];
            }
        }
        vector[i] = valor_min;
    }
}

float calcula_promedio(T_Vec vector, int elementos) {
    int i;
    float valores_vector = 0;

    for (i = 0; i < elementos; i++) {
        valores_vector += vector[i];
    }

    return valores_vector / i; 
}

int main() {
    int num_n, num_m;
    T_Mat matriz_reales;
    T_Vec vector_minimos;
    
    printf("Debe ingresar las dimensiones (n x m) de la matriz a cargar.\n");

    printf("Primero debe ingresar N\n");
    ingreso_dimension_valida(&num_n);

    printf("Primero debe ingresar M\n");
    ingreso_dimension_valida(&num_m);

    carga_matriz(matriz_reales, num_n, num_m);
    completa_vector(matriz_reales, vector_minimos, num_n, num_m);

    printf("El promedio de los elementos menores de cada fila es: %.2f\n", calcula_promedio(vector_minimos, num_n));

    return 0;
}