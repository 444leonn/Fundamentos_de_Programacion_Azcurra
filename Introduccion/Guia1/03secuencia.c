/* Ingresar el radio de una esfera y calcular el volumen. */

# include <stdio.h>
# define PI 3.14

int main()
{
    double radio;
    printf("Ingrese el radio de la esfera a calcular su volumen: ");
    scanf("%lf", &radio);
    
    double vol = (radio * radio * radio * 4 * PI)/3;
    printf("El volumen total de la esfera de radio %.2lf es: %.2lf.", radio, vol);

    return 0;
}
