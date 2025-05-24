/*
* Dada la estructura de datos del problema anterior, escribir el algoritmo de búsqueda binaria para la búsqueda de un dato
* correspondiente a los campos de Apellido, Nombre o número de legajo, a elección del usuario.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NOMBRE 35
#define MAX_DIR 50

typedef struct {
    int dia;
    int mes;
    int anio;
} T_Fecha;

typedef struct {
    char calle[MAX_DIR];
    int altura;
    char localidad[MAX_DIR];
    char provincia[MAX_DIR];
    int cp;
} T_Direccion;

typedef struct {
    char apellido[MAX_NOMBRE];
    char nombre[MAX_NOMBRE];
    int legajo;
    T_Direccion direccion;
    T_Fecha fecha_nacimiento;
    T_Fecha fecha_Ingreso;
} T_Empleado;

