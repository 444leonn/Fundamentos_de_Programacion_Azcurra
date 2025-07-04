/*
* Desarrollar un programa que solicite al usuario el ingreso de un número entero y lo muestre invertido.
* No se puede utilizar vectores.
*/

#include <stdio.h>

void ingresar_numero(int *numero) {
    printf("Ingrese un numero: ");
    scanf("%d", numero);
}

void ingresar_entero(int *numero) {
    ingresar_numero(numero);
    while (*numero < 0) {
        printf("Ingrese un numero entero positivo.\n");
        ingresar_entero(numero);
    }
}

int invertir(int numero) {
    if (numero <= 0)
        return 1;

    printf("%d", numero % 10);
    return invertir((numero - (numero % 10))/10);
}

int main() {
    int num, num_invertido;

    ingresar_entero(&num);

    printf("Numero Invertido: ");
    invertir(num);
    printf("\n");
    
    return 0;
}