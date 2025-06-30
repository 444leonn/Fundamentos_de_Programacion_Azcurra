/*
* Escribir un programa en lenguaje C que solicite un listado de alumnos que consiste en número de padrón (legajo) y 3 notas por alumno.
* Todos los datos se le deben solicitar al usuario uno a uno.
* Informar el mayor y el menor promedio registrado junto con el número de padrón del alumno.
* La carga de datos finaliza cuando se ingresa padrón igual a cero.
* Asumir que los numeros que ingresa el usuario son todos enteros positivos por lo que no requieren validación.
* En los datos de prueba de su ejecución debe estar incluido su propio padrón.
*
* Ejemplo:
* legajo 101101 notas [5,6,7] promedio: 6
* legajo 101202 notas [7,6,7] promedio: 6.6
* legajo 101303 notas [9,6,9] promedio: 8
* legajo 101404 notas [8,6,8] promedio: 7.3
*
* Resultado:
* mayor promedio: 8.00 legajo: 101303
* menor promedio: 6.00 legajo: 101101
*/

#include <stdio.h>

int main()
{
    float primer_nota, segunda_nota, tercer_nota;
    long legajo, legajo_mayor, legajo_menor;
    float promedio, mayor_promedio, menor_promedio;

    printf("Ingrese el numero de legajo y 3 notas del alumno.\n(0 PARA SALIR.)\n");

    printf("Numero de Legajo: ");
    scanf("%ld", &legajo);
    printf("Primer Nota: ");
    scanf("%f", &primer_nota);
    printf("Segunda Nota: ");
    scanf("%f", &segunda_nota);
    printf("Tercer Nota: ");
    scanf("%f", &tercer_nota);

    legajo_mayor = legajo;
    legajo_menor = legajo;

    promedio = (primer_nota + segunda_nota + tercer_nota) / 3;
    mayor_promedio = promedio;
    menor_promedio = promedio;

    while (legajo != 0)
    {
        printf("Ingrese nuevo numero de legajo y 3 notas del alumno.\n(0 PARA SALIR.)\n");

        printf("Numero de Legajo: ");
        scanf("%ld", &legajo);
        if (legajo != 0)
        {
            printf("Primer Nota: ");
            scanf("%f", &primer_nota);
            printf("Segunda Nota: ");
            scanf("%f", &segunda_nota);
            printf("Tercer Nota: ");
            scanf("%f", &tercer_nota);
    
            promedio = (primer_nota + segunda_nota + tercer_nota) / 3;
    
            if (promedio > mayor_promedio)
            {
                mayor_promedio = promedio;
                legajo_mayor = legajo;
            }
            else if (promedio < menor_promedio)
            {
                menor_promedio = promedio;
                legajo_menor = legajo;
            }
        }
    }

    printf("mayor promedio: %.2f legajo: %ld\n", mayor_promedio, legajo_mayor);
    printf("menor promedio: %.2f legajo: %ld\n", menor_promedio, legajo_menor);

    return 0;
}

/*
* Basicamente al hacer el ejercicio se necesita tener el ingreso fuera del while para que pueda usar un numero que sea realmente practico a la hora de validar.
* Tanto padron como promedio mayor o menor, ya que por ejemplo si inicializaramos la variable menor en 0, no se veria nunca modificada ya que es casi imposible que el padron,
* sea negativo.
* En cambio si comparamos con otro valor no nulo, distinto de cero resulta mas satisfactoria la ejecucion del programa.
*/