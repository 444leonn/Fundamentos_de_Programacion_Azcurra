/*
* Este programa tiene el objetivo de cargar el archivo "medicamentos.dat" del ejercicio 1.
* No esta puesto en el archivo de la resolucion, ya que no se pide implicitamente.
* Se recomienda cargar primero el archivo. Aunque el repositorio ya incluye un archivo de ejemplo.
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    int codigo;
    char categoria[25];
    char nombre_comercial[30];
    int stock_actual;
} t_medicamento;

int main() {
    FILE *arc_medicamentos;
    t_medicamento medicamentos[] = {
        {1001, "Analgesico", "Ibuprofeno 600mg", 150},
        {1002, "Antibiotico", "Amoxicilina 500mg", 80},
        {1003, "Antiacido", "Omeprazol 20mg", 200},
        {1004, "Analgesico", "Paracetamol 500mg", 300},
        {1005, "Antihistaminico", "Loratadina 10mg", 120},
        {1006, "Antibiotico", "Azitromicina 500mg", 45},
        {1007, "Cardiovascular", "Enalapril 10mg", 90},
        {1008, "Analgesico", "Aspirina 100mg", 180},
        {1009, "Antiacido", "Ranitidina 150mg", 75},
        {1010, "Vitamina", "Complejo B", 250},
        {1011, "Antiinflamatorio", "Diclofenac 50mg", 110},
        {1012, "Antibiotico", "Cefalexina 500mg", 65},
        {1013, "Cardiovascular", "Losartan 50mg", 85},
        {1014, "Analgesico", "Tramadol 50mg", 40},
        {1015, "Antiacido", "Sucralfato 1g", 95}
    };
    
    int cantidad_medicamentos = sizeof(medicamentos) / sizeof(t_medicamento);
    
    arc_medicamentos = fopen("medicamentos.dat", "wb");
    
    if (arc_medicamentos == NULL) {
        printf("Error, no se pudo crear el archivo medicamentos.dat\n");
    }
    else {
        // Escribir todos los medicamentos al archivo
        fwrite(medicamentos, sizeof(t_medicamento), cantidad_medicamentos, arc_medicamentos);
        
        fclose(arc_medicamentos);
        
        printf("Archivo 'medicamentos.dat' generado exitosamente!\n");
        printf("Se cargaron %d medicamentos en el archivo.\n", cantidad_medicamentos);
    }
    
    return 0;
}
