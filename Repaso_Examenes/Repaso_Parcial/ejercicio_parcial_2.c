/*
* Desarrola una funcion que reciba como parametros una matriz de tipo Tmatriz ya cargada sus maximos logicos (de filas y columnas) y un entero
* que devuelva al modulo invocante los siguientes valores:
*     - La cantidad de veces que el numero recibido por parametro esta presente en la matriz.
*     - La cantidad de elementos presentes en la matriz que son mayores al numero recibido.
* Escribir un programa que invoque dicha funcion.
*/

#include <stdio.h>

#define CANTCOLS 30
#define CANTFILAS 20

typedef int Tmatriz[CANTFILAS][CANTCOLS];

void calc_cant_elementos(Tmatriz matriz, int FIL, int COL, int num_entero, int *cant_veces, int *cant_mayores) {
    int i, j;

    for (i = 0; i < FIL; i++) {
        for (j = 0; j < COL; j++) {
            if (matriz[i][j] == num_entero) {
                *cant_veces += 1;
            }
            else if (matriz[i][j] > num_entero) {
                *cant_mayores += 1;
            }
        }
    }
}

int main() {
    Tmatriz matriz = {
        {3, 1, 2},
        {4, 2, 1},
        {1, 2, 3}
    };

    int cant_veces = 0, cant_mayores = 0;

    calc_cant_elementos(matriz, 3, 3, 2, &cant_veces, &cant_mayores);

    printf("Cantidad de veces que aparece el numero 2: %d\n", cant_veces);
    printf("Elementos mayores: %d\n", cant_mayores);

    return 0;
}