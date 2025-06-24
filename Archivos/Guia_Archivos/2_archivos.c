/*
* Dado un archivo de números enteros, generar otro archivo que contenga aquellos que son primos en el primero.
*/

#include <stdio.h>

void menu(int *opcion) {
    printf("\n------------------------\n");
    printf("| 1) Cargar Archivo.\n");
    printf("| 2) Generar Archivo Nuevo con los numeros primos.\n");
    printf("| 3) Mostrar Archivo Generado.\n");
    printf("| 4) Salir.\n");
    printf("------------------------\n");
    printf("Seleccione una opcion: ");
    scanf("%d", opcion);
}

void mostrar_archivo_enteros(FILE *archivo) {
    int num;

    printf("Dentro del archivo hay...\n");

    fread(&num, sizeof(num), 1, archivo);
    while (!feof(archivo)) {
        printf("%d ", num);
        fread(&num, sizeof(num), 1, archivo);
    }
    printf("\n");
}

void cargar_enteros(FILE *archivo_enteros) {
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    while (num >= 0) {
        fwrite(&num, sizeof(num), 1, archivo_enteros);
        
        printf("Ingrese otro numero: ");
        scanf("%d", &num);
    }
}

void cargar_primos(FILE *archivo_enteros, FILE *archivo_primos) {
    int num, i, resto;

    fread(&num, sizeof(num), 1, archivo_enteros);
    while (!feof(archivo_enteros)) {
        i = 2;
        resto = num % i;
        while (i < num && resto != 0) {       
            resto = num % i;
            i++;
        }
        if (resto != 0) {
            fwrite(&num, sizeof(num), 1, archivo_primos);
        }
        fread(&num, sizeof(num), 1, archivo_enteros);
    }

}

int main() {
    int opc;
    FILE *arch_enteros, *arch_primos;

    menu(&opc);
    while (opc != 4) {
        switch (opc) {
            case 1:
                arch_enteros = fopen("./num_enteros.dat", "wb");
                if (arch_enteros == NULL) {
                    printf("\nNo se ha podido crear el archivo.\n");
                }
                else {
                    cargar_enteros(arch_enteros);
                    fclose(arch_enteros);
                }
                break;
            
            case 2:
                arch_enteros = fopen("./num_enteros.dat", "rb");
                arch_primos = fopen("./num_primos.dat", "wb");
                if (arch_enteros == NULL || arch_primos == NULL) {
                    printf("\nNo se ha podido crear el archivo.\n");
                }
                else {
                    printf("Creando archivos de numeros primos del archivo de enteros....\n");
                    cargar_primos(arch_enteros, arch_primos);
                    printf("Archivo creado.\n");
                    fclose(arch_enteros);
                    fclose(arch_primos);
                }
                break;
            
            case 3:
                arch_primos = fopen("./num_primos.dat", "rb");
                if (arch_primos == NULL) {
                    printf("\nNo se ha podido abrir el archivo.\n");
                }
                else {
                    mostrar_archivo_enteros(arch_primos);
                    fclose(arch_primos);
                }
                break;
                
            default:
                printf("Error, debes selecionar una opcion valida.\n");
                break;
        }
        menu(&opc);
    }

    printf("Nos vemos.\n");
    
    return 0;
}