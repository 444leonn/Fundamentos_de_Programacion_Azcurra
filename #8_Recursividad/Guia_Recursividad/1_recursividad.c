/*
* Desarrollar un programa que calcule la factorial de un número en forma recursiva.
*/

#include <stdio.h>

long calcular_factorial(int numero) {
    if (numero == 1 || numero == 0)
        return 1;
    return numero * calcular_factorial(numero - 1);
}

int main() {
    int num;
    long factorial;

    printf("Ingrese un numero a calcular su factorial:  ");
    scanf("%d", &num);
    while (num < 0) {
        printf("Error no se puede calcular el factorial de un numero negativo.\n");
        printf("Ingrese un numero a calcular su factorial:  ");
        scanf("%d", &num);
    }

    factorial = calcular_factorial(num);

    printf("El factorial de %d da %ld\n", num, factorial);

    return 0;
}