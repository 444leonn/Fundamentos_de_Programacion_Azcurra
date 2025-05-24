// Solicitar al usuario el ingreso de una fecha e indicar que numero de dia del año es. Considerar años bisiestos.
// Ejemplo 1 de febrero es el numero 32 del año

// Es bisiesto cuando es divisible por 400, o divisible por 4 y no por 100.


#include <stdio.h>

int main()
{
    int dia, mes, anio;
    int num_dia = 0;
    printf("Ingrese la fecha actual. Para conocer que numero de dia del año es.\n");
    
    printf("Ingrese el año actual: ");
    scanf("%d", &anio);

    printf("Ingrese el mes actual: ");
    scanf("%d", &mes);

    printf("Ingrese el dia: ");
    scanf("%d", &dia);


    // Valido si es bisiesto, si lo es inicializo la variable num dia en uno para que lo tenga en cuenta.
    if ((anio % 400 == 0) || (anio % 4 == 0 && anio % 100 != 0))
        num_dia++;
    
    if (anio < 0 || dia < 0 || mes < 0)
    {
        printf("Fecha ingresada invalida.\n");
    }
    else
    {
        switch (mes)
        {
        case 1:
            printf("%d\n", dia);
            break;
        case 2:
            dia = dia + 31;
            printf("El numero de dia del año es: %d\n", dia);
            break;
        case 3:
            num_dia += dia + 59;
            printf("El numero de dia del año es: %d\n", num_dia);
            break;
        case 4:
            num_dia += dia + 90;
            printf("El numero de dia del año es: %d\n", num_dia);
            break;
        case 5:
            num_dia += dia + 120;
            printf("El numero de dia del año es: %d\n", num_dia);
            break;
        case 6:
            num_dia += dia + 151;
            printf("El numero de dia del año es: %d\n", num_dia);
            break;
        case 7:
            num_dia += dia + 181;
            printf("El numero de dia del año es: %d\n", num_dia);
            break;
        case 8:
            num_dia += dia + 212;
            printf("El numero de dia del año es: %d\n", num_dia);
            break;
        case 9:
            num_dia += dia + 243;
            printf("El numero de dia del año es: %d\n", num_dia);
            break;
        case 10:
            num_dia += dia + 273;
            printf("El numero de dia del año es: %d\n", num_dia);
            break;
        case 11:
            num_dia += dia + 304;
            printf("El numero de dia del año es: %d\n", num_dia);
            break;
        case 12:
            num_dia += dia + 334;
            printf("El numero de dia del año es: %d\n", num_dia);
            break;
        default:
            printf("Mes ingresado invalido.");
            break;
        }
    }

    return 0;
}