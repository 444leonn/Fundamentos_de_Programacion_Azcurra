/*
* Desarrollar una funcion recursiva que muestre los números pares entre n y 1
*/

#include <stdio.h>

void mostrar_pares(int n) {
	if (n > 0)
		if (n % 2 == 0) {
			printf("%d ", n);	
			mostrar_pares(n-2);
		}
		else {
			mostrar_pares(n-1);
		}
}  	

int main() {
	mostrar_pares(15);
	printf("\n\n");
	return 0;
}