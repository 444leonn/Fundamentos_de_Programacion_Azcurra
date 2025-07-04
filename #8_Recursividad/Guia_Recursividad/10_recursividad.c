/*
* Desarrollar un programa que solicite al usuario el ingreso de un número entero y calcule el máximo común divisor de forma recursiva.
*/

#include <stdio.h>

void ingresar_numero(int *numero) {
    printf("Ingrese un numero entero natural: ");
    scanf("%d", numero);
}

// TODO: Revisar bien como es.
int maximo_divisor_comun(int num_a, int num_b){
    if (num_a % num_b == 0)
        return num_b;
    return maximo_divisor_comun(num_b, num_a % num_b);
}


int main() {
    int num_1, num_2, max_divisor;

    ingresar_numero(&num_1);
    ingresar_numero(&num_2);

    if (num_1 >= num_2) {
        max_divisor = maximo_divisor_comun(num_1, num_2);
    }
    else {
        max_divisor = maximo_divisor_comun(num_2, num_1);
    }

    printf("Maximo comun dividor entre %d y %d: %d.\n", num_1, num_2, max_divisor);

    return 0;    
}