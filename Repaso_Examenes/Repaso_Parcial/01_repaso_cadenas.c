#include <stdio.h>
#include <stdbool.h>

#define MAXNOMBRE 50

typedef char T_cadena[MAXNOMBRE];

void cargar_cadena(T_cadena cadena) {
    fgets(cadena, MAXNOMBRE, stdin);
    

}

void MostrarInvertida (T_cadena cadena) {
    int i;

    
}

int main() {
    T_cadena Cadena;

    printf("Ingresar palabra: ");
    

    MostrarInvertidad(Cadena);

    return 0;
}