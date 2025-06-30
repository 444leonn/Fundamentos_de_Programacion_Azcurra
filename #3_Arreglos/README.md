# Arreglos en C

## Que es un Arreglo en C?

Un ***arreglo*** es una coleccion finita y ordenada de datos **homogeneos** →Son todos del mismo Tipo

Estractura Estatica (en C) —> Se define en tiempo de diseñoNo puede ser redimensionado

Acceso directo a un elemento del arreglo →  A través de su posición en el arreglo

### Clasificacion

- Unidimensionales: Vectores - Listas
- Bidimensionales: Matrices - Tablas
- Multidimensionales: Dimension N

## Unidimensionales - Vectores
![captura_arreglos_1](https://github.com/user-attachments/assets/23613606-5590-490e-89da-5a0c47bb8a38)

### Acceso a los Elementos

El primer elemento ocupa la posición 0 del arreglo (vector), por lo tanto en un arreglo de N elementos, el último de los elementos estará en la posición N-1

***Arreglo V de N elementos: v[n]***

- Primer Elemento →v[0]
- Ultimo Elemento → v[n-1]
- Elemento Intermedio → v[valor entre 1 y n-2]

## Bidimensionales - Matrices
![captura_arreglos_2](https://github.com/user-attachments/assets/f71d4c6d-5b3b-4356-8515-3dab631ade2c)

## Acceso a los elementos

El primer elemento ocupa la posición 0,0 del arreglo (matriz), por lo tanto en un arreglo bidimensional de NxMelementos, el último de los elementos estará en la posición [ N-1 , M-1 ]

***Arreglo M de NxM elementos: v[n]***

- Primer Elemento →m[0][0]
- Ultimo Elemento → m[n-1][m-1]
- Elemento Intermedio →m[valor entre 1 y n-2][valor entre 1 y m-2]

## Declaracion

Debemos indicar, tipo de los elementos, un nombre y la cantidad de/ elementos en cada dimensión

`tipo nombre_arreglo[cantidad_elementos]`

***Arreglos Unidimensionales***

- arreglo de 100 elementos enteros `int v_nros[100]`
- arreglo de 100 elementos reales `float v_reales[100]`
- arreglo de 25 elementos tipo caracter `char v_chars[25]`
- arreglo ***declarado*** por extensión `int v_pares[] = {2,4,6,8,10}`

***Arreglos Bidimensionales***

- Matriz de 5 filas por 4 columnas de enteros `int m_enteros[5][4]`
- Matriz de 2 filas por 3 columnas de enteros `int m_enteros[3][3] ={{1,2,3},{4,5,6}}`

## Restricciones

Los parámetros de tipo arreglo serán pasados siempre por referencia, sin necesidad de indicarlo con el símbolo &.

No se pueden asignar ni comparar arreglos directamente, hay que asignar o comparar sus elementos uno a uno.

vec_1 = vec_2  MAL

`for (i=0; i<100; i++) vec_1[i] = vec_2[i]` BIEN

## Declaracion de Tipos de Datos

Es conveniente declarar tipos de datos para nuestros arreglos.

La sintaxis para declarar un tipo es la siguiente:

# Maximo Fisico vs Maximo Logico

## Maximo Fisico

Se refiere al limite que tiene nuestro arreglo realmente en terminos de datos posibles a almacenar debido a los espacios de memoria reservados que se definen.

## Maximo Logico

Se refiere a los valores que tenemos en nuestro arreglo en uso, los cuales pueden ser una cantidad menor al maximo fisico del arreglo.

Los maximos logicos pueden ser internos o externos:

### Internos

El maximo interno se utiliza

### Externos

El maximo logico ***externo*** nos permite utilizar una variable externa al Arreglo, para definir el limite en que nosotros vamos a tener nuestro maximo logico.

# Estructura Basica de un Programa

```c
#include LIBRERIAS

#define CONSTANTES

typedef TIPOS

FUNCIONES

int main() {
	--- codigo ---
	
	return 0;
}
```
