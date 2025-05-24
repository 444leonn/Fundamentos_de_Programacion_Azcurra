#include <stdio.h>

int main() {
    int vector[] = {1, 2, 3, 4, 5};

    int otro_vector[5]; // Arreglo de 5 sin inicializar las variables, por lo tanto, tiene basura.
    
    int tamanio = sizeof(vector) / sizeof(int); // Permite calcular el tamanio del vector

    printf("%d", tamanio);

    return 0;
}