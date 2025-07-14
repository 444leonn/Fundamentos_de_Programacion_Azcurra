/*
* Reservar memoria dinámica para N alumnos.
* Cargar, mostrar y liberar la memoria.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int legajo;
    char nombre[30];
    float promedio;
} T_Alumno;

void ingresar_n(int *numero) {
    printf("Ingrese la cantidad de alumnos que desea cargar: ");
    scanf("%d", numero);
}

T_Alumno *reservar_memoria(int cantidad) {
    return malloc(cantidad * sizeof(T_Alumno));
}

void cargar_alumnos(T_Alumno alumnos[], int ML) {
    int i;
    for (i = 0; i < ML; i++) {
        printf("Ingrese los datos del alumno.\n");
        printf("Legajo: ");
        scanf("%d", &alumnos[i].legajo);
        printf("Nombre: ");
        scanf("%s", alumnos[i].nombre);
        printf("Promedio: ");
        scanf("%f", &alumnos[i].promedio);
    }
}

void mostrar_alumnos(T_Alumno alumnos[], int ML) {
    int i;
    for (i = 0; i < ML; i++) {
        printf("\nDatos del alumno.\n");
        printf("%d %s %.2f\n", alumnos[i].legajo, alumnos[i].nombre, alumnos[i].promedio);
    }
}

int main() {
    int num_n;
    T_Alumno *tabla_alumnos;

    ingresar_n(&num_n);
    
    tabla_alumnos = reservar_memoria(num_n);
    if (tabla_alumnos == NULL) {
        printf("Error, no se ha podido reservar la memoria.\n");
    }
    else {
        cargar_alumnos(tabla_alumnos, num_n);
        mostrar_alumnos(tabla_alumnos, num_n);
        free(tabla_alumnos);
    }

    return 0;
}