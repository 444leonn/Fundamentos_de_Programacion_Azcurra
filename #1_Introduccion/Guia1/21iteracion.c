/* Se dan como datos de entrada las fechas de nacimiento (día, mes, año) y los números de DNI de cada integrante de un grupo.
Se indica fin de datos de entrada cuando día = 0. Muestre por pantalla el número de DNI del integrante más joven del grupo. */

#include <stdio.h>

int main()
{
    int ingreso_fin = 0;
    while (ingreso_fin == 0)
    {
        int dia;
        int mes;
        int year;
        int num_dni;
        int reingreso_dni;
        int reingreso_dia;
        int reingreso_mes;
        int reingreso_year;

        printf("Ingrese su fecha de nacimiento (dia/mes/year): ");
        scanf("%d/%d/%d", &dia, &mes, &year);
        printf("Ingrese su numero de DNI: ");
        scanf("%d", &num_dni);

        if (dia == 0)
        {
            printf("Saliendo...\n");
            ingreso_fin = 1;
        }
        else if (dia < 0 || mes <= 0 || year <= 0 || num_dni <= 0)
        {
            printf("Error debes ingresar una fecha y numero de DNI valido.\n");
        }
        else
        {
            printf("Ingrese una nueva fecha (dia/mes/year): ");
            scanf("%d/%d/%d", &reingreso_dia, &reingreso_mes, &reingreso_year);

            printf("Ingrese un nuevo numero de DNI: ");
            scanf("%d", &reingreso_dni);
            if (reingreso_dia == 0)
            {
                printf("Saliendo...\n");
                ingreso_fin = 1;
            }
            else if (reingreso_dia < 0 || reingreso_mes < 0 || reingreso_year < 0 || reingreso_dni < 0)
            {
                printf("Error debes ingresar una fecha y numero de DNI valido.\n");
            }
            else if (reingreso_dia < dia || reingreso_mes < mes || reingreso_year < year)
            {
                num_dni = reingreso_dni;
                printf("El numero de dni de la persona mas joven es: %d\n", num_dni);  
            }
        }
    }
    return 0;
}
