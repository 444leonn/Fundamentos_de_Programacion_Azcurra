/*
* Se tiene una colección de datos de la temperatura por hora (0 a 23) por día (1 a 31) del mes de marzo.
* Se pide:
*     a) Cargar el listado en una matriz e informarla en forma bidimensional.
*     b) Informar además la máxima y la mínima temperatura por día, la máxima y la mínima del mes.
*/

#include <stdio.h>
#define DIAS 31
#define HORAS 24
typedef float T_Mat[HORAS][DIAS];

void cargar_datos(T_Mat matriz) {
    int i, j;

    for (i = 0; i < DIAS; i++) {
        printf("Ingrese las temperaturas para el dia: %d\n", i);
        for (j = 0; j < HORAS; j++) {
            printf("Hora: %d", j);
            scanf("%f", &matriz[j][i]);
        }
    } 
}

void mostrar_datos(T_Mat matriz) {
    int i, j;

    for (i = 0; i < HORAS; i++) {
        for (j = 0; j < DIAS; j++) {
            printf("%.2f", matriz[i][j]);
        }
    }

}

int main() {
    T_Mat datos_hora;

    cargar_datos(datos_hora);
    mostrar_datos(datos_hora);
    
    return 0;
}