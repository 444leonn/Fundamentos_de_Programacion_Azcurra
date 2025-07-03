/*
* Desarrollar un programa que calcule y muestre por pantalla los primeros N términos de la sucesión de Fibonacci en forma recursiva.
*/

#include <stdio.h>

int fibonacci(int numero) {
    if (numero <= 1)
        return numero;
    return fibonacci(numero-1) + fibonacci(numero-2);
}

int main() {
    int num, i;

    printf("Ingrese un numero para calcular la sucesion de Fibonacci:  ");
    scanf("%d", &num);
    

    for (i = 0; i < num; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n");
    return 0;
}