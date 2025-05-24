/*
* Dado un listado de valores numéricos i y x, donde i es un entero mayor que 0 y menor o igual 999, y x un número real,
* almacenar x en la posición i de un vector.
* El listado no se ingresa ordenado por posición.
* Informar la cantidad de números y el contenido del vector indicando la posición ocupada por cada número a partir de la primera posición.
* Omitir las posiciones que no contengan valor.
* Considerar una estructura de datos de tamaño físico máximo de 1000 posiciones.
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 1000
#define MIN 1

typedef double T_Vec[MAX];

void limpiar_vector(T_Vec vector) {
    int i;
    for (i = 0; i < MAX; i++) {
        vector[i] = 0;
    }
}

void ingreso_numX(double *numero) {
    printf("Ingrese un numero real a guardar su valor (0 para terminar): ");
    scanf("%lf", numero);
}

void ingreso_numI(int *numero) {
    printf("Ingrese la posicion del vector en la que desea guardarlo: ");
    scanf("%d", numero);
}

bool ingreso_invalido(int numero) {
    bool no_valido = false;
    
    if (numero < MIN || numero >= MAX)
        no_valido = true;

    return no_valido;
}

void almacenar_valor(T_Vec vector, int prim_numero, double seg_numero) {
    vector[prim_numero] = seg_numero;
}

void mostrar_valores(T_Vec vector, int cantidad) {
    int i;

    printf("La cantidad de numeros es: %d.\n\n", cantidad);

    for (i = 0; i < MAX; i++) {
        if (vector[i] != 0) {
            printf("Posicion %d = %.2lf.\n\n", i, vector[i]);
        }
    }
}

int main() {
    int num_i, cant = 0;
    double num_x;
    T_Vec vector_reales;

    limpiar_vector(vector_reales);

    ingreso_numX(&num_x);
    while(num_x != 0) {
        ingreso_numI(&num_i);
        while (ingreso_invalido(num_i)) {
            printf("Error, valor ingresado invalido.\n");
            ingreso_numI(&num_i);
        }

        almacenar_valor(vector_reales, num_i, num_x);
        cant++;
        ingreso_numX(&num_x);
    }

    mostrar_valores(vector_reales, cant);

    return 0;
}