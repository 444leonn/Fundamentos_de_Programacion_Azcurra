/*
* Cargar una serie de números reales positivos en un vector.
* No se conoce la cantidad exacta de datos, pero se sabe que no superan los 100.
* La serie finaliza cuando se ingresa cero.
* Utilizar una función que invierta el contenido del vector.
* Informar el contenido del vector indicando la posición ocupada por cada número a partir de la primera posición
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 100
#define MIN 0

typedef double T_Vec[MAX];

void ingreso_numero(double *numero) {
    printf("Ingrese un numero real positivo: ");
    scanf("%lf", numero);
}

bool ingreso_invalido(double numero){
    bool no_valido = false;

    if (numero < MIN) {
        no_valido = true;
    }

    return no_valido;
}

void almacenar_valor(T_Vec vector, double numero, int *cont) {
    vector[*cont] = numero;
    *cont += 1;
}

void mostrar_vector(T_Vec vector, int max_logico) {
    int i;

    for (i = 0; i < max_logico; i++) {
        printf("Posicion %d: %.3lf\n", i, vector[i]);
    }
}

void invertir_vector(T_Vec vector, int max_logico) {
    int i;
    double num_a;
    int ult_pos = max_logico - 1;

    for (i = 0; i < max_logico / 2; i++) {
        num_a = vector[ult_pos];
        vector[ult_pos] = vector[i];
        vector[i] = num_a;
        
        ult_pos--;
    }
}

int main() {
    double num;
    int ML = 0;
    T_Vec vector_positivos;

    ingreso_numero(&num);
    while (num != 0) {
        while(ingreso_invalido(num)) {
            printf("Error, valor ingresado invalido.\n");
            ingreso_numero(&num);
        }
        almacenar_valor(vector_positivos, num, &ML);
        ingreso_numero(&num);
        
    }

    invertir_vector(vector_positivos, ML);
    mostrar_vector(vector_positivos, ML);

    return 0;

}