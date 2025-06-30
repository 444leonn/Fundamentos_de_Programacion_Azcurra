/*
Generar los n (valor ingresado por el usuario) primeros números naturales e informar por pantalla un listado de cada número generado junto con el factorial
correspondiente. 
Utilizar una función que dado un número devuelva su factorial.
Validar que el número ingresado sea entero positivo, caso contrario se le debe indicar al usuario que el número es incorrecto y se le solicita el ingreso nuevamente.
Ejemplo:
    n = 6
    EL factorial de 1 es 1
    EL factorial de 2 es 2
    EL factorial de 3 es 6
    EL factorial de 4 es 24
    EL factorial de 5 es 120
    EL factorial de 6 es 720
*/

#include <stdio.h>
#include <stdbool.h>

void ingreso_num(int *num) {
    scanf("%d", num);
    while (*num < 0) {
      printf("Error, ingreso invalido.\n");
      printf("Ingreselo nuevamente: ");
      scanf("%d", num);
    }
}

long calc_factorial(int num) {
    long resultado = 1;
    int i;
    
    for (i = 2; i <= num; i++)
      resultado *= i;
    
    return resultado;
}

void informe(int num) {
    int i;
    
    for (i = 1; i <= num; i++)
      printf("EL factorial de %d es %ld\n", i, calc_factorial(i));
}

int main() {
    int num;

    printf("Ingrese un numero para calcular el factorial de cada numero hasya llegar a n: ");
    ingreso_num(&num);

    informe(num);

    return 0;
}
