/*
* Escribir un programa modular que implemente la función del burbujeo optimizado para ordenar un arreglo compuesto por los dígitos de tu DNI.
* Suponé com máximo físico 10 dígitos enteros.
* Invocar la función desde el main.
* Mostrá los valores antes y después del ordenamiento.
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef int T_Vec[MAX];

int ingresar_dni(T_Vec vector) {
    int i, cant_digitos = 0;

    i = 0;
    do {
        printf("Ingrese un digito del DNI: ");
        scanf("%d", &vector[i]);
        cant_digitos++;
        i++;
    } while ((i < MAX) && vector[i] >= 0);

    return cant_digitos;
}

void mostrar_vector(T_Vec vector, int ML) {
    int i;

    for (i = 0; i < ML; i++) {
        printf("%d", vector[i]);
    }
    printf("\n");
}

void intercambio (int *num_a, int *num_b) {
    int aux;

    aux = *num_a;
    *num_a = *num_b;
    *num_b = aux;
}

void ordernar_vector(T_Vec vector, int ML) {
    int i, j;
    bool esta_desordenado = true;

    i = 1;
    while ((i < ML) && esta_desordenado) {
        esta_desordenado = false;

        for (j = 0; j < ML - i; j++) {
            if (vector[j] > vector [j + 1]) {
                esta_desordenado = true;
                intercambio(&vector[j], &vector[j + 1]);
            }
        }
        i++;
    }
}

int main() {
    T_Vec vector_dni;
    int ML = ingresar_dni(vector_dni);

    mostrar_vector(vector_dni, ML);

    ordernar_vector(vector_dni, ML);

    mostrar_vector(vector_dni, ML);

    return 0;
}