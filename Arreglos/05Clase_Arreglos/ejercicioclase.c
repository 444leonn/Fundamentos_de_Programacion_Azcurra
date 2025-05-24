/*
* Mostrar el promedio de notas del curso
* Mostrar todas las notas superiores al promedio calculado
*/

#include <stdio.h>
#define MAX 250
#define APROBADO 4
typedef int Tvec[MAX];

void ingresar_notas(Tvec notas, int *ML) {
    int i, num;
    i = 0;

    printf("Ingrese las notas (-1 para terminar): ");
    scanf("%d", &num);

    while (num > -1 && i <= MAX) {
        notas[i] = num;
        printf("Ingrese las notas (-1 para terminar): ");
        scanf("%d", &num);
        i++;
    }
    *ML = i;
}

float calcular_promedio(Tvec vec, int ML) {
    float notas = 0;
    int i;

    for (i = 0; i < ML; i++) {

        notas += vec[i];
    }
    return (notas / (float)ML);
}

void mostrar_notas_superiores( Tvec vec , int ML, float promedio){
    int  i;
    printf("Notas mayores al promedio %.2f\n", promedio);

    for ( i = 0; i < ML; i++)
    {
        if (vec[i] > promedio)
            printf("Nota: %d\n", vec[i]);
    }
}

int main() {
    Tvec notas_ingresadas;
    int ML;
    float promedio;

    ingresar_notas(notas_ingresadas, &ML);

    promedio = calcular_promedio(notas_ingresadas, ML);
    printf("El promedio de todas las notas del curso es: %.2f", promedio);

    mostrar_notas_superiores(notas_ingresadas, ML, promedio);

    return 0;
}