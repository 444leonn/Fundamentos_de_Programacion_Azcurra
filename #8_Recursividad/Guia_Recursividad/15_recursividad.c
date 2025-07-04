/*
* Implementar una función recursiva la cual calcule la potencia entre dos números enteros.
* Pasa la resolución debe basarse en el algoritmo de exponenciación binaria (ver pdf de consignas).
*/

#include <stdio.h>

void ingresar_numero(int *numero) {
    printf("Ingrese un numero entero: ");
    scanf("%d", numero);
}

int calcular_potencia(int numero_x, int numero_n) {
    int temp;

    if (numero_n == 0)
        return 1;
    else if (numero_n == 1)
        return numero_x;
    else {
        if (numero_n % 2 == 0)
            return calcular_potencia(numero_x, numero_n / 2) * calcular_potencia(numero_x, numero_n / 2);
        else
            return numero_x * calcular_potencia(numero_x, numero_n - 1);
    }
}

int main() {
    int num_x, num_n, resultado;

    ingresar_numero(&num_x);
    ingresar_numero(&num_n);

    resultado = calcular_potencia(num_x, num_n);

    printf("Resultado:  %d", resultado);
    
    return 0;
}