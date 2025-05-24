/*
* Escribir una función que reciba un mes y un año como números enteros; y devuelva la cantidad de días del mes, considerando los años bisiestos.
* Tenga en cuenta que un año bisiesto es aquel divisible por 4, salvo que sea divisible por 100, en cuyo caso también debe ser divisible por 400.
*/

#include <stdio.h>
#include <stdbool.h>

void ingreso(int *mes, int *anio) {
    printf("Ingrese un anio: ");
    scanf("%d", anio);

    printf("Ingrese un mes: ");
    scanf("%d", mes);
}

bool ingreso_valido(int mes, int anio) {
    bool no_valido = false;
    if (mes < 0 || anio < 0) {
        printf("Error debe ingresar una fecha positiva.\n");
        no_valido = true;
    }
    else if (mes > 12) {
        printf("Error debe ingresar una fecha positiva.\n");
        no_valido = true;
    }

    return no_valido;
}

bool det_bisiesto(int anio) {
    return ((anio % 4 == 0 && anio % 100 != 0) || (anio % 100 == 0 && anio % 400 == 0));
}

int calculo_dias(int mes, int anio, bool det_bisiesto) {
    int dias_mes;

    switch (mes) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
          dias_mes = 31;
          break;
        case 2:
          if (det_bisiesto)
            dias_mes = 29;
          else
            dias_mes = 28;
          break;
        case 4:
        case 6:
        case 9:
        case 11:
            dias_mes = 30;
            break;
    }

    return dias_mes;
}

int main() {
    int mes, anio, dias_mes;
    bool es_bisiesto;

    ingreso(&mes, &anio);
    es_bisiesto = det_bisiesto(anio);
    while(ingreso_valido(mes, anio)) {
        ingreso(&mes, &anio);
        es_bisiesto = det_bisiesto(anio);
    }

    dias_mes = calculo_dias(mes, anio, es_bisiesto);

    printf("El mes %d, tiene %d dias.\n", mes, dias_mes);

    return 0;

}