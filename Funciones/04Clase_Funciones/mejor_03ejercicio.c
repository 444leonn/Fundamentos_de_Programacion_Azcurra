/*
/*
* Escribir un programa que solicite el ingreso de valores, que representarán una cantidad de segundos. 
* El programa deberá informar al usuario, el equivalente en días, horas, minutos y segundos.
* Se debe validar que el valor ingresado sea entero y positivo, de lo contrario, deberá mostrarse el mensaje: “Valor ingresado inválido”.
* El ingreso de valores finaliza cuando el usuario ingrese como valor 0.
* 
* Ejemplo:
* Valor ingresado: 1234567
* Resultado: Dias: 14, Horas: 6, Minutos: 56, Segundos 7
*/

#include <stdio.h>

#define segundo_por_dia 86400
#define segundos_por_hora 3600
#define segundos_por_minuto 60

void ingreso_segundos(long *valor) 
{
    do {
        printf("Ingrese un numero entero positivo o 0 para terminar: ");
        scanf("%ld", valor);
        if (*valor < 0) {
            printf("Valor ingresado invalido\n");
        } 
    } while (*valor < 0);
}

void convertir_tiempo(long tiempo_convertido, int *dia, int *horas, int *minutos, int *segundos)
{
    *dia = tiempo_convertido / segundo_por_dia;
    tiempo_convertido %= segundo_por_dia;

    *horas = tiempo_convertido / segundos_por_hora;
    tiempo_convertido %= segundos_por_hora;

    *minutos = tiempo_convertido / segundos_por_minuto;
    *segundos = tiempo_convertido % segundos_por_minuto;
}

void mostrar_conversion(int dia, int horas, int minutos, int segundos)
{
    printf("%dD:%dH:%dM:%dS\n", dia, horas, minutos, segundos);
}

int main()
{
    long tiempo_total;
    int dia, hora, minutos, segundos;

    ingreso_segundos(&tiempo_total);
    while (tiempo_total != 0)
    {
        convertir_tiempo(tiempo_total, &dia, &hora, &minutos, &segundos);
        mostrar_conversion(dia, hora, minutos, segundos);
        ingreso_segundos(&tiempo_total);
    }

    return 0;
}