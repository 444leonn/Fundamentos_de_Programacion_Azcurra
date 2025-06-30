/*
* Escribir una función que recibirá por parámetro, una palabra, que representa un sustantivo en singular.
* La función deberá devolver, el plural de dicho sustantivo, aplicando las siguientes reglas:
*   a. Agregar una “s” al final, si la palabra termina en vocal sin acento.
*   b. Agregar una “s” al final, si la palabra termina con una é (acentuada).
*   c. Si la palabra termina en “z”, la reemplazamos por “ces”.
*   d. Agregamos “es” al final, si la palabra termina en una consonante (a excepción de la “s”, la “z”, y la “x”), ó si la palabra termina con las vocales acentuadas: á, í, ó, ú.
*   e. Si el sustantivo termina en “s” ó “x”, entonces el plural es igual al singular, por lo tanto la función deberá devolver lo mismo que recibió.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 20
#define VOCALES "AEIOUaeiou"
#define VOCALES_ACENTUADAS "ÁÍÓÚáíóú"
#define CONS_EXCEPTUADAS "SXZsxz"

typedef char T_Str[MAX];

void cargar_palabra(T_Str palabra) {
    printf("Ingrese una palabra: ");
    fgets(palabra, MAX, stdin);
    palabra[strcspn(palabra, "\n")] = '\0';
}

bool es_vocal_sin_acento(char caracter) {
    char str_char[] = {caracter, '\0'};
    return strstr(VOCALES, str_char) != NULL;
}

void agregar_s_final(T_Str cadena) {
    int ult_pos = strlen(cadena) - 1;
    char ult_char = cadena[ult_pos];
    cadena[ult_pos + 1] = 's';
    cadena[ult_pos + 2] = '\0'; 
}

void agregar_ces_final(T_Str cadena)  {
    int ult_pos = strlen(cadena) - 1;
    char ult_char = cadena[ult_pos];
    cadena[ult_pos + 1] = 'c';
    cadena[ult_pos + 2] = 'e';
    cadena[ult_pos + 3] = 's';
    cadena[ult_pos + 4] = '\0'; 
}

bool es_consonante(char caracter) {
    char str_char[] = {caracter, '\0'};
    return strstr(CONS_EXCEPTUADAS, str_char) == NULL;
}

bool es_vocal_acentuada(char caracter) {
    char str_char[] = {caracter, '\0'};
    return strstr(VOCALES_ACENTUADAS, str_char) != NULL;
}

void agregar_es_final(T_Str cadena)  {
    int ult_pos = strlen(cadena) - 1;
    char ult_char = cadena[ult_pos];
    cadena[ult_pos + 1] = 'e';
    cadena[ult_pos + 2] = 's';
    cadena[ult_pos + 3] = '\0';
}

void plural_palabra(T_Str palabra)  {
    int ult_pos = strlen(palabra) - 1;
    char ult_char = palabra[ult_pos];
    if (es_vocal_sin_acento(ult_char)) {
        agregar_s_final(palabra);
    }
    else if (ult_char == 'é') {
        agregar_s_final(palabra);
    }
    else if (ult_char == "z" || ult_char == "Z") {
        agregar_ces_final(palabra);
    }
    else if (es_consonante(ult_char) && es_vocal_acentuada(ult_char)) {
        agregar_es_final(palabra);
    }
}

int main() {
    T_Str palabra;

    cargar_palabra(palabra);
    plural_palabra(palabra);

    printf("La palabra en plural es: \"%s\".\n", palabra);
    
    return 0;
}