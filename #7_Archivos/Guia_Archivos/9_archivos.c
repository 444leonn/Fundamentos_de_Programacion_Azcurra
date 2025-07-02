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
#define MAX_EMPLEADOS 100
#define MES_ACTUAL 7
#define ANIO_ACTUAL 2025

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

void menu(int *option) {
    printf("\n--------------------------------------------------\n");
    printf("1) Cargar Empleados.\n");
    printf("2) Imprimir aquellos que cumplen en el mes, y su regalo.\n");
    printf("3) SALIR.\n");
    printf("--------------------------------------------------\n");
    printf("Seleccione una opcion:  ");
    scanf("%d", option);
    printf("\n");
}

void cargar_empleado(T_Empleado *empleado) {
    printf("--------------------------------------------------\n");
    printf("Nombre:  ");
    scanf("%s", empleado->nombre.nombre);
    getchar();
    printf("Apellido:  ");
    scanf("%s", empleado->nombre.apellido);
    getchar();

    printf("\nFecha de Nacimiento.\n");
    printf("Dia:  ");
    scanf("%d", &empleado->fecha_nacimiento.dia);
    printf("Mes:  ");
    scanf("%d", &empleado->fecha_nacimiento.mes);
    printf("Anio:  ");
    scanf("%d", &empleado->fecha_nacimiento.anio);

    printf("\nFecha de Ingreso.\n");
    printf("Dia:  ");
    scanf("%d", &empleado->fecha_ingreso.dia);
    printf("Mes:  ");
    scanf("%d", &empleado->fecha_ingreso.mes);
    printf("Anio:  ");
    scanf("%d", &empleado->fecha_ingreso.anio);

    printf("\nSueldo Basico:  ");
    scanf("%ld", &empleado->sueldo_basico);
    
    printf("--------------------------------------------------\n");
}

void cargar_empleados(FILE *archivo) {
    T_Empleado tabla_empleados[MAX_EMPLEADOS];
    int i;
    char cargar = 's';
    
    i = 0;
    while ((cargar == 's' || cargar == 'S') && i < MAX_EMPLEADOS) {
        cargar_empleado(&tabla_empleados[i]);

        fwrite(&tabla_empleados[i], sizeof(T_Empleado), 1, archivo);

        i++;
        
        getchar();
        printf("Desea seguir cargando empleados? (s/S = si, otro = no)   ");
        cargar = getchar();
    }
}

void mostrar_empleado(T_Empleado empleado) {
    printf("\nDatos del empleado.\n");
    printf("Nombre y Apellido:  %s %s.\n", empleado.nombre.nombre, empleado.nombre.apellido);
    printf("Fecha de Nacimiento:  %d/%d/%d.\n", empleado.fecha_nacimiento.dia, empleado.fecha_nacimiento.mes, empleado.fecha_nacimiento.anio);
    printf("Fecha de Ingreso:  %d/%d/%d.\n", empleado.fecha_ingreso.dia, empleado.fecha_ingreso.mes, empleado.fecha_ingreso.anio);
    printf("Sueldo Basico:  %ld.\n", empleado.sueldo_basico);    
}

int calcular_regalo(int anios_edad, long sueldo_basico) {
    return (sueldo_basico * 0.001 * anios_edad);
}

void imprimir_cumple_mes(FILE *archivo) {
    T_Empleado empleado;
    int anios_edad;
    double suma_regalo;

    fread(&empleado, sizeof(T_Empleado), 1, archivo);
    while (!feof(archivo)) {
        if (empleado.fecha_nacimiento.mes == MES_ACTUAL) {
            mostrar_empleado(empleado);
            
            anios_edad = ANIO_ACTUAL - empleado.fecha_nacimiento.anio;
            suma_regalo = calcular_regalo(anios_edad, empleado.sueldo_basico);
            printf("Regalo Correspondiente:  %.2lf.\n", suma_regalo);
        }
        fread(&empleado, sizeof(T_Empleado), 1, archivo);
    }
}

int main() {
    int opt;
    FILE *arch_empleados;
    
    menu(&opt);
    while (opt != 3) {
        switch (opt) {
            case 1:
                arch_empleados = fopen("./datos_empleados.dat", "ab");
                if (arch_empleados == NULL) {
                    printf("Error, no se ha podido abrir el archivo.\n");
                }
                else {
                    cargar_empleados(arch_empleados);
                    fclose(arch_empleados);
                }
                break;
            
            case 2:
                arch_empleados = fopen("./datos_empleados.dat", "rb");
                if (arch_empleados == NULL) {
                    printf("Error, debe realizar la carga primero.\n");
                }
                else {
                    imprimir_cumple_mes(arch_empleados);
                    fclose(arch_empleados);
                }
                break;

            default:
                printf("Error, opcion invalida.\n");
                break;
        }
        menu(&opt);
    }
    
    return 0;
}