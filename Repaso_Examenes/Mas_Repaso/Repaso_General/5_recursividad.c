/*
* Dada una función recursiva que reciba un vector de enteros, su tamaño y un valor,
* retorna cuántas veces aparece ese valor en el vector.
*/

#include <stdio.h>

int contar_apariciones(int vector[], int tamanio, int valor) {
    if (tamanio <= 0) {
        return 0;
    }
    else if (vector[tamanio - 1] == valor) {
        return 1 + contar_apariciones(vector, tamanio - 1, valor);
    }
    else {
        return contar_apariciones(vector, tamanio - 1, valor);
    }
}

int main() {
    int vector[] = {3, 2, 1, 5, 4, 5};
    int tamanio = 6;
    int valor_busc = 5, apariciones;

    apariciones = contar_apariciones(vector, tamanio, valor_busc);

    printf("Apariciones del valor %d en el vector:  %d\n\n", valor_busc, apariciones);

    return 0;
}