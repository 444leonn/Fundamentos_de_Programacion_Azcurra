/*
* Escribir una función para validar una nueva clave de acceso.
* La función deberá recibir una cadena de caracteres, que contendrá la clave candidata, que ya fue ingresada previamente por el usuario.
* Devolverá true o false, dependiendo de si cumple o no, con las siguientes condiciones:
*     - La clave debe estar formada únicamente por, entre 6 y 12 caracteres numéricos
*     - La cantidad de dígitos pares debe ser mayor a la de los impares. A los sumo debe recorrer una vez la cadena.
* Evite realizar ciclos innecesarios.
* Compruebe el correcto funcionamiento, incluyendo los siguientes casos de prueba:
*     validar("j20893") devuevle false
*     validar("20893a") devuevle false
*     validar("208X930") devuevle false
*     validar("20201") devuelve false
*     validar("23445776") devuelve false
*     validar("089010") devuelve true
*     validar("02784532132567") devuelve false
*     validar("027845320011") devuelve true
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 20
#define CANT_MIN 6
#define CANT_MAX 12
typedef char T_String[MAX];

bool longitud_valida(T_String cadena) {
    bool es_valida = true;

    if (strlen(cadena) < CANT_MIN) {
        es_valida = false;
    }
    else if (strlen(cadena) > CANT_MAX) {
        es_valida = false;
    }

    return es_valida;
}

bool es_digito_numerico(char digito) {
    bool es_numerico = true;

    if ((digito >= 'A' && digito <= 'Z') || (digito >= 'a' && digito <= 'z')) {
        es_numerico = false;
    }
}

bool es_digito_par(char digito) {
    return digito == '0' || digito == '2' || digito == '4' || digito == '6' || digito == '8';
    
}

bool es_digito_impar(char digito) {
    return digito == '1' || digito == '3' || digito == '5' || digito == '7' || digito == '9';
}

bool es_clave_valida(T_String cadena) {
    int i = 0, cant_pares = 0, cant_impares = 0; 
    bool es_valida = true;
    char posicion;


    posicion = cadena[i];
    if (longitud_valida(cadena)) {
        while (cadena[i] != '\0') {
            if (! es_digito_numerico(cadena[i]))
                es_valida = false;
            else if (es_digito_par(cadena[i])) {
                cant_pares++;
            }
            else if (es_digito_impar(cadena[i])) {
                cant_impares++;
            }
    
            i++;
        }
    }

    return es_valida && cant_pares > cant_impares;
}

int main() {
    T_String cadena_caracteres;

    printf("Ingrese una cadena: ");
    fgets(cadena_caracteres, MAX, stdin);

    if (es_clave_valida(cadena_caracteres)) {
        printf("Clave Valida.\n");
    }
    else {
        printf("Clave INvalida.\n");
    }
    
    return 0;
}