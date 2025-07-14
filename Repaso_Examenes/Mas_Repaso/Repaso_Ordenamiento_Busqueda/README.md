# Ejercicios de Ordenamiento y Búsqueda en C

## Ordenamiento con Arreglos Simples

### 1. Ordenamiento de Burbuja

- Escribir un programa que solicite al usuario N números enteros y los almacene en un arreglo. Implementa el método de burbuja para ordenar el arreglo de menor a mayor y muestra el arreglo antes y después de ordenar.

### 2. Ordenamiento por Selección

- Dado un vector de 10 números reales predefinidos, implementa el método de selección para ordenarlo de mayor a menor. Muestra el vector antes y después del ordenamiento.

### 3. Ordenamiento por Inserción

- Solicita al usuario la cantidad de números N, luego pide al usuario que ingrese N números enteros y guárdalos en un arreglo. Ordena el arreglo usando el método de inserción y muestra el resultado.

---

## Búsqueda en Arreglos Simples

### 4. Búsqueda Secuencial

- Dado un arreglo de enteros cargado por el usuario (de tamaño N), solicita un número a buscar e implementa la búsqueda secuencial para determinar si el número está presente e imprime su/s posición/es.

### 5. Búsqueda Binaria

- Dado un arreglo de enteros ordenado ascendentemente, solicita un número a buscar e implementa la búsqueda binaria para indicar si el número está presente y, en caso afirmativo, en qué posición.

---

## Ordenamiento y Búsqueda en Tablas de Registros

Supón la siguiente estructura para un registro de persona:

```c
#define MAX_NOMBRE 30
typedef struct {
    int legajo;
    char nombre[MAX_NOMBRE];
    int edad;
} T_Persona;
```

### 6. Ordenar Tabla de Personas por Legajo (Burbuja)

- Cargar una tabla de personas (struct) con N personas. Implementar el método de burbuja para ordenar la tabla por número de legajo ascendente. Mostrar antes y después de ordenar.

### 7. Ordenar Tabla de Personas por Edad (Selección)

- Utilizando la misma estructura anterior, ordenar la tabla por edad de menor a mayor usando el método de selección.

### 8. Ordenar Tabla de Personas por Nombre (Inserción)

- Ordenar la tabla por nombre alfabéticamente (strcmp) usando el algoritmo de inserción.

---

## Búsqueda en Tablas de Registros

### 9. Búsqueda Secuencial por Nombre

- Dada una tabla de personas cargada, solicita al usuario un nombre y realiza una búsqueda secuencial para indicar si existe alguna persona con ese nombre (strcmp) y su/s posición/es.

### 10. Búsqueda Binaria por Legajo

- Dada una tabla de personas ORDENADA por legajo, solicita un legajo a buscar e implementa la búsqueda binaria para informar si el legajo existe y en qué posición está.

---

## Integrador

### 11. Búsqueda y Ordenamiento Combinados

- Crea un menú que permita al usuario:
- a) Ordenar la tabla de personas por el criterio que elija (legajo, edad, nombre).
- b) Buscar una persona por nombre o legajo (usar método adecuado según criterio).
- c) Mostrar la tabla.

---

## Extra: Desafío

### 12. Ordenar Vector de Structs por Múltiples Criterios

- Ordenar la tabla de personas primero por edad y, en caso de empate, por nombre alfabéticamente.

---

> Todos los ejercicios deben estar modularizados (funciones para cargar, mostrar, ordenar, buscar, etc.). Utiliza la sintaxis y estilos de los ejercicios de tu repositorio.Recuerda validar entradas del usuario y mostrar mensajes claros.
