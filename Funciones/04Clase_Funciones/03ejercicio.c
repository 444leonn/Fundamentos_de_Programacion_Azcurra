/*
* Escribir un programa que solicite el ingreso de valores, que representarán una cantidad de segundos. 
* El programa deberá informar al usuario, el equivalente en días, horas, minutos y segundos.
* Se debe validar que el valor ingresado sea entero y positivo, de lo contrario, deberá mostrarse el mensaje: “Valor ingresado inválido”.
* El ingreso de valores finaliza cuando el usuario ingrese como valor 0.
* 
* Ejemplo:
* Valor ingresado: 1234567
* Resultado: Dias: 14, Horas: 6, Minutos: 56, Segundos 7
*/

unsigned long long ingreso_dato() {
    long num_segundos;

    do
    {
        printf("Ingrese una cantidad de segundos:");
        scanf("%ld", &num_segundos);
    
        if (num_segundos < 0) {
            printf("Valor ingresado invalido.\n");
        }
        else {
            return num_segundos;
        }
    } while (num_segundos != 0);
}

void convertir_tiempo(unsigned long long segundos) {
    int dias, horas, minutos;
    dias = segundos / 86400;
    segundos %= 86400;
    horas = segundos / 3600;
    segundos %= 3600;
    minutos = segundos / 60;
    segundos %= 60;

    printf("Resultado: Dias: %d, Horas: %d, Minutos: %d, Segundos: %llu\n", dias, horas, minutos, segundos);
}

void main(){
    unsigned long long segundos;
    int salir = 1;

    while (salir == 1) {
        segundos = ingreso_dato();

        if (segundos == 0) {
            printf("FIN.\n");
            salir = 0;
        }
        else {
            convertir_tiempo(segundos);
        }
    }
}