/* Calcular y mostrar la suma de los n primeros números naturales. Siendo n un
número ingresado por el usuario. Usar fórmula [ n.(n+1) ] / 2. */

# include <stdio.h>

int main(){
    long num;
    printf("Ingrese un numero natural: ");
    scanf("%ld", &num);

    int suma = (num*(num+1))/2;

    printf("El resultado es: %i \n", suma);

    return 0;
}