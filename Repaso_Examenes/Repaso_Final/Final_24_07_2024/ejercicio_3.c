/*
* Desarrollar una funcion recursiva en lenguaje C que reciba un arreglo y su maximo logico
* y devuelva la suma de los elementos que estan en las posiciones pares del arreglo.
*/

#include <stdio.h>

int suma_elementos_pares(int vector[], int ML) {
    if (ML < 0) {
        return 0;
    }
    else if (ML == 0) {
        return vector[ML];
    }
    else {
        if (ML % 2 == 0) {
            return vector[ML] + suma_elementos_pares(vector, ML - 2);
        }
        else {
            return suma_elementos_pares(vector, ML - 1);
        }
    }
}

int main() {
    int vector[20] = {2, 3, 4, 5, 6, 7, 8};
    int ml = 7, resultado;

    resultado = suma_elementos_pares(vector, ml);
    
    printf("\n\n%d\n\n", resultado);
}