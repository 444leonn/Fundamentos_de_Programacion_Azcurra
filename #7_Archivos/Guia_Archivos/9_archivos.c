/*
* Se tiene un archivo con los siguientes datos de los empleados de una empresa:
*   Apellido
*   Nombre (35 caracteres)
*   Fecha de Nacimiento (día, mes y año)
*   Fecha de Ingreso (día , mes y año)
*   Sueldo Básico
* Se conoce la fecha de procesamiento.
* Se pide:
*   a) imprimir un listado con los apellidos y nombres de las personas que cumplen años en el mes.
*   b) Calcular e informar una suma de regalo equivalente al uno por mil del sueldo por cada año cumplido.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STR 35

typedef struct {
    char nombre[MAX_STR];
    char apellido[MAX_STR];
} T_Nombre;

typedef struct {
    int dia;
    int mes;
    int anio;
} T_Fecha_Nacimiento;

typedef struct {
    int dia;
    int mes;
    int anio;
} T_Fecha_Ingreso;

typedef struct {
    T_Nombre nombre;
    T_Fecha_Nacimiento fecha_nacimiento;
    T_Fecha_Ingreso fecha_ingreso;
    long sueldo_basico;
} T_Empleado;



int main() {

    
    return 0;
}