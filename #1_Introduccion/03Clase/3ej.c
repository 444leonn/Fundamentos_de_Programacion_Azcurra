// Ingresar una serie de numeros enteros finalizada en 0 y mostrar el mayor numero, el menor numero y el promedio de la serie.

#include <stdio.h>

void main()
{
    int serie_num, cant_acum, cant_total = 0, mayor, menor, promedio;

    printf("Ingrese numero para acumular en una serie: ");
    scanf("%d", &serie_num);
    cant_total ++;
    cant_acum = serie_num;
    mayor = serie_num;
    menor = serie_num;

    while (serie_num != 0)
    {
        if (serie_num > mayor)
            mayor = serie_num;
        else if (serie_num < menor)
            menor = serie_num;

        printf("Ingrese numero para acumular en una serie: ");
        scanf("%d", &serie_num);

        cant_acum = cant_acum + serie_num;
        cant_total++;

    }

    promedio = cant_acum / (cant_total - 1);

    printf("El promedio es: %d\n", promedio);
    printf("El mayor es: %d\n", mayor);
    printf("El menor es: %d\n", menor);


}