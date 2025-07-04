/*
* Desarrollar un programa que muestre la suma de los primeros N números naturales.
* El número N lo debe ingresar el usuario.
*/

#include <stdio.h>

void ingresar_numero(int *numero) {
    printf("Ingrese un numero entero natural: ");
    scanf("%d", numero);
}

void ingresar_natural(int *numero) {
    ingresar_numero(numero);
    while (*numero <= 0) {
        printf("Debe ingresar un numero natural.\n");
        ingresar_numero(numero);
    }
}

int suma_natural_recursiva(int numero) {
    if (numero <= 0)
        return 0;
    return numero + suma_natural_recursiva(numero - 1);
}

int main() {
    int num, suma_naturales;

    ingresar_natural(&num);

    suma_naturales = suma_natural_recursiva(num);

    printf("Suma de los %d primeros numeros naturales: %d.\n", num, suma_naturales);

    
    return 0;
}