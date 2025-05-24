/* Calcular el sueldo de un operario ingresando por teclado la cantidad de horas que trabajó en el mes y el valor de la hora. 
Mostrarle el resultado al usuario con un mensaje adecuado. */

# include <stdio.h>

int main()
{
    double horas;
    double valor;

    printf("Ingrese la cantidad de horas trabajadas: ");
    scanf("%lf", &horas);

    printf("Ingrese el valor de cada hora trabajada: ");
    scanf("%lf", &valor);

    double total_a_pagar = horas * valor;

    printf("El total a cobrar por la cantidad de horas trabajadas es de $%.2lf", total_a_pagar);

    return 0;
}
