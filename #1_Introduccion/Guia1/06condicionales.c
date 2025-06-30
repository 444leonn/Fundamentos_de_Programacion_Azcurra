/* Ingresar tres números y hallar el mayor. */

#include <stdio.h>

int main()
{
    float num1, num2, num3;

    printf("Ingrese un primer numero: ");
    scanf("%f", &num1);

    printf("Ingrese un segundo numero: ");
    scanf("%f", &num2);

    printf("Ingrese un tercer numero: ");
    scanf("%f", &num3);

    if ( num1 == num2 && num1 == num3)
        printf("Los numeros son iguales.");
    else 
        if ( num1 > num2 && num1 > num3 )
            printf("El numero: %.2f es el mayor.", num1);
        else
            if ( num2 > num1 && num2 > num3 )
                printf("El numero: %.2f es el mayor.", num2);
            else 
                printf("El numero: %.2f es el mayor.", num3);
    
    return 0;
}
