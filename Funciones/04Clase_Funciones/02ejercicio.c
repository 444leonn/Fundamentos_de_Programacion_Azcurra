/* 
* Escribir una función que reciba dos valores enteros y devuelva la suma de los valores entre el menor y el mayor de dichos números, incluídos.
* No debe imprimir el valor, debe solamente devolverlo.
* Invocarla para los valores (-2, 2); (5, -10); (0, -4); (10, 15) y (-3, -25); mostrando en cada caso lo que devuelve.
*/

#include <stdio.h>

int sumatoria(int num1, int num2)
{
    int resultado = 0;
    int i;
    int mayor, menor;

    if (num1 < num2)
    {
        mayor = num2;
        menor = num1;
    }
    else
    {
        mayor = num1;
        menor = num2;
    }

    for (i = menor; i <= mayor; i++)
    {
        resultado += i;
    }

    return resultado;
}

int main()
{
    printf("Funcion Sumatoria para (-2, 2), %d\n", sumatoria(-2, 2));
    printf("Funcion Sumatoria para (5, -10), %d\n", sumatoria(5, -10));
    printf("Funcion Sumatoria para (0, -4), %d\n", sumatoria(0, -4));
    printf("Funcion Sumatoria para (10, 15), %d\n", sumatoria(10, 15));
    printf("Funcion Sumatoria para (-3, -25), %d\n", sumatoria(-3, -25));

    return 0;
}
