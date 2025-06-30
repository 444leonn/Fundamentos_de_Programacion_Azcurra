/* Hallar la superficie de un triángulo conociendo la base y la altura. Solicitarle los datos de entrada al usuario. */

# include <stdio.h>

int main(){
    int base, altura;

    printf("Ingrese la base de triangulo: ");
    scanf("%i", &base);

    printf("Ingrese la altura del triangulo: ");
    scanf("%i", &altura);

    int superficie = (base * altura)/2;

    printf("La superficie del triangulo es: %i", superficie);

    return 0;
}