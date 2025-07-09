/*
* Dadas las declaraciones de constantes y tipos.
* Desarrollar una funcion que reciba como parametros un vector de tipo T_Vector ya cargado
* y su maximo logico, y devuelva el arreglo invertido y la cantidad de intercambios realizados.
* Cumpliendo las siguientes condiciones: 
*   - La inversion debe ser sobre si mismo, sin vector auxiliar.
*   - Si las posiciones a invertir contienen el mismo valor, no deben ser intercambiadas
*/

#include <stdio.h>

#define MAX 100

typedef int T_vector[MAX];

int invertir_vector(T_vector vector, int ml) {
    int aux, i, cant_intercambios = 0;

    int ult_pos = ml - 1;

    for (i = 0; i < ml / 2; i++) {
        if (vector[i] != vector[ult_pos - i]) {
            aux = vector[i];
            vector[i] = vector[ult_pos - i];
            vector[ult_pos - i] = aux;
            cant_intercambios++;
        }
    }

    return cant_intercambios;
}