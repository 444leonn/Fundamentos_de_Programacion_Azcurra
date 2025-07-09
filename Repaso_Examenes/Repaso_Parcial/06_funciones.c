/*
* Escribir una función que dado un número entero positivo retorne un valor booleano que indique si el mismo es capicúa (palindromo).
*/

#include <stdio.h>
#include <stdbool.h>

void ingresar_numero(int *numero) {
    scanf("%d", numero);
}

bool det_palindromo(int numero) {
    int num_copia = 0, ult_dig, num_orig = numero;

    while (numero > 0) {
        ult_dig = numero % 10;

        num_copia = num_copia * 10 + ult_dig;

        numero /= 10;
    } 

    return num_copia == num_orig;
}

int main() {
    int num;

    printf("Ingrese un numero: ");
    ingresar_numero(&num);

    if (det_palindromo(num))
        printf("El numero es palindromo.\n");
    else
        printf("No lo es.\n");

    return 0;
}