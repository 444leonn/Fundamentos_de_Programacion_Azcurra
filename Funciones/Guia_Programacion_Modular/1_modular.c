/*
* Escribir un programa donde el usuario ingrese una secuencia de números terminada en cero y se le informe la cantidad de múltiplos de 2, 3, 5 y 7.
* Utilizar una función que dados dos números como parámetros por valor devuelve un valor boolean que indique si el primero es o no múltiplo del segundo.
* Ejemplo:
*     Números ingresados: 35, 20, 14, 21, 2
*     múltiplos de 2: 3
*     múltiplos de 3: 1
*     múltiplos de 5: 2
*     múltiplos de 7: 3
*/

#include <stdio.h>
#include <stdbool.h>

void ingresar_numero(int *numero) {
  scanf("%d", numero);
}

bool multiplos(int multiplo, int num) {
  return (num % multiplo) == 0;
}

void ingresos(int *numero, int *mult_2, int *mult_3, int *mult_5, int *mult_7) {
  while (*numero != 0) {
    if (multiplos(2, *numero)) {
      *mult_2 += 1;
    }
    if (multiplos(3, *numero)) {
      *mult_3 += 1;
    }
    if (multiplos(5, *numero)) {
      *mult_5 += 1;
    }
    if (multiplos(7, *numero)) {
      *mult_7 += 1;
    }
    
    printf("Ingrese otro valor: ");
    ingresar_numero(numero);
  }
}

int main() {
    int num, cant_mult_2 = 0, cant_mult_3 = 0, cant_mult_5 = 0, cant_mult_7 = 0;
    
    printf("Ingrese un numero para la secuencia: ");
    ingresar_numero(&num);
    
    ingresos(&num, &cant_mult_2, &cant_mult_3, &cant_mult_5, &cant_mult_7);
    
    printf("múltiplos de 2: %d\n", cant_mult_2);
    printf("múltiplos de 3: %d\n", cant_mult_3);
    printf("múltiplos de 5: %d\n", cant_mult_5);
    printf("múltiplos de 7: %d\n", cant_mult_7);

    return 0;
}
