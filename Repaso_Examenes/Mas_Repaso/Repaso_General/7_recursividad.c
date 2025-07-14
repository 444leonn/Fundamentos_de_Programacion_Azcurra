/*
* Implementar una función recursiva que busque el valor máximo en un vector de enteros.
*/

#include <stdio.h>
#include <stdbool.h>

#define NO_ENCONTRADO -1

int buscar_valor_maximo(int vector[], int tamanio, int i) {
    int max;
    if (i == tamanio - 1) {
        return vector[i];
    }
    else {
        max = buscar_valor_maximo(vector, tamanio, i + 1);
        if (vector[i] > max) {
            return vector[i];
        }
        else {
            return max;
        }
    }
}

int main() {
    int vec[20] = {2, 4, 6, 3, 1};
    int ml = 5, max_valor;

    max_valor = buscar_valor_maximo(vec, ml, 0);

    printf("\n\n%d\n\n", max_valor);

    return 0;
}