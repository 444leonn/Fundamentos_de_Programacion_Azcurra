/*
* Escribir una función para validar una nueva clave de acceso.
* La función deberá recibir una cadena de caracteres, que contendrá la clave candidata, que ya fue ingresada previamente por el usuario.
* Devolverá true o false, dependiendo de si cumple o no, con las siguientes condiciones:
*   - La clave debe estar formada únicamente por, entre 6 y 12 caracteres numéricos
*   - La cantidad de dígitos pares debe ser mayor a la de los impares.
* A los sumo debe recorrer una vez la cadena. Evite realizar ciclos innecesarios.
* Compruebe el correcto funcionamiento, incluyendo los siguientes casos de prueba:
*   validar("j20893") devuevle false
*   validar("20893a") devuevle false
*   validar("208X930") devuevle false
*   validar("20201") devuelve false
*   validar("23445776") devuelve false
*   validar("089010") devuelve true
*   validar("02784532132567") devuelve false
*   validar("027845320011") devuelve true 
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 20
#define LONG_MIN 6
#define LONG_MAX 12
#define PARES "02468"
#define IMPARES "13579"

typedef char T_Cadena[MAX];

void ingresar_clave(T_Cadena cadena) {
    printf("Ingrese una clave candidata a evaluar: ");
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] =  '\0';
}

bool longitud_valida(T_Cadena cadena) {
    return (strlen(cadena) >= 6 && strlen(cadena) <= 12);
}

bool es_digito_par(char dato) {
    char strchar[] = {dato,  '\0'};
    return (strstr(IMPARES, strchar) != NULL);
}

bool es_digito_impar(char dato) {
    char strchar[] = {dato, '\0'};
    return (strstr(IMPARES, strchar) != NULL);
}

bool cadena_valida(T_Cadena cadena) {
    bool es_valida = longitud_valida(cadena);
    int i = 0, cant_pares = 0, cant_impares = 0;

    while (cadena[i] != '\0' && es_valida) {
        if(es_digito_par(cadena[i])) {
            cant_pares++;
        }
        else if(es_digito_impar(cadena[i])) {
            cant_impares++;
        }
        else {
            es_valida = false;
        }

        i++;
    }

    if (cant_impares > cant_pares) {
        es_valida = false;
    }

    return es_valida;
}

int main() {
    T_Cadena cadena_clave;

    ingresar_clave(cadena_clave);

    if (cadena_valida) {
        printf("La clave \"%s\" es valida.\n", cadena_clave);
    }
    else {
        printf("No es valida.\n");
    }

    return 0;
}