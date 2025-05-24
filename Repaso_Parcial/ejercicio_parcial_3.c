/*
* Desarrolar una funcion que reciba como parametros un vector de tipo Tvector ya cargado, y su respectivo maximo logico y devuelva
*     El arreglo invertido y la cantidad de intercambios que fueron realizados
*     Pero cumpliendo con las siguientes condiciones:
*         La inversion debe ser sobre si mismo, no se puede usar un vector auxiliar.
*         Si las posiciones a invertir contienen un mismo valor, no deben ser intercambiadas.
*/

#include <stdio.h>

#define MAX 1000

typedef int Tvector[MAX];

int invertir_vector(Tvector vector, int ML) {
    int i, aux, cant_intercambios = 0;

    for (i = 0; i < ML / 2; i++) {
        if (vector[i] != vector[ML - i - 1]) {
            aux = vector[i];
            vector[i] = vector[ML - i - 1];
            vector[ML - i - 1] = aux;

            cant_intercambios++;
        }
    }

    return cant_intercambios;
}

void mostrar_vector(Tvector vector, int ML) {
    int i;

    for (i = 0; i < ML; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

int main() {
    Tvector vector_enteros = {1, 2, 3, 4, 2, 8};

    int cant_intercambios = invertir_vector(vector_enteros, 6);

    printf("Cantidad de intercambios realizados: %d", cant_intercambios);

    printf("Vector: ");
    mostrar_vector(vector_enteros, 6);
    
    return 0;
}