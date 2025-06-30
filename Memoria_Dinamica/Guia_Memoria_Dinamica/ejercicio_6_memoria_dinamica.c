/*
* Implementar una función que retorna un puntero a un struct del tipo t_alumno,
* el cual apunta a un bloque de memoria dinámica, respetando la siguiente declaración.
* En caso de no poder reservar la memoria, retornar NULL.
*/

#include <stdio.h>
#include <stdlib.h>

#define CHAR_MAX 30

typedef struct {
    int padron;
    char nombre[CHAR_MAX];
    char apellido[CHAR_MAX];
} T_Alumno;

T_Alumno *crear_alumno() {
    return malloc(sizeof(T_Alumno));
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

int main() {
    T_Alumno *alumno = crear_alumno();

    if (alumno == NULL) {
        printf("Error, no se pudo reservar memoria.\n");
    }
    else {
        cargar_alumno(alumno);
        mostrar_alumno(*alumno);

        free(alumno);
    }
}