/*
* Cargar una serie de números reales positivos en un vector.
* No se conoce la cantidad exacta de datos, pero se sabe que no superan los 100.
* La serie finaliza cuando se ingresa cero.
* Utilizar una función que invierta el contenido del vector.
* Informar el contenido del vector indicando la posición ocupada por cada número a partir de la primera posición
*/

#include <stdio.h>

#define MAX 100

typedef float T_Vec[MAX];

int ingreso_vector(T_Vec vector) {
    int i = 0, aux;

    scanf("%d", &aux);

    while (aux != 0 && i < MAX) {
        if (aux > 0) {
            vector[i] = aux;
            printf("Ingrese otro valor: ");
            scanf("%d", &aux);
            i++;
        }
        else {
            printf("Error, ingreso invalido.\n");
            printf("Ingreselo nuevamente: ");
            scanf("%d", &aux);
        }
    }

    return i;
}

void invertir_vector(T_Vec vector, int ML) {
    int i, aux;

    for (i = 0; i < ML / 2; i++) {
        aux = vector[i];
        vector[i] = vector[ML - i - 1];
        vector[ML - i - 1] = aux;
    }
}

void mostrar_vector(T_Vec vector, int max_logico) {
    int i;

    for (i = 0; i < max_logico; i++) {
        printf("Posicion %d: %.3lf\n", i, vector[i]);
    }
}

int main() {
    T_Vec vector;
    int ML;

    printf("Ingrese numeros reales enteros en el vector.\n");
    printf("Ingrese un numero: ");
    ML = ingreso_vector(vector);

    invertir_vector(vector, ML);
    mostrar_vector(vector, ML);

    return 0;
}