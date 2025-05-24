/*  Dados a y n números enteros, informar la potencia enésima de a por productos sucesivos.*/

#include <stdio.h>

int main()
{
    int num_a;
    int num_n;
    int resultado = 1;

    printf("Ingrese un numero a calcular su potencia enesima: ");
    scanf("%d", &num_a);

    printf("Ingrese el numero enesimo hasta donde llegara la potencia: ");
    scanf("%d", &num_n);

    for (num_n ; num_n > 0; num_n--)    
        resultado *= num_a;

    printf("El resultado de la potencia enesima es: %i", resultado);

    return 0;
}