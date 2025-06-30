/*
* Dados dos archivos de números enteros de 5 dígitos ordenados en forma creciente, generar un archivo que contenga todos los números, ordenado de igual forma.
* No hay números repetidos.
*/

#include <stdio.h>

void menu(int *opcion) {
    printf("\n------------------------\n");
    printf("| 1) Cargar Archivos.\n");
    printf("| 2) Generar Archivo Nuevo con los numeros ordenados.\n");
    printf("| 3) Mostrar Archivo Generado.\n");
    printf("| 4) Salir.\n");
    printf("------------------------\n");
    printf("Seleccione una opcion: ");
    scanf("%d", opcion);
}

void cargar_archivos(FILE *archivo_1, FILE *archivo_2) {
    long numero_1, numero_2;

    printf("Carga del primer archivo.\n");
    printf("Ingrese un numero entero de 5 digitos: ");
    scanf("%ld", &numero_1);

    while (numero_1 >= 0) {
        fwrite(&numero_1, sizeof(numero_1), 1, archivo_1);

        printf("Ingrese un numero entero de 5 digitos: ");
        scanf("%ld", &numero_1);
    }

    printf("Carga del segundo archivo.\n");
    printf("Ingrese un numero entero de 5 digitos: ");
    scanf("%ld", &numero_2);

    while (numero_2 >= 0) {
        fwrite(&numero_2, sizeof(numero_2), 1, archivo_2);

        printf("Ingrese un numero entero de 5 digitos: ");
        scanf("%ld", &numero_2);
    }
}

void mostrar_archivo_enteros(FILE *archivo) {
    long num;

    printf("Dentro del archivo hay...\n");

    fread(&num, sizeof(num), 1, archivo);
    while (!feof(archivo)) {
        printf("%ld ", num);
        fread(&num, sizeof(num), 1, archivo);
    }
    printf("\n");
}

void generar_archivo_ordenado(FILE *archivo_final, FILE *archivo_1, FILE *archivo_2) {
    long num_1, num_2;

    fread(&num_1, sizeof(num_1), 1, archivo_1);
    fread(&num_2, sizeof(num_2), 1, archivo_2);

    while (!feof(archivo_1) && !feof(archivo_2)) {
        if (num_1 < num_2) {
            fwrite(&num_1, sizeof(num_1), 1, archivo_final);
            fwrite(&num_2, sizeof(num_2), 1, archivo_final);
        }
        else {
            fwrite(&num_2, sizeof(num_2), 1, archivo_final);
            fwrite(&num_1, sizeof(num_1), 1, archivo_final);
        }

        fread(&num_1, sizeof(num_1), 1, archivo_1);
        fread(&num_2, sizeof(num_2), 1, archivo_2);
    }
}

int main() {
    int opc;
    FILE *archivo_enteros_1, *archivo_enteros_2, *archivo_final;

    menu(&opc);
    while (opc != 4) {
        switch (opc) {
            case 1:
                archivo_enteros_1 = fopen("./archivo_enteros_1.dat", "wb");
                archivo_enteros_2 = fopen("./archivo_enteros_2.dat", "wb");
                if (archivo_enteros_1 == NULL || archivo_enteros_2 == NULL) {
                    printf("No se pudo crear el archivo.\n");
                }
                else {
                    cargar_archivos(archivo_enteros_1, archivo_enteros_2);
                    fclose(archivo_enteros_1);
                    fclose(archivo_enteros_2);
                }
                break;

            case 2:
                archivo_enteros_1 = fopen("./archivo_enteros_1.dat", "rb");
                archivo_enteros_2 = fopen("./archivo_enteros_2.dat", "rb");
                if (archivo_enteros_1 == NULL || archivo_enteros_2 == NULL) {
                    printf("No se pudo crear el archivo.\nDebe realizar la carga primero.\n");
                }
                else {
                    archivo_final = fopen("./archivo_final.dat", "wb");
                    generar_archivo_ordenado(archivo_final, archivo_enteros_1, archivo_enteros_2);
                    fclose(archivo_enteros_1);
                    fclose(archivo_enteros_2);
                    fclose(archivo_final);
                }
                break;
            
            case 3:
                archivo_final = fopen("./archivo_final.dat", "rb");
                if (archivo_final == NULL) {
                    printf("No se pudo crear el archivo.\nDebe generarlo primero.\n");
                }
                else {
                    mostrar_archivo_enteros(archivo_final);
                    fclose(archivo_final);
                }
                break;
            
            default:
                printf("Error, debes selecionar una opcion valida.\n");
                break;
        }
        menu(&opc);
    }
    
    printf("\n NOS VEMOS. \n");

    return 0;
}