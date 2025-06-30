/* Solicitar al usuario el ingreso de una temperatura (puede tener decimales por ejemplo 24.5) y la unidad en la que se encuentra (siendo solo un carácter F ó C).
Luego el programa debe mostrar la temperatura ingresada, convertida en la otra unidad.
La relación entre temperaturas Celsius y Fahrenheit está dada por la fórmula: C=5.0 / 9.0 * (F − 32) */

# include <stdio.h>

int main()
{
    float grados;
    char tipo;

    printf("Ingrese el tipo de grados C o F (en mayuscula): ");
    scanf("%c", &tipo);

    getchar();     /* EL GETCHAR PERMITE LIMPIAR EL BUFFER PARA QUE NO QUEDE NINGUN INGRESO DE TECLADO DANDO VUELTA */

    printf("Ingrese la cantidad de grados: ");
    scanf("%f", &grados);

    if (tipo == 'F') {
        float conversion_f = (grados - 32) * 5.0 / 9.0;
        printf("La conversion da: %.2f grados celsius.\n", conversion_f);}
    else {
        if (tipo == 'C'){
            float conversion_c = (grados * 9.0 / 5.0) + 32;
            printf("La conversion da: %.2f grados fahrenheit.\n", conversion_c);}
        else {
            printf("Error, opcion ingresada invalida.\n");}
    }
    return 0;
}