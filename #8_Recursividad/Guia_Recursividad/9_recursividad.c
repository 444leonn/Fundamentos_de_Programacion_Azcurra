/*
* Desarrollar un programa que solicite al usuario el ingreso de un número entero y muestre el resultado de sumar sus dígitos.
*/

#include <stdio.h>

void ingresar_numero(int *numero) {
    printf("Ingrese un numero entero natural: ");
    scanf("%d", numero);
}

int sumar_digitos(int numero) {
    if (numero == 0)
        return 0;
    return ((numero % 10) + sumar_digitos(numero / 10));
}

int main() {
    int num;

    ingresar_numero(&num);

    printf("Digitos sumados: %d.\n", sumar_digitos(num));
    
    return 0;
}