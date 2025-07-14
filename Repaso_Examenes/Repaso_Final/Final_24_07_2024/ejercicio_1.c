/*
* 1. Una libreria posee un archivo denominado `Stock.dat`, cuyos registros contienen
* el `codigo del libro` (entero), el `titulo` (30 caracteres), el `stock actual` de dicho libro (entero), 
* el `stock minimo` de dicho libro (entero) y el `precio unitario` (real). 
* Dicho archivo no esta ordenado y "NO ENTRA" en memoria en su totalidad.
*
* Se pide desarrollar un programa modular en lenguaje C que procese este archivo y que permita:
* - Generar una tabla llamada `Ofertas` que contenga solo los libros cuyo stock actual esta por encima del doble del stock minimo.
*  Incluir en la tabla los siguientes campos:
*   - El `codigo` del libro (entero)
*   - El `titulo` del libro (30 caracteres).
*   - La `cantidad` de libros a ofertar (entero, a lo sumo se pueden ofertar la mitad de los libros que estan por sobre el stock minimo).
*   - El `precio` unitario de oferta (real, el descuento de la oferta es del 30%).
* Asumir que esta tabla tendra como maximo 100 registros y que cabe en memoria.
* - Ordenar la tabla Ofertas ascendentemenete por titulo del libro.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TABLA 100

typedef struct {
    int codigo;
    char titulo[30];
    int stock_actual;
    int stock_minimo;
    float precio;
} T_Libro;

typedef struct {
    int codigo;
    char titulo[30];
    int cantidad;
    float precio;
} T_Oferta;

void generar_tabla(FILE *archivo, T_Oferta tabla[], int *ML) {
    int i = 0;
    T_Libro aux;

    fread(&aux, sizeof(T_Libro), 1, archivo);
    while (!feof(archivo) && i < MAX_TABLA) {
        if (aux.stock_actual > (2 * aux.stock_minimo)) {
            tabla[i].codigo = aux.codigo;
            strcpy(tabla[i].titulo, aux.titulo);
            tabla[i].cantidad = (aux.stock_actual - aux.stock_minimo) / 2;
            tabla[i].precio = aux.precio * 0.7;
            i++;
        }
        fread(&aux, sizeof(T_Libro), 1, archivo);
    }

    *ML = i;
}

void ordenar_tabla(T_Oferta tabla[], int ML) {
    int i = 1, j;
    T_Oferta aux;
    bool continuar;

    while ((i < ML) && continuar) {
        continuar = false;
        for (j = 0; j < ML - i; j++) {
            if (strcmp(tabla[j].titulo, tabla[j + 1].titulo) > 0) {
                aux = tabla[j];
                tabla[j] = tabla[j + 1];
                tabla[j + 1] = aux;
                continuar = true;
            }
        }
        i++;
    }
}

void mostrar_tabla(T_Oferta tabla[], int ML) {
    
}

int main() {
    FILE *arc_stock;
    T_Oferta ofertas[MAX_TABLA];
    int ml;

    arc_stock = fopen("stock.dat", "rb");
    if (arc_stock == NULL) {
        printf("Error, no se ha podido abrir el archivo.\n");
    }
    else {
        generar_tabla(arc_stock, ofertas, &ml);
        fclose(arc_stock);

        ordenar_tabla(ofertas, ml);
        mostrar_tabla(ofertas, ml); 
    }

    return 0;
}