/*  Escribir un programa que muestre las tablas de multiplicar desde la tabla del 1 hasta la tabla del 9 para los primeros 100 números naturales. */

#include <stdio.h>

int main()
{
   int num;
   int i;
   int resultado;
   
   printf("Ingrese un numero a calcular su tabla: ");
   scanf("%d", &num);

   for (i = 1; i <= 10; i++)
   {
    resultado = num * i;
    printf("%i\n", resultado);
   }
   return 0;
}