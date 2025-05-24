# include <stdio.h>

void main(){
    int num1, num2;
    printf("Ingrese un numero: ");
    scanf("%i", &num1);
    printf("Ingrese otro numero: ");
    scanf("%i", &num2);

    printf("\nValor de la variable 1: %i y Valor de la variable 2: %i", num1, num2);
    
    printf("\nEl resultado de la suma es: %i", num1 + num2);

    printf("\nEl resultado de la resta es: %i", num1 - num2);

    printf("\nEl resultado de la division con coma es: %f", (float)num1 / num2);

    return;
}
