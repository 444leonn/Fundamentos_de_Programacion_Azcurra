/*
 * Programa para generar el archivo stock.dat con datos de libros
 * para probar el ejercicio_1.c
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    int codigo;
    char titulo[30];
    int stock_actual;
    int stock_minimo;
    float precio;
} T_Libro;

int main() {
    FILE *archivo;
    T_Libro libros[] = {
        {101, "El Quijote", 50, 10, 25.50},
        {102, "Cien Anos de Soledad", 8, 5, 18.75},
        {103, "1984", 35, 15, 22.30},
        {104, "Orgullo y Prejuicio", 12, 8, 16.90},
        {105, "El Principito", 60, 20, 12.45},
        {106, "Rayuela", 15, 12, 28.80},
        {107, "Don Juan Tenorio", 45, 10, 19.60},
        {108, "La Casa de Bernarda Alba", 25, 8, 14.25},
        {109, "Ficciones", 40, 15, 21.70},
        {110, "El Aleph", 18, 6, 23.90},
        {111, "Cronica de una Muerte", 32, 12, 17.35},
        {112, "El Amor en los Tiempos", 22, 10, 26.80},
        {113, "Hamlet", 55, 20, 20.15},
        {114, "Romeo y Julieta", 28, 12, 18.40},
        {115, "Macbeth", 38, 15, 19.85},
        {116, "El Gato Negro", 16, 8, 15.60},
        {117, "El Cuervo", 42, 18, 13.75},
        {118, "Moby Dick", 30, 10, 29.90},
        {119, "El Gran Gatsby", 24, 8, 21.25},
        {120, "Matar un Ruisenor", 48, 16, 24.70}
    };
    
    int cantidad_libros = sizeof(libros) / sizeof(T_Libro);
    
    archivo = fopen("stock.dat", "wb");
    if (archivo == NULL) {
        printf("Error: No se pudo crear el archivo stock.dat\n");
        return 1;
    }
    
    // Escribir todos los registros al archivo
    fwrite(libros, sizeof(T_Libro), cantidad_libros, archivo);
    
    fclose(archivo);
    
    printf("Archivo stock.dat generado exitosamente!\n");
    printf("Se crearon %d registros de libros.\n", cantidad_libros);
    printf("\nAlgunos ejemplos de los datos generados:\n");
    printf("----------------------------------------\n");
    
    // Mostrar algunos ejemplos
    for (int i = 0; i < 5; i++) {
        printf("Codigo: %d\n", libros[i].codigo);
        printf("Titulo: %s\n", libros[i].titulo);
        printf("Stock actual: %d\n", libros[i].stock_actual);
        printf("Stock minimo: %d\n", libros[i].stock_minimo);
        printf("Precio: %.2f\n", libros[i].precio);
        
        // Verificar si califica para oferta
        if (libros[i].stock_actual > (2 * libros[i].stock_minimo)) {
            int cantidad_oferta = (libros[i].stock_actual - libros[i].stock_minimo) / 2;
            float precio_oferta = libros[i].precio * 0.7;
            printf("*** CALIFICA PARA OFERTA ***\n");
            printf("    Cantidad a ofertar: %d\n", cantidad_oferta);
            printf("    Precio con descuento (30%%): %.2f\n", precio_oferta);
        }
        printf("----------------------------------------\n");
    }
    
    return 0;
}
