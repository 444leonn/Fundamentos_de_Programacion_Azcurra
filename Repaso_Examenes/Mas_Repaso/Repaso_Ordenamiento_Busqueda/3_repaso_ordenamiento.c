/*
* Solicita al usuario la cantidad de números N, luego pide al usuario que ingrese N números enteros y guárdalos en un arreglo.
* Ordena el arreglo usando el método de inserción y muestra el resultado.
*/

#include <stdio.h>

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

void mostrar_vector(tvec vector, int tamanio) {
    int i;
    for (i = 0; i < tamanio; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void ordenar_insercion(tvec vector, int tamanio) {
    int k, i, aux;

    for (k = 1; k < tamanio; k++) {
        aux = vector[k];
        i = k - 1;
        while ((i >= 0) && (aux < vector[i])) {                      
            vector[i + 1] = vector[i];
            i = i - 1;
        }
        vector[i + 1] = aux;
    }
}

int main() {
    tvec vector;
    int num_n;

    ingresar_n(&num_n);

    almacenar_valores(vector, num_n);

    printf("\nVector antes de ordenar:  ");
    mostrar_vector(vector, num_n);
    
    ordenar_insercion(vector, num_n);
    
    printf("\nVector Ordenado:  ");
    mostrar_vector(vector, num_n);
    
    
    return 0;
}