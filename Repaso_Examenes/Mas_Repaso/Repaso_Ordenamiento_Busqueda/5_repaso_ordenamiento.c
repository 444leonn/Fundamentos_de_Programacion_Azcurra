/*
* Dado un arreglo de enteros ordenado ascendentemente, solicita un número a buscar e implementa la búsqueda binaria
* para indicar si el número está presente y, en caso afirmativo, en qué posición.
*/

#include <stdio.h>
#include <stdbool.h>

#define NO_ENCONTRADO -1

int busqueda_binaria(int valores[], int tamanio, int buscado) {
    int inf, sup, mit;
    bool terminado; 
    int posicion;

    inf = 0;
    sup = tamanio - 1;
    terminado = false;

    while (!terminado) {
        if ((buscado < valores[inf]) || (buscado > valores[sup])) {
        terminado = true;
        posicion = NO_ENCONTRADO;
        }
        else {
        mit = inf + ((sup-inf)/2);

        if (valores[mit] == buscado) {
            terminado = true;
            posicion = mit;
        }
        else if (buscado > valores[mit]) {
            inf = mit + 1;
        } 
        else {
            sup = mit - 1;
        }
        }        
    }

    return posicion;
}

int main() {
    int vector[] = {1, 2, 3, 4, 5};
    int tamanio = 5, num_busc, pos_busc;

    printf("Ingrese un numero a buscar en el arreglo: ");
    scanf("%d", &num_busc);

    pos_busc = busqueda_binaria(vector, tamanio, num_busc);
    if (pos_busc == NO_ENCONTRADO) {
        printf("El valor %d no se ha encontrado en el vector.\n", num_busc);
    }
    else {
        printf("El valor %d se encuentra en el indice %d del vector\n", num_busc, pos_busc);
    }
    
    return 0;
}