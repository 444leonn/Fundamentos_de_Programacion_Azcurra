/*
* Ejemplo de uso de malloc() y free()
* Reserva de espacio de memoria para almacenar un entero
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
        printf("Direccion: H:%x D:%llu", puntero, puntero);

        // 5. Liberamos el espacio de memoria reservado
        free(puntero);
    }
    else
        printf("Error al reservar espacio de memoria.");

    return 0;
}