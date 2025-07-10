/*
* Escribir un programa que solicite al usuario N números enteros y los almacene en un arreglo.
* Implementa el método de burbuja para ordenar el arreglo de menor a mayor y muestra el arreglo antes y después de ordenar.
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 20

typedef int tvec[MAX];

void ingresar_n(int *numero) {
    printf("Ingrese un numero N:  ");
    scanf("%d", numero);

    while ((*numero > MAX) || (*numero < 0)) {
        printf("Error, debe ingresar un numero adecuado.\n");

        printf("Ingrese un numero N:  ");
        scanf("%d", numero);
    }
}

void almacenar_valores(tvec vector, int tamanio) {
    int i;
    for (i = 0; i < tamanio; i++) {
        printf("Ingrese un numero:  ");
        scanf("%d", &vector[i]);
    }
}

void ordenar_burbujeo(tvec vector, int tamanio) {
    int i, j, aux;
    bool continuar = true;

    i = 1;
    while ((i < tamanio) && continuar) {
        continuar = false;
        for (j = 0; j < tamanio - i; j++) {
            if (vector[j] > vector[j + 1]) {
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
                continuar = true;
            }
        }
        i++;
    }
}

void mostrar_vector(tvec vector, int tamanio) {
    int i;
    for (i = 0; i < tamanio; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

int main() {
    int num_n;
    tvec vec_enteros;

    ingresar_n(&num_n);

    almacenar_valores(vec_enteros, num_n);

    ordenar_burbujeo(vec_enteros, num_n);

    mostrar_vector(vec_enteros, num_n);
    
    return 0;
}