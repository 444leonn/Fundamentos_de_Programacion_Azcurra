#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100
#define MAX_NOM 100

typedef char string[MAX_NOM];

typedef struct {
    int DNI;
    string nombre;
    string email;
    int sede;
} TRegistro;

typedef TRegistro T_tabla[MAX];

void cargar(FILE *archivo, Tabla tabla, int *ML) {
    TRegistro reg;
    archivo = fopen(alumnos.dat, "rb");
    int i = 0;

    fread(&reg, sizeof(reg), 1, archivo);
    while (!feof(archivo)) {
        tabla[i] = reg;
        fread(&reg, sizeof(reg), 1, archivo);
        i++;
    }

    fclose(archivo);
    *ML = i;
}

int main() {
    FILE *archivo;
    T_tabla tabla;
    int ml = 0;
    
    cargar(archivo, tabla, &ml);

    return 0;
}