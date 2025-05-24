/*
* Dada una fecha en formato aaaammdd, verificar si es correcta.
* Si lo es, informarla según “dd de cccc de aaaa”.
* Si no lo es, mostrar un mensaje de error acorde.
* cccc es la cadena de caracteres correspondiente al mes mm.
* Ejemplo 1:
*     fecha = 19910123
*     “23 de enero de 1991”
* Ejemplo 2:
*     fecha = 19910231
*     “error fecha inválida”
*/

#include <stdio.h>
#include <stdbool.h>

void ingreso_fecha(int *num) {
    printf("Ingrese el numero de una fecha en formato aaaammdd: ");
    scanf("%d", num);
}

bool ingreso_positivo(int num) {
    bool no_valido = false;
    if (num < 0) {
        printf("Ingrese invalido.\n");
        no_valido = true;
    }
    return no_valido;
}

void descomposicion_fecha(int num, int *año, int *mes, int *dia) {
    *año = num / 10000;
    *mes = (num % 10000) / 100;
    *dia = num % 100;
}

bool det_bisiesto(int año) {
    bool es_bisiesto = false;

    if ((año % 4 == 0 && año % 100 != 0) || (año % 100 == 0 && año % 400 == 0)) {
        es_bisiesto = true;
    }

    return es_bisiesto;
}

int informe_fecha(bool es_bisiesto, int año, int mes, int dia) {
    switch (mes)
    {

    case 1:
        if (dia > 31 || dia < 1) {
            printf("Error fecha invalida.\n");
        }
        else {
            printf("%d de enero de %d\n", dia, año);
        }
        break;

    case 2:
        if (es_bisiesto) {
            if (dia > 29 || dia < 1) {
                printf("Error fecha invalida.\n");
            }
            else {
                printf("%d de febrero de %d\n", dia, año);
            }
        }
        else {
            if (dia > 28 || dia < 1) {
                printf("Error fecha invalida.\n");
            }
            else {
                printf("%d de febrero de %d\n", dia, año);
            }
        }
        break;
                
    case 3:
        if (dia > 31 || dia < 1) {
            printf("Error fecha invalida.\n");
        }
        else {
            printf("%d de marzo de %d\n", dia, año);
        }
        break;
            
    case 4:
        if (dia > 30 || dia < 1) {
            printf("Error fecha invalida.\n");
        }
        else {
            printf("%d de abril de %d\n", dia, año);
        }
        break;
                
    case 5:
        if (dia > 31 || dia < 1) {
            printf("Error fecha invalida.\n");
        }
        else {
            printf("%d de mayo de %d\n", dia, año);
        }
        break;
            
    case 6:
        if (dia > 30 || dia < 1) {
            printf("Error fecha invalida.\n");
        }
        else {
            printf("%d de junio de %d\n", dia, año);
        }
        break;
        
    case 7:
        if (dia > 31 || dia < 1) {
            printf("Error fecha invalida.\n");
        }
        else {
            printf("%d de julio de %d\n", dia, año);
        }
        break;
            
    case 8:
        if (dia > 31 || dia < 1) {
            printf("Error fecha invalida.\n");
        }
        else {
            printf("%d de agosto de %d\n", dia, año);
        }
        break;
                
    case 9:
        if (dia > 30 || dia < 1) {
            printf("Error fecha invalida.\n");
        }
        else {
            printf("%d de septiembre de %d\n", dia, año);
        }
        break;

    case 10:
        if (dia > 31 || dia < 1) {
            printf("Error fecha invalida.\n");
        }
        else {
            printf("%d de octubre de %d\n", dia, año);
        }
        break;

    case 11:
        if (dia > 30 || dia < 1) {
            printf("Error fecha invalida.\n");
        }
        else {
            printf("%d de noviembre de %d\n", dia, año);
        }
        break;

    case 12:
        if (dia > 31 || dia < 1) {
            printf("Error fecha invalida.\n");
        }
        else {
            printf("%d de diciembre de %d\n", dia, año);
        }
        break;

    default:
        printf("Error fecha invalida.\n");
        break;
    }
}

int main() {
    int num;
    int año_descompuesto, mes_descompuesto, dia_descompuesto;
    bool bisiesto;

    ingreso_fecha(&num);
    while (ingreso_positivo(num)) {
        ingreso_fecha(&num);
    }

    descomposicion_fecha(num, &año_descompuesto, &mes_descompuesto, &dia_descompuesto);

    bisiesto = det_bisiesto(año_descompuesto);

    informe_fecha(bisiesto, año_descompuesto, mes_descompuesto, dia_descompuesto);

    return 0;
}