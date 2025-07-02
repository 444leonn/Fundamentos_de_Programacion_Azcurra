/*
* Desarrollar una funcion recursiva que muestre de a uno los dígitos de un número en orden inverso
*/

#include <stdio.h>
	 
void mostrar_digitos(int n) 
{	  
	if (n > 9) {
		printf("%d ", n % 10);	
		mostrar_digitos(n / 10);
	} else {
		printf("%d", n);
	}
}  


int main()
{
	mostrar_digitos(15);
	printf("\n\n");
	return 0;
}		