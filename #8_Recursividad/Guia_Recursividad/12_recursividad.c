/*
* Desarrollar un programa que muestre los primeros N números naturales.
* El número N lo debe ingresar el usuario.
*/

#include <stdio.h>

void ingresar_numero(int *numero) {
    printf("Ingrese un numero entero natural: ");
    scanf("%d", numero);
}

void ingresar_natural(int *numero) {
    ingresar_numero(numero);
    while (*numero <= 0) {
        printf("Debe ingresar un numero natural.\n");
        ingresar_numero(numero);
    }
}


// * Cuando dice mostrar el ejercicio, podemos usar funcion no tipada (void)
void mostrar_naturales_ascendente(int numero) {
    if (numero <= 0)
        return;
    else {
        mostrar_naturales_ascendente(numero - 1);
        printf("%d ", numero);
    }
}

void mostrar_naturales_descendente(int numero) {
    if (numero == 0)
        return;
    else {
        printf("%d ", numero);
        mostrar_naturales_descendente(numero - 1);
    }
}

int main() {
    int num;

    ingresar_natural(&num);
    
    printf("\nDe manera ascendente:  ");
    mostrar_naturales_ascendente(num);

    printf("\nDe manera descendente:  ");
    mostrar_naturales_descendente(num);

    return 0;
}