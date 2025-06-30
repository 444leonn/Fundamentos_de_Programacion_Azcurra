/*
* Ejemplo de uso de malloc() y free()
* Reserva de espacio de memoria para almacenar un entero
* Asignación de un valor al espacio reservado
*/

#include <stdio.h>

// 1. Es necesario incluir la librería stdlib para poder trabajar con las funciones de memoria dinámica
#include <stdlib.h>

int main() {
    // 2. Declaramos un puntero para almacenar la dirección de inicio del espacio que vamos a reservar
    int *puntero = NULL;

    // 3. Reservamos el espacio usando la función malloc que nos devuelve la dirección de inicio
    puntero = malloc(sizeof(int));

    // 4. Evaluamos si la reserva del espacio fue existosa
    if (puntero != NULL) {
        printf("Espacio de memoria reservado exitosamente.\n");

        // 5. Asignamos un valor entero al espacio reservado
        *puntero = 585;

        printf("Direccion: H:%x D:%ull \n", puntero, puntero);
        printf("Valor: %d", *puntero);

        // 6. Liberamos el espacio de memoria reservado
        free(puntero);
    }
    else
        printf("Error al reservar espacio de memoria.");

    return 0;
}