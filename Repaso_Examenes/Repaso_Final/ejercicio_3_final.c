/*
* Desarrollar una función recursiva en lenguaje C que reciba un número entero como parámetro
* y devuelva la sumatoria de los números naturales desde 1 hasta ese número.
* Si el número recibido es menor o igual a 0, la función debe devolver `0`.
* Ejemplo
*     sumatoria(6) → 1 + 2 + 3 + 4 + 5 + 6 = 21
*/

#include <stdio.h>

int sumatoria(int numero) {
    if (numero <= 0) {
        return 0;
    }
    else {
        return numero + sumatoria(numero - 1);
    }
}

int main() {
    int num_1 = 6, num_2 = 3, num_3 = -1;

    printf("Sumatoria de %d:  %d\n", num_1, sumatoria(num_1));
    printf("Sumatoria de %d:  %d\n", num_2, sumatoria(num_2));
    printf("Sumatoria de %d:  %d\n", num_3, sumatoria(num_3));

    return 0;
}