# Lenguaje “C”

## Origen y Evolución

Nace a principio de los anos 70, de la mano de Dennis Ritchie en los laboratorios Bell.

- Toma en base otro lenguaje llamado B, creado por Ken Thompson en 1969.
- Reescribe el Sistema Operativo Unix, en 1972.
- A mediados de los 80 se crea C++, que incorpora la orientación a objetos.
- En 1978, Dennis Ritchie y Brian Kernighan, publican la primer edición del libro “El Lenguaje de Programación C”.
- En 1989 se crea el primer estancar, conocido como ANSI C, y posteriormente surgen otro como ISO, etc.

Unix fue reescrito en C, ademas de que la mayor parte del Kernel de Windows esta hecho en el lenguaje C, ademas de otros lenguajes como Python.

## Características

- Es compilado, a diferencia de Python, (utiliza un compilador que convierte el programa fuente en un programa en lenguaje de maquina, que puede ser ejecutado por esta).
- Es imperativo (pertenece al grupo de los lenguajes cuyo tipo de programacion imperativa, lo cual significa que a nuestro programa le indicamos la secuencia de pasos que tieene que hacer para obtener los resultados que queremos).
    - En lo declarativos (como SQL), en cambio, le decimos directamente lo que queremos que haga.
- Es de Alto Nivel o Nivel Intemedio ( Es cercano al lenguaje humano, lejano al lenguaje de maquina) Se lo considera de niver intermedio, por la posibilidad de manejar recursos como la memeorio que otros lenguajes de alto nivel no tienen.
- Es fuertemente o debilmente tipado? ( una variable con un valor de un tipo determinado, no se puede usar como si fuera de otro tipo, a menos que se haga una conversion).
- ES estructurado (permite escribir programas siguiendo las reglas del paradigma de la programacion estruturada.

## Diferencias entre Compilador vs Interprete

![image](https://github.com/user-attachments/assets/1a1ab789-5e44-411b-9c1a-5c88b50c3a7c)

## Mi Primer Programa

Todo programa debe incluir la primer linea de `#include <stdio.h>` la cual significa “Standar Input Output” la cual es una libreria necesaria de incluir en todos nuestro programas de C, ya que nos pone a disposicion una serie de funciones basicas necesarias.

Todo programa en C debe tener la funcion `main()` y el **`*void*`** declara el tipo de dato que se le esta pasando a la funcion. El cual significa que no retorna nada

Las llaves indican que dentro de ellas se encuentra el bloque de programas.

`printf`  es para mostrar por pantalla

Es importante saber que las instrucciones siempre terminan con un punto y coma `instruccion;`

```c
# include <stdio.h>

void main()
{
	printf("Hola Mundo cruel \n");
	return;
}
```

Otro ejemplo:

```c
# include <stdio.h>

int main() {
	printf("Hola Mundo Cruel \n");
	return(0);
}
```

En este caso vemos que la funcion `main()` se le pasa el valor de un **`*int` .***

Pero por lo general a la funcion `main()` se le pasa un **`*void`*** para que no devuelva nada.

# Introduccion a C

## Variables

Para declarar las variables, se debe indicar el tipo de la variable que vamos a declarar.

`[Tipo de Dato] [Nombre de la variables]`

o

`[Tipo de Dato] [Nombre de la variable] = [Valor]`

*Ejemplo:*

`int x`  o `int x = 100` 

En el primer caso, se reserva la variable “x” pero no va a tener ningun valor inicial, (en el caso de entero puede ser que se le asigne el valor 0)

Vamos a encontrarnos con que hay muchos mas tipos de datos que en Python.

### Como mostrar el valor de la variable

Si yo quiero mostrar el valor de una variable usando `printf` debo elegir donde lo quiero mostrar.

*Ejemplo:*

`printf("%i", edad)` El `%i` indica que el formato de la variable que se va a mostrar el entero.

Ademas de que el **%** es el lugar donde se va a posicionar esa variable que indiquemos.

Por lo que si tuvieramos dos variables y las queremos mostrar podemos:

```c
# include <stdio.h>

void main() {
	int num1 = 10, num2 = 5;
	printf("Numero1: %i Numero2: %i", num1, num2);
	return;
```

### Formateadores

| Tipo | **Descripción** |
| --- | --- |
| %d ó %i | entero en base 10 con signo (int) |
| %u | entero en base 10 sin signo (int) |
| %o | entero en base 8 sin signo (int) |
| %x | entero en base 16, letras en minúscula (int) |
| %X | entero en base 16, letras en mayúscula (int) |
| %f | Coma flotante decimal de precisión simple (float) |
| %lf | Coma flotante decimal de precisión doble (double) |
| %e | La notación científica (mantisa/exponente), minúsculas |
| %E | La notación científica (mantisa/exponente), mayúsculas |
| %c | caracter (char) |
| %s | cadena de caracteres (string) |
| %07i | largo mínimo de 7 dígitos, justificado a la derecha, rellena con ceros |
| %.7i | justificado a la derecha, 7 dígitos de largo, sin relleno |
| %8.2f | tamaño total de 8 dígitos, con dos decimales |
| %.*f | tamaño predeterminado, x números decimales |
| %*.*f | tamaño igual a x, y números decimales |
| %s | cadena terminada en null |
| %5s | primeros cinco caracteres o delimitador |
| %.5s | primeros cinco caracteres, sin tener en cuenta el delimitador |
| %20.5s | primeros cinco caracteres, justificados a la derecha, con 20 caracteres de largo |
| %-20.5s | primeros cinco caracteres, justificados a la izquierda, con 20 caracteres de largo |
| %ld | Sirve para los numeros long. |
| %hu | Formato para unsigned short. |
| %lf | Formato para double. |

## Constantes

Una constante es una variable inmutable, lo que quiere decir que, una vez declara la misma su valor va a permanecer estatico y no se podra modificar durante todo el programa.

Para declarar constantes lo que lo hacemos de la siguiente manera:

`# define [nombre_variable] [valor]` 

## Ingresos de Usuario (inputs)

Para poder pedirle al usuario que ingrese un dato y el programa lo lea podemos usar varias opciones, una de ellas es `scanf()` 

Tiene la siguiente estrutura: `scanf(tipo, &variable)` 

*Ejemplo:*

`scanf("%i", &edad)` 

**IMPORTANTE!** Se debe tener en cuenta que para el ingreso de usuario, previamente debemos definir la variable y dejarla sin ningun valor, ya que cualquier valor que le pasemos va a ser sobreescrito al darse el ingreso de usuario.

## Operadores

### Aritmeticos

---

Suma: +

Resta: - 

Multiplicación: * 

División: /

Resto de la División: %

Incremento en n: variable += n

Incremento en 1: variable ++

Decremento en n: variable -= n

### Comparacion

---

Mayor >

Menor <

Igual ==

Distinto: !=

Mayor Igual: >=

Menor Igual: <=

***Para las comparaciones con caracteres se usa comilla simple ‘’***

### Logicos

---

Conjunción - Y: &&

Disjunción - O: ||

Not lógico: !

*Algunos ejemplos* de codigo haciendo operaciones con los distintos tipos de operadores:

```c
# include <stdio.h>

void main(){
    int num1, num2;
    printf("Ingrese un numero: ");
    scanf("%i", &num1);
    printf("Ingrese otro numero: ");
    scanf("%i", &num2);

    printf("\nValor de la variable 1: %i y Valor de la variable 2: %i", num1, num2);
    
    printf("\nEl resultado de la suma es: %i", num1 + num2);

    printf("\nEl resultado de la resta es: %i", num1 - num2);

    printf("\nEl resultado de la division con coma es: %f", (float)num1 / num2);

    return;
}
```

En el caso de la division, si queremos que nos devuelva un resultado REAL o con coma, debemos pasarle el Formato de float %f y ademas convertir una de las variables a float.

## Delimitando Bloques y Respetando su Estilo

- Un bloque de código va encerrado entre llaves { }
- Las instrucciones terminan con punto y coma ;
- Para comentarios de varias líneas, iniciar con /* y finalizar con */
- Para comentarios de una línea o a continuación de código, anteponer //
- Indentar el código para mejor legibilidad, usando una tabulación de 4 espacios
- Usar minúsculas para las instrucciones
- Usar nombres descriptivos en minúsculas para variables y funciones; cuando estén compuestos por más de una palabra, unirlos con guion bajo (_). Por ejemplo: id_cliente
- Escribir las constantes en mayúsculas

## Estructuras Condicionales

Existen tres tipos de estructuras condicionales if, las cuales son simples, compuestas o anidadas.

### If Simple

El condicional *if simple* se compone de unicamente una sola estructura condicional, con sus respectivos parametros.

*Ejemplo:*

```c
# include <stdio.h>

void main(){
	int num;
	printf("Ingrese un numero: ");
	scanf("%i", &num);
	
	if ( num == 1)
		printf("BINGO! Ingresaste el numero 1.\n");

	printf("Adios!\n");
	
	return;
}
```

En este ejemplo lo que podemos ver es que en este programa se declara una varible *num* y luego se le pide al usuario que ingrese un numero.

El condicional *if simple* evalua si el numero ingresado es igual a 1 y si los es muestra por patnalla el mensaje, si no, no hace nada.

### If Compuesto

El condicional *if compuesto* se compone de ademas de la instruccion de if, una instruccion *else*

*Ejemplo:*

En este ejemplo lo que podemos ver es que se pide el ingreso de dos numero al usuario y luego el *if compuesto* evalua si el primer numero es mayor al segundo y muesta el mensaje, y sino muestra el otro mensaje.

```c
# include <stdio.h>

void main() {
	int num1, num2;
	printf("Ingrese un numero: ");
	scanf("%i", &num1);
	
	printf("Ahora otro ingrese otro numero: ");
	scanf("%i", &num2);
	
	if ( num1 > num2 )
		printf("El numero 1: %i es mayor que el numero 2: %i", num1, num2);
	else
		printf(" El numero 1: %i es menor o igual que el numero 2: %i", num1, num2);
	
	return;
}
```

### If Anidado

El condicional *if anidado* nos permite evaluar multiples condiciones, mas alla de las dos que permite el if compuesto o la unica que evalua el if simple.

*Ejemplo:* 

Se solicita el ingreso de dos numeros, y se informa como es uno respecto del otro

```c
# include <stdio.h>

int main(){
    int x,y;
    printf("Valor de X: ");
    scanf("%i",&x);

    printf("Valor de Y: ");
    scanf("%i",&y);

    if (x < y)
        printf("X es menor a Y\n");
    else
        if (x > y)
            printf("X es mayor a Y\n");
        else
            printf("X es igual a Y\n");

    return(0);
}
```

### Switch

Puede suceder que tengamos multiples opciones que analizar y resulte mas conveniente utilizar un switch, en lugar de anidar if.

*Ejemplo:*

Solicitar el ingreso de un numero de mes, e informar a que mes correponde.

```c
# include <stdio.h>

int main(){
	unsigned short mes;
	printf("Ingrese el nro. del mes: ");
	scanf("%i",&mes);
	printf("\nEl mes ingresado por Ud. es: ");
	
	switch (mes) {
		case 1 :
			printf("Enero");
			break;
		case 2 :
			printf("Febrero");
			break;
		case 3 :
			printf("Marzo");
			break;
		case 4 :
			printf("Abril");
			break;
		case 5 :
			printf("Mayo");
			break;
		case 6 :
			printf("Junio");
			break;
		case 7 :
			printf("Julio");
			break;
		case 8 :
			printf("Agosto");
			break;
		case 9 :
			printf("Setiembre");
			break;
		case 10 :
			printf("Octubre");
			break;
		case 11 :
			printf("Noviembre");
			break;
		case 12 :
			printf("Diciembre");
		default :
			printf("Inexistente");
		}
	return(0);
}
```

## Estructuras Iterativas

### For

La estructura iterativa *for* necesita ciertas intrucciones las cuales son:

1. Una variable contador con su valor inicial.
2. La condicion que debe cumplir la variable contador.
3. El incremento o decremento que se aplicara a la variable contador.

Siempre se deben declarar estas tres condiciones, donde la primera es la declaracion del valor la variable, la segunda es la condicion que debe cumplir, y por ultimo la modificacion que se le hace a la variable en cada iteracion.

Ademas de declarar las variables antes de entrar en el ciclo for.

*Ejemplo:*

*Muestra por pantalla los valores del 1 al 100.*

```c
# include <stdio.h>

void main() {
	int contador;
	
	for ( contador = 1; contador <= 100; contador++ )
		printf("%3i", contador);
	
	return;
}
```

*Otro ejemplo:*

*Muestra los valores pares en decremento del 100 al 2.*

```c
# include <stdio.h>

void main() {
	int contador;
	
	for(contador = 100; contador > 0; contador-=2)
		printf("%3i", contador);
	
	return;
}
```

### While

El *while* nos permite repetir una serie de acciones cuando desconocemos cuando se producira el evento que nos permita salir del ciclo.

Las acciones dentro del ciclo, se llevaran a cabo, siempre que la condicion del ciclo while sea **verdadera**, de lo contrario, no se ingresa al ciclo, y se sigue con la siguiente instrucción.

```c
# include <stdio.h>
# define MINIMO 10
# define MAXIMO 250

int main(){
	int valor;
	printf("Ingrese valor: ");
	scanf("%i", &valor);
	while (valor < MINIMO || valor > MAXIMO)
		{
		printf("\nValor Invalido, Reingrese valor: ");
		scanf("%i", &valor);
		}

	printf("\nExito! Ud. ingreso un valor valido: %i",valor);
	
	return(0);
}
```

### do while

El *do … while* nos permite forzar que se ejecute minimamente una vez el codigo que se desea analizar con el while, donde si se cumple la condicion del while, vuelva a iterar, y si no, salga del bucle.

*Ejemplo:*

Solicitar el ingreso de valores hasta ingresar 0, y mostrar el total acumulado.

```c
# include <stdio.h>

int main(){
	int valor;
	int acumulador=0;
	do
	{
	printf("Ingrese valor: ");
	scanf("%i", &valor);
	acumulador = acumulador + valor;
	}
	while (valor != 0);
	
	printf("\nTotal Acumulado: %i", acumulador);
	
	return(0);
}
```

## Booleanos en C

Permiten almacenar valore TRUE o FALSE.

Debemos importar el <stdbool.h>

### Operadores Logicos de Expresion Booleanas

![image_2](https://github.com/user-attachments/assets/d72f48ae-c1c5-4632-a1cc-1dfd94f5bd3a)

### Uso de Booleanos con If

Se permite el uso de variables para eso se debe importar la libreria de ***stdbool.h***

*Ejemplo:*

```c
# include <stdbool.h>

bool x;

if (true)
	printf("Es true");
	
x = true;
if(x)
	printf("x es True");
	
int a = 3;
int b = 5;

bool x = a < b;
bool y = true;

if (x && y)
	printf("x and y es true");
else
	printf("x and y es false");
```

*Ejemplo:*

```c
# Solicitar numeroas hasta que se ingrese el numero 10

bool continuar = true;
int num;
while (continuar) {
	printf("Ingrese un numero hasta adivinar el numero magico:");
	scanf("%d", &num);
	if (num == 10)
		continuar = false;
}
printf("Has acertado");
```

Podemos usar `getchar()` la cual nos permite limpiar el buffer de datos.

# Usando C en Linux con VS Code

A continuacion se detallan los pasos para poder configurar Visual Studio Code para poder usar el compilador de **GCC C++** y el **GDB Debugger** en Linux.

1. Installar Visual Studio Code.
2. Instalar la extesion C/C++ para VS Code.
    
    ![image_3](https://github.com/user-attachments/assets/77b22e7f-e1dc-42ed-b6ef-2f61a349ea32)
    

## Aseguranos que GCC este instalado o instalarlo.

Para eso debemos primero verificar si GCC esta ya instalado, para eso abrimos la terminal y ejecutamos el siguiente comando: `gcc -v` .

Si no esta instalado, ejecutamos el siguiente comando en la terminal para actualizar los paquetes de Ubuntu: `sudo apt-get update` .

Por ultimo instalamos las herramientas del compilador GNU y el GDB Debugger con el comando

## Crear Archivo

***Nota:*** ESTA PARTE DEL TUTORIAL NO ES OBLIGATORIA PODEMOS TRANQUILAMENTE USAR `code .` EN LA CARPETA QUE NOSOTROS QUERRAMOS ELEGIR O CREAR COMO NUESTRO ENTORNO DE TRABAJO

Desde la terminal vamos a crear un directorio vacio llamado proyectos para guardar nuestro proyectos de VS Code. Luego creamos un subdirectorio llamado holamundo, entramos dentro de el y luego lo abrimos en VSC.

```bash
mkdir proyectos
cd proyectos
mkdir holamundo
cd holamundo
code .
```

El comando `code .` abre VS Code en el directorio actual, el cual se convierte en tu “workspace”

### Agregar Codigo de holamundo

En el explorador de archivos del propio Visual Studio, vamos a crear un nuevo archivo llamado `holamundo.c` .

![image_4](https://github.com/user-attachments/assets/6fa1d9b0-1fe8-4c13-b14b-04bfe0bec3ba)

Pegar dentro de el el siguiente codigo y leugo apreta `CTRL + S`  para guardarlo

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
```

## Ejecutar el Archivo

1. Abrir el archivo `holamundo.c` para que sea el archivo activo.
2. Presionar el boton con el simbolo de play y seleccionar la opcion de “Run C/C++ File”.
    
    ![image_5](https://github.com/user-attachments/assets/955de5a6-ddb9-4782-9dba-5bd98c406e23)

3. Elegir la opcion de “gcc Build and Debug Active Files” de la lista de los compiladores detectados.
   
    ![image_6](https://github.com/user-attachments/assets/ab45f7e0-6bf5-47b6-af8e-cc2f46b20f9d)

Luego de esto la salida por pantalla de nuestro programa va a aparecer en la **Terminal Integrada**.

![image_7](https://github.com/user-attachments/assets/02b1052c-26f6-4ad8-b32b-3a5f9faa2d52)


La primera vez que ejecutemos el programa, la extension de C++ va a crear automaticamente el archivo `tasks.json` lo podemos encontrar en la carpeta `.vscode` dentro de nuestra carpeta de proyecto.

El archivo `tasks.json` deberia verse de la siguiente manera:

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "type": "shell",
      "label": "C/C++: g++ build active file",
      "command": "/usr/bin/g++",
      "args": ["-g", "${file}", "-o", "${fileDirname}/${fileBasenameNoExtension}"],
      "options": {
        "cwd": "/usr/bin"
      },
      "problemMatcher": ["$gcc"],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "detail": "Task generated by Debugger."
    }
  ]
```

## Debug al Archivo

El debug nos permite ejecutar nuestro archivo linea a linea, permitiendo ver como se va dando la secuencia de acciones en nuestro programa.

Para poder hacerlo debemos:

1. Abrir nuestro archivo, en este caso `holamundo.c` .
2. Opcional, poner un breakpoint clickeando en el margen o usando F9 estando sobre la linea que deseamos ponerlo. Podemos ver otra forma de hacerlo en el apartado de *“Personalizando Nuestro Debug”*
    
    ![image_8](https://github.com/user-attachments/assets/82dc3eac-9bbd-45a2-9e47-afd0252ed1d6)
    
3. Desde el menu desplegable al lado del boton de play, seleccionamos la opcion de Debug, en lugar de  la opcion Run como usabamos antes.
    
    ![image_9](https://github.com/user-attachments/assets/fe621bfd-ffeb-4422-aa0b-21dfaa234fdf)
    
4. Elegir el compilador de gcc.
    
    ![image_10](https://github.com/user-attachments/assets/eb4af00e-c8c8-4d27-b19b-1622b1694c08)    

## Explorando las opciones de Debug

Podemos ver que en nuestro codigo se va a ver resaltada la linea en la que nosotros posicionamos el breakpoint.

![image_11](https://github.com/user-attachments/assets/772a41fa-00b9-4f54-b015-1f2661cd6944)

Ademas en la parte superior podemos ver un panel de control aparecer, que nos permite ir ejecutando nuestro de codigo de distintas maneras.

![image_12](https://github.com/user-attachments/assets/4f9887bb-e96d-4774-a565-93b46855d443)

1. Clickeando en la flechita curva nos permitir avanzar linea a linea por el codigo, por cada vez que nosotros apretemos sobre el boton.
    
    ![image_13](https://github.com/user-attachments/assets/483cc2aa-e9c3-4828-9e67-1b15861815b4)
    
2. Si presionamos en la flecha que tiene un linea vertical a su lado izquierdo va a ejecutar el programa completo sin frenar en ningun momento.
    
    ![image_14](https://github.com/user-attachments/assets/308272e0-d460-4ce0-8add-cdcc941edebd)
    
3. Podemos ver todos los cambios en el apartado de “Run an Debug”.
   
    ![image_15](https://github.com/user-attachments/assets/45c67b56-4979-4e9e-8cf9-078903a3b855) 

## Personalizando Nuestro Debug

Hay ocasiones en las que queremos tener una configuracion de debugging personalizada, para poder hacerlo debemos crear el archivo `launch.json` . El cual se crea de la siguiente manera:

![image_16](https://github.com/user-attachments/assets/d5b9f147-e9a1-4322-bccc-3cc15116a5c0)

Y seleccionamos nuestro compilador.

![image_17](https://github.com/user-attachments/assets/19ecbf8f-6b3d-4c6d-a460-d90a2722b4f4)

Esto va a crear automaticamente el archivo `launch.json` que se ver parecido a esto:

```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "C/C++: g++ build and debug active file",
      "type": "cppdbg",
      "request": "launch",
      "program": "${fileDirname}/${fileBasenameNoExtension}",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "miDebuggerPath": "/usr/bin/gdb",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ],
      "preLaunchTask": "C/C++: g++ build active file"
    }
  ]
}
```

En el archivo JSON de arriba, `program` especifica el programa al que queres hacer debug. En este caso esta seteado en el directorio activo `${fileDirname}` y en el archivo activo sin extension `${fileBasenameNoExtension}`, por lo que si `holamundo.c` es el archivo activo entonces sera: `helloworld`. La propiedad `args` es un array de argumentos para pasar al programa durante el tiempo de ejecucion.

***Por defecto, la extension C/C++ no va a agregar ningun tipo de breakpoints a tu codigo y por lo tanto el valor de `stopAtEntry` va a estar seteado en `false`.***

***Si se cambia el valor de `stopAtEntry` a `true` va a forzar al debugger a para en el `main` cuando empieza el debugging.***
