/*
* Se tiene un archivo de números telefónicos cuyos registros son de la forma:
*   Característica de localidad (4 dígitos)
*   Característica central (3 dígitos)
*   Número (4 dígitos)
* Dado un número que representa una característica de localidad, listar todos los números telefónicos con dicha característica.
* Suponer los siguientes casos:
*   a) El archivo no cabe en la memoria y está desordenado.
*   b) El archivo no cabe en la memoria y está ordenado según números telefónicos crecientes.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
typedef struct {
    int car_localidad;
    int car_central;
    long numero;
} T_Numero;

void menu(int *option) {
    printf("\n--------------------------------------------------\n");
    printf("1) Cargar archivo de numeros telefonicos.\n");
    printf("2) Mostrar coincidentes con una localidad.\n");  
    printf("3) SALIR.\n");
    printf("--------------------------------------------------\n");
    printf("Seleccione una opcion:  ");
    scanf("%d", option);
    printf("\n");
}

void ingresar_numero_localidad(int *localidad) {
    printf("Ingrese el numero de la localidad para mostrar los numeros coincidentes.\n");
    printf("Localidad:  ");
    scanf("%d", localidad);
}

void cargar_archivo(FILE *archivo) {
    T_Numero telefono;
    char cargar = 's';

    while (cargar == 's' || cargar == 'S') {
        printf("\nIngrese los datos del numero telefonico.\n");
        printf("Localidad:  ");
        scanf("%d", &telefono.car_localidad);
        printf("Caracteristica Central:  ");
        scanf("%d", &telefono.car_central);
        printf("Numero:  ");
        scanf("%ld", &telefono.numero);

        fwrite(&telefono, sizeof(T_Numero), 1, archivo);

        getchar();
        printf("\nDesar seguir cargando? (s/S = si, otro = no)  ");
        cargar = getchar();
    }        
}

void mostrar_numeros(FILE *archivo, int localidad) {
    T_Numero telefono;

    fread(&telefono, sizeof(T_Numero), 1, archivo);
    while (!feof(archivo)) {
        if (telefono.car_localidad == localidad) {
            printf("%d %d  %ld\n", telefono.car_localidad, telefono.car_central, telefono.numero);
        }
        fread(&telefono, sizeof(T_Numero), 1, archivo);
    }
}

int main() {
    int opt, num_localidad;
    FILE *arc_numeros_telefonicos;
    
    menu(&opt);
    while (opt != 3) {
        switch (opt) {
            case 1:
                arc_numeros_telefonicos = fopen("./archivo_numeros_telefono.dat", "ab");
                if (arc_numeros_telefonicos == NULL) {
                    printf("Error, no se ha podido crear el archivo.\n");
                }
                else {
                    cargar_archivo(arc_numeros_telefonicos);
                    fclose(arc_numeros_telefonicos);
                }
                break;
            
            case 2:
                arc_numeros_telefonicos = fopen("./archivo_numeros_telefono.dat", "rb");
                if (arc_numeros_telefonicos == NULL) {
                    printf("Error, debe realizar la carga primero.\n");
                }
                else {
                    ingresar_numero_localidad(&num_localidad);
                    printf("Numeros coincidentes con la localidad:  %d\n", num_localidad);
                    mostrar_numeros(arc_numeros_telefonicos, num_localidad);
                }
                break;
            
            default:
                printf("Error, opcion invalida.\n");
                break;
        }
        menu(&opt);
    }

    return 0;
}