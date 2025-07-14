/*
* Definir una estructura para un alumno: legajo (int), nombre (string 30), promedio (float).
* Cargar una tabla con N alumnos, mostrar los datos y luego mostrar solo los alumnos con promedio mayor a 8.
* Modularizar: funciones para cargar, mostrar todos, mostrar filtrado.
*/

#include <stdio.h>

#define MAX_ALUMNOS 50

typedef struct {
    int legajo;
    char nombre[30];
    float promedio;
} T_Alumno;

void ingresar_n(int *numero) {
    printf("Ingrese un numero para el tamanio de la tabla:  ");
    scanf("%d", numero);
}

void cargar_alumno(T_Alumno *alumno) {
    printf("\nINGRESE LOS DATOS.\n");
    printf("Legajo:  ");
    scanf("%d", &alumno->legajo);
    printf("Nombre:  ");
    scanf("%s", alumno->nombre);
    printf("Promedio:  ");
    scanf("%f", &alumno->promedio);
}

void cargar_tabla(T_Alumno tabla[], int ML) {
    int i;
    for (i = 0; i < ML; i++) {
        cargar_alumno(&tabla[i]);
    }
}

void mostrar_tabla(T_Alumno tabla[], int ML) {
    int i;
    for (i = 0; i < ML; i++) {
        printf("%d      %s     %.2f\n", tabla[i].legajo, tabla[i].nombre, tabla[i].promedio);
    }
}

void mostrar_alumnos_promedio(T_Alumno tabla[], int ML) {
    int i;
    for (i = 0; i < ML; i++) {
        if (tabla[i].promedio > 8) {
            printf("%d      %s     %.2f\n", tabla[i].legajo, tabla[i].nombre, tabla[i].promedio);
        }
    }
}

int main() {
    int num_n;
    T_Alumno alumnos[MAX_ALUMNOS];
    
    ingresar_n(&num_n);

    cargar_tabla(alumnos, num_n);

    printf("\nTabla Ingresada.\n");
    mostrar_tabla(alumnos, num_n);

    printf("\nAlumnos con promedio mayor a 8.\n");
    mostrar_alumnos_promedio(alumnos, num_n);
    
    return 0;
}