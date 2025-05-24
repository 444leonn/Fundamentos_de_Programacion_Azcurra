/*
* Dados 2 vectores a y b de longitudes n y m, el primero ordenado ascendente y el segundo ordenado descendente,
* crear un nuevo vector c de longitud n + m
* elementos intercalando los elementos de a y b de modo que c quede ordenado ascendente.
*/

#include <stdio.h>

int main() {
    int vector_a[] = {1, 3, 5};
    int vector_b[] = {4, 2};
    int n = 3, m = 2;
    int vector_c[5];
    int i = 0, j = m - 1, k = 0;

    while (i < n && j >= 0) {
        if (vector_a[i] < vector_b[j]) {
            vector_c[k++] = vector_a[i++];
        }
        else {
            vector_c[k++] = vector_b[j--];
        }
    }

    while (i < n) {
        vector_c[k++] = vector_a[i++];
    }

    while (j >= 0) {
        vector_c[k++] = vector_b[j--];
    }

    printf("Vector c ordenado ascendente: ");
    for (i = 0; i < n + m; i++) {
        printf("%d ", vector_c[i]);
    }
    printf("\n");

    return 0;
}