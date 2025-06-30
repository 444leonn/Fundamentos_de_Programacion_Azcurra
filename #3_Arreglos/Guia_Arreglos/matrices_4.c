/*
* Escribir un programa modular que dada una matriz del tipo descrito a continuación,
* muestre el menor número que aparece y cuantas veces aparece dicho número en la matriz.
*     #define CANT_FILAS 3
*     #define CANT_COLS 3
*     typedef int matriz_t[CANT_FILAS][CANT_COLS];
* Ejemplo:
*     5   10  14
*     5   5   7
*     8   6   12
* El menor número es 5 y aparece 3 veces.
*/

#include <stdio.h>
#define CANT_FILAS 3
#define CANT_COLS 3
typedef int matriz_t[CANT_FILAS][CANT_COLS];

void ingreso_matriz(matriz_t matriz) {
  int i, j;

  for (i = 0; i < CANT_FILAS; i++) {
    for (j = 0; j < CANT_COLS; j++) {
      printf("Posicion[%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }
}

int calc_menor(matriz_t matriz) {
  int i, j;
  int valor_minimo;

  valor_minimo = matriz[0][0];
  for (i = 1; i < CANT_FILAS; i++) {
    for (j = 1; j < CANT_COLS; j++) {
      if (matriz[i][j] < valor_minimo) {
	valor_minimo = matriz[i][j];
      }
    }
  }
  return valor_minimo;
}

int cant_veces(matriz_t matriz, int numero) {
  int i, j, resultado = 0;

  for (i = 0; i < CANT_FILAS; i++) {
    for (j = 0; j < CANT_COLS; j++) {
      if (matriz[i][j] == numero) {
	resultado++;
      }
    }
  }

  return resultado;
}

int main() {
  matriz_t matriz_enteros;
  int valor_min, resultado;

  ingreso_matriz(matriz_enteros);
  valor_min = calc_menor(matriz_enteros);
  resultado = cant_veces(matriz_enteros, valor_min);

  printf("El menor numero es %d y aparece %d veces.\n", valor_min, resultado);

  return 0;
}
