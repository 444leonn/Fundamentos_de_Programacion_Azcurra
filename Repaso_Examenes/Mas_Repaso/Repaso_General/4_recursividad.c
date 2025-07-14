/*
* Desarrollar una función recursiva que reciba un vector de enteros y su tamaño, y devuelva la suma de todos sus elementos.
*/

#include <stdio.h>

int sumatoria_vector(int vector[], int tamanio) {
    if (tamanio <= 0) {
        return 0;
    }
    return vector[tamanio - 1] + sumatoria_vector(vector, tamanio - 1);
}

int main() {
    int vec[] = {3, 2, 1, 4, 5};
    int tamanio = 5, resultado;

    resultado = sumatoria_vector(vec, tamanio);
    printf("Sumatoria de los valores del vector:  %d\n\n", resultado);

    return 0;
}