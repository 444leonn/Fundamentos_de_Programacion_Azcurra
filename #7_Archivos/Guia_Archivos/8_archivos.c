/*
* Leer un archivo de caracteres que representa un texto formado por oraciones terminadas en punto. 
* Calcular la cantidad de monosílabos que hay en el texto, la longitud promedio de las palabras y la cantidad de palabras.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void menu(int *option) {
    printf("\n--------------------------------------------------\n");
    printf("1) Contar Monsilabos.\n");
    printf("2) Contar palabras.\n");
    printf("3) Longitud promedio de palabras.\n");
    printf("4) SALIR.\n");
    printf("--------------------------------------------------\n");
    printf("Seleccione una opcion:  ");
    scanf("%d", option);
    printf("\n");
}

int contar_palabras(FILE *archivo) {
    int cantidad = 0;
    char caracter_actual, caracter_anterior = ' ';
    
    fread(&caracter_actual, sizeof(char), 1, archivo);
    while (!feof(archivo)) {
        if ((caracter_actual == ' ' || caracter_actual == '\n' || caracter_actual == '.') && caracter_anterior != ' ' && caracter_anterior != '\n' && caracter_anterior != '.') {
            cantidad++;
        }
        caracter_anterior = caracter_actual;
        fread(&caracter_actual, sizeof(char), 1, archivo);
    }

    if (caracter_anterior != ' ' && caracter_anterior != '\n' && caracter_anterior != '.') {
        cantidad++;
    }
    return cantidad;
}

int contar_monosilabos(FILE *archivo) {
    int monosilabos = 0;
    int longitud_palabra = 0;
    char caracter_actual, caracter_anterior = ' ';
    int leidos = 0;

    fread(&caracter_actual, sizeof(char), 1, archivo);
    while (!feof(archivo)) {
        if ((caracter_actual == ' ' || caracter_actual == '\n' || caracter_actual == '.') && 
            (caracter_anterior != ' ' && caracter_anterior != '\n' && caracter_anterior != '.')) {
            if (longitud_palabra == 1) {
                monosilabos++;
            }
            longitud_palabra = 0;
        } 
        else if (caracter_actual != ' ' && caracter_actual != '\n' && caracter_actual != '.') {
            longitud_palabra++;
        }
        caracter_anterior = caracter_actual;
        fread(&caracter_actual, sizeof(char), 1, archivo);
    }

    if (longitud_palabra == 1) {
        monosilabos++;
    }

    return monosilabos;
}

int calcular_longitud_total(FILE *archivo) {
    int longitud_total = 0;
    char caracter_actual, caracter_anterior = ' ';
    
    fread(&caracter_actual, sizeof(char), 1, archivo);
    while (!feof(archivo)) {
        if (caracter_actual != ' ' && caracter_actual != '\n' && caracter_actual != '.') {
            longitud_total++;
        }
        caracter_anterior = caracter_actual;
        fread(&caracter_actual, sizeof(char), 1, archivo);
    }
    
    return longitud_total;
}

int main() {
    int opt;
    int cant_palabras, cant_monosilabos, longitud_total;
    double longitud_promedio;
    FILE *archivo_texto;

    menu(&opt);
    while (opt != 4) {
        switch (opt) {
            case 1:
            // Contar palabras
                archivo_texto = fopen("./prueba_ej_7.txt", "r");
                if (archivo_texto == NULL) {
                    printf("Error, no se ha podido abrir el archivo.\n");
                    return 1;
                }
                cant_palabras = contar_palabras(archivo_texto);
                fclose(archivo_texto);

                printf("Cantidad total de palabras:  %d .\n", cant_palabras);
                
                break;

            case 2:
            // Contar monosílabos
                archivo_texto = fopen("./prueba_ej_7.txt", "r");
                if (archivo_texto == NULL) {
                    printf("Error, no se ha podido abrir el archivo.\n");
                    return 1;
                }
                cant_monosilabos = contar_monosilabos(archivo_texto);
                fclose(archivo_texto);

                printf("Cantidad total de monosilabos:  %d .\n", cant_monosilabos);
                
                break;
            
            case 3:
            // Calcular longitud total
                archivo_texto = fopen("./prueba_ej_7.txt", "r");
                if (archivo_texto == NULL) {
                    printf("Error, no se ha podido abrir el archivo.\n");
                    return 1;
                }
                longitud_total = calcular_longitud_total(archivo_texto);
                fclose(archivo_texto);
                
                // Calcular longitud promedio
                if (cant_palabras > 0) {
                    longitud_promedio = (double)longitud_total / cant_palabras;
                } else {
                    longitud_promedio = 0;
                }

                printf("Longitud promedio de las palabras:  %lf .\n", longitud_promedio);
                
                break;
            
            default:
                printf("Error, opcion invalida.\n");
                break;
        }
        menu(&opt);
    }

    return 0;
}