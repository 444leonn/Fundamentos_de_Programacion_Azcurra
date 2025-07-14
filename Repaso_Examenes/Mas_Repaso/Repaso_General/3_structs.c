/*
* Estructura: apellido (string 35), nombre (string 35), legajo (int), sueldo (float).
* Cargar N empleados. Implementar función para ordenar la tabla por apellido y mostrarla ordenada.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STR 35
#define MAX_EMPLEADO 50

typedef struct {
    char nombre[35];
    char apellido[35];
    int legajo;
    float sueldo;
} T_Empleado;

void ingresar_n(int *numero) {
    printf("Ingrese un numero para el tamanio de la tabla:  ");
    scanf("%d", numero);
}

void cargar_empleado(T_Empleado *empleado) {
    printf("\nINGRESE LOS DATOS.\n");
    printf("Legajo:  ");
    scanf("%d", &empleado->legajo);
    printf("Nombre:  ");
    scanf("%s", empleado->nombre);
    getchar();
    printf("Apellido:  ");
    scanf("%s", empleado->apellido);
    printf("Sueldo:  ");
    scanf("%f", &empleado->sueldo);
}

void cargar_tabla(T_Empleado tabla[], int ML) {
    int i;
    for (i = 0; i < ML; i++) {
        cargar_empleado(&tabla[i]);
    }
}

void mostrar_tabla(T_Empleado tabla[], int ML) {
    int i;
    for (i = 0; i < ML; i++) {
        printf("%d      %s %s    %.2f\n", tabla[i].legajo, tabla[i].nombre, tabla[i].apellido, tabla[i].sueldo);
    }
}

void ordenar_por_apellido(T_Empleado tabla[], int ML) {
    int i, j;
    T_Empleado aux;
    bool continuar = true;

    i = 1;
    while (i < ML && continuar) {
        continuar = false;
        for (j = 0; j < ML - i; j++) {
            if (strcmp(tabla[j].apellido, tabla[j + 1].apellido) > 0) {
                aux = tabla[j];
                tabla[j] = tabla[j + 1];
                tabla[j + 1] = aux;
                continuar = true;
            }
        }
        i++;
    }
}

int main() {
    int num_n;
    T_Empleado empleados[MAX_EMPLEADO];

    ingresar_n(&num_n);
    cargar_tabla(empleados, num_n);

    ordenar_por_apellido(empleados, num_n);

    printf("\nTabla Ordenada.\n");
    mostrar_tabla(empleados, num_n);

    return 0;
}