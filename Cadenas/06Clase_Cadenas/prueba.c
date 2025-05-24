#include <stdio.h>
#include <string.h>
#define MAX 50

void ingreso_muestra_nombre_direc(char cadena1[MAX], char cadena2[MAX]) {
    printf("Ingrese su nombre completo: ");
    fgets(cadena1, MAX, stdin);

    fflush(stdin);

    printf("Ingrese su direccion: ");
    fgets(cadena2, MAX, stdin);

    printf("Nombre: %s\n", cadena1);
    printf("Direccion: %s\n", cadena2);
}

void ingreso_nombre(char cadena[MAX]) {
    printf("Ingrese su nombre: ");
    fgets(cadena, MAX, stdin);
    fflush(stdin);
}

void mostrar_longitud(char cadena[MAX]) {
    printf("La longitud de la cadena es %ld", strlen(cadena));
}

int main() {
    char nombre[MAX];
    char direccion[MAX];
    char otro_nombre[MAX];

    ingreso_nombre(otro_nombre);
    mostrar_longitud(otro_nombre);

    char *posicion;
    posicion = strstr(otro_nombre, "Juan");
    if (posicion != NULL) {
        printf("El nombre Juan esta dentro de %s.\n", otro_nombre);
    }
    else {
        printf("El nombre Juan no esta dentro de la cadena %s.\n", otro_nombre);
    }

    if (strcmp(nombre, "Ana") == 0) {
        printf("Las palabras son iguales.\n");
    }
    else if (strcmp(nombre, "Ana") > 0) {
        printf("La palabra %s es mayor que Ana");
    }
    else {
        printf("La palabra %s es menor que Ana.\n");
    }

    return 0;
}