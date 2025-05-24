/*
 * Escribir un programa que dada una matriz de números reales, de n x m, devuelva un vector que en cada posición i almacene el elemento mínimo de cada fila i de la matriz.
 * */

#include <stdio.h>
#define MAX 3
typedef float T_Mat[MAX][MAX];
typedef float T_Vec[MAX];

void cargar_matriz(T_Mat matriz) {
  int i, j;

  for (i = 0; i < MAX; i++) {
    for (j = 0; j < MAX; j++) {
      printf("Ingrese valor posicion[%d][%d]: ", i, j);
      scanf("%f", &matriz[i][j]);
    }
  }
}

void calc_minimos(T_Mat matriz, T_Vec vector) {
  int i, j;
  float valor_minimo;

  for (i = 0; i < MAX; i++) {
    valor_minimo = matriz[i][0];

    for (j = 1; j < MAX; j++) {
      if (matriz[i][j] < valor_minimo) {
        valor_minimo = matriz[i][j];
      }
  
      vector[i] = valor_minimo;
    }
  }
}

void mostrar_vector(T_Vec vector) {
  int i;

  for (i = 0; i < MAX; i++) {
    printf("%.2f ", vector[i]);
  }
  printf("\n");
}

int main() {
  T_Mat matriz_reales;
  T_Vec vector_minimos;

  cargar_matriz(matriz_reales);
  calc_minimos(matriz_reales, vector_minimos);

  printf("El vector de los valores minimos es: \n");
  mostrar_vector(vector_minimos);

  return 0;
}
