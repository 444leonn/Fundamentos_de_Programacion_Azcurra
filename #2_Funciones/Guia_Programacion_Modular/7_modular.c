/*
* Escribir un programa que solicite al usuario dos números enteros positivos y determine el máximo común divisor entre dos números.
*/

#include <stdio.h>

void solicitar_numero(int *numero) {
    printf("Ingrese un numero: ");
    scanf("%d", numero);
}

void transformar_positivos(int *prim_numero, int *seg_numero) {
    if (*prim_numero < 0) {
        *prim_numero = - *prim_numero;
    }

    if (*seg_numero < 0) {
        *seg_numero = - *seg_numero;
    }
}

int det_maximo_divisor(int prim_num, int seg_num) {
    int divisor = 0, i;
    int num_mayor, num_menor;

    if (prim_num > seg_num) {
        num_mayor = prim_num;
        num_menor = seg_num;
    }
    else if (prim_num < seg_num) {
        num_mayor = seg_num;
        num_menor = prim_num;
    }

    for (i = 1; i <= num_menor; i++) {
        if ((num_mayor % i == 0) && (num_menor % i == 0)) {
            divisor = i;
        }
    }

    
    return divisor;
}


int main() {
    int num_1, num_2;
    int maximo_divisor;

    solicitar_numero(&num_1);
    solicitar_numero(&num_2);

    transformar_positivos(&num_1, &num_2);
    maximo_divisor = det_maximo_divisor(num_1, num_2);

    printf("El maximo divisor entre los dos numero es %d.\n", maximo_divisor);
    
    return 0;
}