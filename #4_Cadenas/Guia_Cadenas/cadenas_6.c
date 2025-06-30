/*
* Escribir una función para validar una nueva clave de acceso.
* La función deberá recibir una cadena de caracteres, que contendrá la clave candidata, ingresada previamente por el usuario.
* Devolverá true o false, dependiendo de si cumple o no con las siguientes condiciones:
*   - La clave debe estar formada únicamente por, entre 4 y 8 caracteres numéricos
*   - Los caracteres no pueden ser todos iguales
* Ejemplos:
*   validar("j2020") devuevle false
*   validar("2021a") devuevle false
*   validar("20X21") devuevle false
*   validar("2220") devuelve true
*   validar("23445776") devuelve true
*   validar("089") devuelve false
*   validar("027845321") devuelve false
*   validar("02784532") devuelve true
*   validar("33333") devuelve false 
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 20
#define LONG_MIN 4
#define LONG_MAX 8

typedef char T_Cadena[MAX];

void ingresar_clave(T_Cadena cadena) {
    printf("Ingrese una clave candidata a evaluar: ");
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] =  '\0';
}

bool longitud_valida(T_Cadena cadena) {
    return (strlen(cadena) >= 6 && strlen(cadena) <= 12);
}

bool contiene_solo_numeros(char digito) {
    return (digito >= '0' && digito <= '9');
}

bool cadena_valida(T_Cadena cadena) {
    bool es_valida = longitud_valida(cadena);
    int i = 0, cant = 0;

    while (cadena[i] != '\0' && es_valida) {
        if (! contiene_solo_numeros(cadena[i])) {
            es_valida = false;
        }
        else if (cadena[i] == cadena[0]) {
            cant++;
            if (cant == strlen(cadena)) {
                es_valida = false;
            }
        }

        i++;
    }

    return es_valida;
}

int main() {
    T_Cadena cadena_clave;

    ingresar_clave(cadena_clave);

    if (cadena_valida(cadena_clave)) {
        printf("La clave \"%s\" es valida.\n", cadena_clave);
    }
    else {
        printf("No es valida.\n");
    }

    return 0;
}