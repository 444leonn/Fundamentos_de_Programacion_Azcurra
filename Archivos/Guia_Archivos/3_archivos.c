/*
* Dado un archivo de números enteros entre 0 y 255, imprimir los caracteres correspondientes según el código Ascii.
*/

#include <stdio.h>

void crear_archivo_ascii(FILE *archivo_enteros, FILE *archivo_ascii) {
    return;
}

int main() {
    FILE *ar_enteros, *ar_ascii;
    ar_enteros = fopen("./num_enteros.dat", "r");
    ar_ascii = fopen("./ascii.dat", "wb");

    if (ar_enteros == NULL || ar_ascii == NULL) {
        printf("\nNo se ha podido crear el archivo.\n");
    }
    else {
        printf("Creando archivo con los caracteres ASCII...\n");
        crear_archivo_ascii(ar_enteros, ar_ascii);
        fclose(ar_enteros);
        fclose(ar_ascii);
    }
    
    return 0;
}