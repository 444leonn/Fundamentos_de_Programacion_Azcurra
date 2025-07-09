/*
* Desarrollar un funcion que reciba como parametros una matriz cuadrada ya cargasda en su capacidad maxima, y un numero entero.
* Que devuelva al modulo invocante la suma de los valores que se encuentran en el triangulo inferior y que sean divisibles por el numero recibido.
*/

#include <stdio.h>

#define CANT 4

typedef int Tmatriz[CANT][CANT];

int suma_triangulo_inferior(Tmatriz matriz, int numero) {
    int i, j;
    int sumatoria = 0;

    for (i = 1; i < CANT; i++)
        for (j = 0; j < i; j++)
            if (matriz[i][j] % numero == 0)
                sumatoria += matriz[i][j];
    
    return sumatoria;
}

int main() {
    Tmatriz matriz = {
        {1, 2, 3, 4},
        {27, 2, 3, 4},
        {14, -9, 4, 5},
        {3, 5, 16, 9}
    };

    printf("%d.\n", suma_triangulo_inferior(matriz, 3));    
    
    return 0;
}