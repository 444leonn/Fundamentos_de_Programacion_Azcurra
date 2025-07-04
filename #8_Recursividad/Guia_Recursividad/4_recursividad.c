/*
* Desarrollar un programa que calcule y muestre por pantalla la división de 2 números mediante restas sucesivas en forma recursiva.
* Ambos números deben ser ingresados por el usuario.
*/

#include <stdio.h>

int division_sucesiva(int numerador, int denominador) {
    if (denominador == 0) {
        return -1;
    }
    else {
        if (numerador < denominador)
            return 0;
        numerador = numerador - denominador;
        return 1 + division_sucesiva(numerador, denominador);
    }
}

int main() {
    int num_1, num_2, resultado;

    printf("Ingrese un numero:  ");
    scanf("%d", &num_1);

    printf("Ingrese otro numero:  ");
    scanf("%d", &num_2);

    resultado = division_sucesiva(num_1, num_2);

    printf("Resultado:  %d.\n", resultado);

    return 0;
}