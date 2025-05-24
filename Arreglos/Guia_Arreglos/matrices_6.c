/*
* Dadas dos matrices A y B, tales que A ∈ R m×n y B ∈ R q×p , escribir un programa que permita cargar sus dimensiones y sus datos.
* El programa debe multiplicarlas (A.B) en caso de ser posible o devolver una señal si la operación no puede realizarse.
* Para la estructura de datos considere un tamaño máximo de 10 (m, n y p pueden tomar valores entre 1 y 10).
* Aclaración: 
*     para multiplicar matrices, la primera matriz debe tener igual columnas que filas tenga la segunda (n = q).
* La matriz resultante será C ∈ R m×p
* Ejemplo:
*     Matrices          Resultado
*     3 2 4   1 2        {29, 38}
*     5 6 7   3 4        {58, 76} 
*             5 6
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 10
#define MIN 1
typedef int T_Mat[MAX][MAX];

void ingreso_dimension(int *filas, int *columnas) {
  printf("Ingrese cantidad de FILAS: ");
  scanf("%d", filas);
  printf("Ingrese cantidad de COLUMNAS: ");
  scanf("%d", columnas);

  while (*filas < MIN || *columnas < MIN || *filas > MAX || *columnas > MAX) {
    printf("Error, valores ingresdos fuera de rango.\n");
    printf("Ingrese cantidad de FILAS: ");
    scanf("%d", filas);
    printf("Ingrese cantidad de COLUMNAS: ");
    scanf("%d", columnas);
  }
}

void cargar_datos(T_Mat matriz, int filas, int columnas) {
  int i, j;

  for (i = 0; i < filas; i++) {
    for (j = 0; j < columnas; j++) {
      printf("Posicion[%d][%d]: ", i + 1, j + 1);
      scanf("%d", &matriz[i][j]);
    }
  }
}

bool multiplicacion_valida(int columnas_matriz_1, int filas_matriz_2) {
  bool es_valida = true;

  if (columnas_matriz_1 != filas_matriz_2) {
    printf("No se puede realizar la multiplicacion de las matrices.\n");
    es_valida = false;
  }

  return es_valida;
}

void calc_multiplicacion(T_Mat matriz_1, T_Mat matriz_2, T_Mat matriz_multiplicada, int numero, int filas, int columnas) {
  int i, j, k;

  for (i = 0; i < filas; i++) {
    for (j = 0; j < columnas; j++) {
      matriz_multiplicada[i][j] = 0;
      for (k = 0; k < numero; k++) {
        matriz_multiplicada[i][j] += matriz_1[i][k] * matriz_2[k][j];
      }
    }
  }
}

void mostrar_matriz(T_Mat matriz, int filas, int columnas) {
  int i, j;

  for (i = 0; i < filas; i++) {
    for (j = 0; j < columnas; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  } 
}

int main() {
  T_Mat matriz_A, matriz_B, matriz_multiplicada;
  int num_m, num_n, num_q, num_p;
  
  printf("Debe ingresar las dimensiones de las matrices. Con valores entre 1 y 10.\n");

  printf("Ingrese la dimension de la primer matriz.\n");
  ingreso_dimension(&num_m, &num_n);

  printf("Ingrese la dimension de la segunda matriz.\n");
  ingreso_dimension(&num_q, &num_p);

  printf("Cargue los datos de la primer matriz.\n");
  cargar_datos(matriz_A, num_m, num_n);

  printf("Cargue los datos de la segunda matriz.\n");
  cargar_datos(matriz_B, num_q, num_p);


  if (multiplicacion_valida(num_n, num_q)) {
    calc_multiplicacion(matriz_A, matriz_B, matriz_multiplicada, num_n, num_m, num_p);
    mostrar_matriz(matriz_multiplicada, num_m, num_p);
  }

  return 0;
}
