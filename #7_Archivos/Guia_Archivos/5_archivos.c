/*
* Dado un archivo de apellidos y nombres, generar otro archivo con los mismos datos ordenados alfabéticamente.
* Suponer que el archivo de entrada cabe en la memoria.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHARS 25
#define MAX_TABLA 100

typedef char tstr_nombres[MAX_CHARS];
typedef struct {
    tstr_nombres nombre;
    tstr_nombres apellido;
} T_Persona;

typedef T_Persona T_Tabla_Personas[MAX_TABLA];

void menu(int *opcion) {
    printf("\n------------------------------\n");
    printf("1) Cargar archivo nombres.\n");
    printf("2) Generar archivo nuevo ordenado.\n");  
    printf("3) Mostrar archivo ordenado.\n");
    printf("4) SALIR.\n");
    printf("------------------------------\n");
    printf("Seleccione un opcion:  ");
    scanf("%d", opcion);
    printf("\n");
}

void cargar_archivo(FILE *archivo) {
    int i;
    T_Tabla_Personas personas;
    char cargar = 's';

    while ((cargar == 's' || cargar == 'S') && i < MAX_TABLA) {
        printf("\nIngrese los datos de la persona.\n");
        printf("Nombre:  ");
        scanf("%s", personas[i].nombre);
        fwrite(&personas[i].nombre, sizeof(tstr_nombres), 1, archivo);

        getchar();
        printf("Apellido:  ");
        scanf("%s", personas[i].apellido);
        fwrite(&personas[i].apellido, sizeof(tstr_nombres), 1, archivo);
        i++;

        getchar();
        printf("Desar seguir cargando? (s/S = si, otro = no)  ");
        cargar = getchar();
    }
}

int leer_archivo(FILE *archivo, T_Tabla_Personas personas) {
    int cantidad = 0;
    
    while (!feof(archivo) && cantidad < MAX_TABLA) {
        if (fread(&personas[cantidad].nombre, sizeof(tstr_nombres), 1, archivo) == 1) {
            if (fread(&personas[cantidad].apellido, sizeof(tstr_nombres), 1, archivo) == 1) {
                cantidad++;
            }
        }
    }

    return cantidad;
}

void cargar_archivo_ordenado(FILE *archivo, FILE *archivo_ordenado) {
    T_Tabla_Personas personas;
    int cantidad, i = 1, j;
    bool hubo_intercambio = true;
    T_Persona aux;

    cantidad = leer_archivo(archivo, personas);

    while ((i < cantidad) && hubo_intercambio) {
        hubo_intercambio = false;
        for (j = 0; j < cantidad - i; j++) {
            if (strcmp(personas[j].apellido, personas[j + 1].apellido) > 0) {
                aux = personas[j];
                personas[j] = personas[j + 1];
                personas[j + 1] = aux;
                hubo_intercambio = true;
            }
        }
        i++;
    }

    for (i = 0; i < cantidad; i++) {
        fwrite(&personas[i].nombre, sizeof(tstr_nombres), 1, archivo_ordenado);
        fwrite(&personas[i].apellido, sizeof(tstr_nombres), 1, archivo_ordenado);
    }
}

void mostrar_archivo(FILE *archivo) {
    T_Persona persona;

    fread(&persona, sizeof(T_Persona), 1, archivo);
    while (!feof(archivo)) {
        printf("Nombre:  %s.\n", persona.nombre);
        printf("Apellido:  %s\n", persona.apellido);

        fread(&persona, sizeof(T_Persona), 1, archivo);
    }
}

int main() {
    int opc;
    FILE *arc_nombres, *arc_nombres_ordenado;

    menu(&opc);
    while (opc != 4) {
        switch (opc) {
            case 1:
                arc_nombres = fopen("./archivo_nombres.dat", "ab");
                if (arc_nombres == NULL ) {
                    printf("Error, no se ha podido abrir el archivo.\n");
                }
                else {
                    cargar_archivo(arc_nombres);
                    fclose(arc_nombres);
                }
                break;
            
            case 2:
                arc_nombres = fopen("./archivo_nombres.dat", "rb");
                if (arc_nombres == NULL) {
                    printf("Error, debe realizar la carga primero.");
                }
                else {
                    arc_nombres_ordenado = fopen("./archivo_nombres_ordenado.dat", "wb");
                    if (arc_nombres_ordenado == NULL) {
                        printf("Error, no se ha podido abrir el archivo.\n");
                    }
                    else {
                        cargar_archivo_ordenado(arc_nombres, arc_nombres_ordenado);
                        printf("Archivo ordenado con exito.\n");
                        fclose(arc_nombres_ordenado);
                    }
                    fclose(arc_nombres);
                }
                break;
            
            case 3:
                arc_nombres_ordenado = fopen("./archivo_nombres_ordenado.dat", "rb");
                if (arc_nombres_ordenado == NULL) {
                    printf("Error, no se ha podido abrir el archivo.\n");
                    printf("Debe crearlo primero.\n");
                }
                else {
                    mostrar_archivo(arc_nombres_ordenado);
                    fclose(arc_nombres_ordenado);
                }
                break;
            
            default:
                printf("Error, opcion invalida.\n");
                break;
        }
        menu(&opc);
    }

}