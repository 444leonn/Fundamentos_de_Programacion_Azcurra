/*
* Definir un struct Producto: código (int), descripción (string 50), precio (float), stock (int).
* Permitir registrar hasta 50 productos.
* Implementar función para buscar un producto por código y mostrarlo.
* Función para descontar stock de un producto dado su código y cantidad.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PRODUCTOS 50

typedef struct {
    int codigo;
    char descripcion[50];
    float precio;
    int stock;
} T_Producto;

void ingresar_codigo(int *codigo) {
    printf("Ingrese un codigo de producto para buscarlo:  ");
    scanf("%d", codigo);
}

bool buscar_por_codigo(T_Producto tabla[], int ML, int codigo_buscado) {
    int i;
    bool encontrado = false;

    i = 0;
    while (i < ML && !encontrado) {
        if (tabla[i].codigo == codigo_buscado) {
            printf("\nProducto encontrado.\n");
            printf("DATOS DEL PRODUCTO.\n");
            printf("Codigo: %d, Descripcion: %s, Precio: %.2f, Stock: %d.\n", tabla[i].codigo, tabla[i].descripcion, tabla[i].precio, tabla[i].stock);
            encontrado = true;
        }
        i++;
    }

    return encontrado;
}

int main() {
    int cod_buscado;
    bool encontrado;
    T_Producto productos[] = {
        {1001, "Monitor LED 24 pulgadas", 45000.50, 15},
        {1002, "Teclado mecánico RGB", 12500.75, 25},
        {1003, "Mouse inalámbrico", 5800.00, 30},
        {1004, "Auriculares Bluetooth", 18000.25, 10},
        {1005, "Webcam HD", 9500.00, 20},
        {1006, "Microfono", 16000.3, 5}
    };
    int cant_productos = 6;
    
    ingresar_codigo(&cod_buscado);
    encontrado = buscar_por_codigo(productos, cant_productos, cod_buscado);
    if (!encontrado) {
        printf("No se ha encontrado el producto.\n");
    }

    return 0;
}