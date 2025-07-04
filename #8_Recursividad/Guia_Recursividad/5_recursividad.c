/*
* Desarrollar una función recursiva para obtener en mayor valor en un vector de números enteros.
*/

#include <stdio.h>

#define MAX 20

typedef int T_Vec[MAX];

int obtener_mayor(T_Vec enteros, int ml) {
    int mayor_restante;

    if (ml == 1)
        return enteros[0];
        
    mayor_restante = obtener_mayor(enteros, ml - 1);
    if (enteros[ml - 1] > mayor_restante)
        return enteros[ml - 1];
    else
        return mayor_restante;
}

int main() {
    int mayor_valor;
    T_Vec enteros = {1, 7, 2, 3};
    int ml = 4;

    mayor_valor = obtener_mayor(enteros, ml);
    
    printf("Mayor valor del vector:  %d.\n", mayor_valor);

    return 0;   
}