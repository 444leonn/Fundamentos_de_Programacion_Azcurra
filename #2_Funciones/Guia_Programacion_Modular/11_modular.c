/*
* Ingresar un texto terminado en . (punto), e indicar cantidad de vocales y consonantes que se encuentran presentes en el texto.
* Sugerencia: ingresar un único texto una única vez, luego leer caracter a caracter mediante scanf.
* Ejemplo:
*     texto = Este es un texto de prueba 372638 $#"47.
*     La cantidad de vocales es: 10
*     La cantidad de consonantes es: 11
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 60
#define LONG_MAX 50
#define VOCALES "AaEeIiOoUu"

typedef char t_str[MAX];
typedef char t_str_char[2];

void ingresar_texto(t_str cadena) {
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] == '\0';
}

void validar_texto(t_str cadena) {
    while (strlen(cadena) > LONG_MAX) {
        printf("Longitud de Cadena Invalida.\n");
        printf("Ingrese el texto Nuevamente: ");
        ingresar_texto(cadena);
    }
}

void charstr(char c, t_str_char str) {
    str[0] = c;
    str[1] = '\0';
}


int contar_vocales(t_str cadena) {
    int i, cant = 0;
    char caracter;
    t_str_char cadena_caracter;
    
    for (i = 0; i < strlen(cadena); i++) {
        caracter = cadena[i];
        charstr(caracter, cadena_caracter);

        if (strstr(VOCALES, cadena_caracter)) {
            cant++;
        }
    }

    return cant;
}

bool es_caracter_alfabetico(char caracter) {
    bool es_valido = false;

    if ((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z')) {
        es_valido = true;
    }

    return es_valido;
}

int contar_consonantes(t_str cadena) {
    int i, cant = 0;
    char caracter;
    t_str_char cadena_caracter;
    
    for (i = 0; i < strlen(cadena); i++) {
        caracter = cadena[i];
        charstr(caracter, cadena_caracter);

        if ((strstr(VOCALES, cadena_caracter) == NULL ) && (es_caracter_alfabetico(caracter))) {
            cant++;
        }
    }

    return cant;    
}

int main() {
    t_str texto;
    int cant_vocales;
    int cant_consonantes = 0;

    printf("Ingrese un texto: ");
    ingresar_texto(texto);
    validar_texto(texto);

    cant_vocales = contar_vocales(texto);
    cant_consonantes = contar_consonantes(texto);

    printf("\nEl texto: %s", texto);
    printf("Tiene una cantidad de %d vocales.\n", cant_vocales);
    printf("Tiene una cantidad de %d consonantes.\n", cant_consonantes);
    return 0;
}