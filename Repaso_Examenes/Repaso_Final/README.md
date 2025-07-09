# Examen Integrador Final - Fundamentos de Programación / Algortimos y Programacion I (Catedra: Azcurra)
## Ejercicio 1

Una farmacia dispone de un archivo binario llamado `medicamentos.dat`, cuyos registros tienen la siguiente estructura:
- `código` (entero)
- `categoría` (cadena de hasta 25 caracteres, ej. "analgésicos", "antibióticos", etc.)
- `nombre_comercial` (cadena de hasta 30 caracteres)
- `stock_actual` (entero)
El archivo **no está ordenado** y **no entra completamente en memoria**.

Desarrollar un programa modular que permita:
- Solicitar al usuario una categoría.
- Generar una **tabla en memoria** llamada `medxcat` que contenga **todos los medicamentos de esa categoría**.  
   La tabla debe tener la **misma estructura** que el archivo original.
- Suponer que la tabla tiene como máximo 200 registros y **entra en memoria**.
- Mostrar por pantalla los medicamentos de `medxcat` cuyo **stock_actual** sea **superior al stock promedio** dentro de esa categoría.

---

## Ejercicio 2
Escribir una función en lenguaje C llamada `crear_estructura_dinamica` que reciba un **arreglo unidimensional de enteros** ya cargado y su máximo lógico.
La función debe devolver un **puntero** a una estructura dinámica que contenga los elementos del arreglo recibido y utilice solo el espacio de memoria necesario.

Escribir un programa `main` que:
1. Invoque la función `crear_estructura_dinamica` con:
```c
int vec[100] = {4, 8, 23, 25, 18};
```
2. Invocar la función `mostrar_estructura_dinamica`, pasándole la estructura y la cantidad de elementos. Esta función no debe desarrollarse, solo invocarse correctamente si el puntero no es `NULL`.

---

## Ejercicio 3
Desarrollar una función **recursiva** en lenguaje C que reciba un **número entero** como parámetro y devuelva la **sumatoria de los números naturales desde 1 hasta ese número**.
- Si el número recibido es **menor o igual a 0**, la función debe devolver `0`.
**Ejemplo**
```c
sumatoria(6) → 1 + 2 + 3 + 4 + 5 + 6 = 21
```

---