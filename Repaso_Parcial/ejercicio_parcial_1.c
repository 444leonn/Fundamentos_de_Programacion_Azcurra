/*
* Desarrollar una funcion que reciba como parametros un vector de tipo Tvector ya cargado con datos que se encuentrar ordenados
* de manera ascendente, su maximo logico y un numero entero que debe ser intercalo en dicho vector de modo que este siga ordenado.
* Se espera que la funcion devuelva true si pudo realizarlo y false si no.
* Tanto el vector como el maximo logico actualizados deben devolverse sobre los parametros.
*
* Escribir un programa que invoque dicha funcion.
*
* Nota: Se solicita resolverlo recorriendo una sola vez el vector y sin utilizar un arreglo auxiliar. 
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 4

typedef int Tvector[MAX];

bool intercalar_valor(Tvector vector, int *ml, int valor) {
    bool intercalado = true;
    int i;

    if (*ml > MAX)
        intercalado = false;

    i = *ml - 1;
    while ((vector[i] >= valor) && intercalado) {
        vector[i + 1] = vector[i];
        i--;
    }

    if ((vector[i] <= valor) && intercalado) {
        vector[i + 1] = valor;
        *ml += 1;
    }

    return intercalado;    
}

void mostrar_vector(Tvector vector, int ml) {
    int i;

    for (i = 0; i < ml; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void informe(Tvector vector, int *ml, int valor) {
    if (intercalar_valor(vector, ml, valor))
        printf("Se intercalo el valor.\n");
    else
        printf("No se intercalo el valor.\n");
}

int main() {
    Tvector vector_prueba = {1, 3, 5, 6};
    int ml = 4, valor = 8;

    mostrar_vector(vector_prueba, ml);

    informe(vector_prueba, &ml, valor);

    mostrar_vector(vector_prueba, ml);

    return 0;
}