/*
*  Sucesión de Fibonacci
*
*  Definición recurrente
*  f(0) = 0
*  f(1) = 1
*  f(n) = f(n-1) + f(n-2) para n >= 2
*
*  Ejemplos:
*  f(2)=1
*  f(3)=2
*  f(4)=3
*  f(5)=5
*  f(6)=8
*  f(7)=13
*  f(8)=21
*/

#include <stdio.h>

#define MAX 4

int fibonacci(int numero) {
  if (numero <= 1) 
    return numero; 
  return fibonacci(numero-1) + fibonacci(numero-2);
}  

int main() {
  int i;

  printf("Sucesión de Fibonacci hasta n = %d: ", MAX);
  for (i=0; i < MAX; i++) 
    printf("%d ", fibonacci(i));
  
  printf("\n\n");
  return 0;
} 