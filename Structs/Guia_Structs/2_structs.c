/*
* Se tienen datos de empleados de una empresa según la siguiente estructura:
*     Apellido (cadena 35)
*     Nombre (cadena 35)
*     Legajo (entero 5 dígitos)
*     Dirección:
*         Calle (cadena 50)
*         Número (entero)
*         Localidad (cadena 50)
*         Provincia (cadena 50)
*         Código Postal (entero)
*     Fecha de Nacimiento: Día, Mes, Año
*     Fecha de Ingreso: Día, Mes, Año
* Se pide hacer un programa que almacene los datos de todos los empleados en una tabla en memoria y
* que permita obtener un listado ordenado por pantalla según distintos ítems, como, por ejemplo, por Apellido y Nombre, por número de legajo, por edad, por antigüedad, por localidad.
* Utilizar un esquema tipo menú.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NOMBRE 35
#define MAX_DIR 50
#define MAX_EMPLEADOS 30
#define ANIO_ACTUAL 2025

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
    T_Fecha fecha_ingreso;
} T_Empleado;

void menu() {
    printf("---------------------------------------\n");
    printf("1) Ingresar Empleado.\n");
    printf("2) Mostrar por Nombre y Apellido.\n");
    printf("3) Mostrar por Legajo.\n");
    printf("4) Mostrar por Edad.\n");
    printf("5) Mostrar por Antiguedad.\n");
    printf("5) Mostrar por Localidad.\n");
    printf("6) SALIR.\n");
    printf("---------------------------------------\n");
}

void ingreso_empleados(T_Empleado vec[MAX_EMPLEADOS], int *ML) {
    int num = 1;

    while (num != 0) {
        printf("Ingrese los datos del empleado.\n");

        printf("---------------------------------------\n");
        printf("NOMBRE, APELLIDO y LEGAJO.\n");
        printf("Apellido: ");
        fgets(vec[*ML].apellido, MAX_NOMBRE, stdin);
        printf("Nombre: ");
        fgets(vec[*ML].nombre, MAX_NOMBRE, stdin);
        printf("Legajo: ");
        scanf("%d", &vec[*ML].legajo);

        printf("---------------------------------------\n");
        printf("DIRECCION.\n");
        printf("Calle: ");
        fgets(vec[*ML].direccion.calle, MAX_DIR, stdin);
        printf("Altura: ");
        scanf("%d", &vec[*ML].direccion.altura);
        printf("Localidad: ");
        fgets(vec[*ML].direccion.localidad, MAX_DIR, stdin);
        printf("Pronvicia: ");
        fgets(vec[*ML].direccion.provincia, MAX_DIR, stdin);
        printf("Codigo Postal: ");
        scanf("%d", &vec[*ML].direccion.cp);

        printf("---------------------------------------\n");
        printf("FECHA NACIMIENTO.\n");
        printf("Dia: ");
        scanf("%d", &vec[*ML].fecha_nacimiento.dia);
        printf("Mes: ");
        scanf("%d", &vec[*ML].fecha_nacimiento.mes);
        printf("Anio: ");
        scanf("%d", &vec[*ML].fecha_nacimiento.anio);

        printf("---------------------------------------\n");
        printf("FECHA INGRESO.\n");
        printf("Dia: ");
        scanf("%d", &vec[*ML].fecha_ingreso.dia);
        printf("Mes: ");
        scanf("%d", &vec[*ML].fecha_ingreso.mes);
        printf("Anio: ");
        scanf("%d", &vec[*ML].fecha_ingreso.anio);

        *ML += 1;

        printf("Desea ingresar otro empleado? (0 para terminar): ");
        scanf("%d", &num);
    }
}

void ordenar_nombre(T_Empleado vec[MAX_EMPLEADOS], int ML) {
    int i, j;
    T_Empleado aux;

    for (i = 1; i < ML; i++) {
        for (j = 0;  j < ML - i; j++) {
            if (strcmp(vec[j].nombre, vec[j + 1].nombre) > 0) {
                aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }
}

void ordenar_legajo(T_Empleado vec[MAX_EMPLEADOS], int ML) {
    int i, j;
    T_Empleado aux;

    for (i = 1; i < ML; i++) {
        for (j = 0;  j < ML - i; j++) {
            if (vec[j].legajo > vec[j + 1].legajo) {
                aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }
}

void ordenar_edad(T_Empleado vec[MAX_EMPLEADOS], int ML) {
    int i, j;
    T_Empleado aux;

    for (i = 1; i < ML; i++) {
        for (j = 0;  j < ML - i; j++) {
            if (vec[j].fecha_nacimiento.anio > vec[j + 1].fecha_nacimiento.anio) {
                aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }
}

void ordenar_antiguiedad(T_Empleado vec[MAX_EMPLEADOS], int ML) {
    int i, j;
    T_Empleado aux;

    for (i = 1; i < ML; i++) {
        for (j = 0;  j < ML - i; j++) {
            if (vec[j].fecha_ingreso.anio > vec[j + 1].fecha_ingreso.anio) {
                aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }
}

void ordenar_localidad(T_Empleado vec[MAX_EMPLEADOS], int ML) {
    int i, j;
    T_Empleado aux;

    for (i = 1; i < ML; i++) {
        for (j = 0;  j < ML - i; j++) {
            if (strcmp(vec[j].direccion.localidad, vec[j + 1].direccion.localidad) > 0) {
                aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }   
}

int main() {
    T_Empleado empleados[30];
    int ml = 0;

    ingreso_empleados(empleados, &ml);
    
    return 0;
}
