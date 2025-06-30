/*
* Escribir un programa modular (compuesto por funciones) en donde el usuario deba cargar un alias bancario válido.
* 
* En caso de ser invalido se le debe indicar al usuario y solicitar el siguiente.
* Como regla extra el alias no puede contener ninguna de las siguientes palabras: "banco", "cuenta", "saldo"
* 
* Para un alias ser válido debe cumplir las siguientes reglas:
* - Debe tener longitud entre 6 y 20 caracteres.
* - Puede contener caracteres alfabeticos, numericos, "." (punto) y "-" (guión).
* - El guión o punto no pueden estar ubicados ni en la primera ni ultima posición de la cadena.
* 
* En la resolución evitar ciclos innecesario.
* La elección incorrecta del ciclo o el mal uso del mismo, es suficiente condición para considerar al ejercicio como inválido o no aceptado.
* 
* Sugerencias:
*   - Pueden utilizar las funciones strstr, strlen, strcpy y strcmp de la biblioteca "string.h" según crean conveniente.
* 
* Ejemplos:
*   m.al -> inválido, no cumple rango de longitud
*   hogar.perro-balcon -> válido
*   .mi.alias -> inválido, contiene punto como primer caracter
*   mi.alias-banco -> inválido, contiene la palabra banco
*   mi.alias-casa -> válido
*   mi.a$lias -> inválido, contiene un caracter no permitido
*   mi.alias234-casa -> válido
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MF 25
#define LONG_MAX 20
#define LONG_MIN 6
#define NUMEROS "0123456789"

typedef char T_Clave[LONG_MAX];

void gets_string(char cadena[], int size) {
    fgets(cadena, size, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
}

bool es_alfabetico(char caracter) {
    return (caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z');
}

bool es_largo_valido(T_Clave cadena) {
    return (strlen(cadena) >= LONG_MIN) && (strlen(cadena) <= LONG_MAX);
}

bool es_numerico(char caracter) {
    char str_char[] = {caracter, '\0'};
    return strstr(NUMEROS, str_char) != NULL;
}

bool es_punto_guion(char caracter) {
    return (caracter == '.' || caracter == '-');
}

bool primero_ultimo_invalido(T_Clave cadena) {
    int largo_cadena = strlen(cadena);
    int ult_pos = largo_cadena - 1;

    return es_punto_guion(cadena[0]) || es_punto_guion(cadena[ult_pos]);
}

bool clave_valida(T_Clave cadena) {
    bool es_valida;
    int i, j, cant_prohibidas;
    T_Clave claves_prohibidas[] = {"banco", "cuenta", "saldo"};

    es_valida = es_largo_valido(cadena) && !primero_ultimo_invalido(cadena);
    
    cant_prohibidas = 3;
    i = 0;
    while (i < cant_prohibidas && es_valida) {
        if (strstr(cadena, claves_prohibidas[i]) != NULL) {
            es_valida = false;
        }
        i++;
    }

    for (j = 1; j < strlen(cadena) - 2; j++) {
        if (!es_alfabetico(cadena[j]) && !es_numerico(cadena[j]) && !es_punto_guion(cadena[j])) {
            es_valida = false;
        }
    }

    return es_valida;
}

int main() {
    T_Clave clave;
    bool validacion;

    printf("Ingrese una clave para saber si es valida: ");
    gets_string(clave, MF);
    
    while (!clave_valida(clave)) {
        printf("La clave NO es valida.\n");
        printf("Ingrese una clave para saber si es valida: ");
        gets_string(clave, MF);
    }

    printf("La clave es valida.\n");


    return 0;
}