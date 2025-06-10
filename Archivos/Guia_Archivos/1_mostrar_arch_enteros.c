#include <stdio.h>

// Funcion para mostrar archivos con enteros
void mostrar_archivo_enteros(FILE *archivo) {
    int num;

    printf("Dentro del archivo hay...\n");
    while (fread(&num, sizeof(num), 1, archivo) == 1) {
        printf("%d ", num);
    }
    printf("\n");
}

int main() {
    FILE *arNumEnteros;
    arNumEnteros = fopen("./.dat", "rb"); // Cambiar dentro de "" por el nombre del archivo

    if (arNumEnteros == NULL) {
        printf("\nNo se pude leer el archivo!\n");
    }
    else {
        mostrar_archivo_enteros(arNumEnteros);
        fclose(arNumEnteros);
    }

    return 0;
}