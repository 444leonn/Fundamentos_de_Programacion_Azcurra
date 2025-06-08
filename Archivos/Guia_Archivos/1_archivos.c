/*
* Dado un archivo de números enteros mayores o iguales que 0, generar otro archivo que almacene los factoriales de cada número del registro correspondiente del archivo de entrada.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void generar_archivo_factoriales(FILE *archivo_enteros, FILE *archivo_factoriales) {
    int num, factorial, i;

    while (fread(&num, sizeof(num), 1, archivo_enteros) == 1) {
        factorial = 1;
        for (i = 2; i <= num; i++) {
            factorial *= i;
        }
        fwrite(&factorial, sizeof(factorial), 1, archivo_factoriales);
    }
}

int main() {
    FILE *arNumEnteros, *arFactoriales;
    arNumEnteros = fopen("num_enteros.dat", "rb");
    arFactoriales = fopen("num_factoriales.dat", "wb");

    if (arNumEnteros == NULL || arFactoriales == NULL) {
        printf("\nNo se pudo crear el archivo\n");
    }
    else {
        generar_archivo_factoriales(arNumEnteros, arFactoriales);
        fclose(arNumEnteros);
        fclose(arFactoriales);
    }    

    return 0;
}