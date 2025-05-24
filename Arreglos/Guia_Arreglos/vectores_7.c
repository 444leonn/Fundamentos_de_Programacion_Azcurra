/*
* Dado un vector a ordenado ascendente de longitud ml y un elemento p del mismo tipo que los elementos del vector,
* insertar p en el vector a de modo que siga ordenado.
* Validar previamente que en el vector haya espacio libre para guardar el nuevo dato.
* Se solicita resolver lo solicitado recorriendo una sola vez el vector y sin utilizar un arreglo auxiliar.
* Ejemplo:
*   nuevo elemento p=14​
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 15

typedef int T_Vec[MAX];

void mostrar_vector(T_Vec vector, int cant_elementos) {
    int i;
    for (i = 0; i < cant_elementos; i++) {
        printf("%d, ", vector[i]);
    }
}

void ingreso_p(int *numero) {
    printf("Ingrese un numero a insertar en el vector: ");
    scanf("%d", numero);
}

bool validar_vector(int ml) {
    return ml < MAX - 1;
}

void almacenar_valor(T_Vec vector, int numero, int *ml) {
    int i;

    i = *ml - 1;
    while ((vector[i] >= numero) && (i >= 0)) {
        vector[i + 1] = vector[i];
        i--;
    }

    if (vector[i] <= numero) {
        vector[i + 1] = numero;
        *ml += 1;
    }
}

int main() {
    T_Vec vector_enteros = {3, 6, 9, 16, 21, 45};
    int ML = 6;
    int elemento_p;

    ingreso_p(&elemento_p);

    if (validar_vector(ML)) {
        almacenar_valor(vector_enteros, elemento_p, &ML);
    }

    mostrar_vector(vector_enteros, ML);

    return 0;
}
