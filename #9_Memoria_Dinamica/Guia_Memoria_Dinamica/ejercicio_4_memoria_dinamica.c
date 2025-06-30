/*
* Escribir un programa el cual reserve memoria dinámica para almacenar un struct del tipo t_alumno (ver anexo).
* Luego solicitar al usuario que ingrese los datos del alumno y almacenarlos en la memoria previamente reservada.
* Mostrar luego todos los datos del alumno. Liberar la memoria reservada al finalizar el programa.
*/

#include <stdio.h>
#include <stdlib.h>

#define CHAR_MAX 30

typedef struct {
    int padron;
    char nombre[CHAR_MAX];
    char apellido[CHAR_MAX];
} T_Alumno;

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

int main() {
    T_Alumno *alumno;

    alumno = malloc(sizeof(T_Alumno)); // Puede pedir casteo del registro, usar (T_Alumno*)
    
    if (alumno == NULL) {
        printf("Error, no se pudo reservar memoria.\n");
    }
    else {
        cargar_alumno(alumno);
        mostrar_alumno(*alumno);

        free(alumno);
    }

    return 0;
}