/*
* Escribir un programa que solicite el ingreso de una serie de numeros.
* Por cada numero ingresado se debera informar si el mismo es o no, un numero capicua.
* Se debe evaluar que lo ingresado, sea un numero entero positivo, de lo contrario, se debe enviar el mensaje "Numero invalido",
* y solicitar el siguiente.
* El ingreso de numeros, termina cuando el usuario ingresa el numero cero.
*/

#include <stdio.h>
#include <stdbool.h>

void ingresar_numero(int *num) {
    scanf("%d", num);

    while (*num < 0) {
        printf("Numero Invalido.\n");
        printf("Ingreselo nuevamente: ");
        scanf("%d", num);
    }
}

bool det_capicua(int num) {
    int num_copia = 0, orig = num;
    int aux = 0;

    while (num > 0) {
        aux = num % 10;
        num_copia = num_copia * 10 + aux;
        num /= 10;
    }

    return orig == num_copia;
}

void informe(int num) {
    if (det_capicua(num)) {
        printf("El numero es capicua.\n");
    }
    else {
        printf("El numero no es capicua.\n");
    }
}

void ingresos(int *num) {
    while (*num != 0) {
        informe(*num);
        printf("Ingrese otro numero: ");
        ingresar_numero(num);
    }
    printf("Nos vemos.\n");
}

int main() {
    int numero;

    printf("Ingrese un numero: ");
    ingresar_numero(&numero);
    ingresos(&numero);

    return 0;
}