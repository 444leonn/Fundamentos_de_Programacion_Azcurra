/*
Dados 2 vectores a y b de longitudes n y m, el primero ordenado ascendentemente y el segundo ordenado descendente, crear un nuevo vector c
de longitud n + m elementos intercalando lo elementos de a y b de modo que c quede ordenado ascendentemente.
*/

#include <stdio.h>

#define MAX 15

typedef int T_Vec[MAX];

int intercalar_vector(T_Vec prim_vec, T_Vec seg_vec, T_Vec ter_vec, int ML_1, int ML_2) {
    int ML_3 = ML_1 + ML_2;
    int i = 0, j = ML_2 - 1, k = 0;

    while ((i < ML_1) || (j >= 0)) {
        if ((prim_vec[i] < seg_vec[j]) || (j > 0)) {
            ter_vec[k] = prim_vec[i];
            i++;
        }
        else {
            ter_vec[k] = seg_vec[j];
            j--;
        }
        k++;
    }

    return ML_3;
}

void mostrar_vector(int vector[], int cant_elementos) {
    int i;
    for (i = 0; i < cant_elementos; i++) {
        printf("%d, ", vector[i]);
    }
}

int main() {
    T_Vec vec_1 = {1, 3, 5};
    T_Vec vec_2 = {7, 6, 4, 2};
    T_Vec vec_3;

    int ML_1 = 3;
    int ML_2 = 4;
    int ML_3;

    ML_3 = intercalar_vector(vec_1, vec_2, vec_3, ML_1, ML_2);

    mostrar_vector(vec_3, ML_3);
    
    return 0;
}