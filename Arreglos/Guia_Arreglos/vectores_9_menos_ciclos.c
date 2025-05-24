/*
* Dados 2 vectores a y b de longitudes n y m, el primero ordenado ascendente y el segundo ordenado descendente,
* crear un nuevo vector c de longitud n + m elementos, intercalando los elementos de a y b de modo que c quede ordenado ascendente.
*/

#include <stdio.h>

#define MAX 15

typedef int T_Vec[MAX];

int crear_vector(T_Vec vector_1, T_Vec vector_2, T_Vec vector_3, int long_n, int long_m) {
    int long_n_m = long_n + long_m;

    int i, j = long_m - 1, k = 0;

    i = 0;
    while ((k < long_n) || (j >= 0)) {
        if ((vector_2[j] < vector_1[k]) || (k >= long_n)) {
            vector_3[i] = vector_2[j];
            j--;
        }
        else {
            vector_3[i] = vector_1[k];
            k++;
        }
        i++;
    }

    return long_n_m;
}

void mostrar_vector(int vector[], int cant_elementos) {
    int i;
    for (i = 0; i < cant_elementos; i++) {
        printf("%d, ", vector[i]);
    }
}

int main() {
    int long_vector_3;

    T_Vec vector_1 = {9, 7, 5, 3, 1};
    int long_n = 5;

    T_Vec vector_2 = {2, 4};
    int long_m = 2;

    T_Vec vector_3;

    long_vector_3 = crear_vector(vector_1, vector_2, vector_3, long_n, long_m);

    mostrar_vector(vector_3, long_vector_3);
    
    return 0;
}