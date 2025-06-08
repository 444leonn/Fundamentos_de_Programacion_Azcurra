#include <stdio.h>

// Funcion de carga de numeros enteros positivos (innecesaria, solo use una vez) suponer archivo precargado, sino usarla
void cargar_datos(FILE *archivo) {
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    while (num >= 0) {
        fwrite(&num, sizeof(num), 1, archivo);
        
        printf("Ingrese otro numero: ");
        scanf("%d", &num);
    }
}

int main() {
    FILE *arNumEnteros;
    arNumEnteros = fopen("num_enteros.dat", "wb");
        
    if (arNumEnteros == NULL) {
        printf("\nNo se pudo crear el archivo!\n");
    }
    else {
        cargar_datos(arNumEnteros);
        fclose(arNumEnteros);
    }

    return 0;
}