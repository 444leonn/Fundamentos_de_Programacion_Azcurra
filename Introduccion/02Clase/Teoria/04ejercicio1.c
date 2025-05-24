/* Escribir un programa en C, que muestre por pantalla una primer línea, con tu nombre y apellido, por ejemplo:
"Hola soy Juan Perez", reemplazando Juan Perez por tu nombre y tu apellido;
y una segunda línea, con tu legajo, por ejemplo:
"Mi legajo fiuba es: 111324", en este caso previamente declara una variable de tipo entero para almacenar el valor que corresponda a tu legajo, y utilízala dentro de la instrucción que te permite mostrar el mensaje.

Para la construcción del programa, podés utilizar el ide que prefieras.
Luego, ejecuta el programa y recortá la salida de este, junto con el código, para generar un archivo del tipo jpg, y subilo como resultado de la actividad.
Además, copia y pega el código en el cuadro de texto que te aparece. */

# include <stdio.h>

void main(){
    printf("Hola soy Leon Acosta \n");
    
    int num_legajo = 113246;
    printf("Mi legajo fiuba es: %i \n", num_legajo);
    
    return;
}