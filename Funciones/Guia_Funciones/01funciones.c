/*
* Escribir una función que reciba un valor n, entero, y devuelva la suma de los
* valores entre 0 y n.
* Ejemplo:
* suma_n(5) = 15
* suma_n(120) = 7260
* suma_n(120120) = 7214467260
*/

#include <stdio.h>

int suma_n(int numero) {
    int i, sumatoria = 0;
    for (i = 0; i <= numero; i++) {
        sumatoria += i;
    }

    return sumatoria;
}

int main() {
    int numero;

    printf("Introduce un numero: ");
    scanf("%d", &numero);

    printf("La sumatoria del numero da: %d\n", suma_n(numero));

    return 0;
}