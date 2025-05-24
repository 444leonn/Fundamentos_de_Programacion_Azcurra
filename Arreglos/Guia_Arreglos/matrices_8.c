/*
* Se tiene un listado con los siguientes datos:
*     número de alumno ( 1 a n )
*     número de materia ( 1 a m )
*     nota promedio ( 0 a 10 )
* El mismo número de alumno y de materia puede aparecer más de una vez.
* El listado no está ordenado, ni necesariamente completo.
* Esto último quiere decir que puede ser que un alumno no haya cursado una o más materias,
* y por lo tanto no existan los datos correspondientes en el listado.
* Se pide :
*     a) Crear una estructura bidimensional que almacene el promedio por materia de cada alumno 
*        e informarla asignándole en la impresión un guión al caso de falta de datos mencionado.
*     b) Informar el porcentaje de alumnos que cursó cada materia y el promedio general por materia
*        considerando los alumnos que la cursaron.
*     c) Informar la cantidad de materias que cursó cada alumno y el promedio que obtuvo considerando las materias que cursó.
*/

#include <stdio.h>

#define MAX_PROMEDIO 10
#define MATERIAS 8
#define ALUMNOS 20

typedef float T_Matriz[MATERIAS][ALUMNOS];

void limpiar_matriz(T_Matriz matriz) {
    int i, j;

    for (i = 0; i < MATERIAS; i++) 
        for (j = 0; j < ALUMNOS; j++)
            matriz[i][j] = -1;
}

int ingresar_alumno() {
    int alumno;
    scanf("%d", &alumno);

    while (alumno > ALUMNOS || alumno < 0) {
        printf("Error, ingreso invalido.\n");
        printf("Ingrese nuevamnete numero de alumno: ");
        scanf("%d", &alumno);
    }

    return alumno;
}

int ingresar_materia() {
    int materia;
    scanf("%d", &materia);

    while ((materia > MATERIAS || materia <= 0)) {
        printf("Error, ingreso invalido.\n");
        printf("Ingrese nuevamnete numero de materia: ");
        scanf("%d", &materia);
    }

    return materia;
}

void ingresar_nota(float *nota) {
    scanf("%f", nota);

    while (*nota > MAX_PROMEDIO || *nota < 0) {
        printf("Error, ingreso invalido.\n");
        printf("Ingrese nuevamnete la nota: ");
        scanf("%f", nota);
    }
}

void cargar_matriz(T_Matriz matriz) {
    float nota_promedio;

    int num_alumno, num_materia;

    printf("Ingrese el numero de Alumno (0 para terminar): ");
    num_alumno = ingresar_alumno();

    while (num_alumno != 0) {
        printf("Ingrese la materia en la que cargar la nota: ");
        num_materia = ingresar_materia();

        printf("Ingrese la nota promedio del alumno numero %d en la materia %d: ", num_alumno, num_materia);
        ingresar_nota(&nota_promedio);

        matriz[num_materia - 1][num_alumno - 1] = nota_promedio;

        printf("Ingrese el numero de otro Alumno (0 para terminar): ");
        num_alumno = ingresar_alumno();

    }
}

void mostrar_matriz(T_Matriz matriz) {
    int i, j;

    for (i = 0; i < MATERIAS; i++) {
        for (j = 0; j < ALUMNOS; j++) {
            if (matriz[i][j] == -1)
                printf(" -  ");
            else
                printf("%.1f ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    T_Matriz promedio_por_alumno;

    limpiar_matriz(promedio_por_alumno);

    cargar_matriz(promedio_por_alumno);

    mostrar_matriz(promedio_por_alumno);

    return 0;
}