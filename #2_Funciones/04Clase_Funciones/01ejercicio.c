/* 
* Escribir una función que reciba un valor y calcule el factorial del mismo.
* No debe imprimir el valor, debe solamente devolverlo.
* Si no se puede calcular el factorial del valor recibido, la función deberá devolver 0, de lo contrario deberá devolver el valor calculado. 
* Invocarla para los valores -8, 0, 1, 5; mostrando en cada caso lo que devuelve.
* Definición: El factorial de un entero positivo n, se define como el producto de todos los números enteros positivos desde 1 hasta n. El factorial de 0 es 1.
*/

#include <stdio.h>

unsigned long long factorial(int n)
{
    unsigned long long resultado;
    resultado = 1;
    int i;

    if ( n < 0 )
    {
        resultado = 0;
    }
    else
    {
        for (i = 2; i <= n; i++)
        {
            resultado *= i;
        }
    }

    return resultado;
}

int main()
{
    int numero1 = 0, numero2 = 1, numero3 = 5, numero4 = -8;

    printf("El resultado del factorial da %llu\n", factorial(numero1));
    printf("El resultado del factorial da %llu\n", factorial(numero2));
    printf("El resultado del factorial da %llu\n", factorial(numero3));
    printf("El resultado del factorial da %llu\n", factorial(numero4));

    return 0;
}