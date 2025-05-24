# include <stdio.h>

void main() {
	int num1, num2;
	printf("Ingrese un numero: ");
	scanf("%i", &num1);
	
	printf("Ahora otro ingrese otro numero: ");
	scanf("%i", &num2);
	
	if ( num1 > num2 )
		printf("El numero 1: %i es mayor que el numero 2: %i", num1, num2);
	else
		printf(" El numero 1: %i es menor o igual que el numero 2: %i", num1, num2);
	
	return;
}