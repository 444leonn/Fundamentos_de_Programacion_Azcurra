/*
* Dado un número n entero positivo y un listado de n números reales, almacenar los números en un vector según el orden de entrada.
* Informar el contenido del vector indicando la posición ocupada por cada número a partir de la primera posición. (1 <= n <= 100)
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 100
#define MIN 1

typedef double T_Vec[MAX];

void ingresar_numero(int *num) {
    printf("Ingrese la cantidad de numeros que va a tener el vector: ");
    scanf("%d", num);
}

bool ingreso_invalido(int num) {
    bool no_valido = false;

    if (num < MIN || num > MAX) {
        no_valido = true;
    }

    return no_valido;
}

void ingresar_valores(T_Vec vector, int ML){
    int i;
    int cont = 1;
    for (i = 0; i < ML; i++) {
        printf("Ingrese el valor numero %d: ", cont);
        scanf("%lf", &vector[i]);
        cont++;
    }
}

void mostrar_valores(T_Vec vector, int ML) {
    int i;
    int cont = 1;

    for (i = 0; i < ML; i++) {
        printf("Posicion [%d] = %.2lf \n", cont, vector[i]);
        cont++;
    }
}

int main() {
    int num_n;
    T_Vec vector_reales;

    ingresar_numero(&num_n);
    while (ingreso_invalido(num_n)) {
        ingresar_numero(&num_n);
    }

    ingresar_valores(vector_reales, num_n);
    mostrar_valores(vector_reales, num_n);

    return 0;
}