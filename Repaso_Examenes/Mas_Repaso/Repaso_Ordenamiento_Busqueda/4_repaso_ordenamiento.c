/*
* Dado un arreglo de enteros cargado por el usuario (de tamaño N),
* solicita un número a buscar e implementa la búsqueda secuencial para determinar si el número está presente e imprime su/s posición/es.
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 20
#define NO_ENCONTRADO -1

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

void mostrar_vector(tvec vector, int tamanio) {
    int i;
    for (i = 0; i < tamanio; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

int busqueda_secuencial(tvec vector, int tamanio, int valor_buscado) {
    int i, pos = NO_ENCONTRADO;
    bool encontrado = false;

    i = 0;
    while (!encontrado && i < tamanio) {
        if (vector[i] == valor_buscado) {
            encontrado = true;
            pos = i;
        }
        i++;
    }
    
    return pos;
}

int main() {
    tvec vector;
    int num_n, valor_busc, pos_busc;

    ingresar_n(&num_n);

    almacenar_valores(vector, num_n);

    printf("Ingrese un valor para buscar en el vector:  ");
    scanf("%d", &valor_busc);
    pos_busc = busqueda_secuencial(vector, num_n, valor_busc);
    if (pos_busc == NO_ENCONTRADO) {
        printf("El valor %d no se ha encontrado en el vector.\n", valor_busc);
    }
    else {
        printf("El valor %d se encuentra en el indice %d del vector\n", valor_busc, pos_busc);
    }
    
    return 0;
}