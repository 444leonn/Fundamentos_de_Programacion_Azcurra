/*
* Dado un archivo de números enteros, generar otro archivo que contenga aquellos que son primos en el primero.
*/

#include <stdio.h>

void cargar_primos(FILE *archivo_enteros, FILE *archivo_primos) {
    int num, i, resto;

    while (fread(&num, sizeof(num), 1, archivo_enteros) == 1) {
        i = 2;
        resto = num % i;
        while (i < num && resto != 0) {       
            resto = num % i;
            i++;
        }
        if (resto != 0) {
            fwrite(&num, sizeof(num), 1, archivo_primos);
        }
    }

}

int main() {
    FILE *arch_enteros, *arch_primos;
    arch_enteros = fopen("./num_enteros.dat", "rb");
    arch_primos = fopen("./num_primos.dat", "wb");

    if (arch_enteros == NULL || arch_primos == NULL) {
        printf("\nNo se ha podido crear el archivo.\n");
    }
    else {
        printf("Creando archivos de numeros primos del archivo de enteros....\n");
        cargar_primos(arch_enteros, arch_primos);
        fclose(arch_enteros);
        fclose(arch_primos);
        printf("Archivo creado.\n");
    }
    
    return 0;
}