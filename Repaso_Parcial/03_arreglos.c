/*
* Cargar una serie de números reales positivos en un vector.
* No se conoce la cantidad exacta de datos, pero se sabe que no superan los 100.
* La serie finaliza cuando se ingresa cero. Utilizar una función que invierta el contenido del vector.
* Informar el contenido del vector indicando la posición ocupada por cada número a partir de la primera posición
*/

#include <stdio.h>

#define MAX 100

typedef float T_Vec[MAX];

void cargar_vector(T_Vec vector, int *ml) {
    int i = 0;
    float aux;

    printf("Ingrese un numero real positivo: ");
    scanf("%f", &aux);

    while (aux != 0 && i < MAX) {
        if (aux < 0) {
            printf("Numero ingresado invalido.\n");
        }
        else {
            vector[i] = aux;
            i++;
        }

        printf("Ingrese un numero real positivo: ");
        scanf("%f", &aux);
    }

    *ml = i;
}

void invertir_vector(T_Vec vector, int ML) {
    int i;
    float aux;

    for (i = 0; i < ML / 2; i++) {
        aux = vector[i];
        vector[i] = vector[ML - 1 - i];
        vector[ML - 1 - i] = aux;
    }
}


void mostrar_vector(T_Vec vector, int ml) {
    int i;

    for (i = 0; i < ml; i++) {
        printf("%.2f ", vector[i]);
    }
    printf("\n");
}

int main() {
    T_Vec vector_reales;
    int ML = 0;

    cargar_vector(vector_reales, &ML);
    
    /* invertir_vector(vector_reales, ML);

    printf("Vector invertido: \n");
    mostrar_vector(vector_reales, ML);*/

    mostrar_vector(vector_reales, ML);

    return 0;
}