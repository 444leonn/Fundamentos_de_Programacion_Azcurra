/*
* Escribir un programa que solicite el ingreso de una serie de números.
* Por cada número ingresado se deberá informar si el mismo es o no, un número capicúa.
* Se debe evaluar que lo ingresado, sea un número entero positivo, de lo contrario, se debe enviar el mensaje “Número Inválido”, y solicitar el siguiente.
* El ingreso de números, termina cuando el usuario ingresa el número cero.
*/

#include <stdio.h>
#include <stdbool.h>

void ingresar_num(int *num) {
    printf("Ingrese numero para saber si es capicua: ");
    scanf("%d", num);
}

void ingresar_num_valido(int *num) {
    while (*num < 0) {
        printf("Numero Invalido.\n");
        ingresar_num(num);
    }
}

bool det_capicua(int numero) {
    bool capicua = true;
    int original = numero;
    int invertido = 0, digito;

    if (numero < 0) {
        capicua = false;
    }

    while (numero > 0) {
        digito = numero % 10;
        invertido = invertido * 10 + digito;
        numero /= 10;
    }

    capicua = original == invertido;

    return capicua;   
}

void informe_capicua(bool capicua) {
    if (capicua) {
        printf("El numero es capicua.\n");
    }
    else {
        printf("El numero no es capicua.\n");
    }
}

int main() {
    int num;
    bool es_capicua;

    ingresar_num_valido(&num);
    es_capicua = det_capicua(num);
    informe_capicua(es_capicua);

    while (num != 0) {
        ingresar_num(&num);
        es_capicua = det_capicua(num);
        informe_capicua(es_capicua);
    }

}