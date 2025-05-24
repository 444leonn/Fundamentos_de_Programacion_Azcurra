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

#define TAMANIO 3
#define NO_ENCONTRADO -1

/* definimos una estructura alumno */
typedef struct {
    char nombre[30];
    int padron;
    char email[50];
    int notas[2] ;
    float promedio;
} alumno;

void cargar(alumno vec[TAMANIO]) {
    int i;

    for(i = 0; i < TAMANIO; i++) {
        printf("\nIngrese el Nombre:\n");
        scanf("%s",vec[i].nombre);

        printf("Ingrese el padron:\n");
        scanf("%d",&vec[i].padron);

        printf("Ingrese el email:\n");
        scanf("%s",vec[i].email);

        printf("Ingrese la nota del Parcial 1:\n");
        scanf("%d",&vec[i].notas[0]);

        printf("Ingrese la nota del Parcial 2:\n");
        scanf("%d",&vec[i].notas[1]);

	    vec[i].promedio = (float)(vec[i].notas[0] + vec[i].notas[1])/2;
    }
}

void mostrar(alumno vec[TAMANIO]) {
    int i;
    for(i = 0; i < TAMANIO; i++) {
        printf("\n\n Alumnos[%d]",i);
        printf("\n nombre: %s ", vec[i].nombre);
        printf("\n padron: %d ", vec[i].padron);	
        printf("\n email: %s ", vec[i].email);
        printf("\n Nota Parcial 1: %d Nota Parcial 2: %d", vec[i].notas[0],vec[i].notas[1]);
        printf("\n promedio Cd: %.2f ", vec[i].promedio);
    }
}

int max_promedio(alumno vec[TAMANIO]) {
    int i, indice_max_promedio = 0;

    for (i = 1; i < TAMANIO; i++) {
        if (vec[i].promedio > vec[indice_max_promedio].promedio) {
            indice_max_promedio = i;
        }
    }

    return indice_max_promedio;
}

float prom_gen_primer_parcial(alumno vec[TAMANIO]) {
    float prom_gen;
    int i, suma = 0;

    for (i = 0; i < TAMANIO; i++) {
        suma += vec[i].notas[0];
    }

    prom_gen = (float) suma / TAMANIO;

    return prom_gen;
}

void ordenar_por_padron(alumno vec[TAMANIO]) {
    int i, j;
    alumno aux;

    for (i = 1; i < TAMANIO; i++) {
        for (j = 0;  j < TAMANIO - i; j++) {
            if (vec[j].padron > vec[j + 1].padron) {
                aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }
}

void ordenar_por_nombre(alumno vec[TAMANIO]) {
    int i, j;
    alumno aux;

    for (i = 1; i < TAMANIO; i++) {
        for (j = 0;  j < TAMANIO - i; j++) {
            if (strcmp(vec[j].nombre, vec[j + 1].nombre) > 0) {
                aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }
}

int BusqSec(alumno vec[TAMANIO], int busca) {
    int i = 0, posicion = NO_ENCONTRADO;
    bool encontrado = false;

    while (i < TAMANIO && !encontrado) {
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

int main(void) {
    alumno Alumnos[TAMANIO];
    int mejor_promedio, posicion_buscada;
    int valor_busca;

    // cargo los elementos con funcion cargar
    cargar(Alumnos);

 	/* Muestro datos del primer elemento de la tabla */
    mostrar(Alumnos);


    // Indicar el nombre de alumno con mejor promedio
    mejor_promedio = max_promedio(Alumnos);
    printf("\nEl nombre del alumno con mejor promedio es: %s\n", Alumnos[mejor_promedio].nombre);


    // Indicar el promedio general en el primer parcial
    printf("\nEl promedio general del primer parcial fue de %.2f.\n", prom_gen_primer_parcial(Alumnos));


    /* Ordenar ascendentemente el listado segun el padron 
    ordenar_por_padron(Alumnos);
    */

    /* Ordenar ascendentemente el listado segun el nombre */
    ordenar_por_nombre(Alumnos);
    mostrar(Alumnos);

    printf("\n\n");

    /* Ingresar un padron por teclado, buscarlo e imprimir toda la informacion de ese alumno
    printf("Ingrese el elemento a buscar: ");
    scanf("%d", &valor_busca);
    posicion_buscada = BusqSec(Alumnos, valor_busca);

    if (posicion_buscada != NO_ENCONTRADO)
        mostrar_registro(Alumnos[posicion_buscada]);
    else
        printf("No encontrado.\n");
    */

    /* Lo mismo pero con busqueda binaria 
    printf("Ingrese el elemento a buscar: ");
    scanf("%d", &valor_busca);
    posicion_buscada = BusqBinaria(Alumnos, valor_busca);
    if (posicion_buscada != NO_ENCONTRADO)
        mostrar_registro(Alumnos[posicion_buscada]);
    else
        printf("No encontrado.\n");
    */
        
	return 0;
}

/*
* Modificar el programa para que use ML y le vaya preguntando al usuario:
*   - Si quiere hacer alguna ingreso
*   - Si quiere seguir realizando ingresos
* (Se puede hacer que valide un caracter ejemplo s/S para si cualquier otro no)
*/