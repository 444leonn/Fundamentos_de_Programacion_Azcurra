/*
* Cargar una serie de números reales positivos en un vector.
* No se conoce la cantidad exacta de datos, pero se sabe que no superan los 100.
* La serie finaliza cuando se ingresa cero.
* Informar el valor máximo, la cantidad de veces que aparece y la/s posición/es que ocupa.
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 100
#define MIN 0

typedef float T_Vec[MAX];

void ingreso_numero(float *numero) {
    printf("Ingrese un numero real postivo: ");
    scanf("%f", numero);

    while (*numero < MIN) {
        printf("Error, ingreso invalido.\n");
        printf("Ingrese un numero real: ");
        scanf("%f", numero);
    }
}

void almacenar_valor(T_Vec vector, int num_almacenar, int posicion) {
    vector[posicion] = num_almacenar;
}

float valor_maximo(T_Vec vector, int max_logico) {
    int i;
    float num_mayor = 0;

    for (i = 0; i < max_logico; i++) {
        if (vector[i] > num_mayor) {
            num_mayor = vector[i];
        }
    }
    
    return num_mayor;
}

int calc_cant_veces(T_Vec vector, float valor, int max_logico) {
    int i, cant_veces = 0;
    for (i = 0; i < max_logico; i++) {
        if (vector[i] == valor) {
            cant_veces++;
        }
    }

    return cant_veces;
}

void posicion_en_vector(T_Vec vector, float valor, int max_logico) {
    int i;
    for (i = 0; i < max_logico; i++) {
        if (vector[i] == valor) {
            printf("Ocupa la posicion %i\n", i);
        }
    }
}

int main() {
    T_Vec vector_positivos;
    float num, valor_max;
    int ML = 0;

    ingreso_numero(&num);
    while (num != 0) {
        almacenar_valor(vector_positivos, num, ML);
        ingreso_numero(&num);
        ML++;
    }

    valor_max = valor_maximo(vector_positivos, ML);
    printf("El valor maximo del vector es: %.2f\n\n", valor_max);

    printf("Aparece una cantidad de %i veces en total.\n\n", calc_cant_veces(vector_positivos, valor_max, ML));

    posicion_en_vector(vector_positivos, valor_max, ML);
    
    return 0;
}