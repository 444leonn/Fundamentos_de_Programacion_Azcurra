# Ejercicios de Práctica - Tablas y Registros, Recursividad, Memoria Dinámica

## 1. Tablas y Registros

**1.1. Registro de Alumnos**
- Definir una estructura para un alumno: legajo (int), nombre (string 30), promedio (float).
- Cargar una tabla con N alumnos, mostrar los datos y luego mostrar solo los alumnos con promedio mayor a 8.
- Modularizar: funciones para cargar, mostrar todos, mostrar filtrado.

**1.2. Gestión de Productos**
- Definir un struct Producto: código (int), descripción (string 50), precio (float), stock (int).
- Permitir registrar hasta 50 productos. Implementar función para buscar un producto por código y mostrarlo.
- Función para descontar stock de un producto dado su código y cantidad.

**1.3. Ordenar tabla de empleados**
- Estructura: apellido (string 35), nombre (string 35), legajo (int), sueldo (float).
- Cargar N empleados. Implementar función para ordenar la tabla por apellido y mostrarla ordenada.

---

## 2. Recursividad

**2.1. Suma de elementos de un vector**
- Desarrollar una función recursiva que reciba un vector de enteros y su tamaño, y devuelva la suma de todos sus elementos.

**2.2. Contar ocurrencias de un valor en un vector**
- Dada una función recursiva que reciba un vector de enteros, su tamaño y un valor, retorna cuántas veces aparece ese valor en el vector.

**2.3. Invertir una cadena recursivamente**
- Desarrollar una función recursiva que invierta una cadena de caracteres (string).

**2.4. Buscar máximo en un vector recursivamente**
- Implementar una función recursiva que busque el valor máximo en un vector de enteros.

---

## 3. Memoria Dinámica

**3.1. Vector dinámico de enteros**
- Solicitar al usuario la cantidad N de enteros a cargar. Reservar memoria dinámica, cargar los valores y mostrarlos. Liberar la memoria.

**3.2. Tabla dinámica de registros de alumnos**
- Reservar memoria dinámica para N alumnos (struct como en 1.1). Cargar, mostrar y liberar la memoria.

**3.3. Cadena dinámica**
- Solicitar al usuario una palabra, reservar memoria dinámica justa, copiar la palabra, mostrarla y liberar la memoria.

**3.4. Matriz dinámica de enteros**
- Solicitar al usuario cantidad de filas y columnas. Reservar memoria dinámica para una matriz de enteros, cargar valores y mostrarla. Liberar toda la memoria.

---

## 4. Integrador

**4.1. Tabla dinámica con operaciones recursivas**
- Reservar memoria dinámica para N productos (struct como en 1.2).
- Cargar los productos.
- Implementar función recursiva para mostrar solo los productos cuyo stock sea menor a un valor ingresado por el usuario.

---

> Todos los ejercicios deben modularizarse (funciones de carga, mostrar, liberar, etc.).
> Seguir la sintaxis y estilos de tu repositorio (typedefs, structs, modularidad, nombres claros).
> Validar entrada del usuario donde corresponda.