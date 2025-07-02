/*
* Leer un archivo de caracteres que representa un texto formado por oraciones terminadas en punto.
* Copiarlo en otro archivo eliminando los espacios superfluos.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void limpiar_archivo(FILE *archivo, FILE *archivo_copiar) {
    char caracter_actual;
    char caracter_anterior = '\0';

    fread(&caracter_actual, sizeof(char), 1, archivo);
    while (!feof(archivo)) {
        if (!(caracter_actual == ' ' && caracter_anterior == ' ')) {
            fwrite(&caracter_actual, sizeof(char), 1, archivo_copiar);
        }
        caracter_anterior = caracter_actual;
        fread(&caracter_actual, sizeof(char), 1, archivo);
    }
}

int main() {
    FILE *archivo_texto, *archivo_copiado;
    
    archivo_texto = fopen("./prueba_ej_7.txt", "r");
    archivo_copiado = fopen("./copia_texto.txt", "w");

    if (archivo_copiado == NULL || archivo_texto == NULL) {
        printf("Error, no se han podido abrir los archivos.\n");
    }
    else {
        limpiar_archivo(archivo_texto, archivo_copiado);
        printf("Archivo copiado exitosamente sin espacios superfluos.\n");
    }

    fclose(archivo_texto);
    fclose(archivo_copiado);

    return 0;
}