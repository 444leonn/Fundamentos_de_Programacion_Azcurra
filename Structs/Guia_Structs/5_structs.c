/*
* Dados dos 2 listados de inscripción de alumnos a 3 turnos de una misma materia, se pide generar un listado único ordenado por número de alumno.
* La estructura de los listados es:
*     número de alumno (5 dígitos), apellido, nombre, turno (1, 2, 3)
* Puede ocurrir que un alumno se haya inscripto en más de un turno por lo cual en el listado generado deben aparecer todos los turnos en los que se inscribió en un único registro de alumno con campo variable.
* Los listados de entrada están ordenados por número de alumno.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ALUMNOS 100
#define MAX_CHAR 50

typedef char T_Str[MAX_CHAR];
typedef struct {
    int legajo;
    T_Str apellido;
    T_Str nombre;
    int turno;
} T_Alumno;

void ordenar_legajo(T_Alumno vec[MAX_ALUMNOS], int ML) {
    int i, j;
    T_Alumno aux;

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

void mostar_alumnos(T_Alumno vec[MAX_ALUMNOS], int ML) {
    int i;

    for (i = 0; i < ML; i++) {
        printf("---------------------------------------\n");
        printf("NOMBRE, APELLIDO, LEGAJO y TURNO.\n");
        printf("Apellido: %s\n", vec[i].apellido);
        printf("Nombre: %s\n", vec[i].nombre);
        printf("Legajo: %d\n", vec[i].legajo);
        printf("Turno: %d\n", vec[i].turno);
        printf("---------------------------------------\n");
    }
}

int main() {
    T_Alumno alumnos[MAX_ALUMNOS] = {
        {113246, "Acosta", "Leon", 2},
        {123456, "Perez", "Juan", 3},
        {654321, "Garcia", "Noemi", 1},
        {113246, "Acosta", "Leon", 1}
    };

    int ml = 4;

    ordenar_legajo(alumnos, ml);

    mostar_alumnos(alumnos, ml);

    
    
    return 0;    
}