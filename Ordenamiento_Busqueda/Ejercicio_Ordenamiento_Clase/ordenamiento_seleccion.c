#include <stdio.h>
#include <stdbool.h>
#define MAX 20
typedef int tvec[MAX];

void intercambio (int *a, int *b) {
    int aux;
    
    aux = *a;
    *a = *b;
    *b = aux;
}

void ordenar_por_burbujeo (tvec vec, int ml) {
    int i, j;

    for (i = 1; i < ml; i++)
        for (j = 0; j < ml - i; j++)
            if (vec[j] > vec[j + 1])
                intercambio(&vec[j], &vec[j + 1]);
}

void mostrar_vector (tvec vec, int ml) {
    int i;

    printf("( ");
    for (i = 0; i < ml; i++) {
        printf("%d ", vec[i]);
    }    
    printf(")\n");
}

void ordenar_por_burbujeo_optimizado(tvec vec, int ml) {
    int i, j;
    bool hubo_intercambio = true;

    i = 1;

    while ((i < ml) && hubo_intercambio) {
        hubo_intercambio = false;

        for (j = 0; j < ml - i; j++) {
            if (vec[j] > vec[j + 1]) {
                intercambio(&vec[j], &vec[j + 1]);
                hubo_intercambio = true;
            }
        }
        i++;
    }

}

void presione_enter() {
    printf("Pulse enter para continuar y ver el burbujeo optimizado.");
    getchar();
}

int main() {
    tvec arreglo = {3, 7, 4, 6};
    tvec arreglo_2 = {5, 9, 2, 1};
    tvec arreglo_3 = {1, 2, 3, 4};
    int ML = 4;

    mostrar_vector(arreglo, ML);
    ordenar_por_burbujeo(arreglo, ML);
    mostrar_vector(arreglo, ML);

    presione_enter();

    mostrar_vector(arreglo_2, ML);
    ordenar_por_burbujeo_optimizado(arreglo_2, ML);
    mostrar_vector(arreglo_2, ML);


    presione_enter();

    // Aca se ve como con el arreglo_3 que ya esta ordenado el burbujeo optimizado es mas eficiente.
    mostrar_vector(arreglo_3, ML);
    ordenar_por_burbujeo_optimizado(arreglo_3, ML);
    mostrar_vector(arreglo_3, ML);
    
    return 0;
}