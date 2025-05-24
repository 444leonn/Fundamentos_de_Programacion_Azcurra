/* Dado un número n, informar los n primeros términos de la sucesión geométrica de razón 3 (1, 3, 9, 27, etc.). */

#include <stdio.h>

int main()
{
    int num;
    int i;
    int resultado = 1;

    printf("Ingrese un numero a calcular la sucesion geomtrica a razon 3: ");
    scanf("%i", &num);

    for (i = 1; i <= num; i++) {
        printf("%i ", resultado);
        resultado *= 3;
    }
    
    return 0;

}