/*
* Escribir una función en C, que reciba como parámetro una cadena de tipo t_cadena, y devuelva la cantidad de palabras que hay en la cadena.
* Considerar que una palabra está separada de otra, por uno ó más blancos.
* No recorrer la cadena más de una vez.
* Declare un tipo t_cadena acorde.
* Escribir el programa que incluya a la función y las invocaciones con los siguientes caso de prueba:
*    cant_palabras("El sol es amarillo.") devuelve 4
*    cant_palabras(" Hoy es 30 de Junio de 2021 ") devuelve 7
*    cant_palabras("30/06/2021") devuelve 1
*    cant_palabras("El precio es $2.000.- ") devuelve 4
*    cant_palabras(" ") devuelve 0 
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 40
typedef char t_cadena[MAX];

void ingresar_cadena(t_cadena cadena) {
    printf("Ingrese una cadena: ");
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
}

int cant_palabras(t_cadena cadena) {
    int i = 0, cant = 0;
    bool dentro_palabra = false;

    while (cadena[i] != '\0') {
        if (cadena[i] != ' ' && ! dentro_palabra) {
            dentro_palabra = true;
            cant++;
        } else if (cadena[i] == ' ') {
            dentro_palabra = false;
        }
        i++;
    }

    return cant;
}

int main() {
    t_cadena cadena_palabras;

    ingresar_cadena(cadena_palabras);
    
    printf("%d", cant_palabras(cadena_palabras));

    return 0;
}