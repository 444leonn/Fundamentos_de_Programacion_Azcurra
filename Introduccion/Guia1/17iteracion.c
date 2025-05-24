/* Generar un dibujo por pantalla con el siguiente patrón solicitando al usuario la altura.
Ejemplo: altura=5 debe dibujar por pantalla:
*
**
***
****
***** 
*/

#include <stdio.h>

int main()
{
    int altura;
    int i;
    int j;

    printf("Ingrese la altura para el patron a dibujar: ");
    scanf("%d", &altura);
    
    for (i = 1; i <= altura; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}