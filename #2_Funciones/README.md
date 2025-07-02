# Programacion Estructurada y Modular

Significa escribir un programa que cumpla con las siguientes reglas:

1. ***Diseño Modular:*** Implicar dividir un problema en problemas mas pequeños. “Descomponer el programa en modulos independientes.
2. ***Diseño Descendente sobre los Modulos:*** “Refinamiento - Stepwise”, subdividir sucesivamente los modulos hasta que cada modulo tenga solo una tarea especifica a ejecutar.
3. ***Cada modulo debe ser codificado utilizando las estructuras de control basicas.***

Nos detemos cuando un modulo resuelva o de soluciones especificas a un problema en particular.

Los items **1** y **2** se corresponden con el **Diseño Estructurado** y la **Propiedad de Modularidad.** El item **3** se corresponde mas con el **Teorema del Programa Estructurado.**

Esto se da con varios objetivos los cuales son:

- Reducir los tiempos requeridos para, Escribir, Verificar, Depurar y Mantener los programas.
- Reutilizacion del Codigo, estos submodulos vendrian a servir como “subcodigos” que vamos a poder invocar o llamar para reutilizarlo.

## Representaciones Graficas de Modulos

A la hora de desarrollar un aplicacion uno no se sienta a escribir codigo directamente sino que debe idea, pensar e incluso diagramar de alguna manera la resolucion del problema o el desarrollo de la aplicacion.

*Ejemplo:*

- El recuadro vendria a ser un modulo, en este caso se encarga de solicitar el ingreso de datos.
    
    Las flechas en ambos sentidos vendrian siendo la recepcion y devolucion de los datos ingresados.
    
    ![image](https://github.com/user-attachments/assets/a1a8f883-c8ff-4687-a1d9-ae3a8e59e8e6)
    
- Se podria tener otro recuadro, osea otro modulo, que se encargue del calculo de la Deuda del cliente,
    
    Las flechas en un sentido solo es dibido a que toma datos para poder hacer el calculo y luego devuelve un resultado en la flecha de debajo
    
    ![image_1](https://github.com/user-attachments/assets/378d3b4f-cc35-4a7d-8e58-6c08b288cc66)

# Funciones

Ahora nosotros vamos a comenzar a programar nuestras propias funciones.

## Algunas Funciones ya Conocidas por Nosotros

Estas funciones son algunas de las cuales el lenguaje C nos provee para que utilizemos.

| Funcion | Breve Descripcion |
| --- | --- |
| scanf | Permite el ingreso de datos |
| printf | Permite imprimir elementos |
| strlen | Devuelve la longitud de una cadena |
| strcpy | Permite asignar un nuevo valor a una cadena |
| strcat | Permite concatenar valores de una cadena |
| strcmp | Permite comparar 2 cadenas |
| strstr | Busco una cadena en otra cadena |

## Declaracion de Funciones en C

1. Debemos indicar el **Tipo a Devolver.**
2. Luego indicamos el **Nombre** de la funcion.
3. Y entre parentesis vamos a indicar los **parametros formales** (cuando invocamos a la funcion se dicen “parametros actuales”)
4. El cuerpo de la funcion encerrado entre llaves.
5. Por ultimo el **return** que puede retornar o no un valor.

### Pasaje de Parametros

Si yo no necesito devolver el parametro modificado lo paso por valor. Porque en ese caso se entrega una copia del parametro actual

Si el parametro formal se devuelve modificado, y me interesa devolverlo modificado, requiere que se pase por referencia.

- Por **Valor:** se entrega una copia del valor del parametro actual. Los parametros Actuales y los Formales utilizan distintas posiciones de memoria.
- Por **Referencia:** Se entrega una referencia (direccion de memoria) al parametro actual. Los parametros Actuales y los Formales utilizan la misma posicion de memoria en este caso.

Hay parametros que siempre deberemos pasar por referencia.

# Algunos Conceptos de Modularizacion

## Funciones

- ***Funciones con Tipo:*** Devolver un solo valor con return.
- ***Funcion Void:*** Realizar una accion que no sea devolver un valor.

## Cohesion

Hace referencia a cuando cada modulo realiza una unica tarea trabajando sobre una sola estructura de datos.

Un alto grado de cohesion seria cuando las funciones o modulos realizan tareas unicas y mas especificas.

## Acoplamiento

Hace referencia al grado de interaccion entre los modulos.

El grado de acoplamiento seria cuando los modulos tiene poco o baja relacion entre ellos, haciendolos mas independientes.

Alto acoplamiento → Baja relacion

Bajo Acolpamiento → Alta relacion
