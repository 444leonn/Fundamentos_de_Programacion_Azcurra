/*
Una farmacia dispone de un archivo binario llamado "medicamentos.dat", cuyos registros tienen la siguiente estructura:
- código (entero)
- categoría (cadena de hasta 25 caracteres, ej. "analgésicos", "antibióticos", etc.)
- nombre_comercial (cadena de hasta 30 caracteres)
- stock_actual (entero)
El archivo no está ordenado y no entra completamente en memoria.

Desarrollar un programa modular que permita:
- Solicitar al usuario una categoría.
- Generar una tabla en memoria llamada "medxcat" que contenga todos los medicamentos de esa categoría.  
   La tabla debe tener la misma estructura que el archivo original.
- Suponer que la tabla tiene como máximo 200 registros y entra en memoria.
- Mostrar por pantalla los medicamentos de "medxcat" cuyo stock_actual sea superior al stock promedio dentro de esa categoría.
*/

#include <stdio.h>
#include <string.h>

#define MAX_TABLA 200

typedef struct {
    int codigo;
    char categoria[25];
    char nombre_comercial[30];
    int stock_actual;
} t_medicamento;

void ingresar_categoria(char categoria[25]) {
    printf("Ingrese una categoria:  ");
    scanf("%s", categoria);
}

void generar_tabla(FILE *archivo, char categoria[], t_medicamento tabla_medicamentos[MAX_TABLA], int *ML) {
    int i = 0;
    t_medicamento medicamento_aux;

    fread(&medicamento_aux, sizeof(t_medicamento), 1, archivo);
    while (!feof(archivo) && i < MAX_TABLA) {
        if (strcmp(medicamento_aux.categoria, categoria) == 0) {
            tabla_medicamentos[i] = medicamento_aux;
            i++;
        }
        fread(&medicamento_aux, sizeof(t_medicamento), 1, archivo);
    }

    *ML = i;
}

float calcular_stock_promedio(t_medicamento tabla_medicamentos[MAX_TABLA], int ML) {
    int i, acum = 0;
    for (i = 0; i < ML; i++) {
        acum += tabla_medicamentos[i].stock_actual;
    }

    return ((float) acum / ML);
}

void mostrar_medicamentos(t_medicamento tabla_medicamentos[MAX_TABLA], int ML, float stock_promedio) {
    int i;
    for (i = 0; i < ML; i++) {
        if (tabla_medicamentos[i].stock_actual > stock_promedio) {
            printf("DATOS DEL MEDICAMENTO.\n");
            printf("Codigo: %d\n", tabla_medicamentos[i].codigo);
            printf("Categoria:  %s\n", tabla_medicamentos[i].categoria);
            printf("Nombre Comercial:  %s\n", tabla_medicamentos[i].nombre_comercial);
            printf("Stock Actual:  %d\n", tabla_medicamentos[i].stock_actual);
            printf("\n");
        }
    }
}

int main() {
    t_medicamento medxcat[MAX_TABLA];
    int ml;
    char categoria_ingresada[25];
    float stock_prom;
    FILE *arc_medicamentos;
    
    arc_medicamentos = fopen("medicamentos.dat", "rb");

    if (arc_medicamentos == NULL) {
        printf("Error, no se pudo abrir el archivo.\n");
    }
    else {
        ingresar_categoria(categoria_ingresada);

        generar_tabla(arc_medicamentos, categoria_ingresada, medxcat, &ml);

        stock_prom = calcular_stock_promedio(medxcat, ml);
        printf("\nStock Promedio de la tabla: %.2f.\n\n", stock_prom);

        mostrar_medicamentos(medxcat, ml, stock_prom);

        fclose(arc_medicamentos);
    }
    
    return 0;
}