/*
* Desarrollar un programa que solicite al usuario el ingreso de 2 números A y B y calcule la potencia de A elevado a la B de forma recursiva.
*/

#include <stdio.h>

void ingresar_numero(int *numero) {
    printf("Ingrese un numero entero natural: ");
    scanf("%d", numero);
}

long calcular_potencia(int numero_a, int numero_b) {
    if (numero_b == 0)
        return 1;
    else if (numero_a == 0)
        return 0;
    else
        return numero_a * calcular_potencia(numero_a , numero_b - 1);
}

int main() {
    int num_a, num_b;
    long resultado;

    ingresar_numero(&num_a);
    ingresar_numero(&num_b);

    resultado = calcular_potencia(num_a, num_b);

    printf("\n%d elevado a %d es igual a %ld\n", num_a, num_b, resultado);
    
    return 0;
}