// Ej2: Solicitar al usuario el ingreso de la fecha actual, el ingreso de una fecha de nacimiento e indicar la edad correspondiente

#include <stdio.h>

void main()
{
    int d_act, m_act, a_act;
    int d_nac, m_nac, a_nac;
    int edad_a, edad_d, edad_m;

    printf("Ingrese la fecha actual:\n");

    printf("Dia: "); 
    scanf("%i", &d_act);
    printf("Mes: ");
    scanf("%i", &m_act);
    printf("Anio: ");
    scanf("%i", &a_act);

    printf("Ingrese su fecha de nacimiento:\n");

    printf("Dia: "); 
    scanf("%i", &d_nac);
    printf("Mes: ");
    scanf("%i", &m_nac);
    printf("Anio: ");
    scanf("%i", &a_nac);

    edad_a = a_act - a_nac;
    edad_m = m_act - m_nac;
    edad_d = d_act - d_nac;


    printf("Su edad es: %d anios %d meses y %d dias.", edad_a, edad_m, edad_d);
}
