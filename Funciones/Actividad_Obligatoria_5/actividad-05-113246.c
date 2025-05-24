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
#include <stdbool.h>
#define MAX 20
#define MIN 1

void ingreso_numero(int *num) {
    printf("Ingrese un numero entre 1 y 20: ");
    scanf("%d", num);
}

bool ingreso_valido(int num) {
    bool no_valido = false;
    if (num < MIN || num > MAX) {
        printf("Ingreso invalido.\n");
        no_valido = true;
    }

    return no_valido;
}

bool determina_primo(int num) {
    bool es_primo = true;
    int i = 2;

    while (i < num && es_primo) {
        if (num % i == 0) {
            es_primo = false;
        }
        i++;
    }

    return es_primo;
}

unsigned long long calc_factorial(int num) {
    int i;
    unsigned long long resultado;
    resultado = 1;

    for (i = 2; i <= num; i++) {
        resultado *= i;
    }

    return resultado;
}

unsigned long long suma_parcial(int num) {
    unsigned long long resultado;

    resultado = (num * (num + 1)) / 2;

    return resultado;
}

int main() {
    unsigned long long resultado_final;
    int num;
    bool es_primo;

    ingreso_numero(&num);
    while (ingreso_valido(num)) {
        ingreso_numero(&num);
    }

    es_primo = determina_primo(num);

    if (es_primo) {
        resultado_final = calc_factorial(num);
        printf("El numero es primo, por lo tanto el calculo de su factorial da: %llu\n", resultado_final);
    }
    else {
        resultado_final = suma_parcial(num);
        printf("El numero no es primo, por lo tanto el calculo de su suma parcial n-esima da: %llu\n", resultado_final);
    }

    return 0;
}