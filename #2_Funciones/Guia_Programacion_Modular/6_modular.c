/*
* Dada una secuencia de números enteros informar los n primeros números primos que aparezcan y su sumatoria.
* El valor de n es ingresado por el usuario previo al ingreso de los números de la lista.
* Ejemplo:
*     n = 5
*     listado ingresado:
*     6
*     8
*     1 -> es primo
*     2 -> es primo
*     3 -> es primo
*     4
*     5 -> es primo
*     6
*     7 -> es primo
*     La sumatoria de los números primos ingresados es 18
*/

#include <stdio.h>
#include <stdbool.h>

void ingresar_num_n(int *num) {
    printf("Ingrese la cantidad de numeros que va a ingresar: ");
    scanf("%d", num);
}

void ingresar_num_n_valido(int *num) {
    while (*num <= 0) {
        printf("Debes ingresar una cantidad positiva.\n");
        ingresar_num_n(num);
    }
}

void ingreso_numero(int *numero) {
    printf("Ingrese un numero: ");
    scanf("%d", numero);
}

bool evalua_primo(int numero) {
    bool primo = true;
    int cont = 2;

    if (numero <= 1) {
        primo = false;
    }

    while (cont < numero && primo) {
        if (numero % cont == 0) {
            primo = false;
        }
        cont++;
    }

    return primo;
}


int main() {
    int num_n, numero, cant_primos = 0, sumatoria = 0;


    ingresar_num_n_valido(&num_n);
    
    while (cant_primos < num_n) {
        ingreso_numero(&numero);
        if (evalua_primo(numero)) {
                cant_primos++;
                sumatoria += numero;
                printf("El numero %d es primo.\n", numero);
        }
        else {
            printf("El numero %d no es primo.\n", numero);
        }
    }
   
    printf("La sumatoria de los numeros primos ingresados es %d\n", sumatoria); 

    return 0;
}
