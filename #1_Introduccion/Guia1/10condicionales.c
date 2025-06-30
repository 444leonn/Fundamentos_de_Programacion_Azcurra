/* Dada una fecha con año, mes y día, informar si es correcta o no. 
Solicitarle los datos al usuario de forma independiente. Considerar años bisiestos.*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int dia;
    int mes;
    int año;  
    
    printf("Ingrese el año: ");
    scanf("%i", &año);

    printf("Ingrese el mes: ");
    scanf("%i", &mes);

    printf("Ingrese el dia: ");
    scanf("%i", &dia);

    bool es_bisiesto(int año);
    {
        return (año % 4 == 0 && año % 100 != 0) || (año % 400 == 0);
    }

    int dia_en_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
        
    if (mes == 2 && es_bisiesto(año))
    {
        dia_en_mes[1] = 29;
    }
    

    if ( año < 1 || mes < 1 || mes > 12 || dia < 1 || dia > 31 )
        printf("Error, la fecha %02d/%02d/%d es invalida.", dia, mes, año);
    else
        printf("La fecha %02d/%02d/%d es valida.", dia, mes, año);

    return 0;

}