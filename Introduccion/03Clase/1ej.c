// Ej1: Ingresar las 3 medidas de los lados de un triangulo y mostrar que tipo de triangulo es equilatero, escaleno, isosceless

#include <stdio.h>

void main()
{
    int lado_1, lado_2, lado_3;

    printf("Ingrese las medidas de los lados de un triangulo para determinar si es: Escaleno, Equilatero o Isosceles.\n");

    printf("Lado 1: ");
    scanf("%d", &lado_1);

    printf("Lado 2: ");
    scanf("%d", &lado_2);
    
    printf("Lado 3: ");
    scanf("%d", &lado_3);

    if (lado_1 == lado_2 && lado_1 == lado_3)
        printf("El triangulo es Equilatero.");
    else if (lado_1 == lado_2 || lado_1 == lado_3 || lado_2 == lado_3)
        printf("El triangulo es Isosceles.");
    else
        printf("El triangulo es Escaleno.");
}