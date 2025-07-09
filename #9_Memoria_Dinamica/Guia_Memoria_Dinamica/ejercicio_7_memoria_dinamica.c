/*
* Implementar una función que retorna un puntero a un vector de n struct del tipo t_alumno (ver anexo),
* el cual apunta a un bloque de memoria dinámica, respetando la siguiente declaración.
* En caso de no poder reservar la memoria, retornar NULL.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 30
typedef struct {
    int padron;
    char nombre[MAX_STR];
    char apellido[MAX_STR];
} t_alumno;

void ingresar_n(int *numero) {
    printf("Ingrese la cantidad de alumnos:  ");
    scanf("%d", numero);
}

t_alumno *crear_alumnos(int cantidad) {
    return malloc(cantidad * sizeof(t_alumno));
}

int main() {
    int num_n;
    t_alumno *alumnos;

    ingresar_n(&num_n);

    alumnos = crear_alumnos(num_n);
    
    free(alumnos);
    
    return 0;
}