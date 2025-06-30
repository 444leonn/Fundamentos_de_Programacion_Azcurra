/*
* Un supermercado posee un archivo denominado Stock.dat, 
* cuyos registros contienen el código de producto (entero), rubro (25 caracteres), el nombre (30 caracteres) y el stock actual (entero).
* Dicho archivo no está ordenado y "no entra" en memoria en su totalidad.
*
* Se pide desarrollar un programa modular en lenguaje C que procese este archivo y permita:
*   a) Desarrollar un modulo de carga de la información, la misma debe guardarse en el archivo Stock.dat.
*   La carga finaliza cuando el usuario ingresa un código de producto igual a cero.
*   b) Solicitar al usuario el ingreso de un rubro para luego generar una tabla llamada dat_rubro que contenga los productos pertenecientes al rubro ingresado (con la misma estructura del archivo).
*   Asumir que esta tabla tendrá como máximo 200 registros, y que cabe en memoria.
*   c) Mostrar por pantalla un listado de los productos cargados en la tabla del punto "b" cuyo stock sea superior al stock promedio de la tabla.
*   d) A partir de la tabla del punto "b", generar un archivo de texto con los códigos de productos que tengan un stock menor a 25 unidades.
*/

#include <stdio.h>
#include <string.h>

#define MAX_CHAR_NOMBRE 30
#define MAX_CHAR_RUBRO 25
#define MAX_REGISTROS 200
#define STOCK_MAX 25

typedef struct {
    int codigo;
    char rubro[MAX_CHAR_RUBRO];
    char nombre[MAX_CHAR_NOMBRE];
    int stock_actual;
} T_Producto;

void menu(int *opcion) {
    printf("\n------------------------\n");
    printf("1) Cargar Stock.\n");
    printf("2) Generar tabla por Rubro.\n");
    printf("3) Mostrar productos con stock mayor al promedio.\n");
    printf("4) Generar txt con codigos de productos cuyo stock es menor a 25.\n");
    printf("5) Salir.");
    printf("\n------------------------\n");
    printf("Seleccione una opcion:  ");
    scanf("%d", opcion);

    printf("\n");
}

void cargar_productos() {
    T_Producto producto;
    FILE *ar_stock;
    ar_stock = fopen("Stock.dat", "ab");

    printf("Ingrese los datos del/los producto/s (codigo = 0 para terminar).\n");

    printf("Codigo: ");
    scanf("%d", &producto.codigo);

    while (producto.codigo != 0) {
        printf("Rubro: ");
        scanf(" %24[^\n]", producto.rubro);

        printf("Nombre: ");
        scanf(" %29[^\n]", producto.nombre);

        printf("Stock Actual: ");
        scanf("%d", &producto.stock_actual);

        fwrite(&producto, sizeof(T_Producto), 1, ar_stock);

        printf("\n");

        printf("Codigo: ");
        scanf("%d", &producto.codigo);
    }

    fclose(ar_stock);
}

void generar_tabla_rubro(T_Producto tabla_dat_rubro[MAX_REGISTROS], int *ml) {
    int i = 0;
    char rubro_buscado[MAX_CHAR_RUBRO];
    T_Producto producto;
    FILE *ar_stock;

    ar_stock = fopen("Stock.dat", "rb");

    *ml = 0;
    if (ar_stock == NULL) {
        printf("No se pudo abrir el archivo.\nDebe cargar stock primero.\n");
    }
    else {
        printf("Ingrese el rubro: ");
        scanf(" %24[^\n]", rubro_buscado);

        fread(&producto, sizeof(T_Producto), 1, ar_stock);

        while (!feof(ar_stock) && i < MAX_REGISTROS) {
            if (strcmp(producto.rubro, rubro_buscado) == 0) {
                tabla_dat_rubro[i] = producto;
                i++;
            }
            fread(&producto, sizeof(T_Producto), 1, ar_stock);
        }

        *ml = i;

        printf("Tabla Generada.\n");

        fclose(ar_stock);
    }
}

void mostrar_prod_stock_mayor_prom(T_Producto tabla_dat_rubro[MAX_REGISTROS], int ml, int stock_promedio) {
    int i;

    for (i = 0; i < ml; i++) {
        if (tabla_dat_rubro[i].stock_actual > stock_promedio) {
            printf("\nProducto: \n");
            printf("Codigo: %d\n", tabla_dat_rubro[i].codigo);
            printf("Rubro: %s\n", tabla_dat_rubro[i].rubro);
            printf("Nombre: %s\n", tabla_dat_rubro[i].nombre);
            printf("Stock Actual: %d\n", tabla_dat_rubro[i].stock_actual);
        }
    }
}

void generar_txt_codigos_prod(T_Producto tabla_dat_rubro[MAX_REGISTROS], int ml) {
    int i;
    FILE *ar_txt;
    ar_txt = fopen("codigos_productos.txt", "w");

    if (ar_txt == NULL) {
        printf("No se pudo abrir el archivo.\nDebe cargar stock primero.\n");
    }
    else {
        for (i = 0; i < ml; i++) {
            if (tabla_dat_rubro[i].stock_actual < STOCK_MAX) {
                fprintf(ar_txt, "Codigo: %d\n", tabla_dat_rubro[i].codigo);
            }
        }
    }

    fclose(ar_txt);
}

void calcular_promedio_tabla(T_Producto tabla_dat_rubro[MAX_REGISTROS], int ml, float *stock_promedio) {
    int i, acum_stock = 0;

    *stock_promedio = 0;

    for (i = 0; i < ml; i++) {
        acum_stock += tabla_dat_rubro[i].stock_actual;
    }

    *stock_promedio = (float) acum_stock / i;
}

int main() {
    int opc, ML_rubros;
    float prom_stock;
    T_Producto dat_rubro[MAX_REGISTROS];

    menu(&opc);
    while (opc != 5) {
        switch (opc) {
            case 1:
                cargar_productos();
                break;
            
            case 2:
                generar_tabla_rubro(dat_rubro, &ML_rubros);
                break;
            
            case 3:
                calcular_promedio_tabla(dat_rubro, ML_rubros, &prom_stock);
                printf("Productos cuyo stock es mayor a %.2f.\n", prom_stock);
                mostrar_prod_stock_mayor_prom(dat_rubro, ML_rubros, prom_stock);
                break;

            case 4:
                generar_txt_codigos_prod(dat_rubro, ML_rubros);
                printf("Se genero el archivo TXT con los codigos de los archivos cuyo stock es menor a %d\n", STOCK_MAX);
                break;
            
            default:
                printf("Error, opcion invalida.\n");
                break;
        }
        menu(&opc);
    }

    printf("Nos vemos.\n");

    return 0;
}