# Memoria

Hasta ahora trabajamos con un modelo muy simplificado del manejo de memoria en lenguaje C, pero nos alcanzo para comenzar a programar en este lenguaje.

![image](https://github.com/user-attachments/assets/baffdd6b-3c63-4d50-bdfb-596fbc7f115d)

![image_1](https://github.com/user-attachments/assets/67d5118d-3bc3-412c-ad8d-82266c3f179b)

## Punteros: Repaso de Variables

Desde el punto de vista del programador, las variables en el lenguaje C tienen 4 elementos que demeos tener presenta:

1. Nombre de la Variable
2. Tipo de Dato ⇒ que condiciona su tamaño
3. Valor
4. Direccion de memoria

¿Como puedo conocer la posicion de memoria?

Utilizando el operador  &

¿Como puedo acceder a la variable conociendo su posicion de memoria?

Utilizando el operador *

# Pila de Ejecucion (Call Stack)

![image_2](https://github.com/user-attachments/assets/81e2ad25-c666-448e-bc55-49641d7b55d5)

Es una estructura dinamica de datos LIFO (acronimo incles de Last In, First Out), donde se guarda la informacion sobre las funciones que se estan ejecutando en cada momento.

Como vamos a ver mas adelante en el *debugger* (depurador), en C se administra automaticamente y -en realidad- la estamos utilizando desde comenzamos a modularizar.

- Cada vez que se invoca a una funcion, en *“la pila”* se almacena:
    - Variables locales de la funcion
    - Direccion de Retorno
    - Parametros de Invocacion
    
    Por ejemplo:
    
    - En main se invoca a Funcion_1
    - En Funcion_1 se invoca a Funcion_2

![image_3](https://github.com/user-attachments/assets/5abd2284-f9a1-4e7b-abb5-d809887521a3)

## Desbordamiento de Pila

El desbordamiento de pila (en ingles Stack overflow) es un error que ocurre cuando la pila de llamadas del programa no puede almacenar más datos, lo que provoca la terminación del programa.

# Recursividad

La recursividad (en algunos textos llamada recursion, dado que en ingles se denonima *recursion)* es una tecnica de programacion en el cual una funcion se invoca a si misma.

Es una alternativa diferente para implementar soluciones iterativas (estructuras de repeticion o ciclos)

## Funcion Recursiva

Las funciones recursivas se componen de:

## Caso Base

Una solucion simple para un caso particular (puede haber mas de un caso base)

## Caso Recursivo

Una solucion que involucra volver a utilizar la funcion original, pero con parametros que se acercan mas al caso base.

## Ejemplo Factorial

Escribir un programa que calcule el factorial (!) de un entero no negativo. He aquí algunos ejemplos de factoriales:

0! = 1

1! = 1

2! = 2    → 2 * 1

3! = 6    → 3  *2*  1

4! = 24   → 4  *3*  2 * 1

5! = 120  → 5  *4*  3  *2*  1

La imagen muestra una fórmula matemática que define el factorial (N!) de la siguiente manera:

N! = {

1                si N = 0  (base)

N * (N-1)!      si N > 0  (recursión)

### Iterativo

```c
int factorial_iterativo (int numero) {
	int i, fact = 1;
	for  (i = 1; i <= numero; i++)
	     fact = i * fact;
	return fact;
}
```

### Recursivo

```c
int factorial(int numero) {
	if (numero == 0) // Caso Base
		return 1;
	return numero * factorial(numero - 1); // Caso Recursivo
}
```

![image_4](https://github.com/user-attachments/assets/07458c4a-2dd5-471f-8329-fd001c09f0cb)

Vemos entonces que la implementacion recursiva requiere mas recursos que la iterativa

## Por que escribir programas recursivos?

- Pueden resultar mas cercanso a la descripcion matematica.
- A veces la implementacion es mas facil de analizar.
- Se adaptan mejor a las estructuras de datos recursivas.
- Muchas veces los algoritmos recursivos ofrecen soluciones estructuras, modulares y elegantemente simples.

### Ejemplo

Un ejemplo de una implementación "más cercanos a la descripción matemática" se da en el caso de la Sucesión de Fibonacci, que se define como una sucesión infinita de números naturales que comienza con dos números naturales (dependiendo de la referencia, con 0 y 1 en ciertos casos, otras inician con 1 y 1) y a partir de estos, «cada término es la suma de los dos anteriores»

0,1,1,2,3,5,8,13,21,34,...

➔ Piensen como sería la implementación iterativa

## Comparando Recursividad VS Iteracion

Comparando Recursividad vs Iteración

Repetición:

- Iteración: ciclo explícito (se expresa claramente)
- Recursividad: repetidas invocaciones a la función

Terminación:

- Iteración: termina el ciclo
- Recursividad: se reconoce el caso base

En ambos casos podemos tener ciclos infinitos

Al utilizar Recursividad existe el riesgo de tener un desbordamiento de pila (Stack overflow)

## Clasificacion de Recursividad

### Directa

- Cuando una función incluye una llamada a sí misma

### Indirecta

- Cuando una función llama a otra función y ésta causa que la función original sea invocada

## Cuando es Factible usar Recursividad

Factible de utilizar recursividad:

- Para simplificar el código.
- Cuando la estructura de datos es recursiva ejemplo: recorrido de árboles.

No factible utilizar recursividad:

- Cuando los métodos usen arreglos largos.
- Cuando el método cambia de manera impredecible de campos.
- Cuando las iteraciones sean la mejor opción.

## Consideracion a la hora de Elegir Solucion Recursiva o Iterativa

Se debe considerar que resulta más positivo para cada problema

LA RECURSIVIDAD SE DEBE USAR CUANDO SEA REALMENTE NECESARIA, ES DECIR, CUANDO NO EXISTA UNA SOLUCIÓN ITERATIVA SIMPLE.

## Ejemplo - Secuencia de Fibonacci

```c
#include <stdio.h>
int fibonacci(int numero) {
    if (numero <= 1)
        return numero;
    else
        return fibonacci(numero-1) + fibonacci(numero-2);
}
```

## Ejemplo - Busqueda Binaria

```c
#include <stdio.h>

int buscar(int[] numeros, int numero, int inicio, int fin) {
    int centro = (inicio + fin) / 2;
    
    if (fin < inicio) {
        return -1;
    }
    else {
        if (numero < numeros[centro]) {
            return buscar(numeros, numero, inicio, centro - 1);
        }
        else {
            if (numero > numeros[centro]) {
                return buscar(numeros, numero, centro + 1, fin);
            }
            else {
                if (numero == numeros[centro]) {
                    return centro;
                }
                else {
                    return -1;
                }
            }
        }
    }
}
```

## Recursividad - Ejercicios

### 1- Mostrar X primeros Números Naturales

Orden Ascendente: 

```c
void mostrar_naturales_ascendente(int num) {
	if (num <= 0)
		printf("Error %d no es un numero natural.\n", &num);
	else {
		mostrar_naturales(num - 1);
		printf("%d", num);
	}
}
```

Orden Descendente:

```c
void mostrar_naturales_descendente(int num) {
	if (num <= 0)
		printf("Error %d no es un numero natural.\n", &num);
	else {
		printf("%d", num)
		mostrar_naturales(num - 1);
	}
}
```

### 2- Sumar los dígitos un número

```c
int sumar_digitos(int numero) {
    if (numero < 10)
        return numero;
    return numero % 10 + sumar_digitos(numero / 10);
}
```

### 3- Mostrar números pares entre 1 y X

```c
void mostrar_pares(int numero) {
	if (numero <= 0) {
		return;
	}
	else {
		if (numero % 2 == 0) {
			mostrar_pares(numero - 2);
			printf("%d ", &numero);
		}
		else {
			mostrar_pares(numero - 1);
		}
	}
}
```

### 4- Mostrar de a uno los dígitos de un Número

```c
void mostrar_digitos(int numero) {
	if (numero <= 0) {
		return;
	}
	else {
		mostrar_digitos(numero / 10);
		printf("%d ", numero % 10);
}
```

### 5- Una función recursiva en C que suma los elementos en las posiciones pares de un arreglo

```c
int suma_posiciones_pares(tvec arreglo, int ml) {
    if (ml == 0)
        return 0;
    else {
        if (ml % 2 == 0)
            return arreglo[ml] + suma_posiciones_pares(arreglo, ml - 2);
        else
            return suma_posiciones_pares(arreglo, ml - 1);
    }
}
```