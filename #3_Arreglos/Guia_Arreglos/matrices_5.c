/*
* Dadas dos matrices A y B cuadradas de igual dimensión, tales que A ∈ R n×n y B ∈ R n×n,
* escribir un programa que permita cargar su dimensión y sus datos.
* El programa debe sumarlas y mostrar la matriz resultante.
* Para la estructura de datos considere un tamaño máximo de 10 (1 <= n <= 10).
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 10
#define MIN 1
typedef int T_Mat[10][10];

void carga_dimension(int *numero) {
  printf("Numero N: ");
  scanf("%d", numero);
}

bool dimension_invalida(int numero) {
  bool no_valida = false;
  if (numero < MIN || numero > MAX) {
    printf("Dimension no valida.\n");
    no_valida = true;
  }

  return no_valida;
}

void ingreso_datos(T_Mat matriz, int numero) {
  int i, j;

  for (i = 0; i < numero; i++) {
    for (j = 0; j < numero; j++) {
      printf("Posicion[%d][%d]: ", i + 1, j + 1);
      scanf("%d", &matriz[i][j]);
    }
  }
}

void calculo_resultante(T_Mat matriz_1, T_Mat matriz_2, T_Mat matriz_3, int numero) {
  int i, j;

  for (i = 0; i < numero; i++) {
    for (j = 0; j < numero; j++) {
      matriz_3[i][j] = 0;
      matriz_3[i][j] = matriz_1[i][j] + matriz_2[i][j];
    }
  }
}

void mostrar_matriz(T_Mat matriz, int numero) {
  int i, j;

  for (i = 0; i < numero; i++) {
    for (j = 0; j < numero; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

int main() {
  T_Mat matriz_A, matriz_B, matriz_resultante;
  int dimension_n;
  
  printf("Ingrese la dimension para dos matrices cuadradas nxn.\n");
  carga_dimension(&dimension_n);
  while (dimension_invalida(dimension_n)) {
    carga_dimension(&dimension_n);
  }

  printf("Ingrese los datos de la matriz A.\n");
  ingreso_datos(matriz_A, dimension_n);

  printf("Ingreso los datos de la matriz B.\n");
  ingreso_datos(matriz_B, dimension_n);

  calculo_resultante(matriz_A, matriz_B, matriz_resultante, dimension_n);

  mostrar_matriz(matriz_resultante, dimension_n);

  return 0;
}
