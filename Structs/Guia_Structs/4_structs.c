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
} listado_stock;

typedef struct {
    int codigo_producto;
    str descripcion;
    float precio_unitario;
} listado_productos;

typedef struct {
    int codigo_producto;
    int cant_ventas;
} listado_ventas;