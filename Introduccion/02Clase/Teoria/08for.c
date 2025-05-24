/* Ejemplo que usa un for.
 Imprime los numeros pares del 100 al 2.
 El for necesita:
 	1: una variable_contador con su valor_inicial
	2: condicion que debe cumplir la variable_contador
	3: incremento o decremento que se le aplicará en cada ciclo a la variable_contador*/

# include <stdio.h>

void main() {
	int contador;
	
	for(contador = 100; contador > 0; contador-=2)
		printf("%3i", contador);
	
	return;
}