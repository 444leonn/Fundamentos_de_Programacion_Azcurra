/*
* Dado un vector de 10 números reales predefinidos, implementa el método de selección para ordenarlo de mayor a menor.
* Muestra el vector antes y después del ordenamiento.
*/

#include <stdio.h>


void mostrar_vector(int vector[], int tamanio) {
    int i;
    for (i = 0; i < tamanio; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void ordenar_seleccion(int vector[], int tamanio) {
    int i, j, aux, pos_minimo;

    for (i = 0; i < tamanio - 1; i ++) {
        pos_minimo = i;
        for (j = i + 1; j < tamanio; j++) {
            if (vector[j] < vector[pos_minimo]) {
                pos_minimo = j;
            }
        }
        aux = vector[i];
        vector[i] = vector[pos_minimo];
        vector[pos_minimo] = aux;
    }
}

int main() {
    int vector_predef[] = {3, 7, 8, 1, 6, 2, 5, 11, 10, 9};
    int tamanio = 10;

    printf("\nVector antes de ordenar:  ");
    mostrar_vector(vector_predef, tamanio);
    
    ordenar_seleccion(vector_predef, tamanio);
    
    printf("\nVector Ordenado:  ");
    mostrar_vector(vector_predef, tamanio);
    
    return 0;
}