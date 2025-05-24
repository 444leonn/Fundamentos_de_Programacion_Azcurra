/*
* Escribir un programa modular (compuesto por funciones), en donde se le solicita al usuario un número natural positivo entre 1 y 20. 
*
* En el caso que el número ingresado este fuera de rango indicarle al usuario y solicitarlo nuevamente, hasta que esté dentro del rango pedido.
* Luego si el numero ingresado es primo se pide mostrar como resultado el factorial del mismo, 
* en el caso que no sea primo se pide mostrar como resultado la suma n-ésima parcial del número usando la siguiente formula  (n*(n+1))/2.
*
* La obtención del dato por parte del usuario debe realizarse a través de una función que opere con pasaje de parámetros por referencia.
*/

#include <stdio.h>

void ingreso_num(int *numero) {
    printf("Ingrese un numero entero positivo entre 1 y 20:\n");
    scanf("%d", numero);
}

void ingreso_valido(int *numero) {
    do {
        printf("Ingreso invalido, intentelo nuevamente.\n");
        ingreso_num(numero);
    } while (*numero < 1 || *numero > 20);
}

long long calculo(int numero_validado) {
    int i;
    int es_primo = 1;
    long long resultado = 1;

    for (i = 2; i < numero_validado; i++) {
        if (numero_validado % i == 0) {
            es_primo = 0;
        }
    }

    if (es_primo == 1) {
        for (i = 2; i <= numero_validado; i++) {
            resultado *= i;
        }
    }
    else {
        resultado = numero_validado * (numero_validado + 1) / 2;
    }

    return resultado;
}

int main() {
    int num;
    long long resultado_final;

    ingreso_valido(&num);
    resultado_final = calculo(num);

    printf("El resultado del calculo es: %lld", resultado_final);
}