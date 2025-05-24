/*
* Dado un listado de números reales del cual no se conoce la cantidad, almacenar los números en un vector en el orden de entrada.
* Informar la cantidad de números y el contenido del vector indicando la posición ocupada por cada número a partir de la primera posición.
* Considerar una estructura de datos de tamaño físico máximo de 1000 posiciones.
* El ingreso de numeros reales termina con 0.
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 1000

typedef double T_Vec[MAX];

void ingrese_numero(double *num) {
    printf("Ingrese un numero real a almacenar (0 para terminar):  ");
    scanf("%lf", num);
}

void almacenar_numero(double numero, T_Vec vector, int *max_logico) {
    vector[*max_logico] = numero;
    *max_logico += 1;
}

void mostrar_contenido_vector(T_Vec vector, int ML) {
    int cont;

    for (cont = 0; cont < ML; cont++) {
        printf("Posicion %d: %.2lf\n", cont, vector[cont]);
    }
}

int main() {
    double num;
    int ML = 0;
    T_Vec vector_reales;

    ingrese_numero(&num);
    while (num != 0) {
        almacenar_numero(num, vector_reales, &ML);
        ingrese_numero(&num);
    }

    printf("La cantidad de numeros ingresados es de: %d\n", ML);
    mostrar_contenido_vector(vector_reales, ML);
       
    return 0;
}

/*
#include <stdio.h>
#include <stdbool.h>
#define MAX 1000

typedef double T_Vec[MAX];

void ingresar_almacenar(double *num, T_Vec vector) {
    int cont = 0;

    printf("Ingrese un numero: ");
    scanf("%lf", num);

    vector[cont] = *num;
    
    while (*num != 0) {
        cont++;
        printf("Ingrese un numero: ");
        scanf("%lf", num);
        
        vector[cont] = *num; 
    }
}

void mostrar_vector(T_Vec vector) {
    int i = 0;
    while (vector[i] != 0) {
        printf("Posicion %d: %.2lf\n", i, vector[i]);
        i++;
    }
}

int main() {
    double num;
    T_Vec vector_reales;

    ingresar_almacenar(&num, vector_reales);
    mostrar_vector(vector_reales);

    return 0;
}
*/