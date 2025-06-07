// En este ejemplo veremos como crear un archivo binario y cargarlo con datos.

#include <stdio.h>
#include <string.h>

typedef struct {
    int codigo;
    char descripcion[30];
    float cantidad;
} t_regProducto;

void cargar_datos(FILE *arProductos) {
    t_regProducto rProducto;

    printf("Codigo de Articulo: ");
    scanf("%d", &rProducto.codigo);
    fflush(stdin);

    while (rProducto.codigo != 0) {
        printf("Descripcion: ");
        scanf("%30[^\n]s", rProducto.descripcion);
        fflush(stdin);

        printf("Cantidad en Stock: ");
        scanf("%f", &rProducto.cantidad);
        fflush(stdin);

        fwrite(&rProducto, sizeof(t_regProducto), 1, arProductos);

        printf("\nCodigo de Articulo: ");
        scanf("%d", &rProducto.codigo);
        fflush(stdin);
    }
}

int main(void) {
    FILE *arProductos = fopen("productos.dat", "wb");

    if (arProductos == NULL) {
        printf("\nNo se pudo crear el archivo!\n");
    } else {
        cargar_datos(arProductos);
        fclose(arProductos);
    }

    return 0;
}