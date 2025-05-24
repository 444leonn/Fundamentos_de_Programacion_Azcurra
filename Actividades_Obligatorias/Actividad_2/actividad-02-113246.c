/* Solicitar un número entero positivo al usuario y calcular su factorial. 
En el caso de ingresar un número negativo m1ostrar un mensaje que diga “no se puede calcular el factorial del número ingresado”.
Recordar que por definición factorial(0) = 1 y factorial(1) = 1 Utilizar el tipo de dato "long" para el resultado del calculo.
Utilizar valores comprendidos entre 0 y 20 inclusives para las pruebas.*/

#include <stdio.h>

int main()
{
    int num;
    long factorial = 1;
    printf("Ingrese un numero entero a calcular su factorial: ");
    scanf("%i", &num);

    for ( num; num >=1; num-- )
    {
        factorial *= num;
    }

    if ( num < 0 )
        printf("Error, no se puede calcular el factorial de un numero negativo. \n");
    else
        printf("El calculo del factorial da: %ld \n", factorial);

    return 0;
}



