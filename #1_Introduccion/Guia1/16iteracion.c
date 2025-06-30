/* 
    Dado un número entero positivo ingresado por el usuario, procesarlo e indicar: (realizar un programa diferente para cada caso)
    a) La cantidad de dígitos pares e impares que lo componen.
    b) El menor y el mayor dígito del número.
    Recordar uso de división y módulo:
        Ejemplo:
            111 / 10 = 11
            111 % 10 = 1
*/

#include <stdio.h>

int main()
{
    int numero, digito, pares = 0, impares = 0;

    printf("Ingrese un número entero positivo: ");
    scanf("%d", &numero);

    while (numero > 0)
    {
        digito = numero % 10; // Extraer el último dígito
        if (digito % 2 == 0)
            pares++;
        else
            impares++;
        numero /= 10; // Eliminar el último dígito
    }

    printf("Cantidad de dígitos pares: %d\n", pares);
    printf("Cantidad de dígitos impares: %d\n", impares);

    return 0;
}