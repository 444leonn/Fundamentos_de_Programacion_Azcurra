/*
* En una competencia de salto en largo, se presentaron 5 participantes. De cada uno se ingresa:
*     Número de participante
*     Fecha de nacimiento (aaaammdd)
*     Distancias de sus 3 saltos expresados en metros.
* El mejor de los 3 saltos se considera como la mejor marca obtenida.
* Se pide:
*     a) Para cada participante mostrar por pantalla el número de participante, la edad y la marca obtenida.
*     b) Informar el número del participante del atleta que obtuvo la mejor marca.
*/

#include <stdio.h>

void ingresar_datos(int *NUMERO_PART, int *FECHA) {
    printf("Ingrese Numero de Participante: ");
    scanf("%d", NUMERO_PART);

    printf("Ingrese Fecha de Nacimiento: ");
    scanf("%d", FECHA);
}

void ingresar_datos_valido(int *NUMERO, int *FECHA) {
    while (*NUMERO <= 0 || *FECHA <= 0) {
        printf("Error, ingreso invalido.\n");
        ingresar_datos(NUMERO, FECHA);
    }
}

int det_edad(int FECHA) {
    int FECHA_ACTUAL = 2025;
    int FECHA_NAC = FECHA / 10000;

    return FECHA_ACTUAL - FECHA_NAC;
}

void ingresar_saltos(float *PRIM_DIST, float *SEG_DIST, float *TER_DIST) {
    printf("Ingrese la primer Distancia de salto: ");
    scanf("%f", PRIM_DIST);

    printf("Ingrese la segunda Distancia de salto: ");
    scanf("%f", SEG_DIST);

    printf("Ingrese la tercer Distancia de salto: ");
    scanf("%f", TER_DIST);
}

float det_mejor_salto(float PRIM, float SEG, float TER) {
    float mejor_salto;

    if (PRIM > SEG && PRIM > TER) {
        mejor_salto = PRIM;
    }
    else if (SEG > PRIM && SEG > TER) {
        mejor_salto = PRIM;
    }
    else if (TER > PRIM && TER > SEG) {
        mejor_salto = TER;
    }
    else {
        mejor_salto = PRIM;
    }

    return mejor_salto;
}

void mostrar_datos(int NUMERO, int FECHA, float SALTO) {
    printf("\n");
    printf("Numero de Participante: %d.\n", NUMERO);
    printf("Edad: %d anios.\n", FECHA);
    printf("Mejor salto: %.3f.\n", SALTO);
    printf("\n");
}

int det_mejor_part(int *NUM, int *FECHA) {
    int mejor_num, i;
    float dist_prim_salto, dist_seg_salto, dist_ter_salto, mejor_salto_actual, mejor_salto = 0;

    for (i = 0; i < 5; i++) {
        ingresar_datos(NUM, FECHA);
        ingresar_datos_valido(NUM, FECHA);
        ingresar_saltos(&dist_prim_salto, &dist_seg_salto, &dist_ter_salto);
    
        mejor_salto_actual = det_mejor_salto(dist_prim_salto, dist_seg_salto, dist_ter_salto);

        mostrar_datos(*NUM, det_edad(*FECHA), mejor_salto_actual);

        if (mejor_salto_actual > mejor_salto) {
            mejor_salto = mejor_salto_actual;
            mejor_num = *NUM;
        }
    }

    return mejor_num;
}

int main() {
    int numero_part, fecha_nacimiento, mejor_part;

    mejor_part = det_mejor_part(&numero_part, &fecha_nacimiento);

    printf("El numero del mejor participante fu: %d", mejor_part);

    
    return 0;
}