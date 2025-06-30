/* Escribir un programa que permita al usuario ingresar los montos de las compras de un cliente y que al finalizar informe por pantalla el importe total a pagar, 
teniendo en cuenta que si éste supera los $10.000 se le debe aplicar un 10% de descuento.
Se desconoce la cantidad de datos que se van a ingresar.
La carga de datos finaliza cuando el usuario ingresa el monto 0 (cero).
Se debe validar que no se ingresen montos negativos indicando al usuario monto invalido.*/


#include <stdio.h>

int main()
{
    float valor_compra = 1;
    float resultado;

    while (valor_compra != 0)
    {
        printf("Ingrese el monto de la venta (o 0 para terminar): ");
        scanf("%f", &valor_compra);

        if (valor_compra < 0)
        {
            printf("Monto no valido\n");
        }
        else
        {
            resultado += valor_compra;
        }
    }

    if (resultado > 10000)
    {
        float descuento;
        descuento = resultado * 0.1;
        float resultado_descontado;
        resultado_descontado = resultado - descuento;

        printf("El total a pagar ( %.2f ) supera los $10000, se aplica descuento del 10%%\n", resultado);
        printf("Total a pagar: %.2f\n", resultado_descontado);
    }
    else
    {
        printf("Total a pagar: %.2f\n", resultado);
    }

    printf("Saliendo..\n");

    return 0;
}