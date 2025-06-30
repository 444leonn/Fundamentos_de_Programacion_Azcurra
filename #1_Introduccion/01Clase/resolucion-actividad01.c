/*
  a) 
  Escribir un programa en Python, C - o pseudocódigo- que le solicite 
  al usuario que ingrese su número de padrón y devuelva por pantalla 
  todos los divisores del padrón ingresado. En la lista se deben omitir 
  el 1 y el propio padrón.

  b)
  Se debe mostrar una ejecución y la salida por pantalla generada.
*/

// Resolucion en lenguaje C
#include <stdio.h>

int main() {
	int i, padron;
	
	printf("\n");
	printf("Ingrese numero de padron: ");
	scanf("%d", &padron);
	
	printf("Los divisores son:");
	for (i=2; i <= padron/2; i++) {
		if ((padron % i) == 0) {
			printf(" %d", i);
		}
	}
	printf("\n\n");
	return 0;
}
