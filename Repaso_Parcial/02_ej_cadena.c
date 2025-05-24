/*
* Escribir una funcion en C, que reciba como parametro una cadena de tipo t_cadena, y devuelva la cantidad de palabras que hay en la cadena.
* Considerar que una palabra esta separada por otra, por uno o mas blancos.
* No recorrer la cadena mas de una vez
* Declare un tipo t_cadena acorde.
* Escribir el programa que incluya a la funcion y las invocaciones con los siguientes casos de prueba:
*     cant_palabras("El sol es amarillo.") devuelve 4
*     cant_palabras(" Hoy es  30 de Junio de  2021") devuelve 7
*     cant_palabras("30/06/2021") devuelve 1
*     cant_palabras("El precio es  $2.000.- ") devuelve 4
*     cant_palabras("   ") devuelve 0
*/

#include <stdio.h>
#include <string.h>

#define MAX 30

typedef  char t_cadena[MAX];

void ingresar_cadena(t_cadena cadena) {
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
}

int cant_palabras(t_cadena cadena) {
    int i, cant = 1;

    for (i = 0; i < strlen(cadena); i++) {
        if ((cadena[i] == ' ') && (cadena[i + 1] != '  ') && (cadena[i + 1] != '\0')) {
            cant++;
        }
    }

    return cant;
}

int main() {
    t_cadena cadena;

    printf("Ingrese una cadena: ");
    ingresar_cadena(cadena);

    printf("%d\n", cant_palabras(cadena));
    
    return 0;
}