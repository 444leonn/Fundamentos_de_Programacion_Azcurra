/* Ingresar un número entero y decir si: a) es par o impar. b) es mayor, menor o igual a cero. */

# include <stdio.h>

int main()
{
    int num;
    printf("Ingrese un numero entero: ");
    scanf("%i", &num);

    if ( num % 2 == 0 )
        printf("El numero es par.\n");
    else
        printf("El numero es impar.\n");
    
    if ( num > 0 )
        printf("El numero es mayor que 0.\n");
    else if ( num < 0 )
        printf("El numero es menor que 0.\n");
    else
        printf("El numero es igual a 0.\n");

    return 0;
}