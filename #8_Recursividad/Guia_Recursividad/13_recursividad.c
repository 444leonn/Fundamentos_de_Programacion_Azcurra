/*
* Desarrollar una función recursiva que compruebe si un número es binario.
* Un número binario está formado únicamente por ceros y unos.
*/

#include <stdio.h>
#include <stdbool.h>

void ingresar_numero(int *numero) {
    printf("Ingrese un numero entero binario: ");
    scanf("%d", numero);
}

bool es_binario(int numero) {
    if (numero == 0 || numero == 1)
        return true;
    else if ((numero %10 == 0) || (numero % 10 == 1))
        return es_binario(numero / 10);
    else
        return false;
}

int main() {
    int num;

    ingresar_numero(&num);

    if (es_binario(num))
        printf("El numero %d es binario.\n", num);
    else
        printf("El numero no es binario,\n");
    
    return 0;
}