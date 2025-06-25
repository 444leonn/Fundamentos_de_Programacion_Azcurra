# Memoria Dinamica
Podemos considerar la memoria del ordenador como una tira de celdas.
La cual se encuentra dividida en cuatro segmentos logicos:
1. **Code Segment**, (segmento de codigo): donde se localiza el codigo resultante de compilar nuestra aplicacion. Es decir, la algoritmia en codigo maquina.
2. **Data Segment**, (segmento de datos): almacena el contenido de las variables defindas como externas (las globales) y las estaticas.
3. **Stack Segment**, (PILA): almacena el contenido de las variables locales de la invocacion de cada funcion, incluyendo las de la funcion principal _main_.
4. **Extra Segment**, (HEAP): es la zona de la memoria dinamica.

Cada celda se corresponde a un Byte (unidad minima de memoria equivalente a 8 bits)

Si queremos saber en qué dirección está una determinada variable debemos usar el operador &.

Por ejemplo:

    ```
    int a = 8;
    printf("%d \n", &a);
    ```

En este codigo la variable _a_ almacena el valor 8, y se encuentra en una determinada direccion. Esta direccion se mantiene fija durante todo el tiempo de vida de la varaible, es decir, hasta que encuentre una llave de cierre de bloque.

En general, las direcciones en donde estan las variables no nos interesara conocerlas, salvo a modo ilustrativo.

De la gestión de los tres primeros bloques de memoria: el segmento de código, el de datos y el de pila, se encarga el compilador, quien reserva y libera los bloques de memoria de manera automática.

La gestión del bloque identificado como heap será responsabilidad del desarrollador. Es decir, los bloques de memoria que se soliciten al heap deben hacerse con una determinada instrucción en el programa, y cuando la variable no se necesite más debemos liberar la memoria ocupada con otra instrucción, en caso de no hacerlo esa porción de memoria queda inutilizada hasta que apaguemos la máquina.

## Punteros
Un _puntero_ es un tipo de variable especial que almacena direcciones de memoria. Esto quiere decir que, en lugar de guardar datos como una edad (entero), un sueldo (long), una nota (float), etc., almacen direcciones de memoria de la propia maquina. Cuando una variable de tipo puntero guarda una direccion de memoria decimos que _apunta_ a esa direccion.
### Punteros a Datos Simples
Un _puntero_ tiene que conocer, de que **tipo** sera la variable que este en la direccion de memoria que almacenar su valor. Dicho de otra forma, debe conocer el tipo de dato que esta guardado o se va a guardar en la direccion hacia la que apunta.

Por ejemplo, si un puntero guarda la direccion de memoria _AB1002_, debe saber que tipo se almacenara en dicha direccion, si sera un _int_ o un _float_ o cualquier otro.

Esto se debe a dos razones:
1. debe saber qué cantidad de celdas ocupará el dato que está en dicha dirección.
2. debe saber cómo interpretar esos datos.
Tenemos que recordar que cada celda está formada por bits pero esos bits pueden ser interpretados de distinta manera, por ejemplo, como enteros, como flotantes, como un carácter en código ASCII, etc. Por lo tanto, cuando definimos una variable de tipo entero debemos decir a qué tipo de variable apuntará.
### ¿Como se declara una Variable de tipo Puntero?
Al igual que cualquier otra variable, indicando su tipo y un identificador de la variable, con la salvedad que luego de indicar el tipo se debe colocar el signo asterisco “*” que indica que es un puntero.

**Ejemplos:**

    ```
    int * pi;
    char * pc;
    float * pf;
    // El símbolo asterisco puede ir inmediatamente después del tipo
    int* pi;
    // O inmediatamente antes del identificador de la variable
    int *pi;
    ```
### Punteros y Vectores
Cuando declaramos un vector el compilador reserva la memoria solicitada y guarda solo la dirección del primer elemento.

Por ejemplo, si declaramos un vector de 10 enteros
    ```
    int vec[10];
    ```
el compilador reserva 10 lugares contiguos para almacenar los enteros.

De estos 10 lugares solo guarda la dirección del primero en la variable que llamamos vec. Luego, es responsabilidad del programador no excederse de los 10 lugares pedidos.

## Como utilizar la Memoria Dinamica
Vamos a utilizar la biblioteca _"standard library"_ incluyendola en nuestro programa con 
    ```
    #include <stdlib.h>
    ```

Esta biblioteca nos permite acceder a distintas funciones, las cuales nos dan la opcion de hacer distintas acciones con la memoria _HEAP_.
### Funcion malloc()
Solicita una porcion de memoria disponible, sin inicializar. (lo indica en cantidad de bytes).

    ```
    void *malloc(size_t size);
    
    ```

**Descripcion:**
* Reserva la memoria solicitada y retorna un puntero a dicha memoria (si no pude reservar la memoria, devuelve NULL).
* No se realiza ninguna inicializacion de la misma.
### Funcion realloc()
Reasigna una porcion de memoria ya disponible, por otra de un tamaño diferente.

    ```
    void *realloc(void *puntero, size_t size);
    ```

**Descripcion:**
* Intenta cambiar el tamaño del bloque de memoria señado por el _puntero_ y que fue asignado previamente con una llamada a _malloc()_ o _calloc()_.

**Parametros:**
* **puntero** - Puntero a un bloque de memoria previamente asignado con _malloc()_, _calloc()_ o _realloc()_ que se va a reasignar. Si es **NULL**, se asigna un nuevo bloque y la funcion devuelve un puntero al mismo.
* **size** - Nuevo tamaño del bloque de memoria, en bytes. Si es 0 y puntero apunta a un bloque de memoria existente, el bloque de memoria señalado se desasigna y devuelve un puntero NULL.

**Valor de Retorno**
* Retorna un puntero a la nueva memoria reservada, o bien NULL si la solicitud falla.
### Funcion free()
Libera una porcion de memoria previamente solicitada.

    ```
    void free(void *puntero);
    ```

**Descripcion:**
* Libera el bloque de memoria previamente reservada por una invocacion a malloc, calloc o realloc.

**Parametros:**
* **puntero**
### Funcion calloc()
Solicita una porcion de memoria disponible, pero a diferencia de malloc(), esta lo inicializa en cero.

    ```
    void *calloc(size_t nmemb, size_t size); // Cantidad de elementos de un determinado tamaño
    ```

**Descripcion:**
* Reserva la memoria solicitada y retorna un puntero a dicha memoria. Todo el bloque 
### Variables estaticas
Se declaran como
    ```
    static int nombre;
    ```
Y permiten preservar su valor a lo largo del programa mas alla de si la funcion en la que se declaran es cerrada. Lo cual permite guardar un valor dentro de una funcion y utilizarlo en distintas invocaciones de esa misma funcion.
