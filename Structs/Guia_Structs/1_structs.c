/*
* Se tienen los siguientes datos de los empleados de una empresa:
*   Apellido (35 caracteres)
*   Nombre (35 caracteres)
*   Fecha de Nacimiento (día, mes y año)
*   Fecha de Ingreso (día, mes y año)
*   Sueldo Básico
* Se conoce la cantidad N de empleados y la fecha de procesamiento.
* Se pide:
*   Imprimir un listado con los apellidos y nombres de las personas que cumplan años en el mes y
*   calcular e informar una suma de regalo equivalente al uno por mil del sueldo por cada año cumplido.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MES_ACTUAL 5
#define MAX_EMPLEADOS 30
#define LONG_MAX 35

typedef char t_string[LONG_MAX];

typedef struct {
    int dia;
    int mes;
    int anio;
} t_fecha;

typedef struct {
    t_string apellido;
    t_string nombre;
    t_fecha fecha_nacimiento;
    t_fecha fecha_ingreso;
    float sueldo_basico;
} t_empleado;

void ingreso_empleados(t_empleado vec[MAX_EMPLEADOS], int *ml) {
    char ing;
    printf("Desea ingresar un empleado? s/n: ");
    scanf("%c", &ing);

    while (ing == 's' || ing == 'S') {
        printf("Apellido: ");
        scanf("%s", vec[*ml].apellido);
        printf("Nombre: ");
        scanf("%s", vec[*ml].nombre);

        printf("\nFecha de Nacimiento.\n");
        printf("Dia: ");
        scanf("%d", &vec[*ml].fecha_nacimiento.dia);
        printf("Mes: ");
        scanf("%d", &vec[*ml].fecha_nacimiento.mes);
        printf("Anio: ");  
        scanf("%d", &vec[*ml].fecha_nacimiento.anio);

        printf("Fecha de Ingreso.\n");
        printf("Dia: ");
        scanf("%d", &vec[*ml].fecha_ingreso.dia);
        printf("Mes: ");
        scanf("%d", &vec[*ml].fecha_ingreso.mes);
        printf("Anio: ");  
        scanf("%d", &vec[*ml].fecha_ingreso.anio);

        *ml += 1;

        printf("\nDesea seguir ingresando? s/n: ");
        scanf(" %c", &ing);
    }
}

void mostrar_cumplen_mes(t_empleado vec[MAX_EMPLEADOS], int ml) {
    int i;

    for (i = 0; i < ml; i++)
        if (vec[i].fecha_nacimiento.mes == MES_ACTUAL)
            printf("%s %s\n", vec[i].nombre, vec[i].apellido);
}

int main() {
    int ML = 0, i;
    
    t_empleado empleados[MAX_EMPLEADOS];

    ingreso_empleados(empleados, &ML);

    printf("Los empleados que cumplen en el mes %d.\n", MES_ACTUAL);
    mostrar_cumplen_mes(empleados, ML);

    return 0;
}
