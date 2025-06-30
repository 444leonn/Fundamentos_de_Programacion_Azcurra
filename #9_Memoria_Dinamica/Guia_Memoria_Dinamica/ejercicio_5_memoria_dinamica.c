/*
* Escribir un programa el cual reserve memoria dinámica para almacenar una cantidad n de struct del tipo t_alumno.
* El usuario debe ingresar la cantidad n. Luego solicitar al usuario que ingrese los datos de los n alumnos y almacenarlos en la memoria previamente reservada. 
* Mostrar luego todos los datos de todos los alumnos. 
* Liberar la memoria reservada al finalizar el programa.
*/

#include <stdio.h>
#include <stdlib.h>

#define CHAR_MAX 30

typedef struct {
    int padron;
    char nombre[CHAR_MAX];
    char apellido[CHAR_MAX];
} T_Alumno;

void cargar_cantidad_n(int *numero_n) {
    printf("Ingrese la cantidad de alumnos a almacenar.\n");
    printf("Cantidad: ");
    scanf("%d", numero_n);
}

void cargar_alumno(T_Alumno *alumno) {
    printf("Ingrese los datos del alumno.\n");

    printf("Padron: ");
    scanf("%d", &alumno->padron);

    printf("Nombre: ");
    scanf("%s", alumno->nombre);

    printf("Apellido: ");
    scanf("%s", alumno->apellido);
}

void mostrar_alumno(T_Alumno alumno) {
    printf("\nDatos del Alumno\n");
    printf("Padron: %d\n", alumno.padron);
    printf("Nombre: %s\n", alumno.nombre);
    printf("Apellido: %s\n", alumno.apellido);
}

void cargar_alumnos(int cantidad_alumnos, T_Alumno alumnos[]) {
    int i;

    for (i = 0; i < cantidad_alumnos; i++) {
        cargar_alumno(&alumnos[i]);
    }
}

void mostrar_alumnos(int cantidad_alumnos, T_Alumno alumnos[]) {
    int i;

    for (i = 0; i < cantidad_alumnos; i++) {
        mostrar_alumno(alumnos[i]);
    }
}

int main() {
    T_Alumno *alumnos;
    int num_n;

    cargar_cantidad_n(&num_n);

    alumnos = malloc(num_n * sizeof(T_Alumno));

    if (alumnos == NULL) {
        printf("Error, no se pudo guardar la direccion de memoria.\n");
    }
    else {
        cargar_alumnos(num_n, alumnos);
        mostrar_alumnos(num_n, alumnos);

        free(alumnos);
    }
}