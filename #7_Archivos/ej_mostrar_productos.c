// En este ejemplo veremos como mostrar los datos que fueron guardados.

#include <stdio.h>

typedef struct {
    int codigo;
    char descripcion[30];
    float cantidad;
} t_regProducto;

void mostrar_datos(FILE *arProductos) {
    t_regProducto rProducto;

    printf("\nCodigo \tDescripcion \t\t\tCantidad");

    while (fread(&rProducto, sizeof(t_regProducto), 1, arProductos) == 1) {
        printf("\n%5d \t%-30s %8.2f", rProducto.codigo, rProducto.descripcion, rProducto.cantidad);
    }
}

int main(void) {
    FILE *arProductos;

    // Abrimos el archivo en modo lectura
    arProductos = fopen("productos.dat", "rb");

    if (arProductos == NULL) {
        printf("\nNo se pudo abrir el archivo!\n");
    } else {
        mostrar_datos(arProductos);
        fclose(arProductos);
    }

    return 0;
}