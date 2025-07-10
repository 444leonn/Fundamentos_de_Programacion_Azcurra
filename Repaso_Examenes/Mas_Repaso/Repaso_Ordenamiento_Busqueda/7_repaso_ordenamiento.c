/*
* Utilizando la misma estructura anterior, ordenar la tabla por edad de menor a mayor usando el método de selección.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NOMBRE 30
#define MAX_TABLA 50

typedef struct {
    int legajo;
    char nombre[MAX_NOMBRE];
    int edad;
} T_Persona;

typedef T_Persona T_Tabla_Personas[MAX_TABLA];

void ingresar_n(int *numero) {
    printf("Ingrese un numero N:  ");
    scanf("%d", numero);

    while ((*numero > MAX_TABLA) || (*numero < 0)) {
        printf("Error, debe ingresar un numero adecuado.\n");

        printf("Ingrese un numero N:  ");
        scanf("%d", numero);
    }
}

void cargar_persona(T_Persona *persona) {
    printf("INGRESE LOS DATOS DE LA PERSONA.\n");
    printf("Legajo:  ");
    scanf("%d", &persona->legajo);
    printf("Nombre:  ");
    scanf("%s", persona->nombre);
    printf("Edad:  ");
    scanf("%d", &persona->edad);
    printf("\n");
}

void cargar_tabla(T_Tabla_Personas tabla, int MAX) {
    int i;
    for (i = 0; i < MAX; i++) {
        cargar_persona(&tabla[i]);
    }
}

void mostrar_tabla(T_Tabla_Personas tabla, int MAX) {
    int i;
    for (i = 0; i < MAX; i++) {
        printf("%d      %s      %d\n", tabla[i].legajo, tabla[i].nombre, tabla[i].edad);
    }
}

void ordenar_seleccion(T_Tabla_Personas tabla, int MAX) {
    int i, j, minimo;   
    T_Persona aux;  

    for (i = 0; i < MAX - 1; i++) { 
        minimo = i;
        for (j = i + 1; j < MAX; j++) {
            if (tabla[j].legajo < tabla[minimo].legajo) { 
                minimo = j;
            } 
        }
        aux = tabla[i];                  
        tabla[i] = tabla[minimo]; 
        tabla[minimo] = aux; 
    }
}

int main() {
    T_Tabla_Personas tabla_personas;
    int num_n;

    ingresar_n(&num_n);
    cargar_tabla(tabla_personas, num_n);

    printf("Tabla antes de ordenar.\n");
    mostrar_tabla(tabla_personas, num_n);

    ordenar_seleccion(tabla_personas, num_n);

    printf("Tabla despues de ordenar.\n");
    mostrar_tabla(tabla_personas, num_n);

    return 0;
}