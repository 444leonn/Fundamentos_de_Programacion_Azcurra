/*
* Escribir una funcion llamada crear_estructura_dinamica que reciba una
* cadena de caracteres nombre y un entero correspondiente a un legajo, la misma debe reservar memoria, 
* para almacenar los dos valores en un registro t_alumno. 
* La funcion debe devolver un puntero a una estructura dinamica t_alumno que contenga
* los elementos pasados por parametros y utilice solo el espacio de memoria necesario.
* 
* Escribir un main que:
* - Invoque a la funcion utilizando como arreglo la siguiente declaracion:
*     nombre = Pepe
*     legajo = 111111
* - Haga una llamada a la funcion mostrar_estructura_dinamica a la que se le debe pasar la estructura y la
* correspondiente cantidad de elementos a mostrar.
* No tenes que desarrollar esta funcion, solo utilizarla adecuadamente.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nombre[25];
    int legajo;
} T_Alumno;

T_Alumno *crear_estructura_dinamica(char nombre[], int legajo) {
    T_Alumno *alumno_dinamico;

    alumno_dinamico = malloc(sizeof(T_Alumno));

    if (alumno_dinamico != NULL) {
        strcpy(alumno_dinamico->nombre, nombre);
        alumno_dinamico->legajo = legajo;
    }

    return alumno_dinamico;
}

void mostrar_estructura_dinamica(T_Alumno alumno) {
    printf("Datos del alumno.\n");
    printf("Nombre: %s, Legajo: %d\n", alumno.nombre, alumno.legajo);
}

int main() {
    T_Alumno *alumno;
    char nombre[] = "pepe";
    int legajo = 111111;

    alumno = crear_estructura_dinamica(nombre, legajo);
    if (alumno == NULL) {
        printf("Error, no se pudo reservar la memoria.\n");
    }
    else {
        mostrar_estructura_dinamica(*alumno);

        free(alumno);
    }

    return 0;
}