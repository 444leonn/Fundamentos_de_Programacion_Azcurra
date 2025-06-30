/*
* Escribir una función en C, que reciba:
*     a) como primer parámetro un vector de números enteros;
*     b) como segundó parámetro, la cantidad de elementos en el vector;
*     c) como tercer parámetro deberá devolver la cantidad de valores negativos que hay en el vector recibido;
*     d) como cuarto parámetro, la cantidad de elementos positivos que hay en el vector recibido.
* Escribir el programa que incluya a la función y las invocaciones con los siguientes ejemplos, y la respectiva impresión de los valores devueltos:
* Probar el programa con los siguiente casos:
*     v1 = [2,8,1,-5,4]​ -> Negativos: 1, Positivos: 4
*     v2 = [-2,-15,-3]​ ​ -> Negativos: 3, Positivos: 0
*     v3 = [0,0,10,12,23,55,1]​ -> Negativos: 0, Positivos: 5
*/

#include <stdio.h>

void contar_positivos_negativos(int vector[], int cant_elementos, int *cant_negativos, int *cant_positivos) {
    int i;
    *cant_negativos = 0;
    *cant_positivos = 0;

    for (i = 0; i < cant_elementos; i++) {
        if (vector[i] > 0) {
            *cant_positivos += 1;
        }
        else if (vector[i] < 0) {
            *cant_negativos += 1;
        }
    }
}

void mostrar_vector(int vector[], int cant_elementos) {
    int i;
    for (i = 0; i < cant_elementos; i++) {
        printf("%d, ", vector[i]);
    }
}

int main() {
    int vector_enteros1[] = {-1, 2, 3, 0, -2, 12, 5, -2}, ML1 = 8;
    int vector_enteros2[] = {2, 8, 1, -5, 4}, ML2 = 5;
    int vector_enteros3[] = {-2, -15, -3}, ML3 = 3;
    int vector_enteros4[] = {0, 0, 10, 12, 23, 55, 1}, ML4 = 7;

    int positivos, negativos;

    contar_positivos_negativos(vector_enteros1, ML1, &negativos, &positivos);
    mostrar_vector(vector_enteros1, ML1);
    printf("\nCantidad Positivos: %d", positivos);
    printf("\nCantidad Negativos: %d.\n", negativos);

    contar_positivos_negativos(vector_enteros2, ML2, &negativos, &positivos);
    mostrar_vector(vector_enteros2, ML2);
    printf("\nCantidad Positivos: %d", positivos);
    printf("\nCantidad Negativos: %d.\n", negativos);

    contar_positivos_negativos(vector_enteros3, ML3, &negativos, &positivos);
    mostrar_vector(vector_enteros3, ML3);
    printf("\nCantidad Positivos: %d", positivos);
    printf("\nCantidad Negativos: %d.\n", negativos);

    contar_positivos_negativos(vector_enteros4, ML4, &negativos, &positivos);
    mostrar_vector(vector_enteros4, ML4);
    printf("\nCantidad Positivos: %d", positivos);
    printf("\nCantidad Negativos: %d.\n", negativos);


    return 0;
}
