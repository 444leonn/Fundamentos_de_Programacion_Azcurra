#include <stdio.h>
#include <string.h> // Libreria para las funciones de strings.

int main() {
    char cadena1[15] = "HOLA";
    char cadena2[] = "MUNDO";
    char cadena3[] = " ";

    // Uso de STRLEN: para la longitud de la cadena (solo caracteres)
    printf("Cadena: %s tiene %ld caracteres.\n", cadena1, strlen(cadena1));
    printf("Cadena: %s tiene %ld caracteres.\n", cadena2, strlen(cadena2));
    printf("Cadena: %s tiene %ld caracteres.\n", cadena3, strlen(cadena3));
    
    // Uso de STRCPY: para modificar el valor de la cadena strcpy(destino, fuente), se debe tener en cuenta la longitud maxima
    strcpy(cadena1, "CHAU");
    printf("\nAhora la cadena1 tiene: %s\n", cadena1);

    // Uso de STRCAT: para concantenar cadenas strcat(cadena_a_modif, cadena_destino).
    // El STRCAT va a agregarle a la primer cadena de la funcion lo que tenga la segunda, por lo tanto se debe tener en cuenta que la long max de la primera alcanze
    strcat(cadena1, cadena3); 
    strcat(cadena1, cadena2);
    printf("Ahora la cadena tiene la concatenacion: %s\n", cadena1);

    // Uso de STRCMP: para comparar dos cadenas
    if (strcmp(cadena1, cadena2) == 0) {
        printf("Las cadenas 1 y 2 son iguales.\n");
    }
    else if (strcmp(cadena1, cadena2) > 0) {
        printf("La cadena 1 es mayor que la cadena 2.\n"); // Alfabeticamente
    }
    else {
        printf("La cadena 1 es menor que la cadena 2.\n"); // Alfabeticamente
    }

    // Uso de STRSTR: busca una cadena dentro de otra
    char *posicion;
    posicion = strstr(cadena1, cadena2);
    
    if (posicion == NULL) {
        printf("La cadena %s NO existe en la cadena %s\n", cadena2, cadena1);
    }
    else {
        printf("La cadena %s SI existe en la cadena %s\n", cadena2, cadena1);
    }
    
    return 0;
}