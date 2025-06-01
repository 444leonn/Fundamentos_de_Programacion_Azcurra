/*
* Una empresa de venta de productos alimenticios posee los siguientes listados:
*     Listado de Stock:
*         Código de producto (entero de 4 cifras)
*         Cantidad en stock (real mayor que cero)
*     Listado de Productos:
*         Código de producto (entero de 4 cifras)
*         Descripción (cadena de 200)
*         Precio unitario (real)
*     Listado de Ventas:
*         Código de producto (entero de 4 cifras)
*         Cantidad vendida en una venta (entero)
* Los listados de Stock y Productos están ordenados por código y no necesariamente todos los registros de uno están en el otro. El listado de ventas corresponde a un día y no está ordenado.
* Se pide:
*     a) Listar por pantalla la cantidad total vendida por producto.
*     b) Listar por pantalla el monto de venta por producto y el monto total.
*     c) Listar por pantalla el stock actualizado por producto, eliminando de la misma aquellos productos sin existencia y generando una lista aparte de faltantes.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 200
#define MAX_TABLA 100

typedef char str[MAX];

typedef struct {
    int codigo_producto;
    float cant_stock;
} t_stock;

typedef struct {
    int codigo_producto;
    str descripcion;
    float precio_unitario;
} t_producto;

typedef struct {
    int codigo_producto;
    int cant_ventas;
} t_venta;

void calc_cant_ventas(t_producto vec_productos[MAX_TABLA], int ML_PROD, t_venta vec_ventas[MAX_TABLA], int ML_VENTAS, int vec_cant_ventas[MAX_TABLA]) {
    int i, j, cant_vendida;

    for (i = 0; i < ML_PROD; i++) {
        cant_vendida = 0;

        for (j = 0; j < ML_VENTAS; j++) {
            if (vec_ventas[j].codigo_producto == vec_productos[i].codigo_producto) {
                cant_vendida += vec_ventas[j].cant_ventas;
            }
        }
        vec_cant_ventas[i] = cant_vendida;
    }
}

void mostrar_ventas(t_producto vec_productos[MAX_TABLA], int ML_PROD, int vec_cant_ventas[MAX_TABLA]) {
    int i;

    printf("Cantidad de ventas por producto: \n");

    for (i = 0; i < ML_PROD; i++)
        printf("%d  %s  %d\n", vec_productos[i].codigo_producto, vec_productos[i].descripcion, vec_cant_ventas[i]);
}

float mostrar_monto_ventas(t_producto vec_productos[MAX_TABLA], int ML_PROD, int vec_cant_ventas[MAX_TABLA]) {
    int i;
    float monto_produto, monto_total = 0;

    for (i = 0; i < ML_PROD; i++) {
        monto_produto = vec_productos[i].precio_unitario * vec_cant_ventas[i];

        printf("%d  %s:  %.2f\n", vec_productos[i].codigo_producto, vec_productos[i].descripcion, monto_produto);

        monto_total += monto_produto;
    }

    return monto_total;
}

void actualizar_stock(t_stock vec_stock[MAX_TABLA], int ML_STOCK, t_venta vec_ventas[MAX_TABLA], int ML_VENTAS) {
    int i, j, h = 0;

    for (i = 0; i < ML_STOCK; i++) {
        for (j = 0; j < ML_VENTAS; j++) {
            if (vec_stock[i].codigo_producto == vec_ventas[j].codigo_producto) {
                vec_stock[i].cant_stock -= vec_ventas[j].cant_ventas;
            }
        }
    }
}

void mostrar_stock(t_stock vec_stock[MAX_TABLA], int ML_STOCK, t_producto vec_productos[MAX_TABLA]) {
    int i;

    for (i = 0; i < ML_STOCK; i++)
        printf("%d %s %.2f\n", vec_stock[i].codigo_producto, vec_productos[i].descripcion, vec_stock[i].cant_stock);
}

void lista_faltantes(t_stock vec_stockp)

int main() {
    int ml_stock, ml_productos, ml_ventas, ml_ventas_por_producto;
    int ventas_por_producto[MAX_TABLA];
    float total_ventas;

    t_stock stock[MAX_TABLA] = {
        {1001, 150},
        {1002, 40},
        {1003, 16},
        {1004, 50}
    };

    t_producto productos[MAX_TABLA] = {
        {1001, "Pan", 10.00},
        {1002, "Fideos", 20.00},
        {1003, "Leche", 5.00},
        {1004, "Café", 8.00}
    };

    t_venta ventas[MAX_TABLA] = {
        {1004, 7},
        {1001, 8},
        {1002, 20},
        {1001, 3},
        {1003, 1},
        {1003, 5},
        {1004, 3},
        {1002, 20},
        {1003, 10}
    };

    ml_stock = 4;
    ml_productos = 4;
    ml_ventas = 9;

    ml_ventas_por_producto = ml_productos;
    
    // Uso una funcion con un vector auxiliar para almacenar la cantidad de ventas por producto.
    calc_cant_ventas(productos, ml_productos, ventas, ml_ventas, ventas_por_producto);
    mostrar_ventas(productos, ml_productos, ventas_por_producto);

    printf("\n");

    printf("Ventas por producto:\n");
    total_ventas = mostrar_monto_ventas(productos, ml_productos, ventas_por_producto);
    printf("\nMonto Total: %.3f\n", total_ventas);

    printf("\n");

    actualizar_stock(stock, ml_stock, ventas, ml_ventas);
    printf("Stock Actualizado:\n");
    mostrar_stock(stock, ml_stock, productos);

    printf("\n");
    
    return 0;
}