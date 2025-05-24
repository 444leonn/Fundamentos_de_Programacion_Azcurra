/*
* Escribir un programa que solicite el ingreso de un texto que será enviado mediante un telegrama.
* Luego de ingresado, se deberá informar la cantidad de palabras que lo componen y el importe a abonar por el solicitante.
* El texto sólo puede contener, letras, números y los siguientes signos de puntuación: . , ; : ()
* Para el cálculo de las palabras, considerar que una palabra estará separada de otra, por uno ó más blancos.
* Para el cálculo del importe a abonar, deberá considerar que cada palabra pagará $10 por cada 3 caracteres.
* Por las fracciones menores a los 3 caracteres, pagará $8.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 80
#define NUMEROS "0123456789"
#define SIGNOS ".,;:()"

typedef char T_Str[MAX];

void ingreso_telegrama(T_Str texto) {
    fgets(texto, MAX, stdin);
    texto[strcspn(texto, "\n")] = '\0';
}

bool es_alfabetico(char caracter) {
    return ((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z'));
}

bool es_numerico(char caracter) {
    char str_char[2];

    str_char[0] = caracter;
    str_char[1] = '\0';

    return (strchr(NUMEROS, str_char) != NULL);
}

bool es_signo_valido(char caracter) {
    char str_char[2];

    str_char[0] = caracter;
    str_char[1] = '\0';

    return (strstr(SIGNOS, str_char) != NULL);
}

bool det_valida(char aux) {
    return (!(es_alfabetico(aux) || es_numerico(aux) || es_signo_valido(aux)) || aux == ' ');
}

int cant_palabras(T_Str cadena, int caracteres_por_palabra[MAX]) {
    int i, cant_palabras = 0, cant_caracteres;
    bool dentro_palabra = false, es_valida = true;
    char aux;

    i = 0;
    aux = cadena[i];
    while (aux != '\0' && det_valida(aux)) {
        if (aux != ' ') {
            if (! dentro_palabra) {
            dentro_palabra = true;
            cant_palabras++;
            cant_caracteres = 0;
            }
            cant_caracteres++;
            caracteres_por_palabra[cant_palabras - 1] = cant_caracteres;
        }
        else if (aux == ' ') {
            dentro_palabra = false;
        }
        
        i++;
        aux = cadena[i];
    }

    return es_valida ? cant_palabras : 0;
}

void informe(T_Str telegrama) {
    int i;
    bool es_valida = true;
    char aux;
    
    i = 0;


}

int main() {
    T_Str telegrama;
    int caracteres_por_palabra[MAX];

    printf("Ingrese un telegrama:\n");
    ingreso_telegrama(telegrama);

    cant_palabras(telegrama, caracteres_por_palabra);

    return 0;
}