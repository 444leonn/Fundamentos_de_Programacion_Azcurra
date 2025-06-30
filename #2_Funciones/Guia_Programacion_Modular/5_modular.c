/*
* Dada una secuencia de números enteros ingresados por el usuario, informar aquellos que sean primos.
* El listado finaliza al ingresar cero. Al finalizar el ingreso se debe indicar la cantidad y la sumatoria de aquellos que fueron primos.
*/

#include <stdio.h>
#include <stdbool.h>

void ingreso_numero(int *numero) {
    printf("Ingrese un numero: ");
    scanf("%d", numero);
}

bool det_primo(int numero) {
    bool primo = true;
    int cont = 2;

    if (numero <= 1)
        primo = false;
        
    while (cont < numero && primo) {
      if (numero % cont == 0 && numero > 2)
        primo = false;
      cont++;
    }
    
    return primo;
}

void informe_primo(int numero, int *cantidad, int *sumatoria) {
    if (det_primo(numero)) {
        printf("El numero es primo.\n");
        *cantidad += 1;
        *sumatoria += numero;
    }
    else {
        printf("El numero no es primo.\n");
    }
}

void informe_final(int cantidad, int sumatoria) {
    printf("La cantidad de numeros primos es de: %d.\n", cantidad);
    printf("La sumatoria total de numeros primos dio: %d.\n", sumatoria);
}

int main() {
    int num, cant = 0, sumatoria_final = 0; 
    bool es_primo;

    ingreso_numero(&num);
    informe_primo(num, &cant, &sumatoria_final);

    while (num != 0) {
        ingreso_numero(&num);
        informe_primo(num, &cant, &sumatoria_final);
    }

    informe_final(cant, sumatoria_final);

    return 0;
}
