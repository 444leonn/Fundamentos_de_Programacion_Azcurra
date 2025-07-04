/*
* Complete el programa para que permita ingresar los datos de 5 alumnos (modificamos el maximo fisico)
* Indicar el nombre de alumno con mejor promedio (haces un for buscando el subindice donde esta el maximo y te lo guarda)
* Indicar el promedio general en el primer parcial (recorremos con un for la tabla y accedemos a notas[0] y despues divido por la cantidad de elementos que tengo)
* Ordenar ascendentemente el listado segun el padron 
* Ingresar un padron por teclado, buscarlo e imprimir toda la informacion de ese alumno
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TAMANIO 20
#define NO_ENCONTRADO -1

typedef struct {
    char nombre[30];
    int padron;
    char email[50];
    int notas[2] ;
    float promedio;
} alumno;

void menu(int *opcion) {
    printf("\n-----------------------------\n");
    printf("1) Cargar Alumno.\n");
    printf("2) Mostrar alumnos.\n");
    printf("3) Mostrar mejor Promedio.\n");
    printf("4) Ordenar segun padron Ascendente.\n");
    printf("5) Buscar Padron.\n");
    printf("6) Ordenar por Nombre.\n");
    printf("7) Promedio General primer parcial.\n");
    printf("8) Salir.\n");
    printf("-----------------------------\n");
    printf("Elija un opcion: ");
    scanf("%d", opcion);
}

void cargar(alumno vec[TAMANIO], int *ML) {
    int i;
    char opcion = 's';

    i = 0;
    while ((opcion == 's' || opcion == 'S') && *ML < TAMANIO) {
        printf("\nIngrese el Nombre:  ");
        scanf("%s",vec[i].nombre);

        printf("Ingrese el padron:  ");
        scanf("%d",&vec[i].padron);

        getchar();
        printf("Ingrese el email:  ");
        scanf(" %s",vec[i].email);

        printf("Ingrese la nota del Parcial 1:  ");
        scanf("%d",&vec[i].notas[0]);

        printf("Ingrese la nota del Parcial 2:  ");
        scanf("%d",&vec[i].notas[1]);

	    vec[i].promedio = (float)(vec[i].notas[0] + vec[i].notas[1])/2;


        getchar();
        printf("Desar ingresar otro alumno? (s/S = si, otro = no)  ");
        opcion = getchar();

        i++;
        *ML += 1;
    }
}

void mostrar(alumno vec[TAMANIO], int ML) {
    int i;
    for(i = 0; i < ML; i++) {
        printf("\n\n Alumnos[%d]",i);
        printf("\n nombre: %s ", vec[i].nombre);
        printf("\n padron: %d ", vec[i].padron);	
        printf("\n email: %s ", vec[i].email);
        printf("\n Nota Parcial 1: %d Nota Parcial 2: %d", vec[i].notas[0],vec[i].notas[1]);
        printf("\n promedio Cd: %.2f ", vec[i].promedio);
    }
}

int max_promedio(alumno vec[TAMANIO], int ML) {
    int i, indice_max_promedio = 0;
    for (i = 1; i < ML; i++) {
        if (vec[i].promedio > vec[indice_max_promedio].promedio) {
            indice_max_promedio = i;
        }
    }
    return indice_max_promedio;
}

float prom_gen_primer_parcial(alumno vec[TAMANIO], int ML) {
    float prom_gen;
    int i, suma = 0;

    for (i = 0; i < ML; i++) {
        suma += vec[i].notas[0];
    }
    prom_gen = (float) suma / ML;
    return prom_gen;
}

void ordenar_por_padron(alumno vec[TAMANIO], int ML) {
    int i, j;
    alumno aux;

    for (i = 1; i < ML; i++) {
        for (j = 0;  j < ML - i; j++) {
            if (vec[j].padron > vec[j + 1].padron) {
                aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }
}

void ordenar_por_nombre(alumno vec[TAMANIO], int ML) {
    int i, j;
    alumno aux;
    for (i = 1; i < ML; i++) {
        for (j = 0;  j < ML - i; j++) {
            if (strcmp(vec[j].nombre, vec[j + 1].nombre) > 0) {
                aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }
}

int BusqSec(alumno vec[TAMANIO], int busca, int ML) {
    int i = 0, posicion = NO_ENCONTRADO;
    bool encontrado = false;
    while (i < ML && !encontrado) {
        if (vec[i].padron == busca) {
            encontrado = true;
            posicion = i;
        }
        i++;
    }
    return posicion;
}

int BusqBinaria(alumno vec[TAMANIO], int busca) {
    int inf, sup, mit;
    int i = 0, posicion = NO_ENCONTRADO;
    bool terminado = false;

    inf = 0;
    sup = TAMANIO - 1;
    terminado = false;

      while (!terminado) {
        if ((busca < vec[inf].padron) || (busca > vec[sup].padron)) {
            terminado = true; // NO ESTA => FIN DE LA BUSQUEDA
            posicion = NO_ENCONTRADO;
        }
        else {
            mit = inf + ((sup-inf)/2); // evitamos overflow de la suma directa

            if (vec[mit].padron == busca) {
                terminado = true; // ENCONTRADO => FIN DE LA BUSQUEDA
                posicion = mit;
            }
            else if(busca > vec[mit].padron) {
                inf = mit + 1;
            }
            else {
                sup = mit - 1;
            }
        }        
  }

  return posicion;
}

void mostrar_registro(alumno reg) {
    printf("\n nombre: %s ", reg.nombre);
    printf("\n padron: %d ", reg.padron);	
    printf("\n email: %s ", reg.email);
    printf("\n Nota Parcial 1: %d Nota Parcial 2: %d", reg.notas[0],reg.notas[1]);
    printf("\n promedio Cd: %.2f ", reg.promedio);
}

int main() {
    alumno Alumnos[TAMANIO];
    int mejor_promedio, posicion_buscada;
    int valor_busca;
    int opc, ml = 0;

    menu(&opc);
    while (opc != 8) {
        switch (opc) {
            case 1:
                cargar(Alumnos, &ml);
                break;

            case 2:
                mostrar(Alumnos, ml);
                break;

            case 3:
                mejor_promedio = max_promedio(Alumnos, ml);
                printf("\nEl nombre del alumno con mejor promedio es: %s\n", Alumnos[mejor_promedio].nombre);
                break;
                
            case 4:
                ordenar_por_padron(Alumnos, ml);
                printf("Listado ordenado.\n");
                break;

            case 5:
                printf("Ingrese el elemento a buscar: ");
                scanf("%d", &valor_busca);
                posicion_buscada = BusqSec(Alumnos, valor_busca, ml);

                if (posicion_buscada != NO_ENCONTRADO)
                    mostrar_registro(Alumnos[posicion_buscada]);
                else
                    printf("No encontrado.\n");

                /* Lo mismo pero con busqueda binaria 
                *    printf("Ingrese el elemento a buscar: ");
                *    scanf("%d", &valor_busca);
                *    posicion_buscada = BusqBinaria(Alumnos, valor_busca);
                *    if (posicion_buscada != NO_ENCONTRADO)
                *        mostrar_registro(Alumnos[posicion_buscada]);
                *    else
                *        printf("No encontrado.\n");
                */

                break;

            case 6:
                ordenar_por_nombre(Alumnos, ml);
                printf("Listado ordenado.\n");
                break;

            case 7:
                printf("\nEl promedio general del primer parcial fue de %.2f.\n", prom_gen_primer_parcial(Alumnos, ml));
                break;

            default:
                printf("Error, opcion invalida.\n");
                break;
        }
        menu(&opc);
    }
        
	return 0;
}